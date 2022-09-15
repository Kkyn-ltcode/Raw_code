static int amrwb_decode_frame ( AVCodecContext * avctx , void * data , int * got_frame_ptr , AVPacket * avpkt ) {
 AMRWBContext * ctx = avctx -> priv_data ;
 AVFrame * frame = data ;
 AMRWBFrame * cf = & ctx -> frame ;
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 int expected_fr_size , header_size ;
 float * buf_out ;
 float spare_vector [ AMRWB_SFR_SIZE ] ;
 float fixed_gain_factor ;
 float * synth_fixed_vector ;
 float synth_fixed_gain ;
 float voice_fac , stab_fac ;
 float synth_exc [ AMRWB_SFR_SIZE ] ;
 float hb_exc [ AMRWB_SFR_SIZE_16k ] ;
 float hb_samples [ AMRWB_SFR_SIZE_16k ] ;
 float hb_gain ;
 int sub , i , ret ;
 frame -> nb_samples = 4 * AMRWB_SFR_SIZE_16k ;
 if ( ( ret = ff_get_buffer ( avctx , frame , 0 ) ) < 0 ) {
 av_log ( avctx , AV_LOG_ERROR , "get_buffer() failed\n" ) ;
 return ret ;
 }
 buf_out = ( float * ) frame -> data [ 0 ] ;
 header_size = decode_mime_header ( ctx , buf ) ;
 if ( ctx -> fr_cur_mode > MODE_SID ) {
 av_log ( avctx , AV_LOG_ERROR , "Invalid mode %d\n" , ctx -> fr_cur_mode ) ;
 return AVERROR_INVALIDDATA ;
 }
 expected_fr_size = ( ( cf_sizes_wb [ ctx -> fr_cur_mode ] + 7 ) >> 3 ) + 1 ;
 if ( buf_size < expected_fr_size ) {
 av_log ( avctx , AV_LOG_ERROR , "Frame too small (%d bytes). Truncated file?\n" , buf_size ) ;
 * got_frame_ptr = 0 ;
 return AVERROR_INVALIDDATA ;
 }
 if ( ! ctx -> fr_quality || ctx -> fr_cur_mode > MODE_SID ) av_log ( avctx , AV_LOG_ERROR , "Encountered a bad or corrupted frame\n" ) ;
 if ( ctx -> fr_cur_mode == MODE_SID ) {
 av_log_missing_feature ( avctx , "SID mode" , 1 ) ;
 return AVERROR_PATCHWELCOME ;
 }
 ff_amr_bit_reorder ( ( uint16_t * ) & ctx -> frame , sizeof ( AMRWBFrame ) , buf + header_size , amr_bit_orderings_by_mode [ ctx -> fr_cur_mode ] ) ;
 if ( ctx -> fr_cur_mode == MODE_6k60 ) {
 decode_isf_indices_36b ( cf -> isp_id , ctx -> isf_cur ) ;
 }
 else {
 decode_isf_indices_46b ( cf -> isp_id , ctx -> isf_cur ) ;
 }
 isf_add_mean_and_past ( ctx -> isf_cur , ctx -> isf_q_past ) ;
 ff_set_min_dist_lsf ( ctx -> isf_cur , MIN_ISF_SPACING , LP_ORDER - 1 ) ;
 stab_fac = stability_factor ( ctx -> isf_cur , ctx -> isf_past_final ) ;
 ctx -> isf_cur [ LP_ORDER - 1 ] *= 2.0 ;
 ff_acelp_lsf2lspd ( ctx -> isp [ 3 ] , ctx -> isf_cur , LP_ORDER ) ;
 if ( ctx -> first_frame ) {
 ctx -> first_frame = 0 ;
 memcpy ( ctx -> isp_sub4_past , ctx -> isp [ 3 ] , LP_ORDER * sizeof ( double ) ) ;
 }
 interpolate_isp ( ctx -> isp , ctx -> isp_sub4_past ) ;
 for ( sub = 0 ;
 sub < 4 ;
 sub ++ ) ff_amrwb_lsp2lpc ( ctx -> isp [ sub ] , ctx -> lp_coef [ sub ] , LP_ORDER ) ;
 for ( sub = 0 ;
 sub < 4 ;
 sub ++ ) {
 const AMRWBSubFrame * cur_subframe = & cf -> subframe [ sub ] ;
 float * sub_buf = buf_out + sub * AMRWB_SFR_SIZE_16k ;
 decode_pitch_vector ( ctx , cur_subframe , sub ) ;
 decode_fixed_vector ( ctx -> fixed_vector , cur_subframe -> pul_ih , cur_subframe -> pul_il , ctx -> fr_cur_mode ) ;
 pitch_sharpening ( ctx , ctx -> fixed_vector ) ;
 decode_gains ( cur_subframe -> vq_gain , ctx -> fr_cur_mode , & fixed_gain_factor , & ctx -> pitch_gain [ 0 ] ) ;
 ctx -> fixed_gain [ 0 ] = ff_amr_set_fixed_gain ( fixed_gain_factor , avpriv_scalarproduct_float_c ( ctx -> fixed_vector , ctx -> fixed_vector , AMRWB_SFR_SIZE ) / AMRWB_SFR_SIZE , ctx -> prediction_error , ENERGY_MEAN , energy_pred_fac ) ;
 voice_fac = voice_factor ( ctx -> pitch_vector , ctx -> pitch_gain [ 0 ] , ctx -> fixed_vector , ctx -> fixed_gain [ 0 ] ) ;
 ctx -> tilt_coef = voice_fac * 0.25 + 0.25 ;
 for ( i = 0 ;
 i < AMRWB_SFR_SIZE ;
 i ++ ) {
 ctx -> excitation [ i ] *= ctx -> pitch_gain [ 0 ] ;
 ctx -> excitation [ i ] += ctx -> fixed_gain [ 0 ] * ctx -> fixed_vector [ i ] ;
 ctx -> excitation [ i ] = truncf ( ctx -> excitation [ i ] ) ;
 }
 synth_fixed_gain = noise_enhancer ( ctx -> fixed_gain [ 0 ] , & ctx -> prev_tr_gain , voice_fac , stab_fac ) ;
 synth_fixed_vector = anti_sparseness ( ctx , ctx -> fixed_vector , spare_vector ) ;
 pitch_enhancer ( synth_fixed_vector , voice_fac ) ;
 synthesis ( ctx , ctx -> lp_coef [ sub ] , synth_exc , synth_fixed_gain , synth_fixed_vector , & ctx -> samples_az [ LP_ORDER ] ) ;
 de_emphasis ( & ctx -> samples_up [ UPS_MEM_SIZE ] , & ctx -> samples_az [ LP_ORDER ] , PREEMPH_FAC , ctx -> demph_mem ) ;
 ff_acelp_apply_order_2_transfer_function ( & ctx -> samples_up [ UPS_MEM_SIZE ] , & ctx -> samples_up [ UPS_MEM_SIZE ] , hpf_zeros , hpf_31_poles , hpf_31_gain , ctx -> hpf_31_mem , AMRWB_SFR_SIZE ) ;
 upsample_5_4 ( sub_buf , & ctx -> samples_up [ UPS_FIR_SIZE ] , AMRWB_SFR_SIZE_16k ) ;
 ff_acelp_apply_order_2_transfer_function ( hb_samples , & ctx -> samples_up [ UPS_MEM_SIZE ] , hpf_zeros , hpf_400_poles , hpf_400_gain , ctx -> hpf_400_mem , AMRWB_SFR_SIZE ) ;
 hb_gain = find_hb_gain ( ctx , hb_samples , cur_subframe -> hb_gain , cf -> vad ) ;
 scaled_hb_excitation ( ctx , hb_exc , synth_exc , hb_gain ) ;
 hb_synthesis ( ctx , sub , & ctx -> samples_hb [ LP_ORDER_16k ] , hb_exc , ctx -> isf_cur , ctx -> isf_past_final ) ;
 hb_fir_filter ( hb_samples , bpf_6_7_coef , ctx -> bpf_6_7_mem , & ctx -> samples_hb [ LP_ORDER_16k ] ) ;
 if ( ctx -> fr_cur_mode == MODE_23k85 ) hb_fir_filter ( hb_samples , lpf_7_coef , ctx -> lpf_7_mem , hb_samples ) ;
 for ( i = 0 ;
 i < AMRWB_SFR_SIZE_16k ;
 i ++ ) sub_buf [ i ] = ( sub_buf [ i ] + hb_samples [ i ] ) * ( 1.0f / ( 1 << 15 ) ) ;
 update_sub_state ( ctx ) ;
 }
 memcpy ( ctx -> isp_sub4_past , ctx -> isp [ 3 ] , LP_ORDER * sizeof ( ctx -> isp [ 3 ] [ 0 ] ) ) ;
 memcpy ( ctx -> isf_past_final , ctx -> isf_cur , LP_ORDER * sizeof ( float ) ) ;
 * got_frame_ptr = 1 ;
 return expected_fr_size ;
 }
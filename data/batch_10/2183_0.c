static int mpeg1_decode_sequence ( AVCodecContext * avctx , const uint8_t * buf , int buf_size ) {
 Mpeg1Context * s1 = avctx -> priv_data ;
 MpegEncContext * s = & s1 -> mpeg_enc_ctx ;
 int width , height ;
 int i , v , j ;
 init_get_bits ( & s -> gb , buf , buf_size * 8 ) ;
 width = get_bits ( & s -> gb , 12 ) ;
 height = get_bits ( & s -> gb , 12 ) ;
 if ( width <= 0 || height <= 0 ) return - 1 ;
 s -> aspect_ratio_info = get_bits ( & s -> gb , 4 ) ;
 if ( s -> aspect_ratio_info == 0 ) {
 av_log ( avctx , AV_LOG_ERROR , "aspect ratio has forbidden 0 value\n" ) ;
 if ( avctx -> err_recognition & AV_EF_BITSTREAM ) return - 1 ;
 }
 s -> frame_rate_index = get_bits ( & s -> gb , 4 ) ;
 if ( s -> frame_rate_index == 0 || s -> frame_rate_index > 13 ) return - 1 ;
 s -> bit_rate = get_bits ( & s -> gb , 18 ) * 400 ;
 if ( get_bits1 ( & s -> gb ) == 0 ) return - 1 ;
 s -> width = width ;
 s -> height = height ;
 s -> avctx -> rc_buffer_size = get_bits ( & s -> gb , 10 ) * 1024 * 16 ;
 skip_bits ( & s -> gb , 1 ) ;
 if ( get_bits1 ( & s -> gb ) ) {
 load_matrix ( s , s -> chroma_intra_matrix , s -> intra_matrix , 1 ) ;
 }
 else {
 for ( i = 0 ;
 i < 64 ;
 i ++ ) {
 j = s -> dsp . idct_permutation [ i ] ;
 v = ff_mpeg1_default_intra_matrix [ i ] ;
 s -> intra_matrix [ j ] = v ;
 s -> chroma_intra_matrix [ j ] = v ;
 }
 }
 if ( get_bits1 ( & s -> gb ) ) {
 load_matrix ( s , s -> chroma_inter_matrix , s -> inter_matrix , 0 ) ;
 }
 else {
 for ( i = 0 ;
 i < 64 ;
 i ++ ) {
 int j = s -> dsp . idct_permutation [ i ] ;
 v = ff_mpeg1_default_non_intra_matrix [ i ] ;
 s -> inter_matrix [ j ] = v ;
 s -> chroma_inter_matrix [ j ] = v ;
 }
 }
 if ( show_bits ( & s -> gb , 23 ) != 0 ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "sequence header damaged\n" ) ;
 return - 1 ;
 }
 s -> progressive_sequence = 1 ;
 s -> progressive_frame = 1 ;
 s -> picture_structure = PICT_FRAME ;
 s -> frame_pred_frame_dct = 1 ;
 s -> chroma_format = 1 ;
 s -> codec_id = s -> avctx -> codec_id = AV_CODEC_ID_MPEG1VIDEO ;
 s -> out_format = FMT_MPEG1 ;
 s -> swap_uv = 0 ;
 if ( s -> flags & CODEC_FLAG_LOW_DELAY ) s -> low_delay = 1 ;
 if ( s -> avctx -> debug & FF_DEBUG_PICT_INFO ) av_log ( s -> avctx , AV_LOG_DEBUG , "vbv buffer: %d, bitrate:%d\n" , s -> avctx -> rc_buffer_size , s -> bit_rate ) ;
 return 0 ;
 }
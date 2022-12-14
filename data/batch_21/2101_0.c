static int dca_subsubframe ( DCAContext * s , int base_channel , int block_index ) {
 int k , l ;
 int subsubframe = s -> current_subsubframe ;
 const float * quant_step_table ;
 float ( * subband_samples ) [ DCA_SUBBANDS ] [ 8 ] = s -> subband_samples [ block_index ] ;
 LOCAL_ALIGNED_16 ( int , block , [ 8 ] ) ;
 if ( s -> bit_rate_index == 0x1f ) quant_step_table = lossless_quant_d ;
 else quant_step_table = lossy_quant_d ;
 for ( k = base_channel ;
 k < s -> prim_channels ;
 k ++ ) {
 if ( get_bits_left ( & s -> gb ) < 0 ) return AVERROR_INVALIDDATA ;
 for ( l = 0 ;
 l < s -> vq_start_subband [ k ] ;
 l ++ ) {
 int m ;
 int abits = s -> bitalloc [ k ] [ l ] ;
 float quant_step_size = quant_step_table [ abits ] ;
 int sel = s -> quant_index_huffman [ k ] [ abits ] ;
 if ( ! abits ) {
 memset ( subband_samples [ k ] [ l ] , 0 , 8 * sizeof ( subband_samples [ 0 ] [ 0 ] [ 0 ] ) ) ;
 }
 else {
 int sfi = s -> transition_mode [ k ] [ l ] && subsubframe >= s -> transition_mode [ k ] [ l ] ;
 float rscale = quant_step_size * s -> scale_factor [ k ] [ l ] [ sfi ] * s -> scalefactor_adj [ k ] [ sel ] ;
 if ( abits >= 11 || ! dca_smpl_bitalloc [ abits ] . vlc [ sel ] . table ) {
 if ( abits <= 7 ) {
 int block_code1 , block_code2 , size , levels , err ;
 size = abits_sizes [ abits - 1 ] ;
 levels = abits_levels [ abits - 1 ] ;
 block_code1 = get_bits ( & s -> gb , size ) ;
 block_code2 = get_bits ( & s -> gb , size ) ;
 err = decode_blockcodes ( block_code1 , block_code2 , levels , block ) ;
 if ( err ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "ERROR: block code look-up failed\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 }
 else {
 for ( m = 0 ;
 m < 8 ;
 m ++ ) block [ m ] = get_sbits ( & s -> gb , abits - 3 ) ;
 }
 }
 else {
 for ( m = 0 ;
 m < 8 ;
 m ++ ) block [ m ] = get_bitalloc ( & s -> gb , & dca_smpl_bitalloc [ abits ] , sel ) ;
 }
 s -> fmt_conv . int32_to_float_fmul_scalar ( subband_samples [ k ] [ l ] , block , rscale , 8 ) ;
 }
 if ( s -> prediction_mode [ k ] [ l ] ) {
 int n ;
 for ( m = 0 ;
 m < 8 ;
 m ++ ) {
 for ( n = 1 ;
 n <= 4 ;
 n ++ ) if ( m >= n ) subband_samples [ k ] [ l ] [ m ] += ( adpcm_vb [ s -> prediction_vq [ k ] [ l ] ] [ n - 1 ] * subband_samples [ k ] [ l ] [ m - n ] / 8192 ) ;
 else if ( s -> predictor_history ) subband_samples [ k ] [ l ] [ m ] += ( adpcm_vb [ s -> prediction_vq [ k ] [ l ] ] [ n - 1 ] * s -> subband_samples_hist [ k ] [ l ] [ m - n + 4 ] / 8192 ) ;
 }
 }
 }
 for ( l = s -> vq_start_subband [ k ] ;
 l < s -> subband_activity [ k ] ;
 l ++ ) {
 int hfvq = s -> high_freq_vq [ k ] [ l ] ;
 if ( ! s -> debug_flag & 0x01 ) {
 av_log ( s -> avctx , AV_LOG_DEBUG , "Stream with high frequencies VQ coding\n" ) ;
 s -> debug_flag |= 0x01 ;
 }
 int8x8_fmul_int32 ( subband_samples [ k ] [ l ] , & high_freq_vq [ hfvq ] [ subsubframe * 8 ] , s -> scale_factor [ k ] [ l ] [ 0 ] ) ;
 }
 }
 if ( s -> aspf || subsubframe == s -> subsubframes [ s -> current_subframe ] - 1 ) {
 if ( 0xFFFF == get_bits ( & s -> gb , 16 ) ) {
 # ifdef TRACE av_log ( s -> avctx , AV_LOG_DEBUG , "Got subframe DSYNC\n" ) ;
 # endif }
 else {
 av_log ( s -> avctx , AV_LOG_ERROR , "Didn't get subframe DSYNC\n" ) ;
 }
 }
 for ( k = base_channel ;
 k < s -> prim_channels ;
 k ++ ) for ( l = 0 ;
 l < s -> vq_start_subband [ k ] ;
 l ++ ) memcpy ( s -> subband_samples_hist [ k ] [ l ] , & subband_samples [ k ] [ l ] [ 4 ] , 4 * sizeof ( subband_samples [ 0 ] [ 0 ] [ 0 ] ) ) ;
 return 0 ;
 }
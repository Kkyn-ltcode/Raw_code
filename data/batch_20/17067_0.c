void vp8_set_speed_features ( VP8_COMP * cpi ) {
 SPEED_FEATURES * sf = & cpi -> sf ;
 int Mode = cpi -> compressor_speed ;
 int Speed = cpi -> Speed ;
 int i ;
 VP8_COMMON * cm = & cpi -> common ;
 int last_improved_quant = sf -> improved_quant ;
 int ref_frames ;
 for ( i = 0 ;
 i < MAX_MODES ;
 i ++ ) {
 cpi -> mode_check_freq [ i ] = 0 ;
 }
 cpi -> mb . mbs_tested_so_far = 0 ;
 sf -> RD = 1 ;
 sf -> search_method = NSTEP ;
 sf -> improved_quant = 1 ;
 sf -> improved_dct = 1 ;
 sf -> auto_filter = 1 ;
 sf -> recode_loop = 1 ;
 sf -> quarter_pixel_search = 1 ;
 sf -> half_pixel_search = 1 ;
 sf -> iterative_sub_pixel = 1 ;
 sf -> optimize_coefficients = 1 ;
 sf -> use_fastquant_for_pick = 0 ;
 sf -> no_skip_block4x4_search = 1 ;
 sf -> first_step = 0 ;
 sf -> max_step_search_steps = MAX_MVSEARCH_STEPS ;
 sf -> improved_mv_pred = 1 ;
 for ( i = 0 ;
 i < MAX_MODES ;
 i ++ ) sf -> thresh_mult [ i ] = 0 ;
 ref_frames = 1 ;
 if ( cpi -> ref_frame_flags & VP8_LAST_FRAME ) ref_frames ++ ;
 if ( cpi -> ref_frame_flags & VP8_GOLD_FRAME ) ref_frames ++ ;
 if ( cpi -> ref_frame_flags & VP8_ALTR_FRAME ) ref_frames ++ ;
 if ( Mode == 0 ) Speed = 0 ;
 else if ( Mode == 2 ) Speed = RT ( Speed ) ;
 else {
 if ( Speed > 5 ) Speed = 5 ;
 Speed = GOOD ( Speed ) ;
 }
 sf -> thresh_mult [ THR_ZERO1 ] = sf -> thresh_mult [ THR_NEAREST1 ] = sf -> thresh_mult [ THR_NEAR1 ] = sf -> thresh_mult [ THR_DC ] = 0 ;
 sf -> thresh_mult [ THR_ZERO2 ] = sf -> thresh_mult [ THR_ZERO3 ] = sf -> thresh_mult [ THR_NEAREST2 ] = sf -> thresh_mult [ THR_NEAREST3 ] = sf -> thresh_mult [ THR_NEAR2 ] = sf -> thresh_mult [ THR_NEAR3 ] = speed_map ( Speed , thresh_mult_map_znn ) ;
 sf -> thresh_mult [ THR_V_PRED ] = sf -> thresh_mult [ THR_H_PRED ] = speed_map ( Speed , thresh_mult_map_vhpred ) ;
 sf -> thresh_mult [ THR_B_PRED ] = speed_map ( Speed , thresh_mult_map_bpred ) ;
 sf -> thresh_mult [ THR_TM ] = speed_map ( Speed , thresh_mult_map_tm ) ;
 sf -> thresh_mult [ THR_NEW1 ] = speed_map ( Speed , thresh_mult_map_new1 ) ;
 sf -> thresh_mult [ THR_NEW2 ] = sf -> thresh_mult [ THR_NEW3 ] = speed_map ( Speed , thresh_mult_map_new2 ) ;
 sf -> thresh_mult [ THR_SPLIT1 ] = speed_map ( Speed , thresh_mult_map_split1 ) ;
 sf -> thresh_mult [ THR_SPLIT2 ] = sf -> thresh_mult [ THR_SPLIT3 ] = speed_map ( Speed , thresh_mult_map_split2 ) ;
 cpi -> mode_check_freq [ THR_ZERO1 ] = cpi -> mode_check_freq [ THR_NEAREST1 ] = cpi -> mode_check_freq [ THR_NEAR1 ] = cpi -> mode_check_freq [ THR_TM ] = cpi -> mode_check_freq [ THR_DC ] = 0 ;
 cpi -> mode_check_freq [ THR_ZERO2 ] = cpi -> mode_check_freq [ THR_ZERO3 ] = cpi -> mode_check_freq [ THR_NEAREST2 ] = cpi -> mode_check_freq [ THR_NEAREST3 ] = speed_map ( Speed , mode_check_freq_map_zn2 ) ;
 cpi -> mode_check_freq [ THR_NEAR2 ] = cpi -> mode_check_freq [ THR_NEAR3 ] = speed_map ( Speed , mode_check_freq_map_near2 ) ;
 cpi -> mode_check_freq [ THR_V_PRED ] = cpi -> mode_check_freq [ THR_H_PRED ] = cpi -> mode_check_freq [ THR_B_PRED ] = speed_map ( Speed , mode_check_freq_map_vhbpred ) ;
 cpi -> mode_check_freq [ THR_NEW1 ] = speed_map ( Speed , mode_check_freq_map_new1 ) ;
 cpi -> mode_check_freq [ THR_NEW2 ] = cpi -> mode_check_freq [ THR_NEW3 ] = speed_map ( Speed , mode_check_freq_map_new2 ) ;
 cpi -> mode_check_freq [ THR_SPLIT1 ] = speed_map ( Speed , mode_check_freq_map_split1 ) ;
 cpi -> mode_check_freq [ THR_SPLIT2 ] = cpi -> mode_check_freq [ THR_SPLIT3 ] = speed_map ( Speed , mode_check_freq_map_split2 ) ;
 Speed = cpi -> Speed ;
 switch ( Mode ) {
 # if ! ( CONFIG_REALTIME_ONLY ) case 0 : sf -> first_step = 0 ;
 sf -> max_step_search_steps = MAX_MVSEARCH_STEPS ;
 break ;
 case 1 : case 3 : if ( Speed > 0 ) {
 sf -> optimize_coefficients = 0 ;
 sf -> use_fastquant_for_pick = 1 ;
 sf -> no_skip_block4x4_search = 0 ;
 sf -> first_step = 1 ;
 }
 if ( Speed > 2 ) {
 sf -> improved_quant = 0 ;
 sf -> improved_dct = 0 ;
 sf -> recode_loop = 2 ;
 }
 if ( Speed > 3 ) {
 sf -> auto_filter = 1 ;
 sf -> recode_loop = 0 ;
 sf -> RD = 0 ;
 }
 if ( Speed > 4 ) {
 sf -> auto_filter = 0 ;
 }
 break ;
 # endif case 2 : sf -> optimize_coefficients = 0 ;
 sf -> recode_loop = 0 ;
 sf -> auto_filter = 1 ;
 sf -> iterative_sub_pixel = 1 ;
 sf -> search_method = NSTEP ;
 if ( Speed > 0 ) {
 sf -> improved_quant = 0 ;
 sf -> improved_dct = 0 ;
 sf -> use_fastquant_for_pick = 1 ;
 sf -> no_skip_block4x4_search = 0 ;
 sf -> first_step = 1 ;
 }
 if ( Speed > 2 ) sf -> auto_filter = 0 ;
 if ( Speed > 3 ) {
 sf -> RD = 0 ;
 sf -> auto_filter = 1 ;
 }
 if ( Speed > 4 ) {
 sf -> auto_filter = 0 ;
 sf -> search_method = HEX ;
 sf -> iterative_sub_pixel = 0 ;
 }
 if ( Speed > 6 ) {
 unsigned int sum = 0 ;
 unsigned int total_mbs = cm -> MBs ;
 int thresh ;
 unsigned int total_skip ;
 int min = 2000 ;
 if ( cpi -> oxcf . encode_breakout > 2000 ) min = cpi -> oxcf . encode_breakout ;
 min >>= 7 ;
 for ( i = 0 ;
 i < min ;
 i ++ ) {
 sum += cpi -> mb . error_bins [ i ] ;
 }
 total_skip = sum ;
 sum = 0 ;
 for ( ;
 i < 1024 ;
 i ++ ) {
 sum += cpi -> mb . error_bins [ i ] ;
 if ( 10 * sum >= ( unsigned int ) ( cpi -> Speed - 6 ) * ( total_mbs - total_skip ) ) break ;
 }
 i -- ;
 thresh = ( i << 7 ) ;
 if ( thresh < 2000 ) thresh = 2000 ;
 if ( ref_frames > 1 ) {
 sf -> thresh_mult [ THR_NEW1 ] = thresh ;
 sf -> thresh_mult [ THR_NEAREST1 ] = thresh >> 1 ;
 sf -> thresh_mult [ THR_NEAR1 ] = thresh >> 1 ;
 }
 if ( ref_frames > 2 ) {
 sf -> thresh_mult [ THR_NEW2 ] = thresh << 1 ;
 sf -> thresh_mult [ THR_NEAREST2 ] = thresh ;
 sf -> thresh_mult [ THR_NEAR2 ] = thresh ;
 }
 if ( ref_frames > 3 ) {
 sf -> thresh_mult [ THR_NEW3 ] = thresh << 1 ;
 sf -> thresh_mult [ THR_NEAREST3 ] = thresh ;
 sf -> thresh_mult [ THR_NEAR3 ] = thresh ;
 }
 sf -> improved_mv_pred = 0 ;
 }
 if ( Speed > 8 ) sf -> quarter_pixel_search = 0 ;
 if ( cm -> version == 0 ) {
 cm -> filter_type = NORMAL_LOOPFILTER ;
 if ( Speed >= 14 ) cm -> filter_type = SIMPLE_LOOPFILTER ;
 }
 else {
 cm -> filter_type = SIMPLE_LOOPFILTER ;
 }
 if ( Speed >= 15 ) sf -> half_pixel_search = 0 ;
 vpx_memset ( cpi -> mb . error_bins , 0 , sizeof ( cpi -> mb . error_bins ) ) ;
 }
 ;
 if ( cpi -> pass == 1 ) {
 sf -> improved_quant = 0 ;
 sf -> optimize_coefficients = 0 ;
 sf -> improved_dct = 0 ;
 }
 if ( cpi -> sf . search_method == NSTEP ) {
 vp8_init3smotion_compensation ( & cpi -> mb , cm -> yv12_fb [ cm -> lst_fb_idx ] . y_stride ) ;
 }
 else if ( cpi -> sf . search_method == DIAMOND ) {
 vp8_init_dsmotion_compensation ( & cpi -> mb , cm -> yv12_fb [ cm -> lst_fb_idx ] . y_stride ) ;
 }
 if ( cpi -> sf . improved_dct ) {
 cpi -> mb . short_fdct8x4 = vp8_short_fdct8x4 ;
 cpi -> mb . short_fdct4x4 = vp8_short_fdct4x4 ;
 }
 else {
 cpi -> mb . short_fdct8x4 = vp8_short_fdct8x4 ;
 cpi -> mb . short_fdct4x4 = vp8_short_fdct4x4 ;
 }
 cpi -> mb . short_walsh4x4 = vp8_short_walsh4x4 ;
 if ( cpi -> sf . improved_quant ) {
 cpi -> mb . quantize_b = vp8_regular_quantize_b ;
 cpi -> mb . quantize_b_pair = vp8_regular_quantize_b_pair ;
 }
 else {
 cpi -> mb . quantize_b = vp8_fast_quantize_b ;
 cpi -> mb . quantize_b_pair = vp8_fast_quantize_b_pair ;
 }
 if ( cpi -> sf . improved_quant != last_improved_quant ) vp8cx_init_quantizer ( cpi ) ;
 if ( cpi -> sf . iterative_sub_pixel == 1 ) {
 cpi -> find_fractional_mv_step = vp8_find_best_sub_pixel_step_iteratively ;
 }
 else if ( cpi -> sf . quarter_pixel_search ) {
 cpi -> find_fractional_mv_step = vp8_find_best_sub_pixel_step ;
 }
 else if ( cpi -> sf . half_pixel_search ) {
 cpi -> find_fractional_mv_step = vp8_find_best_half_pixel_step ;
 }
 else {
 cpi -> find_fractional_mv_step = vp8_skip_fractional_mv_step ;
 }
 if ( cpi -> sf . optimize_coefficients == 1 && cpi -> pass != 1 ) cpi -> mb . optimize = 1 ;
 else cpi -> mb . optimize = 0 ;
 if ( cpi -> common . full_pixel ) cpi -> find_fractional_mv_step = vp8_skip_fractional_mv_step ;
 # ifdef SPEEDSTATS frames_at_speed [ cpi -> Speed ] ++ ;
 # endif }
void vp9_rc_init_minq_luts ( ) {
 init_minq_luts ( kf_low_motion_minq_8 , kf_high_motion_minq_8 , arfgf_low_motion_minq_8 , arfgf_high_motion_minq_8 , inter_minq_8 , rtc_minq_8 , VPX_BITS_8 ) ;
 # if CONFIG_VP9_HIGHBITDEPTH init_minq_luts ( kf_low_motion_minq_10 , kf_high_motion_minq_10 , arfgf_low_motion_minq_10 , arfgf_high_motion_minq_10 , inter_minq_10 , rtc_minq_10 , VPX_BITS_10 ) ;
 init_minq_luts ( kf_low_motion_minq_12 , kf_high_motion_minq_12 , arfgf_low_motion_minq_12 , arfgf_high_motion_minq_12 , inter_minq_12 , rtc_minq_12 , VPX_BITS_12 ) ;
 # endif }
static int calc_pframe_target_size_one_pass_vbr ( const VP9_COMP * const cpi ) {
 static const int af_ratio = 10 ;
 const RATE_CONTROL * const rc = & cpi -> rc ;
 int target ;
 # if USE_ALTREF_FOR_ONE_PASS target = ( ! rc -> is_src_frame_alt_ref && ( cpi -> refresh_golden_frame || cpi -> refresh_alt_ref_frame ) ) ? ( rc -> avg_frame_bandwidth * rc -> baseline_gf_interval * af_ratio ) / ( rc -> baseline_gf_interval + af_ratio - 1 ) : ( rc -> avg_frame_bandwidth * rc -> baseline_gf_interval ) / ( rc -> baseline_gf_interval + af_ratio - 1 ) ;
 # else target = rc -> avg_frame_bandwidth ;
 # endif return vp9_rc_clamp_pframe_target_size ( cpi , target ) ;
 }
static void init_motion_estimation ( VP9_COMP * cpi ) {
 int y_stride = cpi -> scaled_source . y_stride ;
 if ( cpi -> sf . mv . search_method == NSTEP ) {
 vp9_init3smotion_compensation ( & cpi -> ss_cfg , y_stride ) ;
 }
 else if ( cpi -> sf . mv . search_method == DIAMOND ) {
 vp9_init_dsmotion_compensation ( & cpi -> ss_cfg , y_stride ) ;
 }
 }
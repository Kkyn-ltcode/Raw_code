void vp9_new_framerate ( VP9_COMP * cpi , double framerate ) {
 cpi -> framerate = framerate < 0.1 ? 30 : framerate ;
 vp9_rc_update_framerate ( cpi ) ;
 }
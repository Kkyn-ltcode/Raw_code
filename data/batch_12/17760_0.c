int vp9_update_entropy ( VP9_COMP * cpi , int update ) {
 cpi -> ext_refresh_frame_context = update ;
 cpi -> ext_refresh_frame_context_pending = 1 ;
 return 0 ;
 }
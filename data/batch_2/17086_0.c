int vp8_get_preview_raw_frame ( VP8_COMP * cpi , YV12_BUFFER_CONFIG * dest , vp8_ppflags_t * flags ) {
 if ( cpi -> common . refresh_alt_ref_frame ) return - 1 ;
 else {
 int ret ;
 # if CONFIG_MULTITHREAD if ( cpi -> b_lpf_running ) {
 sem_wait ( & cpi -> h_event_end_lpf ) ;
 cpi -> b_lpf_running = 0 ;
 }
 # endif # if CONFIG_POSTPROC cpi -> common . show_frame_mi = cpi -> common . mi ;
 ret = vp8_post_proc_frame ( & cpi -> common , dest , flags ) ;
 # else if ( cpi -> common . frame_to_show ) {
 * dest = * cpi -> common . frame_to_show ;
 dest -> y_width = cpi -> common . Width ;
 dest -> y_height = cpi -> common . Height ;
 dest -> uv_height = cpi -> common . Height / 2 ;
 ret = 0 ;
 }
 else {
 ret = - 1 ;
 }
 # endif vp8_clear_system_state ( ) ;
 return ret ;
 }
 }
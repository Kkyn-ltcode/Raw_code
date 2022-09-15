int vp8_receive_raw_frame ( VP8_COMP * cpi , unsigned int frame_flags , YV12_BUFFER_CONFIG * sd , int64_t time_stamp , int64_t end_time ) {
 struct vpx_usec_timer timer ;
 int res = 0 ;
 vpx_usec_timer_start ( & timer ) ;
 if ( sd -> y_width != cpi -> oxcf . Width || sd -> y_height != cpi -> oxcf . Height ) {
 assert ( cpi -> oxcf . lag_in_frames < 2 ) ;
 dealloc_raw_frame_buffers ( cpi ) ;
 alloc_raw_frame_buffers ( cpi ) ;
 }
 if ( vp8_lookahead_push ( cpi -> lookahead , sd , time_stamp , end_time , frame_flags , cpi -> active_map_enabled ? cpi -> active_map : NULL ) ) res = - 1 ;
 vpx_usec_timer_mark ( & timer ) ;
 cpi -> time_receive_data += vpx_usec_timer_elapsed ( & timer ) ;
 return res ;
 }
static void dealloc_raw_frame_buffers ( VP8_COMP * cpi ) {
 # if VP8_TEMPORAL_ALT_REF vp8_yv12_de_alloc_frame_buffer ( & cpi -> alt_ref_buffer ) ;
 # endif vp8_lookahead_destroy ( cpi -> lookahead ) ;
 }
static void alloc_raw_frame_buffers ( VP8_COMP * cpi ) {
 # if VP8_TEMPORAL_ALT_REF int width = ( cpi -> oxcf . Width + 15 ) & ~ 15 ;
 int height = ( cpi -> oxcf . Height + 15 ) & ~ 15 ;
 # endif cpi -> lookahead = vp8_lookahead_init ( cpi -> oxcf . Width , cpi -> oxcf . Height , cpi -> oxcf . lag_in_frames ) ;
 if ( ! cpi -> lookahead ) vpx_internal_error ( & cpi -> common . error , VPX_CODEC_MEM_ERROR , "Failed to allocate lag buffers" ) ;
 # if VP8_TEMPORAL_ALT_REF if ( vp8_yv12_alloc_frame_buffer ( & cpi -> alt_ref_buffer , width , height , VP8BORDERINPIXELS ) ) vpx_internal_error ( & cpi -> common . error , VPX_CODEC_MEM_ERROR , "Failed to allocate altref buffer" ) ;
 # endif }
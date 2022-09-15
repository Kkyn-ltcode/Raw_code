static void alloc_raw_frame_buffers ( VP9_COMP * cpi ) {
 VP9_COMMON * cm = & cpi -> common ;
 const VP9EncoderConfig * oxcf = & cpi -> oxcf ;
 cpi -> lookahead = vp9_lookahead_init ( oxcf -> width , oxcf -> height , cm -> subsampling_x , cm -> subsampling_y , # if CONFIG_VP9_HIGHBITDEPTH cm -> use_highbitdepth , # endif oxcf -> lag_in_frames ) ;
 if ( ! cpi -> lookahead ) vpx_internal_error ( & cm -> error , VPX_CODEC_MEM_ERROR , "Failed to allocate lag buffers" ) ;
 if ( vp9_realloc_frame_buffer ( & cpi -> alt_ref_buffer , oxcf -> width , oxcf -> height , cm -> subsampling_x , cm -> subsampling_y , # if CONFIG_VP9_HIGHBITDEPTH cm -> use_highbitdepth , # endif VP9_ENC_BORDER_IN_PIXELS , NULL , NULL , NULL ) ) vpx_internal_error ( & cm -> error , VPX_CODEC_MEM_ERROR , "Failed to allocate altref buffer" ) ;
 }
static void dealloc_compressor_data ( VP8_COMP * cpi ) {
 vpx_free ( cpi -> tplist ) ;
 cpi -> tplist = NULL ;
 vpx_free ( cpi -> lfmv ) ;
 cpi -> lfmv = 0 ;
 vpx_free ( cpi -> lf_ref_frame_sign_bias ) ;
 cpi -> lf_ref_frame_sign_bias = 0 ;
 vpx_free ( cpi -> lf_ref_frame ) ;
 cpi -> lf_ref_frame = 0 ;
 vpx_free ( cpi -> segmentation_map ) ;
 cpi -> segmentation_map = 0 ;
 vpx_free ( cpi -> active_map ) ;
 cpi -> active_map = 0 ;
 vp8_de_alloc_frame_buffers ( & cpi -> common ) ;
 vp8_yv12_de_alloc_frame_buffer ( & cpi -> pick_lf_lvl_frame ) ;
 vp8_yv12_de_alloc_frame_buffer ( & cpi -> scaled_source ) ;
 dealloc_raw_frame_buffers ( cpi ) ;
 vpx_free ( cpi -> tok ) ;
 cpi -> tok = 0 ;
 vpx_free ( cpi -> gf_active_flags ) ;
 cpi -> gf_active_flags = 0 ;
 vpx_free ( cpi -> mb_activity_map ) ;
 cpi -> mb_activity_map = 0 ;
 vpx_free ( cpi -> mb . pip ) ;
 cpi -> mb . pip = 0 ;
 # if CONFIG_MULTITHREAD vpx_free ( cpi -> mt_current_mb_col ) ;
 cpi -> mt_current_mb_col = NULL ;
 # endif }
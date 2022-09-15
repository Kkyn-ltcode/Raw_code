void vp8_alloc_compressor_data ( VP8_COMP * cpi ) {
 VP8_COMMON * cm = & cpi -> common ;
 int width = cm -> Width ;
 int height = cm -> Height ;
 if ( vp8_alloc_frame_buffers ( cm , width , height ) ) vpx_internal_error ( & cpi -> common . error , VPX_CODEC_MEM_ERROR , "Failed to allocate frame buffers" ) ;
 if ( vp8_alloc_partition_data ( cpi ) ) vpx_internal_error ( & cpi -> common . error , VPX_CODEC_MEM_ERROR , "Failed to allocate partition data" ) ;
 if ( ( width & 0xf ) != 0 ) width += 16 - ( width & 0xf ) ;
 if ( ( height & 0xf ) != 0 ) height += 16 - ( height & 0xf ) ;
 if ( vp8_yv12_alloc_frame_buffer ( & cpi -> pick_lf_lvl_frame , width , height , VP8BORDERINPIXELS ) ) vpx_internal_error ( & cpi -> common . error , VPX_CODEC_MEM_ERROR , "Failed to allocate last frame buffer" ) ;
 if ( vp8_yv12_alloc_frame_buffer ( & cpi -> scaled_source , width , height , VP8BORDERINPIXELS ) ) vpx_internal_error ( & cpi -> common . error , VPX_CODEC_MEM_ERROR , "Failed to allocate scaled source buffer" ) ;
 vpx_free ( cpi -> tok ) ;
 {
 # if CONFIG_REALTIME_ONLY & CONFIG_ONTHEFLY_BITPACKING unsigned int tokens = 8 * 24 * 16 ;
 # else unsigned int tokens = cm -> mb_rows * cm -> mb_cols * 24 * 16 ;
 # endif CHECK_MEM_ERROR ( cpi -> tok , vpx_calloc ( tokens , sizeof ( * cpi -> tok ) ) ) ;
 }
 cpi -> zeromv_count = 0 ;
 vpx_free ( cpi -> gf_active_flags ) ;
 CHECK_MEM_ERROR ( cpi -> gf_active_flags , vpx_calloc ( sizeof ( * cpi -> gf_active_flags ) , cm -> mb_rows * cm -> mb_cols ) ) ;
 cpi -> gf_active_count = cm -> mb_rows * cm -> mb_cols ;
 vpx_free ( cpi -> mb_activity_map ) ;
 CHECK_MEM_ERROR ( cpi -> mb_activity_map , vpx_calloc ( sizeof ( * cpi -> mb_activity_map ) , cm -> mb_rows * cm -> mb_cols ) ) ;
 vpx_free ( cpi -> lfmv ) ;
 CHECK_MEM_ERROR ( cpi -> lfmv , vpx_calloc ( ( cm -> mb_rows + 2 ) * ( cm -> mb_cols + 2 ) , sizeof ( * cpi -> lfmv ) ) ) ;
 vpx_free ( cpi -> lf_ref_frame_sign_bias ) ;
 CHECK_MEM_ERROR ( cpi -> lf_ref_frame_sign_bias , vpx_calloc ( ( cm -> mb_rows + 2 ) * ( cm -> mb_cols + 2 ) , sizeof ( * cpi -> lf_ref_frame_sign_bias ) ) ) ;
 vpx_free ( cpi -> lf_ref_frame ) ;
 CHECK_MEM_ERROR ( cpi -> lf_ref_frame , vpx_calloc ( ( cm -> mb_rows + 2 ) * ( cm -> mb_cols + 2 ) , sizeof ( * cpi -> lf_ref_frame ) ) ) ;
 vpx_free ( cpi -> segmentation_map ) ;
 CHECK_MEM_ERROR ( cpi -> segmentation_map , vpx_calloc ( cm -> mb_rows * cm -> mb_cols , sizeof ( * cpi -> segmentation_map ) ) ) ;
 cpi -> cyclic_refresh_mode_index = 0 ;
 vpx_free ( cpi -> active_map ) ;
 CHECK_MEM_ERROR ( cpi -> active_map , vpx_calloc ( cm -> mb_rows * cm -> mb_cols , sizeof ( * cpi -> active_map ) ) ) ;
 vpx_memset ( cpi -> active_map , 1 , ( cm -> mb_rows * cm -> mb_cols ) ) ;
 # if CONFIG_MULTITHREAD if ( width < 640 ) cpi -> mt_sync_range = 1 ;
 else if ( width <= 1280 ) cpi -> mt_sync_range = 4 ;
 else if ( width <= 2560 ) cpi -> mt_sync_range = 8 ;
 else cpi -> mt_sync_range = 16 ;
 if ( cpi -> oxcf . multi_threaded > 1 ) {
 vpx_free ( cpi -> mt_current_mb_col ) ;
 CHECK_MEM_ERROR ( cpi -> mt_current_mb_col , vpx_malloc ( sizeof ( * cpi -> mt_current_mb_col ) * cm -> mb_rows ) ) ;
 }
 # endif vpx_free ( cpi -> tplist ) ;
 CHECK_MEM_ERROR ( cpi -> tplist , vpx_malloc ( sizeof ( TOKENLIST ) * cm -> mb_rows ) ) ;
 # if CONFIG_TEMPORAL_DENOISING if ( cpi -> oxcf . noise_sensitivity > 0 ) {
 vp8_denoiser_free ( & cpi -> denoiser ) ;
 vp8_denoiser_allocate ( & cpi -> denoiser , width , height , cm -> mb_rows , cm -> mb_cols , cpi -> oxcf . noise_sensitivity ) ;
 }
 # endif }
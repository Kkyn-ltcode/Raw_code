int vp9_receive_compressed_data ( VP9Decoder * pbi , size_t size , const uint8_t * * psource ) {
 VP9_COMMON * const cm = & pbi -> common ;
 const uint8_t * source = * psource ;
 int retcode = 0 ;
 cm -> error . error_code = VPX_CODEC_OK ;
 if ( size == 0 ) {
 if ( cm -> frame_refs [ 0 ] . idx != INT_MAX ) cm -> frame_refs [ 0 ] . buf -> corrupted = 1 ;
 }
 if ( cm -> new_fb_idx >= 0 && cm -> frame_bufs [ cm -> new_fb_idx ] . ref_count == 0 ) cm -> release_fb_cb ( cm -> cb_priv , & cm -> frame_bufs [ cm -> new_fb_idx ] . raw_frame_buffer ) ;
 cm -> new_fb_idx = get_free_fb ( cm ) ;
 if ( setjmp ( cm -> error . jmp ) ) {
 pbi -> need_resync = 1 ;
 cm -> error . setjmp = 0 ;
 vp9_clear_system_state ( ) ;
 if ( cm -> frame_refs [ 0 ] . idx != INT_MAX && cm -> frame_refs [ 0 ] . buf != NULL ) cm -> frame_refs [ 0 ] . buf -> corrupted = 1 ;
 if ( cm -> new_fb_idx > 0 && cm -> frame_bufs [ cm -> new_fb_idx ] . ref_count > 0 ) cm -> frame_bufs [ cm -> new_fb_idx ] . ref_count -- ;
 return - 1 ;
 }
 cm -> error . setjmp = 1 ;
 vp9_decode_frame ( pbi , source , source + size , psource ) ;
 swap_frame_buffers ( pbi ) ;
 vp9_clear_system_state ( ) ;
 cm -> last_width = cm -> width ;
 cm -> last_height = cm -> height ;
 if ( ! cm -> show_existing_frame ) cm -> last_show_frame = cm -> show_frame ;
 if ( cm -> show_frame ) {
 if ( ! cm -> show_existing_frame ) vp9_swap_mi_and_prev_mi ( cm ) ;
 cm -> current_video_frame ++ ;
 }
 pbi -> ready_for_new_data = 0 ;
 cm -> error . setjmp = 0 ;
 return retcode ;
 }
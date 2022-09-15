static vpx_fixed_buf_t pass0 ( vpx_image_t * raw , FILE * infile , const VpxInterface * encoder , const vpx_codec_enc_cfg_t * cfg ) {
 vpx_codec_ctx_t codec ;
 int frame_count = 0 ;
 vpx_fixed_buf_t stats = {
 NULL , 0 }
 ;
 if ( vpx_codec_enc_init ( & codec , encoder -> codec_interface ( ) , cfg , 0 ) ) die_codec ( & codec , "Failed to initialize encoder" ) ;
 while ( vpx_img_read ( raw , infile ) ) {
 ++ frame_count ;
 get_frame_stats ( & codec , raw , frame_count , 1 , 0 , VPX_DL_GOOD_QUALITY , & stats ) ;
 }
 while ( get_frame_stats ( & codec , NULL , frame_count , 1 , 0 , VPX_DL_GOOD_QUALITY , & stats ) ) {
 }
 printf ( "Pass 0 complete. Processed %d frames.\n" , frame_count ) ;
 if ( vpx_codec_destroy ( & codec ) ) die_codec ( & codec , "Failed to destroy codec." ) ;
 return stats ;
 }
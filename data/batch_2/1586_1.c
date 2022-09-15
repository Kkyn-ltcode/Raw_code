static void pass1 ( vpx_image_t * raw , FILE * infile , const char * outfile_name , const VpxInterface * encoder , const vpx_codec_enc_cfg_t * cfg ) {
 VpxVideoInfo info = {
 encoder -> fourcc , cfg -> g_w , cfg -> g_h , {
 cfg -> g_timebase . num , cfg -> g_timebase . den }
 }
 ;
 VpxVideoWriter * writer = NULL ;
 vpx_codec_ctx_t codec ;
 int frame_count = 0 ;
 writer = vpx_video_writer_open ( outfile_name , kContainerIVF , & info ) ;
 if ( ! writer ) die ( "Failed to open %s for writing" , outfile_name ) ;
 if ( vpx_codec_enc_init ( & codec , encoder -> codec_interface ( ) , cfg , 0 ) ) die_codec ( & codec , "Failed to initialize encoder" ) ;
 while ( vpx_img_read ( raw , infile ) ) {
 ++ frame_count ;
 encode_frame ( & codec , raw , frame_count , 1 , 0 , VPX_DL_BEST_QUALITY , writer ) ;
 }
 while ( encode_frame ( & codec , NULL , - 1 , 1 , 0 , VPX_DL_BEST_QUALITY , writer ) ) {
 }
 printf ( "\n" ) ;
 if ( vpx_codec_destroy ( & codec ) ) die_codec ( & codec , "Failed to destroy codec." ) ;
 vpx_video_writer_close ( writer ) ;
 printf ( "Pass 1 complete. Processed %d frames.\n" , frame_count ) ;
 }
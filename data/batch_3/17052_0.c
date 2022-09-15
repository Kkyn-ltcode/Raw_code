static void close_output_file ( struct stream_state * stream , unsigned int fourcc ) {
 const struct vpx_codec_enc_cfg * const cfg = & stream -> config . cfg ;
 if ( cfg -> g_pass == VPX_RC_FIRST_PASS ) return ;
 # if CONFIG_WEBM_IO if ( stream -> config . write_webm ) {
 write_webm_file_footer ( & stream -> ebml ) ;
 }
 # endif if ( ! stream -> config . write_webm ) {
 if ( ! fseek ( stream -> file , 0 , SEEK_SET ) ) ivf_write_file_header ( stream -> file , & stream -> config . cfg , fourcc , stream -> frames_out ) ;
 }
 fclose ( stream -> file ) ;
 }
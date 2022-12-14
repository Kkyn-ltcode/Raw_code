static int idcin_decode_frame ( AVCodecContext * avctx , void * data , int * got_frame , AVPacket * avpkt ) {
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 IdcinContext * s = avctx -> priv_data ;
 const uint8_t * pal = av_packet_get_side_data ( avpkt , AV_PKT_DATA_PALETTE , NULL ) ;
 AVFrame * frame = data ;
 int ret ;
 s -> buf = buf ;
 s -> size = buf_size ;
 if ( ( ret = ff_get_buffer ( avctx , frame , 0 ) ) < 0 ) {
 av_log ( avctx , AV_LOG_ERROR , " id CIN Video: get_buffer() failed\n" ) ;
 return ret ;
 }
 idcin_decode_vlcs ( s , frame ) ;
 if ( pal ) {
 frame -> palette_has_changed = 1 ;
 memcpy ( s -> pal , pal , AVPALETTE_SIZE ) ;
 }
 memcpy ( frame -> data [ 1 ] , s -> pal , AVPALETTE_SIZE ) ;
 * got_frame = 1 ;
 return buf_size ;
 }
static int msrle_decode_frame ( AVCodecContext * avctx , void * data , int * got_frame , AVPacket * avpkt ) {
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 MsrleContext * s = avctx -> priv_data ;
 int istride = FFALIGN ( avctx -> width * avctx -> bits_per_coded_sample , 32 ) / 8 ;
 int ret ;
 s -> buf = buf ;
 s -> size = buf_size ;
 s -> frame . reference = 1 ;
 s -> frame . buffer_hints = FF_BUFFER_HINTS_VALID | FF_BUFFER_HINTS_PRESERVE | FF_BUFFER_HINTS_REUSABLE ;
 if ( ( ret = avctx -> reget_buffer ( avctx , & s -> frame ) ) < 0 ) {
 av_log ( avctx , AV_LOG_ERROR , "reget_buffer() failed\n" ) ;
 return ret ;
 }
 if ( avctx -> bits_per_coded_sample <= 8 ) {
 const uint8_t * pal = av_packet_get_side_data ( avpkt , AV_PKT_DATA_PALETTE , NULL ) ;
 if ( pal ) {
 s -> frame . palette_has_changed = 1 ;
 memcpy ( s -> pal , pal , AVPALETTE_SIZE ) ;
 }
 memcpy ( s -> frame . data [ 1 ] , s -> pal , AVPALETTE_SIZE ) ;
 }
 if ( avctx -> height * istride == avpkt -> size ) {
 int linesize = avctx -> width * avctx -> bits_per_coded_sample / 8 ;
 uint8_t * ptr = s -> frame . data [ 0 ] ;
 uint8_t * buf = avpkt -> data + ( avctx -> height - 1 ) * istride ;
 int i , j ;
 for ( i = 0 ;
 i < avctx -> height ;
 i ++ ) {
 if ( avctx -> bits_per_coded_sample == 4 ) {
 for ( j = 0 ;
 j < avctx -> width - 1 ;
 j += 2 ) {
 ptr [ j + 0 ] = buf [ j >> 1 ] >> 4 ;
 ptr [ j + 1 ] = buf [ j >> 1 ] & 0xF ;
 }
 if ( avctx -> width & 1 ) ptr [ j + 0 ] = buf [ j >> 1 ] >> 4 ;
 }
 else {
 memcpy ( ptr , buf , linesize ) ;
 }
 buf -= istride ;
 ptr += s -> frame . linesize [ 0 ] ;
 }
 }
 else {
 bytestream2_init ( & s -> gb , buf , buf_size ) ;
 ff_msrle_decode ( avctx , ( AVPicture * ) & s -> frame , avctx -> bits_per_coded_sample , & s -> gb ) ;
 }
 * got_frame = 1 ;
 * ( AVFrame * ) data = s -> frame ;
 return buf_size ;
 }
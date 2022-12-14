static int decode ( AVCodecContext * avctx , void * data , int * data_size , AVPacket * avpkt ) {
 PGSSubContext * ctx = avctx -> priv_data ;
 const uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 AVSubtitle * sub = data ;
 const uint8_t * buf_end ;
 uint8_t segment_type ;
 int segment_length ;
 int i ;
 av_dlog ( avctx , "PGS sub packet:\n" ) ;
 for ( i = 0 ;
 i < buf_size ;
 i ++ ) {
 av_dlog ( avctx , "%02x " , buf [ i ] ) ;
 if ( i % 16 == 15 ) av_dlog ( avctx , "\n" ) ;
 }
 if ( i & 15 ) av_dlog ( avctx , "\n" ) ;
 * data_size = 0 ;
 if ( buf_size < 3 ) return - 1 ;
 buf_end = buf + buf_size ;
 while ( buf < buf_end ) {
 segment_type = bytestream_get_byte ( & buf ) ;
 segment_length = bytestream_get_be16 ( & buf ) ;
 av_dlog ( avctx , "Segment Length %d, Segment Type %x\n" , segment_length , segment_type ) ;
 if ( segment_type != DISPLAY_SEGMENT && segment_length > buf_end - buf ) break ;
 switch ( segment_type ) {
 case PALETTE_SEGMENT : parse_palette_segment ( avctx , buf , segment_length ) ;
 break ;
 case PICTURE_SEGMENT : parse_picture_segment ( avctx , buf , segment_length ) ;
 break ;
 case PRESENTATION_SEGMENT : parse_presentation_segment ( avctx , buf , segment_length ) ;
 ctx -> pts = sub -> pts ;
 break ;
 case WINDOW_SEGMENT : break ;
 case DISPLAY_SEGMENT : * data_size = display_end_segment ( avctx , data , buf , segment_length ) ;
 break ;
 default : av_log ( avctx , AV_LOG_ERROR , "Unknown subtitle segment type 0x%x, length %d\n" , segment_type , segment_length ) ;
 break ;
 }
 buf += segment_length ;
 }
 return buf_size ;
 }
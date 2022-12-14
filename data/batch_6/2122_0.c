static int libspeex_decode_frame ( AVCodecContext * avctx , void * data , int * got_frame_ptr , AVPacket * avpkt ) {
 uint8_t * buf = avpkt -> data ;
 int buf_size = avpkt -> size ;
 LibSpeexContext * s = avctx -> priv_data ;
 AVFrame * frame = data ;
 int16_t * output ;
 int ret , consumed = 0 ;
 frame -> nb_samples = s -> frame_size ;
 if ( ( ret = ff_get_buffer ( avctx , frame , 0 ) ) < 0 ) {
 av_log ( avctx , AV_LOG_ERROR , "get_buffer() failed\n" ) ;
 return ret ;
 }
 output = ( int16_t * ) frame -> data [ 0 ] ;
 if ( speex_bits_remaining ( & s -> bits ) < 5 || speex_bits_peek_unsigned ( & s -> bits , 5 ) == 0x1F ) {
 if ( ! buf || ! buf_size ) {
 * got_frame_ptr = 0 ;
 return buf_size ;
 }
 speex_bits_read_from ( & s -> bits , buf , buf_size ) ;
 consumed = buf_size ;
 }
 ret = speex_decode_int ( s -> dec_state , & s -> bits , output ) ;
 if ( ret <= - 2 ) {
 av_log ( avctx , AV_LOG_ERROR , "Error decoding Speex frame.\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 if ( avctx -> channels == 2 ) speex_decode_stereo_int ( output , s -> frame_size , & s -> stereo ) ;
 * got_frame_ptr = 1 ;
 return consumed ;
 }
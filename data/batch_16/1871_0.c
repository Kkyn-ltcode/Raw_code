static int decode_p_frame ( FourXContext * f , AVFrame * frame , const uint8_t * buf , int length ) {
 int x , y ;
 const int width = f -> avctx -> width ;
 const int height = f -> avctx -> height ;
 uint16_t * src = ( uint16_t * ) f -> last_picture -> data [ 0 ] ;
 uint16_t * dst = ( uint16_t * ) frame -> data [ 0 ] ;
 const int stride = frame -> linesize [ 0 ] >> 1 ;
 unsigned int bitstream_size , bytestream_size , wordstream_size , extra , bytestream_offset , wordstream_offset ;
 if ( f -> version > 1 ) {
 extra = 20 ;
 bitstream_size = AV_RL32 ( buf + 8 ) ;
 wordstream_size = AV_RL32 ( buf + 12 ) ;
 bytestream_size = AV_RL32 ( buf + 16 ) ;
 }
 else {
 extra = 0 ;
 bitstream_size = AV_RL16 ( buf - 4 ) ;
 wordstream_size = AV_RL16 ( buf - 2 ) ;
 bytestream_size = FFMAX ( length - bitstream_size - wordstream_size , 0 ) ;
 }
 if ( bitstream_size + bytestream_size + wordstream_size + extra != length || bitstream_size > ( 1 << 26 ) || bytestream_size > ( 1 << 26 ) || wordstream_size > ( 1 << 26 ) ) {
 av_log ( f -> avctx , AV_LOG_ERROR , "lengths %d %d %d %d\n" , bitstream_size , bytestream_size , wordstream_size , bitstream_size + bytestream_size + wordstream_size - length ) ;
 return AVERROR_INVALIDDATA ;
 }
 av_fast_malloc ( & f -> bitstream_buffer , & f -> bitstream_buffer_size , bitstream_size + FF_INPUT_BUFFER_PADDING_SIZE ) ;
 if ( ! f -> bitstream_buffer ) return AVERROR ( ENOMEM ) ;
 f -> dsp . bswap_buf ( f -> bitstream_buffer , ( const uint32_t * ) ( buf + extra ) , bitstream_size / 4 ) ;
 memset ( ( uint8_t * ) f -> bitstream_buffer + bitstream_size , 0 , FF_INPUT_BUFFER_PADDING_SIZE ) ;
 init_get_bits ( & f -> gb , f -> bitstream_buffer , 8 * bitstream_size ) ;
 wordstream_offset = extra + bitstream_size ;
 bytestream_offset = extra + bitstream_size + wordstream_size ;
 bytestream2_init ( & f -> g2 , buf + wordstream_offset , length - wordstream_offset ) ;
 bytestream2_init ( & f -> g , buf + bytestream_offset , length - bytestream_offset ) ;
 init_mv ( f , frame -> linesize [ 0 ] ) ;
 for ( y = 0 ;
 y < height ;
 y += 8 ) {
 for ( x = 0 ;
 x < width ;
 x += 8 ) decode_p_block ( f , dst + x , src + x , 3 , 3 , stride ) ;
 src += 8 * stride ;
 dst += 8 * stride ;
 }
 return 0 ;
 }
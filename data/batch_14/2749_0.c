static int ipvideo_decode_block_opcode_0x9 ( IpvideoContext * s , AVFrame * frame ) {
 int x , y ;
 unsigned char P [ 4 ] ;
 bytestream2_get_buffer ( & s -> stream_ptr , P , 4 ) ;
 if ( P [ 0 ] <= P [ 1 ] ) {
 if ( P [ 2 ] <= P [ 3 ] ) {
 for ( y = 0 ;
 y < 8 ;
 y ++ ) {
 int flags = bytestream2_get_le16 ( & s -> stream_ptr ) ;
 for ( x = 0 ;
 x < 8 ;
 x ++ , flags >>= 2 ) * s -> pixel_ptr ++ = P [ flags & 0x03 ] ;
 s -> pixel_ptr += s -> line_inc ;
 }
 }
 else {
 uint32_t flags ;
 flags = bytestream2_get_le32 ( & s -> stream_ptr ) ;
 for ( y = 0 ;
 y < 8 ;
 y += 2 ) {
 for ( x = 0 ;
 x < 8 ;
 x += 2 , flags >>= 2 ) {
 s -> pixel_ptr [ x ] = s -> pixel_ptr [ x + 1 ] = s -> pixel_ptr [ x + s -> stride ] = s -> pixel_ptr [ x + 1 + s -> stride ] = P [ flags & 0x03 ] ;
 }
 s -> pixel_ptr += s -> stride * 2 ;
 }
 }
 }
 else {
 uint64_t flags ;
 flags = bytestream2_get_le64 ( & s -> stream_ptr ) ;
 if ( P [ 2 ] <= P [ 3 ] ) {
 for ( y = 0 ;
 y < 8 ;
 y ++ ) {
 for ( x = 0 ;
 x < 8 ;
 x += 2 , flags >>= 2 ) {
 s -> pixel_ptr [ x ] = s -> pixel_ptr [ x + 1 ] = P [ flags & 0x03 ] ;
 }
 s -> pixel_ptr += s -> stride ;
 }
 }
 else {
 for ( y = 0 ;
 y < 8 ;
 y += 2 ) {
 for ( x = 0 ;
 x < 8 ;
 x ++ , flags >>= 2 ) {
 s -> pixel_ptr [ x ] = s -> pixel_ptr [ x + s -> stride ] = P [ flags & 0x03 ] ;
 }
 s -> pixel_ptr += s -> stride * 2 ;
 }
 }
 }
 return 0 ;
 }
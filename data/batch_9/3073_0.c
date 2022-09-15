static int read_uncompressed_sgi ( unsigned char * out_buf , uint8_t * out_end , SgiState * s ) {
 int x , y , z ;
 unsigned int offset = s -> height * s -> width * s -> bytes_per_channel ;
 GetByteContext gp [ 4 ] ;
 if ( offset * s -> depth > bytestream2_get_bytes_left ( & s -> g ) ) return AVERROR_INVALIDDATA ;
 for ( z = 0 ;
 z < s -> depth ;
 z ++ ) {
 gp [ z ] = s -> g ;
 bytestream2_skip ( & gp [ z ] , z * offset ) ;
 }
 for ( y = s -> height - 1 ;
 y >= 0 ;
 y -- ) {
 out_end = out_buf + ( y * s -> linesize ) ;
 if ( s -> bytes_per_channel == 1 ) {
 for ( x = s -> width ;
 x > 0 ;
 x -- ) for ( z = 0 ;
 z < s -> depth ;
 z ++ ) * out_end ++ = bytestream2_get_byteu ( & gp [ z ] ) ;
 }
 else {
 uint16_t * out16 = ( uint16_t * ) out_end ;
 for ( x = s -> width ;
 x > 0 ;
 x -- ) for ( z = 0 ;
 z < s -> depth ;
 z ++ ) * out16 ++ = bytestream2_get_ne16u ( & gp [ z ] ) ;
 }
 }
 return 0 ;
 }
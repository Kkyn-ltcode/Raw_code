static int ir2_decode_plane ( Ir2Context * ctx , int width , int height , uint8_t * dst , int stride , const uint8_t * table ) {
 int i ;
 int j ;
 int out = 0 ;
 int c ;
 int t ;
 if ( width & 1 ) return AVERROR_INVALIDDATA ;
 while ( out < width ) {
 c = ir2_get_code ( & ctx -> gb ) ;
 if ( c >= 0x80 ) {
 c -= 0x7F ;
 if ( out + c * 2 > width ) return AVERROR_INVALIDDATA ;
 for ( i = 0 ;
 i < c * 2 ;
 i ++ ) dst [ out ++ ] = 0x80 ;
 }
 else {
 dst [ out ++ ] = table [ c * 2 ] ;
 dst [ out ++ ] = table [ ( c * 2 ) + 1 ] ;
 }
 }
 dst += stride ;
 for ( j = 1 ;
 j < height ;
 j ++ ) {
 out = 0 ;
 while ( out < width ) {
 c = ir2_get_code ( & ctx -> gb ) ;
 if ( c >= 0x80 ) {
 c -= 0x7F ;
 if ( out + c * 2 > width ) return AVERROR_INVALIDDATA ;
 for ( i = 0 ;
 i < c * 2 ;
 i ++ ) {
 dst [ out ] = dst [ out - stride ] ;
 out ++ ;
 }
 }
 else {
 t = dst [ out - stride ] + ( table [ c * 2 ] - 128 ) ;
 t = av_clip_uint8 ( t ) ;
 dst [ out ] = t ;
 out ++ ;
 t = dst [ out - stride ] + ( table [ ( c * 2 ) + 1 ] - 128 ) ;
 t = av_clip_uint8 ( t ) ;
 dst [ out ] = t ;
 out ++ ;
 }
 }
 dst += stride ;
 }
 return 0 ;
 }
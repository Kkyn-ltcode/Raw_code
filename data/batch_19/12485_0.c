static void HCLComposite ( const MagickRealType hue , const MagickRealType chroma , const MagickRealType luma , MagickRealType * red , MagickRealType * green , MagickRealType * blue ) {
 MagickRealType b , c , g , h , m , r , x ;
 assert ( red != ( MagickRealType * ) NULL ) ;
 assert ( green != ( MagickRealType * ) NULL ) ;
 assert ( blue != ( MagickRealType * ) NULL ) ;
 h = 6.0 * hue ;
 c = chroma ;
 x = c * ( 1.0 - fabs ( fmod ( h , 2.0 ) - 1.0 ) ) ;
 r = 0.0 ;
 g = 0.0 ;
 b = 0.0 ;
 if ( ( 0.0 <= h ) && ( h < 1.0 ) ) {
 r = c ;
 g = x ;
 }
 else if ( ( 1.0 <= h ) && ( h < 2.0 ) ) {
 r = x ;
 g = c ;
 }
 else if ( ( 2.0 <= h ) && ( h < 3.0 ) ) {
 g = c ;
 b = x ;
 }
 else if ( ( 3.0 <= h ) && ( h < 4.0 ) ) {
 g = x ;
 b = c ;
 }
 else if ( ( 4.0 <= h ) && ( h < 5.0 ) ) {
 r = x ;
 b = c ;
 }
 else if ( ( 5.0 <= h ) && ( h < 6.0 ) ) {
 r = c ;
 b = x ;
 }
 m = luma - ( 0.298839 * r + 0.586811 * g + 0.114350 * b ) ;
 * red = QuantumRange * ( r + m ) ;
 * green = QuantumRange * ( g + m ) ;
 * blue = QuantumRange * ( b + m ) ;
 }
void TIFFCvtNativeToIEEEFloat ( TIFF * tif , u_int n , float * f ) {
 float_t * fp = ( float_t * ) f ;
 while ( n -- > 0 ) {
 NATIVE2IEEEFLOAT ( fp ) ;
 fp ++ ;
 }
 }
const char * cpio_i64toa ( int64_t n0 ) {
 static char buff [ 22 ] ;
 int64_t n = n0 < 0 ? - n0 : n0 ;
 char * p = buff + sizeof ( buff ) ;
 * -- p = '\0' ;
 do {
 * -- p = '0' + ( int ) ( n % 10 ) ;
 n /= 10 ;
 }
 while ( n > 0 ) ;
 if ( n0 < 0 ) * -- p = '-' ;
 return p ;
 }
size_t check_mul_overflow ( size_t a , size_t b , size_t * res ) {
 size_t tmp = a * b ;
 if ( a != 0 && tmp / a != b ) return 1 ;
 * res = tmp ;
 return 0 ;
 }
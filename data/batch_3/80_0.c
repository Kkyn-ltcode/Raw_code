static int jbig2_find_changing_element ( const byte * line , uint32_t x , uint32_t w ) {
 int a , b ;
 if ( line == 0 ) return ( int ) w ;
 if ( x == MINUS1 ) {
 a = 0 ;
 x = 0 ;
 }
 else {
 a = getbit ( line , x ) ;
 x ++ ;
 }
 while ( x < w ) {
 b = getbit ( line , x ) ;
 if ( a != b ) break ;
 x ++ ;
 }
 return x ;
 }
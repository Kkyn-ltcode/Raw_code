static Int decGetDigits ( Unit * uar , Int len ) {
 Unit * up = uar + ( len - 1 ) ;
 Int digits = ( len - 1 ) * DECDPUN + 1 ;
 # if DECDPUN > 4 uInt const * pow ;
 # endif # if DECCHECK if ( len < 1 ) printf ( "decGetDigits called with len<1 [%ld]\n" , ( LI ) len ) ;
 # endif for ( ;
 up >= uar ;
 up -- ) {
 if ( * up == 0 ) {
 if ( digits == 1 ) break ;
 digits -= DECDPUN ;
 continue ;
 }
 # if DECDPUN > 1 if ( * up < 10 ) break ;
 digits ++ ;
 # if DECDPUN > 2 if ( * up < 100 ) break ;
 digits ++ ;
 # if DECDPUN > 3 if ( * up < 1000 ) break ;
 digits ++ ;
 # if DECDPUN > 4 for ( pow = & powers [ 4 ] ;
 * up >= * pow ;
 pow ++ ) digits ++ ;
 # endif # endif # endif # endif break ;
 }
 return digits ;
 }
static Int decShiftToLeast ( Unit * uar , Int units , Int shift ) {
 Unit * target , * up ;
 Int cut , count ;
 Int quot , rem ;
 if ( shift == 0 ) return units ;
 if ( shift == units * DECDPUN ) {
 * uar = 0 ;
 return 1 ;
 }
 target = uar ;
 cut = MSUDIGITS ( shift ) ;
 if ( cut == DECDPUN ) {
 up = uar + D2U ( shift ) ;
 for ( ;
 up < uar + units ;
 target ++ , up ++ ) * target = * up ;
 return target - uar ;
 }
 up = uar + D2U ( shift - cut ) ;
 count = units * DECDPUN - shift ;
 # if DECDPUN <= 4 quot = QUOT10 ( * up , cut ) ;
 # else quot = * up / powers [ cut ] ;
 # endif for ( ;
 ;
 target ++ ) {
 * target = ( Unit ) quot ;
 count -= ( DECDPUN - cut ) ;
 if ( count <= 0 ) break ;
 up ++ ;
 quot = * up ;
 # if DECDPUN <= 4 quot = QUOT10 ( quot , cut ) ;
 rem = * up - quot * powers [ cut ] ;
 # else rem = quot % powers [ cut ] ;
 quot = quot / powers [ cut ] ;
 # endif * target = ( Unit ) ( * target + rem * powers [ DECDPUN - cut ] ) ;
 count -= cut ;
 if ( count <= 0 ) break ;
 }
 return target - uar + 1 ;
 }
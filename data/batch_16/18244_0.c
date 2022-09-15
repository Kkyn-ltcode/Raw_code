static Int decGetInt ( const decNumber * dn ) {
 Int theInt ;
 const Unit * up ;
 Int got ;
 Int ilength = dn -> digits + dn -> exponent ;
 Flag neg = decNumberIsNegative ( dn ) ;
 # if DEC_MAX_EMAX > 999999999 # error GetInt may need updating [ for Emax ] # endif # if DEC_MIN_EMIN < - 999999999 # error GetInt may need updating [ for Emin ] # endif if ( ISZERO ( dn ) ) return 0 ;
 up = dn -> lsu ;
 theInt = 0 ;
 if ( dn -> exponent >= 0 ) {
 got = dn -> exponent ;
 }
 else {
 Int count = - dn -> exponent ;
 for ( ;
 count >= DECDPUN ;
 up ++ ) {
 if ( * up != 0 ) return BADINT ;
 count -= DECDPUN ;
 }
 if ( count == 0 ) got = 0 ;
 else {
 Int rem ;
 # if DECDPUN <= 4 theInt = QUOT10 ( * up , count ) ;
 rem = * up - theInt * powers [ count ] ;
 # else rem = * up % powers [ count ] ;
 theInt = * up / powers [ count ] ;
 # endif if ( rem != 0 ) return BADINT ;
 got = DECDPUN - count ;
 up ++ ;
 }
 }
 if ( got == 0 ) {
 theInt = * up ;
 got += DECDPUN ;
 up ++ ;
 }
 if ( ilength < 11 ) {
 Int save = theInt ;
 for ( ;
 got < ilength ;
 up ++ ) {
 theInt += * up * powers [ got ] ;
 got += DECDPUN ;
 }
 if ( ilength == 10 ) {
 if ( theInt / ( Int ) powers [ got - DECDPUN ] != ( Int ) * ( up - 1 ) ) ilength = 11 ;
 else if ( neg && theInt > 1999999997 ) ilength = 11 ;
 else if ( ! neg && theInt > 999999999 ) ilength = 11 ;
 if ( ilength == 11 ) theInt = save ;
 }
 }
 if ( ilength > 10 ) {
 if ( theInt & 1 ) return BIGODD ;
 return BIGEVEN ;
 }
 if ( neg ) theInt = - theInt ;
 return theInt ;
 }
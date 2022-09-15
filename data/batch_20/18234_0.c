static decNumber * decDecap ( decNumber * dn , Int drop ) {
 Unit * msu ;
 Int cut ;
 if ( drop >= dn -> digits ) {
 # if DECCHECK if ( drop > dn -> digits ) printf ( "decDecap called with drop>digits [%ld>%ld]\n" , ( LI ) drop , ( LI ) dn -> digits ) ;
 # endif dn -> lsu [ 0 ] = 0 ;
 dn -> digits = 1 ;
 return dn ;
 }
 msu = dn -> lsu + D2U ( dn -> digits - drop ) - 1 ;
 cut = MSUDIGITS ( dn -> digits - drop ) ;
 if ( cut != DECDPUN ) * msu %= powers [ cut ] ;
 dn -> digits = decGetDigits ( dn -> lsu , msu - dn -> lsu + 1 ) ;
 return dn ;
 }
static decNumber * decTrim ( decNumber * dn , decContext * set , Flag all , Flag noclamp , Int * dropped ) {
 Int d , exp ;
 uInt cut ;
 Unit * up ;
 # if DECCHECK if ( decCheckOperands ( dn , DECUNUSED , DECUNUSED , DECUNCONT ) ) return dn ;
 # endif * dropped = 0 ;
 if ( ( dn -> bits & DECSPECIAL ) || ( * dn -> lsu & 0x01 ) ) return dn ;
 if ( ISZERO ( dn ) ) {
 dn -> exponent = 0 ;
 return dn ;
 }
 exp = dn -> exponent ;
 cut = 1 ;
 up = dn -> lsu ;
 for ( d = 0 ;
 d < dn -> digits - 1 ;
 d ++ ) {
 # if DECDPUN <= 4 uInt quot = QUOT10 ( * up , cut ) ;
 if ( ( * up - quot * powers [ cut ] ) != 0 ) break ;
 # else if ( * up % powers [ cut ] != 0 ) break ;
 # endif if ( ! all ) {
 if ( exp <= 0 ) {
 if ( exp == 0 ) break ;
 exp ++ ;
 }
 }
 cut ++ ;
 if ( cut > DECDPUN ) {
 up ++ ;
 cut = 1 ;
 }
 }
 if ( d == 0 ) return dn ;
 if ( set -> clamp && ! noclamp ) {
 Int maxd = set -> emax - set -> digits + 1 - dn -> exponent ;
 if ( maxd <= 0 ) return dn ;
 if ( d > maxd ) d = maxd ;
 }
 decShiftToLeast ( dn -> lsu , D2U ( dn -> digits ) , d ) ;
 dn -> exponent += d ;
 dn -> digits -= d ;
 * dropped = d ;
 return dn ;
 }
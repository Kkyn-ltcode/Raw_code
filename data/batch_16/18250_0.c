static Int decUnitAddSub ( const Unit * a , Int alength , const Unit * b , Int blength , Int bshift , Unit * c , Int m ) {
 const Unit * alsu = a ;
 Unit * clsu = c ;
 Unit * minC ;
 Unit * maxC ;
 eInt carry = 0 ;
 Int add ;
 # if DECDPUN <= 4 Int est ;
 # endif # if DECTRACE if ( alength < 1 || blength < 1 ) printf ( "decUnitAddSub: alen blen m %ld %ld [%ld]\n" , alength , blength , m ) ;
 # endif maxC = c + alength ;
 minC = c + blength ;
 if ( bshift != 0 ) {
 minC += bshift ;
 if ( a == c && bshift <= alength ) {
 c += bshift ;
 a += bshift ;
 }
 else for ( ;
 c < clsu + bshift ;
 a ++ , c ++ ) {
 if ( a < alsu + alength ) * c = * a ;
 else * c = 0 ;
 }
 }
 if ( minC > maxC ) {
 Unit * hold = minC ;
 minC = maxC ;
 maxC = hold ;
 }
 for ( ;
 c < minC ;
 c ++ ) {
 carry += * a ;
 a ++ ;
 carry += ( ( eInt ) * b ) * m ;
 b ++ ;
 if ( ( ueInt ) carry <= DECDPUNMAX ) {
 * c = ( Unit ) carry ;
 carry = 0 ;
 continue ;
 }
 # if DECDPUN == 4 if ( carry >= 0 ) {
 est = ( ( ( ueInt ) carry >> 11 ) * 53687 ) >> 18 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 est = ( ( ( ueInt ) carry >> 11 ) * 53687 ) >> 18 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est - ( DECDPUNMAX + 1 ) ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 # elif DECDPUN == 3 if ( carry >= 0 ) {
 est = ( ( ( ueInt ) carry >> 3 ) * 16777 ) >> 21 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 est = ( ( ( ueInt ) carry >> 3 ) * 16777 ) >> 21 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est - ( DECDPUNMAX + 1 ) ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 # elif DECDPUN <= 2 if ( carry >= 0 ) {
 est = QUOT10 ( carry , DECDPUN ) ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 est = QUOT10 ( carry , DECDPUN ) ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est - ( DECDPUNMAX + 1 ) ;
 # else if ( ( ueInt ) carry < ( DECDPUNMAX + 1 ) * 2 ) {
 * c = ( Unit ) ( carry - ( DECDPUNMAX + 1 ) ) ;
 carry = 1 ;
 continue ;
 }
 if ( carry >= 0 ) {
 * c = ( Unit ) ( carry % ( DECDPUNMAX + 1 ) ) ;
 carry = carry / ( DECDPUNMAX + 1 ) ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 * c = ( Unit ) ( carry % ( DECDPUNMAX + 1 ) ) ;
 carry = carry / ( DECDPUNMAX + 1 ) - ( DECDPUNMAX + 1 ) ;
 # endif }
 if ( c < maxC ) for ( ;
 c < maxC ;
 c ++ ) {
 if ( a < alsu + alength ) {
 carry += * a ;
 a ++ ;
 }
 else {
 carry += ( ( eInt ) * b ) * m ;
 b ++ ;
 }
 if ( ( ueInt ) carry <= DECDPUNMAX ) {
 * c = ( Unit ) carry ;
 carry = 0 ;
 continue ;
 }
 # if DECDPUN == 4 if ( carry >= 0 ) {
 est = ( ( ( ueInt ) carry >> 11 ) * 53687 ) >> 18 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 est = ( ( ( ueInt ) carry >> 11 ) * 53687 ) >> 18 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est - ( DECDPUNMAX + 1 ) ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 # elif DECDPUN == 3 if ( carry >= 0 ) {
 est = ( ( ( ueInt ) carry >> 3 ) * 16777 ) >> 21 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 est = ( ( ( ueInt ) carry >> 3 ) * 16777 ) >> 21 ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est - ( DECDPUNMAX + 1 ) ;
 if ( * c < DECDPUNMAX + 1 ) continue ;
 carry ++ ;
 * c -= DECDPUNMAX + 1 ;
 # elif DECDPUN <= 2 if ( carry >= 0 ) {
 est = QUOT10 ( carry , DECDPUN ) ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 est = QUOT10 ( carry , DECDPUN ) ;
 * c = ( Unit ) ( carry - est * ( DECDPUNMAX + 1 ) ) ;
 carry = est - ( DECDPUNMAX + 1 ) ;
 # else if ( ( ueInt ) carry < ( DECDPUNMAX + 1 ) * 2 ) {
 * c = ( Unit ) ( carry - ( DECDPUNMAX + 1 ) ) ;
 carry = 1 ;
 continue ;
 }
 if ( carry >= 0 ) {
 * c = ( Unit ) ( carry % ( DECDPUNMAX + 1 ) ) ;
 carry = carry / ( DECDPUNMAX + 1 ) ;
 continue ;
 }
 carry = carry + ( eInt ) ( DECDPUNMAX + 1 ) * ( DECDPUNMAX + 1 ) ;
 * c = ( Unit ) ( carry % ( DECDPUNMAX + 1 ) ) ;
 carry = carry / ( DECDPUNMAX + 1 ) - ( DECDPUNMAX + 1 ) ;
 # endif }
 if ( carry == 0 ) return c - clsu ;
 if ( carry > 0 ) {
 * c = ( Unit ) carry ;
 c ++ ;
 return c - clsu ;
 }
 add = 1 ;
 for ( c = clsu ;
 c < maxC ;
 c ++ ) {
 add = DECDPUNMAX + add - * c ;
 if ( add <= DECDPUNMAX ) {
 * c = ( Unit ) add ;
 add = 0 ;
 }
 else {
 * c = 0 ;
 add = 1 ;
 }
 }
 # if DECTRACE printf ( "UAS borrow: add %ld, carry %ld\n" , add , carry ) ;
 # endif if ( ( add - carry - 1 ) != 0 ) {
 * c = ( Unit ) ( add - carry - 1 ) ;
 c ++ ;
 }
 return clsu - c ;
 }
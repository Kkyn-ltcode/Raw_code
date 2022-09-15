decNumber * decLnOp ( decNumber * res , const decNumber * rhs , decContext * set , uInt * status ) {
 uInt ignore = 0 ;
 uInt needbytes ;
 Int residue ;
 Int r ;
 Int p ;
 Int pp ;
 Int t ;
 decNumber bufa [ D2N ( DECBUFFER + 12 ) ] ;
 decNumber * allocbufa = NULL ;
 decNumber * a = bufa ;
 decNumber bufb [ D2N ( DECBUFFER * 2 + 2 ) ] ;
 decNumber * allocbufb = NULL ;
 decNumber * b = bufb ;
 decNumber numone ;
 decNumber cmp ;
 decContext aset , bset ;
 # if DECCHECK Int iterations = 0 ;
 if ( decCheckOperands ( res , DECUNUSED , rhs , set ) ) return res ;
 # endif do {
 if ( SPECIALARG ) {
 if ( decNumberIsInfinite ( rhs ) ) {
 if ( decNumberIsNegative ( rhs ) ) * status |= DEC_Invalid_operation ;
 else uprv_decNumberCopy ( res , rhs ) ;
 }
 else decNaNs ( res , rhs , NULL , set , status ) ;
 break ;
 }
 if ( ISZERO ( rhs ) ) {
 uprv_decNumberZero ( res ) ;
 res -> bits = DECINF | DECNEG ;
 break ;
 }
 if ( decNumberIsNegative ( rhs ) ) {
 * status |= DEC_Invalid_operation ;
 break ;
 }
 if ( rhs -> exponent == 0 && set -> digits <= 40 ) {
 # if DECDPUN == 1 if ( rhs -> lsu [ 0 ] == 0 && rhs -> lsu [ 1 ] == 1 && rhs -> digits == 2 ) {
 # else if ( rhs -> lsu [ 0 ] == 10 && rhs -> digits == 2 ) {
 # endif aset = * set ;
 aset . round = DEC_ROUND_HALF_EVEN ;
 # define LN10 "2.302585092994045684017991454684364207601" uprv_decNumberFromString ( res , LN10 , & aset ) ;
 * status |= ( DEC_Inexact | DEC_Rounded ) ;
 break ;
 }
 if ( rhs -> lsu [ 0 ] == 2 && rhs -> digits == 1 ) {
 aset = * set ;
 aset . round = DEC_ROUND_HALF_EVEN ;
 # define LN2 "0.6931471805599453094172321214581765680755" uprv_decNumberFromString ( res , LN2 , & aset ) ;
 * status |= ( DEC_Inexact | DEC_Rounded ) ;
 break ;
 }
 }
 p = MAXI ( rhs -> digits , MAXI ( set -> digits , 7 ) ) + 2 ;
 needbytes = sizeof ( decNumber ) + ( D2U ( MAXI ( p , 16 ) ) - 1 ) * sizeof ( Unit ) ;
 if ( needbytes > sizeof ( bufa ) ) {
 allocbufa = ( decNumber * ) malloc ( needbytes ) ;
 if ( allocbufa == NULL ) {
 * status |= DEC_Insufficient_storage ;
 break ;
 }
 a = allocbufa ;
 }
 pp = p + rhs -> digits ;
 needbytes = sizeof ( decNumber ) + ( D2U ( MAXI ( pp , 16 ) ) - 1 ) * sizeof ( Unit ) ;
 if ( needbytes > sizeof ( bufb ) ) {
 allocbufb = ( decNumber * ) malloc ( needbytes ) ;
 if ( allocbufb == NULL ) {
 * status |= DEC_Insufficient_storage ;
 break ;
 }
 b = allocbufb ;
 }
 uprv_decContextDefault ( & aset , DEC_INIT_DECIMAL64 ) ;
 r = rhs -> exponent + rhs -> digits ;
 uprv_decNumberFromInt32 ( a , r ) ;
 uprv_decNumberFromInt32 ( b , 2302585 ) ;
 b -> exponent = - 6 ;
 decMultiplyOp ( a , a , b , & aset , & ignore ) ;
 residue = 0 ;
 aset . digits = 2 ;
 aset . round = DEC_ROUND_DOWN ;
 decCopyFit ( b , rhs , & aset , & residue , & ignore ) ;
 b -> exponent = 0 ;
 t = decGetInt ( b ) ;
 if ( t < 10 ) t = X10 ( t ) ;
 t = LNnn [ t - 10 ] ;
 uprv_decNumberFromInt32 ( b , t >> 2 ) ;
 b -> exponent = - ( t & 3 ) - 3 ;
 b -> bits = DECNEG ;
 aset . digits = 16 ;
 aset . round = DEC_ROUND_HALF_EVEN ;
 decAddOp ( a , a , b , & aset , 0 , & ignore ) ;
 uprv_decNumberZero ( & numone ) ;
 * numone . lsu = 1 ;
 aset . emax = set -> emax ;
 aset . emin = set -> emin ;
 aset . clamp = 0 ;
 bset = aset ;
 bset . emax = DEC_MAX_MATH * 2 ;
 bset . emin = - DEC_MAX_MATH * 2 ;
 pp = 9 ;
 aset . digits = pp ;
 bset . digits = pp + rhs -> digits ;
 for ( ;
 ;
 ) {
 # if DECCHECK iterations ++ ;
 if ( iterations > 24 ) break ;
 # endif a -> bits ^= DECNEG ;
 decExpOp ( b , a , & bset , & ignore ) ;
 a -> bits ^= DECNEG ;
 decMultiplyOp ( b , b , rhs , & bset , & ignore ) ;
 decAddOp ( b , b , & numone , & bset , DECNEG , & ignore ) ;
 if ( decNumberIsZero ( b ) || ( a -> digits + a -> exponent ) >= ( b -> digits + b -> exponent + set -> digits + 1 ) ) {
 if ( a -> digits == p ) break ;
 if ( decNumberIsZero ( a ) ) {
 decCompareOp ( & cmp , rhs , & numone , & aset , COMPARE , & ignore ) ;
 if ( cmp . lsu [ 0 ] == 0 ) a -> exponent = 0 ;
 else * status |= ( DEC_Inexact | DEC_Rounded ) ;
 break ;
 }
 if ( decNumberIsZero ( b ) ) b -> exponent = a -> exponent - p ;
 }
 decAddOp ( a , a , b , & aset , 0 , & ignore ) ;
 if ( pp == p ) continue ;
 pp = pp * 2 ;
 if ( pp > p ) pp = p ;
 aset . digits = pp ;
 bset . digits = pp + rhs -> digits ;
 }
 # if DECCHECK if ( iterations > 24 ) printf ( "Ln iterations=%ld, status=%08lx, p=%ld, d=%ld\n" , ( LI ) iterations , ( LI ) * status , ( LI ) p , ( LI ) rhs -> digits ) ;
 # endif residue = 1 ;
 if ( ISZERO ( a ) ) residue = 0 ;
 aset . digits = set -> digits ;
 decCopyFit ( res , a , & aset , & residue , status ) ;
 decFinish ( res , set , & residue , status ) ;
 }
 while ( 0 ) ;
 if ( allocbufa != NULL ) free ( allocbufa ) ;
 if ( allocbufb != NULL ) free ( allocbufb ) ;
 return res ;
 }
static int fmtfp ( char * * sbuffer , char * * buffer , size_t * currlen , size_t * maxlen , LDOUBLE fvalue , int min , int max , int flags ) {
 int signvalue = 0 ;
 LDOUBLE ufvalue ;
 char iconvert [ 20 ] ;
 char fconvert [ 20 ] ;
 int iplace = 0 ;
 int fplace = 0 ;
 int padlen = 0 ;
 int zpadlen = 0 ;
 long intpart ;
 long fracpart ;
 long max10 ;
 if ( max < 0 ) max = 6 ;
 ufvalue = abs_val ( fvalue ) ;
 if ( fvalue < 0 ) signvalue = '-' ;
 else if ( flags & DP_F_PLUS ) signvalue = '+' ;
 else if ( flags & DP_F_SPACE ) signvalue = ' ' ;
 intpart = ( long ) ufvalue ;
 if ( max > 9 ) max = 9 ;
 max10 = roundv ( pow_10 ( max ) ) ;
 fracpart = roundv ( pow_10 ( max ) * ( ufvalue - intpart ) ) ;
 if ( fracpart >= max10 ) {
 intpart ++ ;
 fracpart -= max10 ;
 }
 do {
 iconvert [ iplace ++ ] = "0123456789" [ intpart % 10 ] ;
 intpart = ( intpart / 10 ) ;
 }
 while ( intpart && ( iplace < ( int ) sizeof ( iconvert ) ) ) ;
 if ( iplace == sizeof iconvert ) iplace -- ;
 iconvert [ iplace ] = 0 ;
 do {
 fconvert [ fplace ++ ] = "0123456789" [ fracpart % 10 ] ;
 fracpart = ( fracpart / 10 ) ;
 }
 while ( fplace < max ) ;
 if ( fplace == sizeof fconvert ) fplace -- ;
 fconvert [ fplace ] = 0 ;
 padlen = min - iplace - max - 1 - ( ( signvalue ) ? 1 : 0 ) ;
 zpadlen = max - fplace ;
 if ( zpadlen < 0 ) zpadlen = 0 ;
 if ( padlen < 0 ) padlen = 0 ;
 if ( flags & DP_F_MINUS ) padlen = - padlen ;
 if ( ( flags & DP_F_ZERO ) && ( padlen > 0 ) ) {
 if ( signvalue ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , signvalue ) ) return 0 ;
 -- padlen ;
 signvalue = 0 ;
 }
 while ( padlen > 0 ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , '0' ) ) return 0 ;
 -- padlen ;
 }
 }
 while ( padlen > 0 ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , ' ' ) ) return 0 ;
 -- padlen ;
 }
 if ( signvalue && ! doapr_outch ( sbuffer , buffer , currlen , maxlen , signvalue ) ) return 0 ;
 while ( iplace > 0 ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , iconvert [ -- iplace ] ) ) return 0 ;
 }
 if ( max > 0 || ( flags & DP_F_NUM ) ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , '.' ) ) return 0 ;
 while ( fplace > 0 ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , fconvert [ -- fplace ] ) ) return 0 ;
 }
 }
 while ( zpadlen > 0 ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , '0' ) ) return 0 ;
 -- zpadlen ;
 }
 while ( padlen < 0 ) {
 if ( ! doapr_outch ( sbuffer , buffer , currlen , maxlen , ' ' ) ) return 0 ;
 ++ padlen ;
 }
 return 1 ;
 }
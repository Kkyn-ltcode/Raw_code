static void ppp_hdlc ( netdissect_options * ndo , const u_char * p , int length ) {
 u_char * b , * s , * t , c ;
 int i , proto ;
 const void * se ;
 if ( length <= 0 ) return ;
 b = ( uint8_t * ) malloc ( length ) ;
 if ( b == NULL ) return ;
 for ( s = ( u_char * ) p , t = b , i = length ;
 i > 0 ;
 i -- ) {
 c = * s ++ ;
 if ( c == 0x7d ) {
 if ( i > 1 ) {
 i -- ;
 c = * s ++ ^ 0x20 ;
 }
 else continue ;
 }
 * t ++ = c ;
 }
 se = ndo -> ndo_snapend ;
 ndo -> ndo_snapend = t ;
 length = t - b ;
 if ( length < 1 ) goto trunc ;
 proto = * b ;
 switch ( proto ) {
 case PPP_IP : ip_print ( ndo , b + 1 , length - 1 ) ;
 goto cleanup ;
 case PPP_IPV6 : ip6_print ( ndo , b + 1 , length - 1 ) ;
 goto cleanup ;
 default : break ;
 }
 if ( length < 2 ) goto trunc ;
 proto = EXTRACT_16BITS ( b ) ;
 switch ( proto ) {
 case ( PPP_ADDRESS << 8 | PPP_CONTROL ) : if ( length < 4 ) goto trunc ;
 proto = EXTRACT_16BITS ( b + 2 ) ;
 handle_ppp ( ndo , proto , b + 4 , length - 4 ) ;
 break ;
 default : handle_ppp ( ndo , proto , b + 2 , length - 2 ) ;
 break ;
 }
 cleanup : ndo -> ndo_snapend = se ;
 free ( b ) ;
 return ;
 trunc : ndo -> ndo_snapend = se ;
 free ( b ) ;
 ND_PRINT ( ( ndo , "[|ppp]" ) ) ;
 }
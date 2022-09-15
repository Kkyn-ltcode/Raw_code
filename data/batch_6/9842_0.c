static void sliplink_print ( netdissect_options * ndo , register const u_char * p , register const struct ip * ip , register u_int length ) {
 int dir ;
 u_int hlen ;
 dir = p [ SLX_DIR ] ;
 switch ( dir ) {
 case SLIPDIR_IN : ND_PRINT ( ( ndo , "I " ) ) ;
 break ;
 case SLIPDIR_OUT : ND_PRINT ( ( ndo , "O " ) ) ;
 break ;
 default : ND_PRINT ( ( ndo , "Invalid direction %d " , dir ) ) ;
 dir = - 1 ;
 break ;
 }
 if ( ndo -> ndo_nflag ) {
 register int i ;
 for ( i = SLX_CHDR ;
 i < SLX_CHDR + CHDR_LEN - 1 ;
 ++ i ) ND_PRINT ( ( ndo , "%02x." , p [ i ] ) ) ;
 ND_PRINT ( ( ndo , "%02x: " , p [ SLX_CHDR + CHDR_LEN - 1 ] ) ) ;
 return ;
 }
 switch ( p [ SLX_CHDR ] & 0xf0 ) {
 case TYPE_IP : ND_PRINT ( ( ndo , "ip %d: " , length + SLIP_HDRLEN ) ) ;
 break ;
 case TYPE_UNCOMPRESSED_TCP : lastconn = ( ( const struct ip * ) & p [ SLX_CHDR ] ) -> ip_p ;
 ND_PRINT ( ( ndo , "utcp %d: " , lastconn ) ) ;
 if ( dir == - 1 ) {
 return ;
 }
 hlen = IP_HL ( ip ) ;
 hlen += TH_OFF ( ( const struct tcphdr * ) & ( ( const int * ) ip ) [ hlen ] ) ;
 lastlen [ dir ] [ lastconn ] = length - ( hlen << 2 ) ;
 break ;
 default : if ( dir == - 1 ) {
 return ;
 }
 if ( p [ SLX_CHDR ] & TYPE_COMPRESSED_TCP ) {
 compressed_sl_print ( ndo , & p [ SLX_CHDR ] , ip , length , dir ) ;
 ND_PRINT ( ( ndo , ": " ) ) ;
 }
 else ND_PRINT ( ( ndo , "slip-%d!: " , p [ SLX_CHDR ] ) ) ;
 }
 }
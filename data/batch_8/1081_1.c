static void sliplink_print ( netdissect_options * ndo , register const u_char * p , register const struct ip * ip , register u_int length ) {
 int dir ;
 u_int hlen ;
 dir = p [ SLX_DIR ] ;
 ND_PRINT ( ( ndo , dir == SLIPDIR_IN ? "I " : "O " ) ) ;
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
 hlen = IP_HL ( ip ) ;
 hlen += TH_OFF ( ( const struct tcphdr * ) & ( ( const int * ) ip ) [ hlen ] ) ;
 lastlen [ dir ] [ lastconn ] = length - ( hlen << 2 ) ;
 ND_PRINT ( ( ndo , "utcp %d: " , lastconn ) ) ;
 break ;
 default : if ( p [ SLX_CHDR ] & TYPE_COMPRESSED_TCP ) {
 compressed_sl_print ( ndo , & p [ SLX_CHDR ] , ip , length , dir ) ;
 ND_PRINT ( ( ndo , ": " ) ) ;
 }
 else ND_PRINT ( ( ndo , "slip-%d!: " , p [ SLX_CHDR ] ) ) ;
 }
 }
u_int sl_if_print ( netdissect_options * ndo , const struct pcap_pkthdr * h , const u_char * p ) {
 register u_int caplen = h -> caplen ;
 register u_int length = h -> len ;
 register const struct ip * ip ;
 if ( caplen < SLIP_HDRLEN || length < SLIP_HDRLEN ) {
 ND_PRINT ( ( ndo , "%s" , tstr ) ) ;
 return ( caplen ) ;
 }
 caplen -= SLIP_HDRLEN ;
 length -= SLIP_HDRLEN ;
 ip = ( const struct ip * ) ( p + SLIP_HDRLEN ) ;
 if ( ndo -> ndo_eflag ) sliplink_print ( ndo , p , ip , length ) ;
 if ( caplen < 1 || length < 1 ) {
 ND_PRINT ( ( ndo , "%s" , tstr ) ) ;
 return ( caplen + SLIP_HDRLEN ) ;
 }
 switch ( IP_V ( ip ) ) {
 case 4 : ip_print ( ndo , ( const u_char * ) ip , length ) ;
 break ;
 case 6 : ip6_print ( ndo , ( const u_char * ) ip , length ) ;
 break ;
 default : ND_PRINT ( ( ndo , "ip v%d" , IP_V ( ip ) ) ) ;
 }
 return ( SLIP_HDRLEN ) ;
 }
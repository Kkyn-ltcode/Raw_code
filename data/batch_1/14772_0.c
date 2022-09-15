static enum checksum_status pimv2_check_checksum ( netdissect_options * ndo , const u_char * bp , const u_char * bp2 , u_int len ) {
 const struct ip * ip ;
 u_int cksum ;
 if ( ! ND_TTEST2 ( bp [ 0 ] , len ) ) {
 return ( UNVERIFIED ) ;
 }
 ip = ( const struct ip * ) bp2 ;
 if ( IP_V ( ip ) == 4 ) {
 struct cksum_vec vec [ 1 ] ;
 vec [ 0 ] . ptr = bp ;
 vec [ 0 ] . len = len ;
 cksum = in_cksum ( vec , 1 ) ;
 return ( cksum ? INCORRECT : CORRECT ) ;
 }
 else if ( IP_V ( ip ) == 6 ) {
 const struct ip6_hdr * ip6 ;
 ip6 = ( const struct ip6_hdr * ) bp2 ;
 cksum = nextproto6_cksum ( ndo , ip6 , bp , len , len , IPPROTO_PIM ) ;
 return ( cksum ? INCORRECT : CORRECT ) ;
 }
 else {
 return ( UNVERIFIED ) ;
 }
 }
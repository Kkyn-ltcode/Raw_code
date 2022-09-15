static void handle_mlppp ( netdissect_options * ndo , const u_char * p , int length ) {
 if ( ! ndo -> ndo_eflag ) ND_PRINT ( ( ndo , "MLPPP, " ) ) ;
 ND_PRINT ( ( ndo , "seq 0x%03x, Flags [%s], length %u" , ( EXTRACT_16BITS ( p ) ) & 0x0fff , bittok2str ( ppp_ml_flag_values , "none" , * p & 0xc0 ) , length ) ) ;
 }
void safeputs ( netdissect_options * ndo , const u_char * s , const u_int maxlen ) {
 u_int idx = 0 ;
 while ( * s && idx < maxlen ) {
 safeputchar ( ndo , * s ) ;
 idx ++ ;
 s ++ ;
 }
 }
static size_t b_encoder ( char * str , const char * buf , size_t buflen , const char * tocode ) {
 char * s0 = str ;
 memcpy ( str , "=?" , 2 ) ;
 str += 2 ;
 memcpy ( str , tocode , strlen ( tocode ) ) ;
 str += strlen ( tocode ) ;
 memcpy ( str , "?B?" , 3 ) ;
 str += 3 ;
 while ( buflen ) {
 char encoded [ 11 ] ;
 size_t ret ;
 size_t in_len = MIN ( 3 , buflen ) ;
 ret = mutt_b64_encode ( encoded , buf , in_len , sizeof ( encoded ) ) ;
 for ( size_t i = 0 ;
 i < ret ;
 i ++ ) * str ++ = encoded [ i ] ;
 buflen -= in_len ;
 buf += in_len ;
 }
 memcpy ( str , "?=" , 2 ) ;
 str += 2 ;
 return ( str - s0 ) ;
 }
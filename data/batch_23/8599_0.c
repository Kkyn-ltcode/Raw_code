static void handle_chap ( netdissect_options * ndo , const u_char * p , int length ) {
 u_int code , len ;
 int val_size , name_size , msg_size ;
 const u_char * p0 ;
 int i ;
 p0 = p ;
 if ( length < 1 ) {
 ND_PRINT ( ( ndo , "[|chap]" ) ) ;
 return ;
 }
 else if ( length < 4 ) {
 ND_TCHECK ( * p ) ;
 ND_PRINT ( ( ndo , "[|chap 0x%02x]" , * p ) ) ;
 return ;
 }
 ND_TCHECK ( * p ) ;
 code = * p ;
 ND_PRINT ( ( ndo , "CHAP, %s (0x%02x)" , tok2str ( chapcode_values , "unknown" , code ) , code ) ) ;
 p ++ ;
 ND_TCHECK ( * p ) ;
 ND_PRINT ( ( ndo , ", id %u" , * p ) ) ;
 p ++ ;
 ND_TCHECK2 ( * p , 2 ) ;
 len = EXTRACT_16BITS ( p ) ;
 p += 2 ;
 switch ( code ) {
 case CHAP_CHAL : case CHAP_RESP : if ( length - ( p - p0 ) < 1 ) return ;
 ND_TCHECK ( * p ) ;
 val_size = * p ;
 p ++ ;
 if ( length - ( p - p0 ) < val_size ) return ;
 ND_PRINT ( ( ndo , ", Value " ) ) ;
 for ( i = 0 ;
 i < val_size ;
 i ++ ) {
 ND_TCHECK ( * p ) ;
 ND_PRINT ( ( ndo , "%02x" , * p ++ ) ) ;
 }
 name_size = len - ( p - p0 ) ;
 ND_PRINT ( ( ndo , ", Name " ) ) ;
 for ( i = 0 ;
 i < name_size ;
 i ++ ) {
 ND_TCHECK ( * p ) ;
 safeputchar ( ndo , * p ++ ) ;
 }
 break ;
 case CHAP_SUCC : case CHAP_FAIL : msg_size = len - ( p - p0 ) ;
 ND_PRINT ( ( ndo , ", Msg " ) ) ;
 for ( i = 0 ;
 i < msg_size ;
 i ++ ) {
 ND_TCHECK ( * p ) ;
 safeputchar ( ndo , * p ++ ) ;
 }
 break ;
 }
 return ;
 trunc : ND_PRINT ( ( ndo , "[|chap]" ) ) ;
 }
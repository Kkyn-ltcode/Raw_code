static size_t try_block ( const char * d , size_t dlen , const char * fromcode , const char * tocode , encoder_t * encoder , size_t * wlen ) {
 char buf [ ENCWORD_LEN_MAX - ENCWORD_LEN_MIN + 1 ] ;
 const char * ib = NULL ;
 char * ob = NULL ;
 size_t ibl , obl ;
 int count , len , len_b , len_q ;
 if ( fromcode ) {
 iconv_t cd = mutt_ch_iconv_open ( tocode , fromcode , 0 ) ;
 assert ( cd != ( iconv_t ) ( - 1 ) ) ;
 ib = d ;
 ibl = dlen ;
 ob = buf ;
 obl = sizeof ( buf ) - strlen ( tocode ) ;
 if ( iconv ( cd , ( ICONV_CONST char * * ) & ib , & ibl , & ob , & obl ) == ( size_t ) ( - 1 ) || iconv ( cd , NULL , NULL , & ob , & obl ) == ( size_t ) ( - 1 ) ) {
 assert ( errno == E2BIG ) ;
 iconv_close ( cd ) ;
 assert ( ib > d ) ;
 return ( ib - d == dlen ) ? dlen : ib - d + 1 ;
 }
 iconv_close ( cd ) ;
 }
 else {
 if ( dlen > ( sizeof ( buf ) - strlen ( tocode ) ) ) return ( sizeof ( buf ) - strlen ( tocode ) + 1 ) ;
 memcpy ( buf , d , dlen ) ;
 ob = buf + dlen ;
 }
 count = 0 ;
 for ( char * p = buf ;
 p < ob ;
 p ++ ) {
 unsigned char c = * p ;
 assert ( strchr ( MimeSpecials , '?' ) ) ;
 if ( ( c >= 0x7f ) || ( c < 0x20 ) || ( * p == '_' ) || ( ( c != ' ' ) && strchr ( MimeSpecials , * p ) ) ) {
 count ++ ;
 }
 }
 len = ENCWORD_LEN_MIN - 2 + strlen ( tocode ) ;
 len_b = len + ( ( ( ob - buf ) + 2 ) / 3 ) * 4 ;
 len_q = len + ( ob - buf ) + 2 * count ;
 if ( mutt_str_strcasecmp ( tocode , "ISO-2022-JP" ) == 0 ) len_q = ENCWORD_LEN_MAX + 1 ;
 if ( ( len_b < len_q ) && ( len_b <= ENCWORD_LEN_MAX ) ) {
 * encoder = b_encoder ;
 * wlen = len_b ;
 return 0 ;
 }
 else if ( len_q <= ENCWORD_LEN_MAX ) {
 * encoder = q_encoder ;
 * wlen = len_q ;
 return 0 ;
 }
 else return dlen ;
 }
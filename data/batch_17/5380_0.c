static int rfc2047_encode ( const char * d , size_t dlen , int col , const char * fromcode , const char * charsets , char * * e , size_t * elen , const char * specials ) {
 int rc = 0 ;
 char * buf = NULL ;
 size_t bufpos , buflen ;
 char * t0 = NULL , * t1 = NULL , * t = NULL ;
 char * s0 = NULL , * s1 = NULL ;
 size_t ulen , r , wlen = 0 ;
 encoder_t encoder = NULL ;
 char * tocode1 = NULL ;
 const char * tocode = NULL ;
 char * icode = "utf-8" ;
 char * u = mutt_str_substr_dup ( d , d + dlen ) ;
 if ( mutt_ch_convert_string ( & u , fromcode , icode , 0 ) != 0 ) {
 rc = 1 ;
 icode = 0 ;
 }
 ulen = mutt_str_strlen ( u ) ;
 s0 = s1 = t0 = t1 = 0 ;
 for ( t = u ;
 t < ( u + ulen ) ;
 t ++ ) {
 if ( ( * t & 0x80 ) || ( ( * t == '=' ) && ( t [ 1 ] == '?' ) && ( ( t == u ) || HSPACE ( * ( t - 1 ) ) ) ) ) {
 if ( ! t0 ) t0 = t ;
 t1 = t ;
 }
 else if ( specials && * t && strchr ( specials , * t ) ) {
 if ( ! s0 ) s0 = t ;
 s1 = t ;
 }
 }
 if ( t0 && s0 && ( s0 < t0 ) ) t0 = s0 ;
 if ( t1 && s1 && ( s1 > t1 ) ) t1 = s1 ;
 if ( ! t0 ) {
 * e = u ;
 * elen = ulen ;
 return rc ;
 }
 tocode = fromcode ;
 if ( icode ) {
 tocode1 = mutt_ch_choose ( icode , charsets , u , ulen , 0 , 0 ) ;
 if ( tocode1 ) tocode = tocode1 ;
 else {
 rc = 2 ;
 icode = 0 ;
 }
 }
 if ( ! icode && mutt_ch_is_us_ascii ( tocode ) ) tocode = "unknown-8bit" ;
 t = u + ( ENCWORD_LEN_MAX + 1 ) - col - ENCWORD_LEN_MIN ;
 if ( t < u ) t = u ;
 if ( t < t0 ) t0 = t ;
 for ( ;
 t0 > u ;
 t0 -- ) {
 if ( ! HSPACE ( * ( t0 - 1 ) ) ) continue ;
 t = t0 + 1 ;
 if ( icode ) while ( ( t < ( u + ulen ) ) && CONTINUATION_BYTE ( * t ) ) t ++ ;
 if ( ( try_block ( t0 , t - t0 , icode , tocode , & encoder , & wlen ) == 0 ) && ( ( col + ( t0 - u ) + wlen ) <= ( ENCWORD_LEN_MAX + 1 ) ) ) {
 break ;
 }
 }
 for ( ;
 t1 < ( u + ulen ) ;
 t1 ++ ) {
 if ( ! HSPACE ( * t1 ) ) continue ;
 t = t1 - 1 ;
 if ( icode ) while ( CONTINUATION_BYTE ( * t ) ) t -- ;
 if ( ( try_block ( t , t1 - t , icode , tocode , & encoder , & wlen ) == 0 ) && ( ( 1 + wlen + ( u + ulen - t1 ) ) <= ( ENCWORD_LEN_MAX + 1 ) ) ) {
 break ;
 }
 }
 buflen = 2 * ulen ;
 buf = mutt_mem_malloc ( buflen ) ;
 bufpos = t0 - u ;
 memcpy ( buf , u , t0 - u ) ;
 col += t0 - u ;
 t = t0 ;
 while ( true ) {
 size_t n = choose_block ( t , t1 - t , col , icode , tocode , & encoder , & wlen ) ;
 if ( n == ( t1 - t ) ) {
 if ( ( col + wlen + ( u + ulen - t1 ) ) <= ( ENCWORD_LEN_MAX + 1 ) ) break ;
 n = t1 - t - 1 ;
 if ( icode ) while ( CONTINUATION_BYTE ( t [ n ] ) ) n -- ;
 if ( ! n ) {
 assert ( t1 < ( u + ulen ) ) ;
 for ( t1 ++ ;
 ( t1 < ( u + ulen ) ) && ! HSPACE ( * t1 ) ;
 t1 ++ ) ;
 continue ;
 }
 n = choose_block ( t , n , col , icode , tocode , & encoder , & wlen ) ;
 }
 const char * line_break = "\n\t" ;
 const int lb_len = 2 ;
 if ( ( bufpos + wlen + lb_len ) > buflen ) {
 buflen = bufpos + wlen + lb_len ;
 mutt_mem_realloc ( & buf , buflen ) ;
 }
 r = encode_block ( buf + bufpos , t , n , icode , tocode , encoder ) ;
 assert ( r == wlen ) ;
 bufpos += wlen ;
 memcpy ( buf + bufpos , line_break , lb_len ) ;
 bufpos += lb_len ;
 col = 1 ;
 t += n ;
 }
 buflen = bufpos + wlen + ( u + ulen - t1 ) ;
 mutt_mem_realloc ( & buf , buflen + 1 ) ;
 r = encode_block ( buf + bufpos , t , t1 - t , icode , tocode , encoder ) ;
 assert ( r == wlen ) ;
 bufpos += wlen ;
 memcpy ( buf + bufpos , t1 , u + ulen - t1 ) ;
 FREE ( & tocode1 ) ;
 FREE ( & u ) ;
 buf [ buflen ] = '\0' ;
 * e = buf ;
 * elen = buflen + 1 ;
 return rc ;
 }
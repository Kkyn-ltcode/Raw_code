void convert_to_format_v1 ( char * query ) {
 int last_c_was_quote = 0 ;
 char * p = query , * to = query ;
 char * end = strend ( query ) ;
 char last_c ;
 while ( p <= end ) {
 if ( * p == '\n' && ! last_c_was_quote ) {
 * to ++ = * p ++ ;
 while ( * p && my_isspace ( charset_info , * p ) ) p ++ ;
 last_c_was_quote = 0 ;
 }
 else if ( * p == '\'' || * p == '"' || * p == '`' ) {
 last_c = * p ;
 * to ++ = * p ++ ;
 while ( * p && * p != last_c ) * to ++ = * p ++ ;
 * to ++ = * p ++ ;
 last_c_was_quote = 1 ;
 }
 else {
 * to ++ = * p ++ ;
 last_c_was_quote = 0 ;
 }
 }
 }
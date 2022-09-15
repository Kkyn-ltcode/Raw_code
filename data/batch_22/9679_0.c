static void convert_UTF8_to_JSON ( FBuffer * buffer , VALUE string ) {
 const char * ptr = RSTRING_PTR ( string ) , * p ;
 unsigned long len = RSTRING_LEN ( string ) , start = 0 , end = 0 ;
 const char * escape = NULL ;
 int escape_len ;
 unsigned char c ;
 char buf [ 6 ] = {
 '\\' , 'u' }
 ;
 for ( start = 0 , end = 0 ;
 end < len ;
 ) {
 p = ptr + end ;
 c = ( unsigned char ) * p ;
 if ( c < 0x20 ) {
 switch ( c ) {
 case '\n' : escape = "\\n" ;
 escape_len = 2 ;
 break ;
 case '\r' : escape = "\\r" ;
 escape_len = 2 ;
 break ;
 case '\t' : escape = "\\t" ;
 escape_len = 2 ;
 break ;
 case '\f' : escape = "\\f" ;
 escape_len = 2 ;
 break ;
 case '\b' : escape = "\\b" ;
 escape_len = 2 ;
 break ;
 default : unicode_escape ( buf , ( UTF16 ) * p ) ;
 escape = buf ;
 escape_len = 6 ;
 break ;
 }
 }
 else {
 switch ( c ) {
 case '\\' : escape = "\\\\" ;
 escape_len = 2 ;
 break ;
 case '"' : escape = "\\\"" ;
 escape_len = 2 ;
 break ;
 default : {
 unsigned short clen = trailingBytesForUTF8 [ c ] + 1 ;
 if ( end + clen > len ) {
 rb_raise ( rb_path2class ( "JSON::GeneratorError" ) , "partial character in source, but hit end" ) ;
 }
 if ( ! isLegalUTF8 ( ( UTF8 * ) p , clen ) ) {
 rb_raise ( rb_path2class ( "JSON::GeneratorError" ) , "source sequence is illegal/malformed utf-8" ) ;
 }
 end += clen ;
 }
 continue ;
 break ;
 }
 }
 fbuffer_append ( buffer , ptr + start , end - start ) ;
 fbuffer_append ( buffer , escape , escape_len ) ;
 start = ++ end ;
 escape = NULL ;
 }
 fbuffer_append ( buffer , ptr + start , end - start ) ;
 }
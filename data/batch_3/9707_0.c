static void convert_UTF8_to_JSON_ASCII ( FBuffer * buffer , VALUE string ) {
 const UTF8 * source = ( UTF8 * ) RSTRING_PTR ( string ) ;
 const UTF8 * sourceEnd = source + RSTRING_LEN ( string ) ;
 char buf [ 6 ] = {
 '\\' , 'u' }
 ;
 while ( source < sourceEnd ) {
 UTF32 ch = 0 ;
 unsigned short extraBytesToRead = trailingBytesForUTF8 [ * source ] ;
 if ( source + extraBytesToRead >= sourceEnd ) {
 rb_raise ( rb_path2class ( "JSON::GeneratorError" ) , "partial character in source, but hit end" ) ;
 }
 if ( ! isLegalUTF8 ( source , extraBytesToRead + 1 ) ) {
 rb_raise ( rb_path2class ( "JSON::GeneratorError" ) , "source sequence is illegal/malformed utf-8" ) ;
 }
 switch ( extraBytesToRead ) {
 case 5 : ch += * source ++ ;
 ch <<= 6 ;
 case 4 : ch += * source ++ ;
 ch <<= 6 ;
 case 3 : ch += * source ++ ;
 ch <<= 6 ;
 case 2 : ch += * source ++ ;
 ch <<= 6 ;
 case 1 : ch += * source ++ ;
 ch <<= 6 ;
 case 0 : ch += * source ++ ;
 }
 ch -= offsetsFromUTF8 [ extraBytesToRead ] ;
 if ( ch <= UNI_MAX_BMP ) {
 if ( ch >= UNI_SUR_HIGH_START && ch <= UNI_SUR_LOW_END ) {
 # if UNI_STRICT_CONVERSION source -= ( extraBytesToRead + 1 ) ;
 rb_raise ( rb_path2class ( "JSON::GeneratorError" ) , "source sequence is illegal/malformed utf-8" ) ;
 # else unicode_escape_to_buffer ( buffer , buf , UNI_REPLACEMENT_CHAR ) ;
 # endif }
 else {
 if ( ch >= 0x20 && ch <= 0x7f ) {
 switch ( ch ) {
 case '\\' : fbuffer_append ( buffer , "\\\\" , 2 ) ;
 break ;
 case '"' : fbuffer_append ( buffer , "\\\"" , 2 ) ;
 break ;
 default : fbuffer_append_char ( buffer , ( char ) ch ) ;
 break ;
 }
 }
 else {
 switch ( ch ) {
 case '\n' : fbuffer_append ( buffer , "\\n" , 2 ) ;
 break ;
 case '\r' : fbuffer_append ( buffer , "\\r" , 2 ) ;
 break ;
 case '\t' : fbuffer_append ( buffer , "\\t" , 2 ) ;
 break ;
 case '\f' : fbuffer_append ( buffer , "\\f" , 2 ) ;
 break ;
 case '\b' : fbuffer_append ( buffer , "\\b" , 2 ) ;
 break ;
 default : unicode_escape_to_buffer ( buffer , buf , ( UTF16 ) ch ) ;
 break ;
 }
 }
 }
 }
 else if ( ch > UNI_MAX_UTF16 ) {
 # if UNI_STRICT_CONVERSION source -= ( extraBytesToRead + 1 ) ;
 rb_raise ( rb_path2class ( "JSON::GeneratorError" ) , "source sequence is illegal/malformed utf8" ) ;
 # else unicode_escape_to_buffer ( buffer , buf , UNI_REPLACEMENT_CHAR ) ;
 # endif }
 else {
 ch -= halfBase ;
 unicode_escape_to_buffer ( buffer , buf , ( UTF16 ) ( ( ch >> halfShift ) + UNI_SUR_HIGH_START ) ) ;
 unicode_escape_to_buffer ( buffer , buf , ( UTF16 ) ( ( ch & halfMask ) + UNI_SUR_LOW_START ) ) ;
 }
 }
 RB_GC_GUARD ( string ) ;
 }
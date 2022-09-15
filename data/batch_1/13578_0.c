static gboolean has_invalid_xml_char ( char * str ) {
 gunichar c ;
 while ( * str != 0 ) {
 c = g_utf8_get_char ( str ) ;
 if ( ! ( c == 0x9 || c == 0xA || c == 0xD || ( c >= 0x20 && c <= 0xD7FF ) || ( c >= 0xE000 && c <= 0xFFFD ) || ( c >= 0x10000 && c <= 0x10FFFF ) ) ) {
 return TRUE ;
 }
 str = g_utf8_next_char ( str ) ;
 }
 return FALSE ;
 }
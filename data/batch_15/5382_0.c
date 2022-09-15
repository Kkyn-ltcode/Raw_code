static char * parse_encoded_word ( char * str , enum ContentEncoding * enc , char * * charset , size_t * charsetlen , char * * text , size_t * textlen ) {
 static struct Regex * re = NULL ;
 regmatch_t match [ 4 ] ;
 size_t nmatch = 4 ;
 if ( re == NULL ) {
 re = mutt_regex_compile ( "=\\?" "([^][()<>@,;
:\\\"/?. =]+)" "\\?" "([qQbB])" "\\?" "([^?]+)" "\\?=" , REG_EXTENDED ) ;
 assert ( re && "Something is wrong with your RE engine." ) ;
 }
 int rc = regexec ( re -> regex , str , nmatch , match , 0 ) ;
 if ( rc != 0 ) return NULL ;
 * charset = str + match [ 1 ] . rm_so ;
 * charsetlen = match [ 1 ] . rm_eo - match [ 1 ] . rm_so ;
 * enc = ( ( str [ match [ 2 ] . rm_so ] == 'Q' ) || ( str [ match [ 2 ] . rm_so ] == 'q' ) ) ? ENCQUOTEDPRINTABLE : ENCBASE64 ;
 * text = str + match [ 3 ] . rm_so ;
 * textlen = match [ 3 ] . rm_eo - match [ 3 ] . rm_so ;
 return ( str + match [ 0 ] . rm_so ) ;
 }
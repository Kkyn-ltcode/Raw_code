static char * quote_for_like ( const char * name , char * buff ) {
 char * to = buff ;
 * to ++ = '\'' ;
 while ( * name ) {
 if ( * name == '\\' ) {
 * to ++ = '\\' ;
 * to ++ = '\\' ;
 * to ++ = '\\' ;
 }
 else if ( * name == '\'' || * name == '_' || * name == '%' ) * to ++ = '\\' ;
 * to ++ = * name ++ ;
 }
 to [ 0 ] = '\'' ;
 to [ 1 ] = 0 ;
 return buff ;
 }
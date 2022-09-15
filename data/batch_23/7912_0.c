static char * quote_name ( const char * name , char * buff , my_bool force ) {
 char * to = buff ;
 char qtype = ( opt_compatible_mode & MASK_ANSI_QUOTES ) ? '\"' : '`' ;
 if ( ! force && ! opt_quoted && ! test_if_special_chars ( name ) ) return ( char * ) name ;
 * to ++ = qtype ;
 while ( * name ) {
 if ( * name == qtype ) * to ++ = qtype ;
 * to ++ = * name ++ ;
 }
 to [ 0 ] = qtype ;
 to [ 1 ] = 0 ;
 return buff ;
 }
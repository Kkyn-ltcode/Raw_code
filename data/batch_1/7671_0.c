void mi_check_print_info ( MI_CHECK * param __attribute__ ( ( unused ) ) , const char * fmt , ... ) {
 va_list args ;
 va_start ( args , fmt ) ;
 ( void ) vfprintf ( stdout , fmt , args ) ;
 ( void ) fputc ( '\n' , stdout ) ;
 va_end ( args ) ;
 }
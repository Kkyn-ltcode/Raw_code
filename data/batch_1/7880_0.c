static void maybe_die ( int error_num , const char * fmt_reason , ... ) {
 char buffer [ 1000 ] ;
 va_list args ;
 va_start ( args , fmt_reason ) ;
 my_vsnprintf ( buffer , sizeof ( buffer ) , fmt_reason , args ) ;
 va_end ( args ) ;
 fprintf ( stderr , "%s: %s\n" , my_progname_short , buffer ) ;
 fflush ( stderr ) ;
 maybe_exit ( error_num ) ;
 }
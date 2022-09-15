static void verbose_msg ( const char * fmt , ... ) {
 va_list args ;
 DBUG_ENTER ( "verbose_msg" ) ;
 if ( ! verbose ) DBUG_VOID_RETURN ;
 va_start ( args , fmt ) ;
 vfprintf ( stderr , fmt , args ) ;
 va_end ( args ) ;
 fflush ( stderr ) ;
 DBUG_VOID_RETURN ;
 }
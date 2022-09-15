static void unixErrorHandler ( const char * module , const char * fmt , va_list ap ) {
 if ( module != NULL ) fprintf ( stderr , "%s: " , module ) ;
 vfprintf ( stderr , fmt , ap ) ;
 fprintf ( stderr , ".\n" ) ;
 }
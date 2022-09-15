static void unixWarningHandler ( const char * module , const char * fmt , va_list ap ) {
 if ( module != NULL ) fprintf ( stderr , "%s: " , module ) ;
 fprintf ( stderr , "Warning, " ) ;
 vfprintf ( stderr , fmt , ap ) ;
 fprintf ( stderr , ".\n" ) ;
 }
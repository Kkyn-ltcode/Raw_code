void mct_log ( const char * format , ... ) {
 va_list args ;
 va_start ( args , format ) ;
 vprintf ( format , args ) ;
 va_end ( args ) ;
 if ( mct_log_file ) {
 va_list args ;
 va_start ( args , format ) ;
 vfprintf ( mct_log_file , format , args ) ;
 va_end ( args ) ;
 }
 }
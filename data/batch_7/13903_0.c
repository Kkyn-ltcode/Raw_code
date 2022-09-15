static void virLogStackTraceToFd ( int fd ) {
 void * array [ 100 ] ;
 int size ;
 static bool doneWarning ;
 const char * msg = "Stack trace not available on this platform\n" ;
 # define STRIP_DEPTH 3 size = backtrace ( array , ARRAY_CARDINALITY ( array ) ) ;
 if ( size ) {
 backtrace_symbols_fd ( array + STRIP_DEPTH , size - STRIP_DEPTH , fd ) ;
 ignore_value ( safewrite ( fd , "\n" , 1 ) ) ;
 }
 else if ( ! doneWarning ) {
 ignore_value ( safewrite ( fd , msg , strlen ( msg ) ) ) ;
 doneWarning = true ;
 }
 # undef STRIP_DEPTH }
void unireg_end ( void ) {
 clean_up ( 1 ) ;
 my_thread_end ( ) ;
 # if defined ( SIGNALS_DONT_BREAK_READ ) exit ( 0 ) ;
 # else pthread_exit ( 0 ) ;
 # endif }
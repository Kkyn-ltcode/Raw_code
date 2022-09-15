void lock_memory ( MI_CHECK * param __attribute__ ( ( unused ) ) ) {
 # ifdef SUN_OS if ( param -> opt_lock_memory ) {
 int success = mlockall ( MCL_CURRENT ) ;
 if ( geteuid ( ) == 0 && success != 0 ) mi_check_print_warning ( param , "Failed to lock memory. errno %d" , my_errno ) ;
 }
 # endif }
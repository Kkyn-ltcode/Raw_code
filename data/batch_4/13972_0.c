static void clean_up_error_log_mutex ( ) {
 mysql_mutex_destroy ( & LOCK_error_log ) ;
 }
void create_thread_to_handle_connection ( THD * thd ) {
 if ( cached_thread_count > wake_thread ) {
 thread_cache . push_back ( thd ) ;
 wake_thread ++ ;
 mysql_cond_signal ( & COND_thread_cache ) ;
 }
 else {
 char error_message_buff [ MYSQL_ERRMSG_SIZE ] ;
 int error ;
 thread_created ++ ;
 threads . append ( thd ) ;
 DBUG_PRINT ( "info" , ( ( "creating thread %lu" ) , thd -> thread_id ) ) ;
 thd -> prior_thr_create_utime = microsecond_interval_timer ( ) ;
 if ( ( error = mysql_thread_create ( key_thread_one_connection , & thd -> real_id , & connection_attrib , handle_one_connection , ( void * ) thd ) ) ) {
 DBUG_PRINT ( "error" , ( "Can't create thread to handle request (error %d)" , error ) ) ;
 thread_count -- ;
 thd -> killed = KILL_CONNECTION ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 mysql_mutex_lock ( & LOCK_connection_count ) ;
 ( * thd -> scheduler -> connection_count ) -- ;
 mysql_mutex_unlock ( & LOCK_connection_count ) ;
 statistic_increment ( aborted_connects , & LOCK_status ) ;
 my_snprintf ( error_message_buff , sizeof ( error_message_buff ) , ER_THD ( thd , ER_CANT_CREATE_THREAD ) , error ) ;
 net_send_error ( thd , ER_CANT_CREATE_THREAD , error_message_buff , NULL ) ;
 close_connection ( thd , ER_OUT_OF_RESOURCES ) ;
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 delete thd ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 return ;
 }
 }
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 DBUG_PRINT ( "info" , ( "Thread created" ) ) ;
 }
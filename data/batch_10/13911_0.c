bool one_thread_per_connection_end ( THD * thd , bool put_in_cache ) {
 DBUG_ENTER ( "one_thread_per_connection_end" ) ;
 unlink_thd ( thd ) ;
 my_pthread_setspecific_ptr ( THR_THD , 0 ) ;
 if ( put_in_cache ) {
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 put_in_cache = cache_thread ( ) ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 if ( put_in_cache ) DBUG_RETURN ( 0 ) ;
 }
 DBUG_PRINT ( "signal" , ( "Broadcasting COND_thread_count" ) ) ;
 DBUG_LEAVE ;
 # if defined ( HAVE_OPENSSL ) && ! defined ( EMBEDDED_LIBRARY ) ERR_remove_state ( 0 ) ;
 # endif my_thread_end ( ) ;
 mysql_cond_broadcast ( & COND_thread_count ) ;
 pthread_exit ( 0 ) ;
 return 0 ;
 }
void handle_connection_in_main_thread ( THD * thd ) {
 mysql_mutex_assert_owner ( & LOCK_thread_count ) ;
 thread_cache_size = 0 ;
 threads . append ( thd ) ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 thd -> start_utime = microsecond_interval_timer ( ) ;
 do_handle_one_connection ( thd ) ;
 }
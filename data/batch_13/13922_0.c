void flush_thread_cache ( ) {
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 kill_cached_threads ++ ;
 while ( cached_thread_count ) {
 mysql_cond_broadcast ( & COND_thread_cache ) ;
 mysql_cond_wait ( & COND_flush_thread_cache , & LOCK_thread_count ) ;
 }
 kill_cached_threads -- ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 }
void dec_connection_count ( THD * thd ) {
 mysql_mutex_lock ( & LOCK_connection_count ) ;
 ( * thd -> scheduler -> connection_count ) -- ;
 mysql_mutex_unlock ( & LOCK_connection_count ) ;
 }
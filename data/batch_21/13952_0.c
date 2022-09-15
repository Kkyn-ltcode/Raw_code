static int show_prepared_stmt_count ( THD * thd , SHOW_VAR * var , char * buff ) {
 var -> type = SHOW_LONG ;
 var -> value = buff ;
 mysql_mutex_lock ( & LOCK_prepared_stmt_count ) ;
 * ( ( long * ) buff ) = ( long ) prepared_stmt_count ;
 mysql_mutex_unlock ( & LOCK_prepared_stmt_count ) ;
 return 0 ;
 }
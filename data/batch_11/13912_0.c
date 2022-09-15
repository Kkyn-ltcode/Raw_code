static void clean_up_mutexes ( ) {
 DBUG_ENTER ( "clean_up_mutexes" ) ;
 mysql_rwlock_destroy ( & LOCK_grant ) ;
 mysql_mutex_destroy ( & LOCK_thread_count ) ;
 mysql_mutex_destroy ( & LOCK_status ) ;
 mysql_mutex_destroy ( & LOCK_delayed_insert ) ;
 mysql_mutex_destroy ( & LOCK_delayed_status ) ;
 mysql_mutex_destroy ( & LOCK_delayed_create ) ;
 mysql_mutex_destroy ( & LOCK_crypt ) ;
 mysql_mutex_destroy ( & LOCK_user_conn ) ;
 mysql_mutex_destroy ( & LOCK_connection_count ) ;
 mysql_mutex_destroy ( & LOCK_stats ) ;
 mysql_mutex_destroy ( & LOCK_global_user_client_stats ) ;
 mysql_mutex_destroy ( & LOCK_global_table_stats ) ;
 mysql_mutex_destroy ( & LOCK_global_index_stats ) ;
 # ifdef HAVE_OPENSSL mysql_mutex_destroy ( & LOCK_des_key_file ) ;
 # ifndef HAVE_YASSL for ( int i = 0 ;
 i < CRYPTO_num_locks ( ) ;
 ++ i ) mysql_rwlock_destroy ( & openssl_stdlocks [ i ] . lock ) ;
 OPENSSL_free ( openssl_stdlocks ) ;
 # endif # endif # ifdef HAVE_REPLICATION mysql_mutex_destroy ( & LOCK_rpl_status ) ;
 mysql_cond_destroy ( & COND_rpl_status ) ;
 # endif mysql_mutex_destroy ( & LOCK_active_mi ) ;
 mysql_rwlock_destroy ( & LOCK_sys_init_connect ) ;
 mysql_rwlock_destroy ( & LOCK_sys_init_slave ) ;
 mysql_mutex_destroy ( & LOCK_global_system_variables ) ;
 mysql_rwlock_destroy ( & LOCK_system_variables_hash ) ;
 mysql_mutex_destroy ( & LOCK_short_uuid_generator ) ;
 mysql_mutex_destroy ( & LOCK_prepared_stmt_count ) ;
 mysql_mutex_destroy ( & LOCK_error_messages ) ;
 mysql_cond_destroy ( & COND_thread_count ) ;
 mysql_cond_destroy ( & COND_thread_cache ) ;
 mysql_cond_destroy ( & COND_flush_thread_cache ) ;
 mysql_mutex_destroy ( & LOCK_server_started ) ;
 mysql_cond_destroy ( & COND_server_started ) ;
 mysql_mutex_destroy ( & LOCK_prepare_ordered ) ;
 mysql_mutex_destroy ( & LOCK_commit_ordered ) ;
 DBUG_VOID_RETURN ;
 }
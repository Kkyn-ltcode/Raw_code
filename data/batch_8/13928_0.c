int mysqld_main ( int argc , char * * argv ) # endif {
 my_progname = argv [ 0 ] ;
 sf_leaking_memory = 1 ;
 # ifdef HAVE_NPTL ld_assume_kernel_is_set = ( getenv ( "LD_ASSUME_KERNEL" ) != 0 ) ;
 # endif # ifndef _WIN32 if ( my_init ( ) ) {
 fprintf ( stderr , "my_init() failed." ) ;
 return 1 ;
 }
 # endif orig_argc = argc ;
 orig_argv = argv ;
 my_getopt_use_args_separator = TRUE ;
 if ( load_defaults ( MYSQL_CONFIG_NAME , load_default_groups , & argc , & argv ) ) return 1 ;
 my_getopt_use_args_separator = FALSE ;
 defaults_argc = argc ;
 defaults_argv = argv ;
 remaining_argc = argc ;
 remaining_argv = argv ;
 system_charset_info = & my_charset_utf8_general_ci ;
 init_sql_statement_names ( ) ;
 sys_var_init ( ) ;
 # ifdef WITH_PERFSCHEMA_STORAGE_ENGINE int ho_error ;
 DYNAMIC_ARRAY all_early_options ;
 my_getopt_register_get_addr ( NULL ) ;
 my_getopt_skip_unknown = TRUE ;
 my_init_dynamic_array ( & all_early_options , sizeof ( my_option ) , 100 , 25 ) ;
 sys_var_add_options ( & all_early_options , sys_var : : PARSE_EARLY ) ;
 add_terminator ( & all_early_options ) ;
 buffered_logs . init ( ) ;
 my_getopt_error_reporter = buffered_option_error_reporter ;
 ho_error = handle_options ( & remaining_argc , & remaining_argv , ( my_option * ) ( all_early_options . buffer ) , NULL ) ;
 delete_dynamic ( & all_early_options ) ;
 if ( ho_error == 0 ) {
 remaining_argc ++ ;
 remaining_argv -- ;
 if ( pfs_param . m_enabled ) {
 PSI_hook = initialize_performance_schema ( & pfs_param ) ;
 if ( PSI_hook == NULL ) {
 pfs_param . m_enabled = false ;
 buffered_logs . buffer ( WARNING_LEVEL , "Performance schema disabled (reason: init failed)." ) ;
 }
 }
 }
 # else # endif # ifdef HAVE_PSI_INTERFACE if ( PSI_hook ) PSI_server = ( PSI * ) PSI_hook -> get_interface ( PSI_CURRENT_VERSION ) ;
 if ( PSI_server ) {
 init_server_psi_keys ( ) ;
 PSI_thread * psi = PSI_server -> new_thread ( key_thread_main , NULL , 0 ) ;
 if ( psi ) PSI_server -> set_thread ( psi ) ;
 my_thread_global_reinit ( ) ;
 }
 # endif init_error_log_mutex ( ) ;
 mysql_audit_initialize ( ) ;
 logger . init_base ( ) ;
 # ifdef WITH_PERFSCHEMA_STORAGE_ENGINE if ( ho_error ) {
 buffered_logs . print ( ) ;
 buffered_logs . cleanup ( ) ;
 exit ( ho_error ) ;
 }
 # endif # ifdef _CUSTOMSTARTUPCONFIG_ if ( _cust_check_startup ( ) ) {
 / * _cust_check_startup will report startup failure error * / exit ( 1 ) ;
 }
 # endif if ( init_common_variables ( ) ) unireg_abort ( 1 ) ;
 init_signals ( ) ;
 my_thread_stack_size = my_setstacksize ( & connection_attrib , my_thread_stack_size ) ;
 ( void ) thr_setconcurrency ( concurrency ) ;
 select_thread = pthread_self ( ) ;
 select_thread_in_use = 1 ;
 # ifdef HAVE_LIBWRAP libwrapName = my_progname + dirname_length ( my_progname ) ;
 openlog ( libwrapName , LOG_PID , LOG_AUTH ) ;
 # endif # ifndef DBUG_OFF test_lc_time_sz ( ) ;
 srand ( ( uint ) time ( NULL ) ) ;
 # endif check_data_home ( mysql_real_data_home ) ;
 if ( my_setwd ( mysql_real_data_home , opt_abort ? 0 : MYF ( MY_WME ) ) && ! opt_abort ) unireg_abort ( 1 ) ;
 if ( ( user_info = check_user ( mysqld_user ) ) ) {
 # if defined ( HAVE_MLOCKALL ) && defined ( MCL_CURRENT ) if ( locked_in_memory ) set_effective_user ( user_info ) ;
 else # endif set_user ( mysqld_user , user_info ) ;
 }
 if ( opt_bin_log && ! server_id ) {
 server_id = 1 ;
 # ifdef EXTRA_DEBUG sql_print_warning ( "You have enabled the binary log, but you haven't set " "server-id to a non-zero value: we force server id to 1;
 " "updates will be logged to the binary log, but " "connections from slaves will not be accepted." ) ;
 # endif }
 # if defined ( _WIN32 ) && ! defined ( EMBEDDED_LIBRARY ) Service . SetSlowStarting ( slow_start_timeout ) ;
 # endif if ( init_server_components ( ) ) unireg_abort ( 1 ) ;
 init_ssl ( ) ;
 network_init ( ) ;
 # ifdef __WIN__ if ( ! opt_console ) {
 if ( reopen_fstreams ( log_error_file , stdout , stderr ) ) unireg_abort ( 1 ) ;
 setbuf ( stderr , NULL ) ;
 FreeConsole ( ) ;
 }
 # endif my_str_malloc = & my_str_malloc_mysqld ;
 my_str_free = & my_str_free_mysqld ;
 start_signal_handler ( ) ;
 if ( mysql_rm_tmp_tables ( ) || acl_init ( opt_noacl ) || my_tz_init ( ( THD * ) 0 , default_tz_name , opt_bootstrap ) ) {
 abort_loop = 1 ;
 select_thread_in_use = 0 ;
 ( void ) pthread_kill ( signal_thread , MYSQL_KILL_SIGNAL ) ;
 delete_pid_file ( MYF ( MY_WME ) ) ;
 if ( unix_sock != INVALID_SOCKET ) unlink ( mysqld_unix_port ) ;
 exit ( 1 ) ;
 }
 if ( ! opt_noacl ) ( void ) grant_init ( ) ;
 if ( ! opt_bootstrap ) servers_init ( 0 ) ;
 udf_init ( ) ;
 init_status_vars ( ) ;
 if ( opt_bootstrap ) opt_skip_slave_start = 1 ;
 binlog_unsafe_map_init ( ) ;
 if ( init_slave ( ) && ! active_mi ) {
 unireg_abort ( 1 ) ;
 }
 # ifdef WITH_PERFSCHEMA_STORAGE_ENGINE initialize_performance_schema_acl ( opt_bootstrap ) ;
 if ( ! opt_bootstrap ) check_performance_schema ( ) ;
 # endif initialize_information_schema_acl ( ) ;
 execute_ddl_log_recovery ( ) ;
 if ( Events : : init ( opt_noacl || opt_bootstrap ) ) unireg_abort ( 1 ) ;
 if ( opt_bootstrap ) {
 select_thread_in_use = 0 ;
 bootstrap ( mysql_stdin ) ;
 if ( ! kill_in_progress ) unireg_abort ( bootstrap_error ? 1 : 0 ) ;
 else {
 sleep ( 2 ) ;
 exit ( 0 ) ;
 }
 }
 if ( opt_init_file && * opt_init_file ) {
 if ( read_init_file ( opt_init_file ) ) unireg_abort ( 1 ) ;
 }
 create_shutdown_thread ( ) ;
 start_handle_manager ( ) ;
 sql_print_information ( ER_DEFAULT ( ER_STARTUP ) , my_progname , server_version , ( ( unix_sock == INVALID_SOCKET ) ? ( char * ) "" : mysqld_unix_port ) , mysqld_port , MYSQL_COMPILATION_COMMENT ) ;
 # if defined ( _WIN32 ) && ! defined ( EMBEDDED_LIBRARY ) Service . SetRunning ( ) ;
 # endif mysql_mutex_lock ( & LOCK_server_started ) ;
 mysqld_server_started = 1 ;
 mysql_cond_signal ( & COND_server_started ) ;
 mysql_mutex_unlock ( & LOCK_server_started ) ;
 # if defined ( _WIN32 ) || defined ( HAVE_SMEM ) handle_connections_methods ( ) ;
 # else handle_connections_sockets ( ) ;
 # endif DBUG_PRINT ( "quit" , ( "Exiting main thread" ) ) ;
 # ifndef __WIN__ # ifdef EXTRA_DEBUG2 sql_print_error ( "Before Lock_thread_count" ) ;
 # endif mysql_mutex_lock ( & LOCK_thread_count ) ;
 DBUG_PRINT ( "quit" , ( "Got thread_count mutex" ) ) ;
 select_thread_in_use = 0 ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 mysql_cond_broadcast ( & COND_thread_count ) ;
 # ifdef EXTRA_DEBUG2 sql_print_error ( "After lock_thread_count" ) ;
 # endif # endif # ifdef HAVE_PSI_INTERFACE if ( PSI_server ) PSI_server -> delete_current_thread ( ) ;
 # endif mysql_mutex_lock ( & LOCK_thread_count ) ;
 while ( ! ready_to_exit ) mysql_cond_wait ( & COND_thread_count , & LOCK_thread_count ) ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 # if defined ( __WIN__ ) && ! defined ( EMBEDDED_LIBRARY ) if ( Service . IsNT ( ) && start_mode ) Service . Stop ( ) ;
 else {
 Service . SetShutdownEvent ( 0 ) ;
 if ( hEventShutdown ) CloseHandle ( hEventShutdown ) ;
 }
 # endif mysqld_exit ( 0 ) ;
 return 0 ;
 }
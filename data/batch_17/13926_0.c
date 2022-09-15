static void close_connections ( void ) {
 # ifdef EXTRA_DEBUG int count = 0 ;
 # endif DBUG_ENTER ( "close_connections" ) ;
 kill_cached_threads ++ ;
 flush_thread_cache ( ) ;
 # if ! defined ( __WIN__ ) DBUG_PRINT ( "quit" , ( "waiting for select thread: 0x%lx" , ( ulong ) select_thread ) ) ;
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 while ( select_thread_in_use ) {
 struct timespec abstime ;
 int error ;
 LINT_INIT ( error ) ;
 DBUG_PRINT ( "info" , ( "Waiting for select thread" ) ) ;
 # ifndef DONT_USE_THR_ALARM if ( pthread_kill ( select_thread , thr_client_alarm ) ) break ;
 # endif set_timespec ( abstime , 2 ) ;
 for ( uint tmp = 0 ;
 tmp < 10 && select_thread_in_use ;
 tmp ++ ) {
 error = mysql_cond_timedwait ( & COND_thread_count , & LOCK_thread_count , & abstime ) ;
 if ( error != EINTR ) break ;
 }
 # ifdef EXTRA_DEBUG if ( error != 0 && error != ETIMEDOUT && ! count ++ ) sql_print_error ( "Got error %d from mysql_cond_timedwait" , error ) ;
 # endif close_server_sock ( ) ;
 }
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 # endif DBUG_PRINT ( "quit" , ( "Closing sockets" ) ) ;
 if ( ! opt_disable_networking ) {
 if ( base_ip_sock != INVALID_SOCKET ) {
 ( void ) mysql_socket_shutdown ( base_ip_sock , SHUT_RDWR ) ;
 ( void ) closesocket ( base_ip_sock ) ;
 base_ip_sock = INVALID_SOCKET ;
 }
 if ( extra_ip_sock != INVALID_SOCKET ) {
 ( void ) mysql_socket_shutdown ( extra_ip_sock , SHUT_RDWR ) ;
 ( void ) closesocket ( extra_ip_sock ) ;
 extra_ip_sock = INVALID_SOCKET ;
 }
 }
 # ifdef _WIN32 if ( hPipe != INVALID_HANDLE_VALUE && opt_enable_named_pipe ) {
 HANDLE temp ;
 DBUG_PRINT ( "quit" , ( "Closing named pipes" ) ) ;
 if ( ( temp = CreateFile ( pipe_name , GENERIC_READ | GENERIC_WRITE , 0 , NULL , OPEN_EXISTING , 0 , NULL ) ) != INVALID_HANDLE_VALUE ) {
 WaitNamedPipe ( pipe_name , 1000 ) ;
 DWORD dwMode = PIPE_READMODE_BYTE | PIPE_WAIT ;
 SetNamedPipeHandleState ( temp , & dwMode , NULL , NULL ) ;
 CancelIo ( temp ) ;
 DisconnectNamedPipe ( temp ) ;
 CloseHandle ( temp ) ;
 }
 }
 # endif # ifdef HAVE_SYS_UN_H if ( unix_sock != INVALID_SOCKET ) {
 ( void ) mysql_socket_shutdown ( unix_sock , SHUT_RDWR ) ;
 ( void ) closesocket ( unix_sock ) ;
 ( void ) unlink ( mysqld_unix_port ) ;
 unix_sock = INVALID_SOCKET ;
 }
 # endif end_thr_alarm ( 0 ) ;
 THD * tmp ;
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 I_List_iterator < THD > it ( threads ) ;
 while ( ( tmp = it ++ ) ) {
 DBUG_PRINT ( "quit" , ( "Informing thread %ld that it's time to die" , tmp -> thread_id ) ) ;
 if ( tmp -> slave_thread ) continue ;
 tmp -> killed = KILL_SERVER_HARD ;
 MYSQL_CALLBACK ( thread_scheduler , post_kill_notification , ( tmp ) ) ;
 mysql_mutex_lock ( & tmp -> LOCK_thd_data ) ;
 if ( tmp -> mysys_var ) {
 tmp -> mysys_var -> abort = 1 ;
 mysql_mutex_lock ( & tmp -> mysys_var -> mutex ) ;
 if ( tmp -> mysys_var -> current_cond ) {
 uint i ;
 for ( i = 0 ;
 i < 2 ;
 i ++ ) {
 int ret = mysql_mutex_trylock ( tmp -> mysys_var -> current_mutex ) ;
 mysql_cond_broadcast ( tmp -> mysys_var -> current_cond ) ;
 if ( ! ret ) {
 mysql_mutex_unlock ( tmp -> mysys_var -> current_mutex ) ;
 break ;
 }
 sleep ( 1 ) ;
 }
 }
 mysql_mutex_unlock ( & tmp -> mysys_var -> mutex ) ;
 }
 mysql_mutex_unlock ( & tmp -> LOCK_thd_data ) ;
 }
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 Events : : deinit ( ) ;
 end_slave ( ) ;
 for ( int i = 0 ;
 thread_count && i < 100 ;
 i ++ ) my_sleep ( 20000 ) ;
 for ( ;
 ;
 ) {
 DBUG_PRINT ( "quit" , ( "Locking LOCK_thread_count" ) ) ;
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 if ( ! ( tmp = threads . get ( ) ) ) {
 DBUG_PRINT ( "quit" , ( "Unlocking LOCK_thread_count" ) ) ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 break ;
 }
 # ifndef __bsdi__ if ( tmp -> vio_ok ( ) ) {
 if ( global_system_variables . log_warnings ) sql_print_warning ( ER_DEFAULT ( ER_FORCING_CLOSE ) , my_progname , tmp -> thread_id , ( tmp -> main_security_ctx . user ? tmp -> main_security_ctx . user : "" ) ) ;
 close_connection ( tmp , ER_SERVER_SHUTDOWN ) ;
 }
 # endif DBUG_PRINT ( "quit" , ( "Unlocking LOCK_thread_count" ) ) ;
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 }
 DBUG_PRINT ( "quit" , ( "Waiting for threads to die (count=%u)" , thread_count ) ) ;
 mysql_mutex_lock ( & LOCK_thread_count ) ;
 while ( thread_count ) {
 mysql_cond_wait ( & COND_thread_count , & LOCK_thread_count ) ;
 DBUG_PRINT ( "quit" , ( "One thread died (count=%u)" , thread_count ) ) ;
 }
 mysql_mutex_unlock ( & LOCK_thread_count ) ;
 DBUG_PRINT ( "quit" , ( "close_connections thread" ) ) ;
 DBUG_VOID_RETURN ;
 }
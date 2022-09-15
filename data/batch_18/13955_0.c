void kill_mysql ( void ) {
 DBUG_ENTER ( "kill_mysql" ) ;
 # if defined ( SIGNALS_DONT_BREAK_READ ) && ! defined ( EMBEDDED_LIBRARY ) abort_loop = 1 ;
 close_server_sock ( ) ;
 # endif # if defined ( __WIN__ ) # if ! defined ( EMBEDDED_LIBRARY ) {
 if ( ! SetEvent ( hEventShutdown ) ) {
 DBUG_PRINT ( "error" , ( "Got error: %ld from SetEvent" , GetLastError ( ) ) ) ;
 }
 }
 # endif # elif defined ( HAVE_PTHREAD_KILL ) if ( pthread_kill ( signal_thread , MYSQL_KILL_SIGNAL ) ) {
 DBUG_PRINT ( "error" , ( "Got error %d from pthread_kill" , errno ) ) ;
 }
 # elif ! defined ( SIGNALS_DONT_BREAK_READ ) kill ( current_pid , MYSQL_KILL_SIGNAL ) ;
 # endif DBUG_PRINT ( "quit" , ( "After pthread_kill" ) ) ;
 shutdown_in_progress = 1 ;
 # ifdef SIGNALS_DONT_BREAK_READ if ( ! kill_in_progress ) {
 pthread_t tmp ;
 int error ;
 abort_loop = 1 ;
 if ( ( error = mysql_thread_create ( 0 , & tmp , & connection_attrib , kill_server_thread , ( void * ) 0 ) ) ) sql_print_error ( "Can't create thread to kill server (errno= %d)." , error ) ;
 }
 # endif DBUG_VOID_RETURN ;
 }
static void init_signals ( void ) {
 sigset_t set ;
 struct sigaction sa ;
 DBUG_ENTER ( "init_signals" ) ;
 my_sigset ( THR_SERVER_ALARM , print_signal_warning ) ;
 if ( opt_stack_trace || ( test_flags & TEST_CORE_ON_SIGNAL ) ) {
 sa . sa_flags = SA_RESETHAND | SA_NODEFER ;
 sigemptyset ( & sa . sa_mask ) ;
 sigprocmask ( SIG_SETMASK , & sa . sa_mask , NULL ) ;
 my_init_stacktrace ( ) ;
 # if defined ( __amiga__ ) sa . sa_handler = ( void ( * ) ( ) ) handle_fatal_signal ;
 # else sa . sa_handler = handle_fatal_signal ;
 # endif sigaction ( SIGSEGV , & sa , NULL ) ;
 sigaction ( SIGABRT , & sa , NULL ) ;
 # ifdef SIGBUS sigaction ( SIGBUS , & sa , NULL ) ;
 # endif sigaction ( SIGILL , & sa , NULL ) ;
 sigaction ( SIGFPE , & sa , NULL ) ;
 }
 # ifdef HAVE_GETRLIMIT if ( test_flags & TEST_CORE_ON_SIGNAL ) {
 STRUCT_RLIMIT rl ;
 rl . rlim_cur = rl . rlim_max = ( rlim_t ) RLIM_INFINITY ;
 if ( setrlimit ( RLIMIT_CORE , & rl ) && global_system_variables . log_warnings ) sql_print_warning ( "setrlimit could not change the size of core files to 'infinity';
 We may not be able to generate a core file on signals" ) ;
 }
 # endif ( void ) sigemptyset ( & set ) ;
 my_sigset ( SIGPIPE , SIG_IGN ) ;
 sigaddset ( & set , SIGPIPE ) ;
 # ifndef IGNORE_SIGHUP_SIGQUIT sigaddset ( & set , SIGQUIT ) ;
 sigaddset ( & set , SIGHUP ) ;
 # endif sigaddset ( & set , SIGTERM ) ;
 sigemptyset ( & sa . sa_mask ) ;
 sa . sa_flags = 0 ;
 sa . sa_handler = print_signal_warning ;
 sigaction ( SIGTERM , & sa , ( struct sigaction * ) 0 ) ;
 sa . sa_flags = 0 ;
 sa . sa_handler = print_signal_warning ;
 sigaction ( SIGHUP , & sa , ( struct sigaction * ) 0 ) ;
 if ( thd_lib_detected != THD_LIB_LT ) sigaddset ( & set , THR_SERVER_ALARM ) ;
 if ( test_flags & TEST_SIGINT ) {
 my_sigset ( SIGINT , end_mysqld_signal ) ;
 sigdelset ( & set , SIGINT ) ;
 }
 else {
 sigaddset ( & set , SIGINT ) ;
 # ifdef SIGTSTP sigaddset ( & set , SIGTSTP ) ;
 # endif }
 sigprocmask ( SIG_SETMASK , & set , NULL ) ;
 pthread_sigmask ( SIG_SETMASK , & set , NULL ) ;
 DBUG_VOID_RETURN ;
 }
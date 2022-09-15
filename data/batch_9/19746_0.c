static void test_signal_restore ( void ) {
 struct event ev ;
 struct event_base * base = event_init ( ) ;
 # ifdef HAVE_SIGACTION struct sigaction sa ;
 # endif test_ok = 0 ;
 printf ( "Signal handler restore: " ) ;
 # ifdef HAVE_SIGACTION sa . sa_handler = signal_cb_sa ;
 sa . sa_flags = 0x0 ;
 sigemptyset ( & sa . sa_mask ) ;
 if ( sigaction ( SIGUSR1 , & sa , NULL ) == - 1 ) goto out ;
 # else if ( signal ( SIGUSR1 , signal_cb_sa ) == SIG_ERR ) goto out ;
 # endif signal_set ( & ev , SIGUSR1 , signal_cb , & ev ) ;
 signal_add ( & ev , NULL ) ;
 signal_del ( & ev ) ;
 raise ( SIGUSR1 ) ;
 if ( test_ok != 2 ) test_ok = 0 ;
 out : event_base_free ( base ) ;
 cleanup_test ( ) ;
 return ;
 }
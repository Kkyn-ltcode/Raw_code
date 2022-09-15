static void evsignal_handler ( int sig ) {
 int save_errno = errno ;
 if ( evsignal_base == NULL ) {
 event_warn ( "%s: received signal %d, but have no base configured" , __func__ , sig ) ;
 return ;
 }
 evsignal_base -> sig . evsigcaught [ sig ] ++ ;
 evsignal_base -> sig . evsignal_caught = 1 ;
 # ifndef HAVE_SIGACTION signal ( sig , evsignal_handler ) ;
 # endif send ( evsignal_base -> sig . ev_signal_pair [ 0 ] , "a" , 1 , 0 ) ;
 errno = save_errno ;
 }
int _evsignal_restore_handler ( struct event_base * base , int evsignal ) {
 int ret = 0 ;
 struct evsignal_info * sig = & base -> sig ;
 # ifdef HAVE_SIGACTION struct sigaction * sh ;
 # else ev_sighandler_t * sh ;
 # endif sh = sig -> sh_old [ evsignal ] ;
 sig -> sh_old [ evsignal ] = NULL ;
 # ifdef HAVE_SIGACTION if ( sigaction ( evsignal , sh , NULL ) == - 1 ) {
 event_warn ( "sigaction" ) ;
 ret = - 1 ;
 }
 # else if ( signal ( evsignal , * sh ) == SIG_ERR ) {
 event_warn ( "signal" ) ;
 ret = - 1 ;
 }
 # endif free ( sh ) ;
 return ret ;
 }
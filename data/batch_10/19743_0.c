static int evport_dispatch ( struct event_base * base , void * arg , struct timeval * tv ) {
 int i , res ;
 struct evport_data * epdp = arg ;
 port_event_t pevtlist [ EVENTS_PER_GETN ] ;
 int nevents = 1 ;
 struct timespec ts ;
 struct timespec * ts_p = NULL ;
 if ( tv != NULL ) {
 ts . tv_sec = tv -> tv_sec ;
 ts . tv_nsec = tv -> tv_usec * 1000 ;
 ts_p = & ts ;
 }
 for ( i = 0 ;
 i < EVENTS_PER_GETN ;
 ++ i ) {
 struct fd_info * fdi = NULL ;
 if ( epdp -> ed_pending [ i ] != - 1 ) {
 fdi = & ( epdp -> ed_fds [ epdp -> ed_pending [ i ] ] ) ;
 }
 if ( fdi != NULL && FDI_HAS_EVENTS ( fdi ) ) {
 int fd = FDI_HAS_READ ( fdi ) ? fdi -> fdi_revt -> ev_fd : fdi -> fdi_wevt -> ev_fd ;
 reassociate ( epdp , fdi , fd ) ;
 epdp -> ed_pending [ i ] = - 1 ;
 }
 }
 if ( ( res = port_getn ( epdp -> ed_port , pevtlist , EVENTS_PER_GETN , ( unsigned int * ) & nevents , ts_p ) ) == - 1 ) {
 if ( errno == EINTR || errno == EAGAIN ) {
 evsignal_process ( base ) ;
 return ( 0 ) ;
 }
 else if ( errno == ETIME ) {
 if ( nevents == 0 ) return ( 0 ) ;
 }
 else {
 event_warn ( "port_getn" ) ;
 return ( - 1 ) ;
 }
 }
 else if ( base -> sig . evsignal_caught ) {
 evsignal_process ( base ) ;
 }
 event_debug ( ( "%s: port_getn reports %d events" , __func__ , nevents ) ) ;
 for ( i = 0 ;
 i < nevents ;
 ++ i ) {
 struct event * ev ;
 struct fd_info * fdi ;
 port_event_t * pevt = & pevtlist [ i ] ;
 int fd = ( int ) pevt -> portev_object ;
 check_evportop ( epdp ) ;
 check_event ( pevt ) ;
 epdp -> ed_pending [ i ] = fd ;
 res = 0 ;
 if ( pevt -> portev_events & POLLIN ) res |= EV_READ ;
 if ( pevt -> portev_events & POLLOUT ) res |= EV_WRITE ;
 if ( pevt -> portev_events & ( POLLERR | POLLHUP | POLLNVAL ) ) res |= EV_READ | EV_WRITE ;
 assert ( epdp -> ed_nevents > fd ) ;
 fdi = & ( epdp -> ed_fds [ fd ] ) ;
 if ( ( res & EV_READ ) && ( ( ev = fdi -> fdi_revt ) != NULL ) ) {
 event_active ( ev , res , 1 ) ;
 }
 if ( ( res & EV_WRITE ) && ( ( ev = fdi -> fdi_wevt ) != NULL ) ) {
 event_active ( ev , res , 1 ) ;
 }
 }
 check_evportop ( epdp ) ;
 return ( 0 ) ;
 }
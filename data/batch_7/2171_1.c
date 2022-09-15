int evutil_make_socket_nonblocking ( int fd ) {
 # ifdef WIN32 {
 unsigned long nonblocking = 1 ;
 ioctlsocket ( fd , FIONBIO , ( unsigned long * ) & nonblocking ) ;
 }
 # else if ( fcntl ( fd , F_SETFL , O_NONBLOCK ) == - 1 ) {
 event_warn ( "fcntl(O_NONBLOCK)" ) ;
 return - 1 ;
 }
 # endif return 0 ;
 }
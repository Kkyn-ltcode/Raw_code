int evutil_make_socket_nonblocking ( int fd ) {
 # ifdef WIN32 {
 unsigned long nonblocking = 1 ;
 ioctlsocket ( fd , FIONBIO , ( unsigned long * ) & nonblocking ) ;
 }
 # else {
 int flags ;
 if ( ( flags = fcntl ( fd , F_GETFL , NULL ) ) < 0 ) {
 event_warn ( "fcntl(%d, F_GETFL)" , fd ) ;
 return - 1 ;
 }
 if ( fcntl ( fd , F_SETFL , flags | O_NONBLOCK ) == - 1 ) {
 event_warn ( "fcntl(%d, F_SETFL)" , fd ) ;
 return - 1 ;
 }
 }
 # endif return 0 ;
 }
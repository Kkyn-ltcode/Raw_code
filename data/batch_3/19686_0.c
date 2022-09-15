static void evsignal_cb ( int fd , short what , void * arg ) {
 static char signals [ 1 ] ;
 # ifdef WIN32 SSIZE_T n ;
 # else ssize_t n ;
 # endif n = recv ( fd , signals , sizeof ( signals ) , 0 ) ;
 if ( n == - 1 ) {
 int err = EVUTIL_SOCKET_ERROR ( ) ;
 if ( ! error_is_eagain ( err ) ) event_err ( 1 , "%s: read" , __func__ ) ;
 }
 }
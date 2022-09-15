static int select_loop ( int maxFd , fd_set * workerset , bool * aborting ) {
 int i ;
 fd_set saveSet = * workerset ;
 if ( CancelRequested ) {
 * aborting = true ;
 return - 1 ;
 }
 else * aborting = false ;
 for ( ;
 ;
 ) {
 struct timeval * tvp ;
 # ifdef WIN32 struct timeval tv = {
 0 , 1000000 }
 ;
 tvp = & tv ;
 # else tvp = NULL ;
 # endif * workerset = saveSet ;
 i = select ( maxFd + 1 , workerset , NULL , NULL , tvp ) ;
 # ifdef WIN32 if ( i == SOCKET_ERROR ) {
 i = - 1 ;
 if ( WSAGetLastError ( ) == WSAEINTR ) errno = EINTR ;
 }
 # endif if ( i < 0 && errno == EINTR ) continue ;
 if ( i < 0 || CancelRequested ) * aborting = true ;
 if ( i == 0 ) continue ;
 break ;
 }
 return i ;
 }
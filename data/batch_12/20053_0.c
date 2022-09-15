static int socket_connect ( int fd , const char * address , unsigned short port ) {
 struct addrinfo * ai = make_addrinfo ( address , port ) ;
 int res = - 1 ;
 if ( ai == NULL ) {
 event_debug ( ( "%s: make_addrinfo: \"%s:%d\"" , __func__ , address , port ) ) ;
 return ( - 1 ) ;
 }
 if ( connect ( fd , ai -> ai_addr , ai -> ai_addrlen ) == - 1 ) {
 # ifdef WIN32 int tmp_error = WSAGetLastError ( ) ;
 if ( tmp_error != WSAEWOULDBLOCK && tmp_error != WSAEINVAL && tmp_error != WSAEINPROGRESS ) {
 goto out ;
 }
 # else if ( errno != EINPROGRESS ) {
 goto out ;
 }
 # endif }
 res = 0 ;
 out : # ifdef HAVE_GETADDRINFO freeaddrinfo ( ai ) ;
 # else fake_freeaddrinfo ( ai ) ;
 # endif return ( res ) ;
 }
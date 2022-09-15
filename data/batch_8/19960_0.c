static int http_connect ( const char * address , u_short port ) {
 # ifdef WIN32 struct hostent * he ;
 struct sockaddr_in sin ;
 # else struct addrinfo ai , * aitop ;
 char strport [ NI_MAXSERV ] ;
 # endif struct sockaddr * sa ;
 int slen ;
 int fd ;
 # ifdef WIN32 if ( ! ( he = gethostbyname ( address ) ) ) {
 event_warn ( "gethostbyname" ) ;
 }
 memcpy ( & sin . sin_addr , he -> h_addr_list [ 0 ] , he -> h_length ) ;
 sin . sin_family = AF_INET ;
 sin . sin_port = htons ( port ) ;
 slen = sizeof ( struct sockaddr_in ) ;
 sa = ( struct sockaddr * ) & sin ;
 # else memset ( & ai , 0 , sizeof ( ai ) ) ;
 ai . ai_family = AF_INET ;
 ai . ai_socktype = SOCK_STREAM ;
 snprintf ( strport , sizeof ( strport ) , "%d" , port ) ;
 if ( getaddrinfo ( address , strport , & ai , & aitop ) != 0 ) {
 event_warn ( "getaddrinfo" ) ;
 return ( - 1 ) ;
 }
 sa = aitop -> ai_addr ;
 slen = aitop -> ai_addrlen ;
 # endif fd = socket ( AF_INET , SOCK_STREAM , 0 ) ;
 if ( fd == - 1 ) event_err ( 1 , "socket failed" ) ;
 if ( connect ( fd , sa , slen ) == - 1 ) event_err ( 1 , "connect failed" ) ;
 # ifndef WIN32 freeaddrinfo ( aitop ) ;
 # endif return ( fd ) ;
 }
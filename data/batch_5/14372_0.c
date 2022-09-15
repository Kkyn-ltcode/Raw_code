int setup_listen_socket ( const sockaddr_t * sa ) {
 int nfd ;
 char * addrstr ;
 int option ;
 char * iface ;
 nfd = socket ( sa -> sa . sa_family , SOCK_STREAM , IPPROTO_TCP ) ;
 if ( nfd < 0 ) {
 ifdebug ( STATUS ) logger ( LOG_ERR , "Creating metasocket failed: %s" , sockstrerror ( sockerrno ) ) ;
 return - 1 ;
 }
 # ifdef FD_CLOEXEC fcntl ( nfd , F_SETFD , FD_CLOEXEC ) ;
 # endif option = 1 ;
 setsockopt ( nfd , SOL_SOCKET , SO_REUSEADDR , ( void * ) & option , sizeof ( option ) ) ;
 # if defined ( IPV6_V6ONLY ) if ( sa -> sa . sa_family == AF_INET6 ) {
 setsockopt ( nfd , IPPROTO_IPV6 , IPV6_V6ONLY , ( void * ) & option , sizeof ( option ) ) ;
 }
 # else # warning IPV6_V6ONLY not defined # endif if ( get_config_string ( lookup_config ( config_tree , "BindToInterface" ) , & iface ) ) {
 # if defined ( SOL_SOCKET ) && defined ( SO_BINDTODEVICE ) struct ifreq ifr ;
 memset ( & ifr , 0 , sizeof ( ifr ) ) ;
 strncpy ( ifr . ifr_ifrn . ifrn_name , iface , IFNAMSIZ ) ;
 ifr . ifr_ifrn . ifrn_name [ IFNAMSIZ - 1 ] = 0 ;
 free ( iface ) ;
 if ( setsockopt ( nfd , SOL_SOCKET , SO_BINDTODEVICE , ( void * ) & ifr , sizeof ( ifr ) ) ) {
 closesocket ( nfd ) ;
 logger ( LOG_ERR , "Can't bind to interface %s: %s" , ifr . ifr_ifrn . ifrn_name , strerror ( sockerrno ) ) ;
 return - 1 ;
 }
 # else logger ( LOG_WARNING , "%s not supported on this platform" , "BindToInterface" ) ;
 # endif }
 if ( bind ( nfd , & sa -> sa , SALEN ( sa -> sa ) ) ) {
 closesocket ( nfd ) ;
 addrstr = sockaddr2hostname ( sa ) ;
 logger ( LOG_ERR , "Can't bind to %s/tcp: %s" , addrstr , sockstrerror ( sockerrno ) ) ;
 free ( addrstr ) ;
 return - 1 ;
 }
 if ( listen ( nfd , 3 ) ) {
 closesocket ( nfd ) ;
 logger ( LOG_ERR , "System call `%s' failed: %s" , "listen" , sockstrerror ( sockerrno ) ) ;
 return - 1 ;
 }
 return nfd ;
 }
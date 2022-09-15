int setup_vpn_in_socket ( const sockaddr_t * sa ) {
 int nfd ;
 char * addrstr ;
 int option ;
 nfd = socket ( sa -> sa . sa_family , SOCK_DGRAM , IPPROTO_UDP ) ;
 if ( nfd < 0 ) {
 logger ( LOG_ERR , "Creating UDP socket failed: %s" , sockstrerror ( sockerrno ) ) ;
 return - 1 ;
 }
 # ifdef FD_CLOEXEC fcntl ( nfd , F_SETFD , FD_CLOEXEC ) ;
 # endif # ifdef O_NONBLOCK {
 int flags = fcntl ( nfd , F_GETFL ) ;
 if ( fcntl ( nfd , F_SETFL , flags | O_NONBLOCK ) < 0 ) {
 closesocket ( nfd ) ;
 logger ( LOG_ERR , "System call `%s' failed: %s" , "fcntl" , strerror ( errno ) ) ;
 return - 1 ;
 }
 }
 # elif defined ( WIN32 ) {
 unsigned long arg = 1 ;
 if ( ioctlsocket ( nfd , FIONBIO , & arg ) != 0 ) {
 closesocket ( nfd ) ;
 logger ( LOG_ERR , "Call to `%s' failed: %s" , "ioctlsocket" , sockstrerror ( sockerrno ) ) ;
 return - 1 ;
 }
 }
 # endif option = 1 ;
 setsockopt ( nfd , SOL_SOCKET , SO_REUSEADDR , ( void * ) & option , sizeof ( option ) ) ;
 setsockopt ( nfd , SOL_SOCKET , SO_BROADCAST , ( void * ) & option , sizeof ( option ) ) ;
 if ( udp_rcvbuf && setsockopt ( nfd , SOL_SOCKET , SO_RCVBUF , ( void * ) & udp_rcvbuf , sizeof ( udp_rcvbuf ) ) ) {
 logger ( LOG_WARNING , "Can't set UDP SO_RCVBUF to %i: %s" , udp_rcvbuf , strerror ( errno ) ) ;
 }
 if ( udp_sndbuf && setsockopt ( nfd , SOL_SOCKET , SO_SNDBUF , ( void * ) & udp_sndbuf , sizeof ( udp_sndbuf ) ) ) {
 logger ( LOG_WARNING , "Can't set UDP SO_SNDBUF to %i: %s" , udp_sndbuf , strerror ( errno ) ) ;
 }
 # if defined ( IPV6_V6ONLY ) if ( sa -> sa . sa_family == AF_INET6 ) {
 setsockopt ( nfd , IPPROTO_IPV6 , IPV6_V6ONLY , ( void * ) & option , sizeof ( option ) ) ;
 }
 # endif # if defined ( IP_DONTFRAG ) && ! defined ( IP_DONTFRAGMENT ) # define IP_DONTFRAGMENT IP_DONTFRAG # endif # if defined ( IP_MTU_DISCOVER ) && defined ( IP_PMTUDISC_DO ) if ( myself -> options & OPTION_PMTU_DISCOVERY ) {
 option = IP_PMTUDISC_DO ;
 setsockopt ( nfd , IPPROTO_IP , IP_MTU_DISCOVER , ( void * ) & option , sizeof ( option ) ) ;
 }
 # elif defined ( IP_DONTFRAGMENT ) if ( myself -> options & OPTION_PMTU_DISCOVERY ) {
 option = 1 ;
 setsockopt ( nfd , IPPROTO_IP , IP_DONTFRAGMENT , ( void * ) & option , sizeof ( option ) ) ;
 }
 # endif # if defined ( IPV6_MTU_DISCOVER ) && defined ( IPV6_PMTUDISC_DO ) if ( myself -> options & OPTION_PMTU_DISCOVERY ) {
 option = IPV6_PMTUDISC_DO ;
 setsockopt ( nfd , IPPROTO_IPV6 , IPV6_MTU_DISCOVER , ( void * ) & option , sizeof ( option ) ) ;
 }
 # elif defined ( IPV6_DONTFRAG ) if ( myself -> options & OPTION_PMTU_DISCOVERY ) {
 option = 1 ;
 setsockopt ( nfd , IPPROTO_IPV6 , IPV6_DONTFRAG , ( void * ) & option , sizeof ( option ) ) ;
 }
 # endif if ( ! bind_to_interface ( nfd ) ) {
 closesocket ( nfd ) ;
 return - 1 ;
 }
 if ( bind ( nfd , & sa -> sa , SALEN ( sa -> sa ) ) ) {
 closesocket ( nfd ) ;
 addrstr = sockaddr2hostname ( sa ) ;
 logger ( LOG_ERR , "Can't bind to %s/udp: %s" , addrstr , sockstrerror ( sockerrno ) ) ;
 free ( addrstr ) ;
 return - 1 ;
 }
 return nfd ;
 }
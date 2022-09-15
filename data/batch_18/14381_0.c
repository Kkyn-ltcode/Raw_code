static void configure_tcp ( connection_t * c ) {
 int option ;
 # ifdef O_NONBLOCK int flags = fcntl ( c -> socket , F_GETFL ) ;
 if ( fcntl ( c -> socket , F_SETFL , flags | O_NONBLOCK ) < 0 ) {
 logger ( LOG_ERR , "fcntl for %s: %s" , c -> hostname , strerror ( errno ) ) ;
 }
 # elif defined ( WIN32 ) unsigned long arg = 1 ;
 if ( ioctlsocket ( c -> socket , FIONBIO , & arg ) != 0 ) {
 logger ( LOG_ERR , "ioctlsocket for %s: %s" , c -> hostname , sockstrerror ( sockerrno ) ) ;
 }
 # endif # if defined ( SOL_TCP ) && defined ( TCP_NODELAY ) option = 1 ;
 setsockopt ( c -> socket , SOL_TCP , TCP_NODELAY , ( void * ) & option , sizeof ( option ) ) ;
 # endif # if defined ( IP_TOS ) && defined ( IPTOS_LOWDELAY ) option = IPTOS_LOWDELAY ;
 setsockopt ( c -> socket , IPPROTO_IP , IP_TOS , ( void * ) & option , sizeof ( option ) ) ;
 # endif # if defined ( IPV6_TCLASS ) && defined ( IPTOS_LOWDELAY ) option = IPTOS_LOWDELAY ;
 setsockopt ( c -> socket , IPPROTO_IPV6 , IPV6_TCLASS , ( void * ) & option , sizeof ( option ) ) ;
 # endif }
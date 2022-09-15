static bool bind_to_interface ( int sd ) {
 char * iface ;
 # if defined ( SOL_SOCKET ) && defined ( SO_BINDTODEVICE ) struct ifreq ifr ;
 int status ;
 # endif if ( ! get_config_string ( lookup_config ( config_tree , "BindToInterface" ) , & iface ) ) {
 return true ;
 }
 # if defined ( SOL_SOCKET ) && defined ( SO_BINDTODEVICE ) memset ( & ifr , 0 , sizeof ( ifr ) ) ;
 strncpy ( ifr . ifr_ifrn . ifrn_name , iface , IFNAMSIZ ) ;
 ifr . ifr_ifrn . ifrn_name [ IFNAMSIZ - 1 ] = 0 ;
 free ( iface ) ;
 status = setsockopt ( sd , SOL_SOCKET , SO_BINDTODEVICE , ( void * ) & ifr , sizeof ( ifr ) ) ;
 if ( status ) {
 logger ( LOG_ERR , "Can't bind to interface %s: %s" , ifr . ifr_ifrn . ifrn_name , strerror ( errno ) ) ;
 return false ;
 }
 # else logger ( LOG_WARNING , "%s not supported on this platform" , "BindToInterface" ) ;
 # endif return true ;
 }
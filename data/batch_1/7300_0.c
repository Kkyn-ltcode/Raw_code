static void nbd_client_closed ( NBDClient * client , bool negotiated ) {
 nb_fds -- ;
 if ( negotiated && nb_fds == 0 && ! persistent && state == RUNNING ) {
 state = TERMINATE ;
 }
 nbd_update_server_watch ( ) ;
 nbd_client_put ( client ) ;
 }
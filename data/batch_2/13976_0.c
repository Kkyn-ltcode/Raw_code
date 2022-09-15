static void close_server_sock ( ) {
 # ifdef HAVE_CLOSE_SERVER_SOCK DBUG_ENTER ( "close_server_sock" ) ;
 close_socket ( base_ip_sock , "TCP/IP" ) ;
 close_socket ( extra_ip_sock , "TCP/IP" ) ;
 close_socket ( unix_sock , "unix/IP" ) ;
 if ( unix_sock != INVALID_SOCKET ) ( void ) unlink ( mysqld_unix_port ) ;
 base_ip_sock = extra_ip_sock = unix_sock = INVALID_SOCKET ;
 DBUG_VOID_RETURN ;
 # endif }
static void init_ssl ( ) {
 # if defined ( HAVE_OPENSSL ) && ! defined ( EMBEDDED_LIBRARY ) if ( opt_use_ssl ) {
 enum enum_ssl_init_error error = SSL_INITERR_NOERROR ;
 ssl_acceptor_fd = new_VioSSLAcceptorFd ( opt_ssl_key , opt_ssl_cert , opt_ssl_ca , opt_ssl_capath , opt_ssl_cipher , & error ) ;
 DBUG_PRINT ( "info" , ( "ssl_acceptor_fd: 0x%lx" , ( long ) ssl_acceptor_fd ) ) ;
 ERR_remove_state ( 0 ) ;
 if ( ! ssl_acceptor_fd ) {
 sql_print_warning ( "Failed to setup SSL" ) ;
 sql_print_warning ( "SSL error: %s" , sslGetErrString ( error ) ) ;
 opt_use_ssl = 0 ;
 have_ssl = SHOW_OPTION_DISABLED ;
 }
 }
 else {
 have_ssl = SHOW_OPTION_DISABLED ;
 }
 if ( des_key_file ) load_des_key_file ( des_key_file ) ;
 # endif }
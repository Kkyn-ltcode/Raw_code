static void end_ssl ( ) {
 # ifdef HAVE_OPENSSL # ifndef EMBEDDED_LIBRARY if ( ssl_acceptor_fd ) {
 free_vio_ssl_acceptor_fd ( ssl_acceptor_fd ) ;
 ssl_acceptor_fd = 0 ;
 }
 # endif # endif }
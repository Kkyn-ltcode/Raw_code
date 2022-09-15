static const char * passphrase_callback ( struct archive * a , void * _client_data ) {
 struct cpio * cpio = ( struct cpio * ) _client_data ;
 ( void ) a ;
 if ( cpio -> ppbuff == NULL ) {
 cpio -> ppbuff = malloc ( PPBUFF_SIZE ) ;
 if ( cpio -> ppbuff == NULL ) lafe_errc ( 1 , errno , "Out of memory" ) ;
 }
 return lafe_readpassphrase ( "Enter passphrase:" , cpio -> ppbuff , PPBUFF_SIZE ) ;
 }
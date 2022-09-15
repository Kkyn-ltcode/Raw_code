WORK_STATE tls_finish_handshake ( SSL * s , WORK_STATE wst ) {
 void ( * cb ) ( const SSL * ssl , int type , int val ) = NULL ;
 # ifndef OPENSSL_NO_SCTP if ( SSL_IS_DTLS ( s ) && BIO_dgram_is_sctp ( SSL_get_wbio ( s ) ) ) {
 WORK_STATE ret ;
 ret = dtls_wait_for_dry ( s ) ;
 if ( ret != WORK_FINISHED_CONTINUE ) return ret ;
 }
 # endif ssl3_cleanup_key_block ( s ) ;
 if ( ! SSL_IS_DTLS ( s ) ) {
 BUF_MEM_free ( s -> init_buf ) ;
 s -> init_buf = NULL ;
 }
 ssl_free_wbio_buffer ( s ) ;
 s -> init_num = 0 ;
 if ( ! s -> server || s -> renegotiate == 2 ) {
 s -> renegotiate = 0 ;
 s -> new_session = 0 ;
 if ( s -> server ) {
 ssl_update_cache ( s , SSL_SESS_CACHE_SERVER ) ;
 s -> ctx -> stats . sess_accept_good ++ ;
 s -> handshake_func = ossl_statem_accept ;
 }
 else {
 ssl_update_cache ( s , SSL_SESS_CACHE_CLIENT ) ;
 if ( s -> hit ) s -> ctx -> stats . sess_hit ++ ;
 s -> handshake_func = ossl_statem_connect ;
 s -> ctx -> stats . sess_connect_good ++ ;
 }
 if ( s -> info_callback != NULL ) cb = s -> info_callback ;
 else if ( s -> ctx -> info_callback != NULL ) cb = s -> ctx -> info_callback ;
 if ( cb != NULL ) cb ( s , SSL_CB_HANDSHAKE_DONE , 1 ) ;
 if ( SSL_IS_DTLS ( s ) ) {
 s -> d1 -> handshake_read_seq = 0 ;
 s -> d1 -> handshake_write_seq = 0 ;
 s -> d1 -> next_handshake_write_seq = 0 ;
 dtls1_clear_received_buffer ( s ) ;
 }
 }
 return WORK_FINISHED_STOP ;
 }
int tls1_setup_key_block ( SSL * s ) {
 unsigned char * p1 , * p2 = NULL ;
 const EVP_CIPHER * c ;
 const EVP_MD * hash ;
 int num ;
 SSL_COMP * comp ;
 int mac_type = NID_undef , mac_secret_size = 0 ;
 int ret = 0 ;
 # ifdef KSSL_DEBUG printf ( "tls1_setup_key_block()\n" ) ;
 # endif if ( s -> s3 -> tmp . key_block_length != 0 ) return ( 1 ) ;
 if ( ! ssl_cipher_get_evp ( s -> session , & c , & hash , & mac_type , & mac_secret_size , & comp ) ) {
 SSLerr ( SSL_F_TLS1_SETUP_KEY_BLOCK , SSL_R_CIPHER_OR_HASH_UNAVAILABLE ) ;
 return ( 0 ) ;
 }
 s -> s3 -> tmp . new_sym_enc = c ;
 s -> s3 -> tmp . new_hash = hash ;
 s -> s3 -> tmp . new_mac_pkey_type = mac_type ;
 s -> s3 -> tmp . new_mac_secret_size = mac_secret_size ;
 num = EVP_CIPHER_key_length ( c ) + mac_secret_size + EVP_CIPHER_iv_length ( c ) ;
 num *= 2 ;
 ssl3_cleanup_key_block ( s ) ;
 if ( ( p1 = ( unsigned char * ) OPENSSL_malloc ( num ) ) == NULL ) {
 SSLerr ( SSL_F_TLS1_SETUP_KEY_BLOCK , ERR_R_MALLOC_FAILURE ) ;
 goto err ;
 }
 s -> s3 -> tmp . key_block_length = num ;
 s -> s3 -> tmp . key_block = p1 ;
 if ( ( p2 = ( unsigned char * ) OPENSSL_malloc ( num ) ) == NULL ) {
 SSLerr ( SSL_F_TLS1_SETUP_KEY_BLOCK , ERR_R_MALLOC_FAILURE ) ;
 goto err ;
 }
 # ifdef TLS_DEBUG printf ( "client random\n" ) ;
 {
 int z ;
 for ( z = 0 ;
 z < SSL3_RANDOM_SIZE ;
 z ++ ) printf ( "%02X%c" , s -> s3 -> client_random [ z ] , ( ( z + 1 ) % 16 ) ? ' ' : '\n' ) ;
 }
 printf ( "server random\n" ) ;
 {
 int z ;
 for ( z = 0 ;
 z < SSL3_RANDOM_SIZE ;
 z ++ ) printf ( "%02X%c" , s -> s3 -> server_random [ z ] , ( ( z + 1 ) % 16 ) ? ' ' : '\n' ) ;
 }
 printf ( "pre-master\n" ) ;
 {
 int z ;
 for ( z = 0 ;
 z < s -> session -> master_key_length ;
 z ++ ) printf ( "%02X%c" , s -> session -> master_key [ z ] , ( ( z + 1 ) % 16 ) ? ' ' : '\n' ) ;
 }
 # endif if ( ! tls1_generate_key_block ( s , p1 , p2 , num ) ) goto err ;
 # ifdef TLS_DEBUG printf ( "\nkey block\n" ) ;
 {
 int z ;
 for ( z = 0 ;
 z < num ;
 z ++ ) printf ( "%02X%c" , p1 [ z ] , ( ( z + 1 ) % 16 ) ? ' ' : '\n' ) ;
 }
 # endif if ( ! ( s -> options & SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS ) && s -> method -> version <= TLS1_VERSION ) {
 s -> s3 -> need_empty_fragments = 1 ;
 if ( s -> session -> cipher != NULL ) {
 if ( s -> session -> cipher -> algorithm_enc == SSL_eNULL ) s -> s3 -> need_empty_fragments = 0 ;
 # ifndef OPENSSL_NO_RC4 if ( s -> session -> cipher -> algorithm_enc == SSL_RC4 ) s -> s3 -> need_empty_fragments = 0 ;
 # endif }
 }
 ret = 1 ;
 err : if ( p2 ) {
 OPENSSL_cleanse ( p2 , num ) ;
 OPENSSL_free ( p2 ) ;
 }
 return ( ret ) ;
 }
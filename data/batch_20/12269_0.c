int tls1_export_keying_material ( SSL * s , unsigned char * out , size_t olen , const char * label , size_t llen , const unsigned char * context , size_t contextlen , int use_context ) {
 unsigned char * buff ;
 unsigned char * val = NULL ;
 size_t vallen , currentvalpos ;
 int rv ;
 # ifdef KSSL_DEBUG printf ( "tls1_export_keying_material(%p,%p,%d,%s,%d,%p,%d)\n" , s , out , olen , label , llen , p , plen ) ;
 # endif buff = OPENSSL_malloc ( olen ) ;
 if ( buff == NULL ) goto err2 ;
 vallen = llen + SSL3_RANDOM_SIZE * 2 ;
 if ( use_context ) {
 vallen += 2 + contextlen ;
 }
 val = OPENSSL_malloc ( vallen ) ;
 if ( val == NULL ) goto err2 ;
 currentvalpos = 0 ;
 memcpy ( val + currentvalpos , ( unsigned char * ) label , llen ) ;
 currentvalpos += llen ;
 memcpy ( val + currentvalpos , s -> s3 -> client_random , SSL3_RANDOM_SIZE ) ;
 currentvalpos += SSL3_RANDOM_SIZE ;
 memcpy ( val + currentvalpos , s -> s3 -> server_random , SSL3_RANDOM_SIZE ) ;
 currentvalpos += SSL3_RANDOM_SIZE ;
 if ( use_context ) {
 val [ currentvalpos ] = ( contextlen >> 8 ) & 0xff ;
 currentvalpos ++ ;
 val [ currentvalpos ] = contextlen & 0xff ;
 currentvalpos ++ ;
 if ( ( contextlen > 0 ) || ( context != NULL ) ) {
 memcpy ( val + currentvalpos , context , contextlen ) ;
 }
 }
 if ( memcmp ( val , TLS_MD_CLIENT_FINISH_CONST , TLS_MD_CLIENT_FINISH_CONST_SIZE ) == 0 ) goto err1 ;
 if ( memcmp ( val , TLS_MD_SERVER_FINISH_CONST , TLS_MD_SERVER_FINISH_CONST_SIZE ) == 0 ) goto err1 ;
 if ( memcmp ( val , TLS_MD_MASTER_SECRET_CONST , TLS_MD_MASTER_SECRET_CONST_SIZE ) == 0 ) goto err1 ;
 if ( memcmp ( val , TLS_MD_KEY_EXPANSION_CONST , TLS_MD_KEY_EXPANSION_CONST_SIZE ) == 0 ) goto err1 ;
 rv = tls1_PRF ( s -> s3 -> tmp . new_cipher -> algorithm2 , val , vallen , NULL , 0 , NULL , 0 , NULL , 0 , NULL , 0 , s -> session -> master_key , s -> session -> master_key_length , out , buff , olen ) ;
 # ifdef KSSL_DEBUG printf ( "tls1_export_keying_material() complete\n" ) ;
 # endif goto ret ;
 err1 : SSLerr ( SSL_F_TLS1_EXPORT_KEYING_MATERIAL , SSL_R_TLS_ILLEGAL_EXPORTER_LABEL ) ;
 rv = 0 ;
 goto ret ;
 err2 : SSLerr ( SSL_F_TLS1_EXPORT_KEYING_MATERIAL , ERR_R_MALLOC_FAILURE ) ;
 rv = 0 ;
 ret : if ( buff != NULL ) OPENSSL_free ( buff ) ;
 if ( val != NULL ) OPENSSL_free ( val ) ;
 return ( rv ) ;
 }
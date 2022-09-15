static int aes_gcm_init_key ( EVP_CIPHER_CTX * ctx , const unsigned char * key , const unsigned char * iv , int enc ) {
 EVP_AES_GCM_CTX * gctx = EVP_C_DATA ( EVP_AES_GCM_CTX , ctx ) ;
 if ( ! iv && ! key ) return 1 ;
 if ( key ) {
 do {
 # ifdef HWAES_CAPABLE if ( HWAES_CAPABLE ) {
 HWAES_set_encrypt_key ( key , EVP_CIPHER_CTX_key_length ( ctx ) * 8 , & gctx -> ks . ks ) ;
 CRYPTO_gcm128_init ( & gctx -> gcm , & gctx -> ks , ( block128_f ) HWAES_encrypt ) ;
 # ifdef HWAES_ctr32_encrypt_blocks gctx -> ctr = ( ctr128_f ) HWAES_ctr32_encrypt_blocks ;
 # else gctx -> ctr = NULL ;
 # endif break ;
 }
 else # endif # ifdef BSAES_CAPABLE if ( BSAES_CAPABLE ) {
 AES_set_encrypt_key ( key , EVP_CIPHER_CTX_key_length ( ctx ) * 8 , & gctx -> ks . ks ) ;
 CRYPTO_gcm128_init ( & gctx -> gcm , & gctx -> ks , ( block128_f ) AES_encrypt ) ;
 gctx -> ctr = ( ctr128_f ) bsaes_ctr32_encrypt_blocks ;
 break ;
 }
 else # endif # ifdef VPAES_CAPABLE if ( VPAES_CAPABLE ) {
 vpaes_set_encrypt_key ( key , EVP_CIPHER_CTX_key_length ( ctx ) * 8 , & gctx -> ks . ks ) ;
 CRYPTO_gcm128_init ( & gctx -> gcm , & gctx -> ks , ( block128_f ) vpaes_encrypt ) ;
 gctx -> ctr = NULL ;
 break ;
 }
 else # endif ( void ) 0 ;
 AES_set_encrypt_key ( key , EVP_CIPHER_CTX_key_length ( ctx ) * 8 , & gctx -> ks . ks ) ;
 CRYPTO_gcm128_init ( & gctx -> gcm , & gctx -> ks , ( block128_f ) AES_encrypt ) ;
 # ifdef AES_CTR_ASM gctx -> ctr = ( ctr128_f ) AES_ctr32_encrypt ;
 # else gctx -> ctr = NULL ;
 # endif }
 while ( 0 ) ;
 if ( iv == NULL && gctx -> iv_set ) iv = gctx -> iv ;
 if ( iv ) {
 CRYPTO_gcm128_setiv ( & gctx -> gcm , iv , gctx -> ivlen ) ;
 gctx -> iv_set = 1 ;
 }
 gctx -> key_set = 1 ;
 }
 else {
 if ( gctx -> key_set ) CRYPTO_gcm128_setiv ( & gctx -> gcm , iv , gctx -> ivlen ) ;
 else memcpy ( gctx -> iv , iv , gctx -> ivlen ) ;
 gctx -> iv_set = 1 ;
 gctx -> iv_gen = 0 ;
 }
 return 1 ;
 }
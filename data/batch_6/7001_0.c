static int aes_ccm_cipher ( EVP_CIPHER_CTX * ctx , unsigned char * out , const unsigned char * in , size_t len ) {
 EVP_AES_CCM_CTX * cctx = EVP_C_DATA ( EVP_AES_CCM_CTX , ctx ) ;
 CCM128_CONTEXT * ccm = & cctx -> ccm ;
 if ( ! cctx -> key_set ) return - 1 ;
 if ( cctx -> tls_aad_len >= 0 ) return aes_ccm_tls_cipher ( ctx , out , in , len ) ;
 if ( ! cctx -> iv_set ) return - 1 ;
 if ( ! EVP_CIPHER_CTX_encrypting ( ctx ) && ! cctx -> tag_set ) return - 1 ;
 if ( ! out ) {
 if ( ! in ) {
 if ( CRYPTO_ccm128_setiv ( ccm , EVP_CIPHER_CTX_iv_noconst ( ctx ) , 15 - cctx -> L , len ) ) return - 1 ;
 cctx -> len_set = 1 ;
 return len ;
 }
 if ( ! cctx -> len_set && len ) return - 1 ;
 CRYPTO_ccm128_aad ( ccm , in , len ) ;
 return len ;
 }
 if ( ! in ) return 0 ;
 if ( ! cctx -> len_set ) {
 if ( CRYPTO_ccm128_setiv ( ccm , EVP_CIPHER_CTX_iv_noconst ( ctx ) , 15 - cctx -> L , len ) ) return - 1 ;
 cctx -> len_set = 1 ;
 }
 if ( EVP_CIPHER_CTX_encrypting ( ctx ) ) {
 if ( cctx -> str ? CRYPTO_ccm128_encrypt_ccm64 ( ccm , in , out , len , cctx -> str ) : CRYPTO_ccm128_encrypt ( ccm , in , out , len ) ) return - 1 ;
 cctx -> tag_set = 1 ;
 return len ;
 }
 else {
 int rv = - 1 ;
 if ( cctx -> str ? ! CRYPTO_ccm128_decrypt_ccm64 ( ccm , in , out , len , cctx -> str ) : ! CRYPTO_ccm128_decrypt ( ccm , in , out , len ) ) {
 unsigned char tag [ 16 ] ;
 if ( CRYPTO_ccm128_tag ( ccm , tag , cctx -> M ) ) {
 if ( ! CRYPTO_memcmp ( tag , EVP_CIPHER_CTX_buf_noconst ( ctx ) , cctx -> M ) ) rv = len ;
 }
 }
 if ( rv == - 1 ) OPENSSL_cleanse ( out , len ) ;
 cctx -> iv_set = 0 ;
 cctx -> tag_set = 0 ;
 cctx -> len_set = 0 ;
 return rv ;
 }
 }
static int aes_ccm_tls_cipher ( EVP_CIPHER_CTX * ctx , unsigned char * out , const unsigned char * in , size_t len ) {
 EVP_AES_CCM_CTX * cctx = EVP_C_DATA ( EVP_AES_CCM_CTX , ctx ) ;
 CCM128_CONTEXT * ccm = & cctx -> ccm ;
 if ( out != in || len < ( EVP_CCM_TLS_EXPLICIT_IV_LEN + ( size_t ) cctx -> M ) ) return - 1 ;
 if ( EVP_CIPHER_CTX_encrypting ( ctx ) ) memcpy ( out , EVP_CIPHER_CTX_buf_noconst ( ctx ) , EVP_CCM_TLS_EXPLICIT_IV_LEN ) ;
 memcpy ( EVP_CIPHER_CTX_iv_noconst ( ctx ) + EVP_CCM_TLS_FIXED_IV_LEN , in , EVP_CCM_TLS_EXPLICIT_IV_LEN ) ;
 len -= EVP_CCM_TLS_EXPLICIT_IV_LEN + cctx -> M ;
 if ( CRYPTO_ccm128_setiv ( ccm , EVP_CIPHER_CTX_iv_noconst ( ctx ) , 15 - cctx -> L , len ) ) return - 1 ;
 CRYPTO_ccm128_aad ( ccm , EVP_CIPHER_CTX_buf_noconst ( ctx ) , cctx -> tls_aad_len ) ;
 in += EVP_CCM_TLS_EXPLICIT_IV_LEN ;
 out += EVP_CCM_TLS_EXPLICIT_IV_LEN ;
 if ( EVP_CIPHER_CTX_encrypting ( ctx ) ) {
 if ( cctx -> str ? CRYPTO_ccm128_encrypt_ccm64 ( ccm , in , out , len , cctx -> str ) : CRYPTO_ccm128_encrypt ( ccm , in , out , len ) ) return - 1 ;
 if ( ! CRYPTO_ccm128_tag ( ccm , out + len , cctx -> M ) ) return - 1 ;
 return len + EVP_CCM_TLS_EXPLICIT_IV_LEN + cctx -> M ;
 }
 else {
 if ( cctx -> str ? ! CRYPTO_ccm128_decrypt_ccm64 ( ccm , in , out , len , cctx -> str ) : ! CRYPTO_ccm128_decrypt ( ccm , in , out , len ) ) {
 unsigned char tag [ 16 ] ;
 if ( CRYPTO_ccm128_tag ( ccm , tag , cctx -> M ) ) {
 if ( ! CRYPTO_memcmp ( tag , in + len , cctx -> M ) ) return len ;
 }
 }
 OPENSSL_cleanse ( out , len ) ;
 return - 1 ;
 }
 }
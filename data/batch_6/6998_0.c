static int aes_xts_ctrl ( EVP_CIPHER_CTX * c , int type , int arg , void * ptr ) {
 EVP_AES_XTS_CTX * xctx = EVP_C_DATA ( EVP_AES_XTS_CTX , c ) ;
 if ( type == EVP_CTRL_COPY ) {
 EVP_CIPHER_CTX * out = ptr ;
 EVP_AES_XTS_CTX * xctx_out = EVP_C_DATA ( EVP_AES_XTS_CTX , out ) ;
 if ( xctx -> xts . key1 ) {
 if ( xctx -> xts . key1 != & xctx -> ks1 ) return 0 ;
 xctx_out -> xts . key1 = & xctx_out -> ks1 ;
 }
 if ( xctx -> xts . key2 ) {
 if ( xctx -> xts . key2 != & xctx -> ks2 ) return 0 ;
 xctx_out -> xts . key2 = & xctx_out -> ks2 ;
 }
 return 1 ;
 }
 else if ( type != EVP_CTRL_INIT ) return - 1 ;
 xctx -> xts . key1 = NULL ;
 xctx -> xts . key2 = NULL ;
 return 1 ;
 }
static int aes_ocb_ctrl ( EVP_CIPHER_CTX * c , int type , int arg , void * ptr ) {
 EVP_AES_OCB_CTX * octx = EVP_C_DATA ( EVP_AES_OCB_CTX , c ) ;
 EVP_CIPHER_CTX * newc ;
 EVP_AES_OCB_CTX * new_octx ;
 switch ( type ) {
 case EVP_CTRL_INIT : octx -> key_set = 0 ;
 octx -> iv_set = 0 ;
 octx -> ivlen = EVP_CIPHER_CTX_iv_length ( c ) ;
 octx -> iv = EVP_CIPHER_CTX_iv_noconst ( c ) ;
 octx -> taglen = 16 ;
 octx -> data_buf_len = 0 ;
 octx -> aad_buf_len = 0 ;
 return 1 ;
 case EVP_CTRL_AEAD_SET_IVLEN : if ( arg <= 0 || arg > 15 ) return 0 ;
 octx -> ivlen = arg ;
 return 1 ;
 case EVP_CTRL_AEAD_SET_TAG : if ( ! ptr ) {
 if ( arg < 0 || arg > 16 ) return 0 ;
 octx -> taglen = arg ;
 return 1 ;
 }
 if ( arg != octx -> taglen || EVP_CIPHER_CTX_encrypting ( c ) ) return 0 ;
 memcpy ( octx -> tag , ptr , arg ) ;
 return 1 ;
 case EVP_CTRL_AEAD_GET_TAG : if ( arg != octx -> taglen || ! EVP_CIPHER_CTX_encrypting ( c ) ) return 0 ;
 memcpy ( ptr , octx -> tag , arg ) ;
 return 1 ;
 case EVP_CTRL_COPY : newc = ( EVP_CIPHER_CTX * ) ptr ;
 new_octx = EVP_C_DATA ( EVP_AES_OCB_CTX , newc ) ;
 return CRYPTO_ocb128_copy_ctx ( & new_octx -> ocb , & octx -> ocb , & new_octx -> ksenc . ks , & new_octx -> ksdec . ks ) ;
 default : return - 1 ;
 }
 }
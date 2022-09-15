static int aes_ofb_cipher ( EVP_CIPHER_CTX * ctx , unsigned char * out , const unsigned char * in , size_t len ) {
 EVP_AES_KEY * dat = EVP_C_DATA ( EVP_AES_KEY , ctx ) ;
 int num = EVP_CIPHER_CTX_num ( ctx ) ;
 CRYPTO_ofb128_encrypt ( in , out , len , & dat -> ks , EVP_CIPHER_CTX_iv_noconst ( ctx ) , & num , dat -> block ) ;
 EVP_CIPHER_CTX_set_num ( ctx , num ) ;
 return 1 ;
 }
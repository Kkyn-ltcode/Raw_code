void EVP_EncodeUpdate ( EVP_ENCODE_CTX * ctx , unsigned char * out , int * outl , const unsigned char * in , int inl ) {
 int i , j ;
 unsigned int total = 0 ;
 * outl = 0 ;
 if ( inl <= 0 ) return ;
 OPENSSL_assert ( ctx -> length <= ( int ) sizeof ( ctx -> enc_data ) ) ;
 if ( ( ctx -> num + inl ) < ctx -> length ) {
 memcpy ( & ( ctx -> enc_data [ ctx -> num ] ) , in , inl ) ;
 ctx -> num += inl ;
 return ;
 }
 if ( ctx -> num != 0 ) {
 i = ctx -> length - ctx -> num ;
 memcpy ( & ( ctx -> enc_data [ ctx -> num ] ) , in , i ) ;
 in += i ;
 inl -= i ;
 j = EVP_EncodeBlock ( out , ctx -> enc_data , ctx -> length ) ;
 ctx -> num = 0 ;
 out += j ;
 * ( out ++ ) = '\n' ;
 * out = '\0' ;
 total = j + 1 ;
 }
 while ( inl >= ctx -> length ) {
 j = EVP_EncodeBlock ( out , in , ctx -> length ) ;
 in += ctx -> length ;
 inl -= ctx -> length ;
 out += j ;
 * ( out ++ ) = '\n' ;
 * out = '\0' ;
 total += j + 1 ;
 }
 if ( inl != 0 ) memcpy ( & ( ctx -> enc_data [ 0 ] ) , in , inl ) ;
 ctx -> num = inl ;
 * outl = total ;
 }
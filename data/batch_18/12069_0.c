int DSA_verify ( int type , const unsigned char * dgst , int dgst_len , const unsigned char * sigbuf , int siglen , DSA * dsa ) {
 DSA_SIG * s ;
 const unsigned char * p = sigbuf ;
 unsigned char * der = NULL ;
 int derlen = - 1 ;
 int ret = - 1 ;
 s = DSA_SIG_new ( ) ;
 if ( s == NULL ) return ( ret ) ;
 if ( d2i_DSA_SIG ( & s , & p , siglen ) == NULL ) goto err ;
 derlen = i2d_DSA_SIG ( s , & der ) ;
 if ( derlen != siglen || memcmp ( sigbuf , der , derlen ) ) goto err ;
 ret = DSA_do_verify ( dgst , dgst_len , s , dsa ) ;
 err : if ( derlen > 0 ) {
 OPENSSL_cleanse ( der , derlen ) ;
 OPENSSL_free ( der ) ;
 }
 DSA_SIG_free ( s ) ;
 return ( ret ) ;
 }
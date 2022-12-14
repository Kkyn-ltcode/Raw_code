int BIO_vprintf ( BIO * bio , const char * format , va_list args ) {
 int ret ;
 size_t retlen ;
 char hugebuf [ 1024 * 2 ] ;
 char * hugebufp = hugebuf ;
 size_t hugebufsize = sizeof ( hugebuf ) ;
 char * dynbuf = NULL ;
 int ignored ;
 dynbuf = NULL ;
 CRYPTO_push_info ( "doapr()" ) ;
 if ( ! _dopr ( & hugebufp , & dynbuf , & hugebufsize , & retlen , & ignored , format , args ) ) {
 OPENSSL_free ( dynbuf ) ;
 return - 1 ;
 }
 if ( dynbuf ) {
 ret = BIO_write ( bio , dynbuf , ( int ) retlen ) ;
 OPENSSL_free ( dynbuf ) ;
 }
 else {
 ret = BIO_write ( bio , hugebuf , ( int ) retlen ) ;
 }
 CRYPTO_pop_info ( ) ;
 return ( ret ) ;
 }
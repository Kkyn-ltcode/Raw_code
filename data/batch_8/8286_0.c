PHP_FUNCTION ( uwsgi_cache_get ) {
 char * key = NULL ;
 int keylen = 0 ;
 char * cache = NULL ;
 int cachelen = 0 ;
 uint64_t valsize ;
 if ( ! uwsgi . caches ) RETURN_NULL ( ) ;
 if ( zend_parse_parameters ( ZEND_NUM_ARGS ( ) TSRMLS_CC , "s|s" , & key , & keylen , & cache , & cachelen ) == FAILURE ) {
 RETURN_NULL ( ) ;
 }
 char * value = uwsgi_cache_magic_get ( key , keylen , & valsize , NULL , cache ) ;
 if ( value ) {
 char * ret = estrndup ( value , valsize ) ;
 free ( value ) ;
 # ifdef UWSGI_PHP7 RETURN_STRING ( ret ) ;
 # else RETURN_STRING ( ret , 0 ) ;
 # endif }
 RETURN_NULL ( ) ;
 }
PHP_FUNCTION ( uwsgi_version ) {
 # ifdef UWSGI_PHP7 RETURN_STRING ( UWSGI_VERSION ) ;
 # else RETURN_STRING ( UWSGI_VERSION , 1 ) ;
 # endif }
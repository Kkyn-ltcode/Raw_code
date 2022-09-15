static void evhttp_maybe_add_content_length_header ( struct evkeyvalq * headers , long content_length ) {
 if ( evhttp_find_header ( headers , "Transfer-Encoding" ) == NULL && evhttp_find_header ( headers , "Content-Length" ) == NULL ) {
 char len [ 12 ] ;
 evutil_snprintf ( len , sizeof ( len ) , "%ld" , content_length ) ;
 evhttp_add_header ( headers , "Content-Length" , len ) ;
 }
 }
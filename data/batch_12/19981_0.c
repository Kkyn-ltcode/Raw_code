void http_postrequest_done ( struct evhttp_request * req , void * arg ) {
 const char * what = "This is funny" ;
 if ( req == NULL ) {
 fprintf ( stderr , "FAILED (timeout)\n" ) ;
 exit ( 1 ) ;
 }
 if ( req -> response_code != HTTP_OK ) {
 fprintf ( stderr , "FAILED (response code)\n" ) ;
 exit ( 1 ) ;
 }
 if ( evhttp_find_header ( req -> input_headers , "Content-Type" ) == NULL ) {
 fprintf ( stderr , "FAILED (content type)\n" ) ;
 exit ( 1 ) ;
 }
 if ( EVBUFFER_LENGTH ( req -> input_buffer ) != strlen ( what ) ) {
 fprintf ( stderr , "FAILED (length %zu vs %zu)\n" , EVBUFFER_LENGTH ( req -> input_buffer ) , strlen ( what ) ) ;
 exit ( 1 ) ;
 }
 if ( memcmp ( EVBUFFER_DATA ( req -> input_buffer ) , what , strlen ( what ) ) != 0 ) {
 fprintf ( stderr , "FAILED (data)\n" ) ;
 exit ( 1 ) ;
 }
 test_ok = 1 ;
 event_loopexit ( NULL ) ;
 }
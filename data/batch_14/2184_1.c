static void evhttp_handle_request ( struct evhttp_request * req , void * arg ) {
 struct evhttp * http = arg ;
 struct evhttp_cb * cb = NULL ;
 if ( req -> uri == NULL ) {
 evhttp_send_error ( req , HTTP_BADREQUEST , "Bad Request" ) ;
 return ;
 }
 if ( ( cb = evhttp_dispatch_callback ( & http -> callbacks , req ) ) != NULL ) {
 ( * cb -> cb ) ( req , cb -> cbarg ) ;
 return ;
 }
 if ( http -> gencb ) {
 ( * http -> gencb ) ( req , http -> gencbarg ) ;
 return ;
 }
 else {
 # define ERR_FORMAT "<html><head>" "<title>404 Not Found</title>" "</head><body>" "<h1>Not Found</h1>" "<p>The requested URL %s was not found on this server.</p>" "</body></html>\n" char * escaped_html = evhttp_htmlescape ( req -> uri ) ;
 struct evbuffer * buf = evbuffer_new ( ) ;
 evhttp_response_code ( req , HTTP_NOTFOUND , "Not Found" ) ;
 evbuffer_add_printf ( buf , ERR_FORMAT , escaped_html ) ;
 free ( escaped_html ) ;
 evhttp_send_page ( req , buf ) ;
 evbuffer_free ( buf ) ;
 # undef ERR_FORMAT }
 }
void evhttp_send_error ( struct evhttp_request * req , int error , const char * reason ) {
 # define ERR_FORMAT "<HTML><HEAD>\n" "<TITLE>%d %s</TITLE>\n" "</HEAD><BODY>\n" "<H1>Method Not Implemented</H1>\n" "Invalid method in request<P>\n" "</BODY></HTML>\n" struct evbuffer * buf = evbuffer_new ( ) ;
 evhttp_add_header ( req -> output_headers , "Connection" , "close" ) ;
 evhttp_response_code ( req , error , reason ) ;
 evbuffer_add_printf ( buf , ERR_FORMAT , error , reason ) ;
 evhttp_send_page ( req , buf ) ;
 evbuffer_free ( buf ) ;
 # undef ERR_FORMAT }
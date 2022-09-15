static void evhttp_maybe_add_date_header ( struct evkeyvalq * headers ) {
 if ( evhttp_find_header ( headers , "Date" ) == NULL ) {
 char date [ 50 ] ;
 # ifndef WIN32 struct tm cur ;
 # endif struct tm * cur_p ;
 time_t t = time ( NULL ) ;
 # ifdef WIN32 cur_p = gmtime ( & t ) ;
 # else gmtime_r ( & t , & cur ) ;
 cur_p = & cur ;
 # endif if ( strftime ( date , sizeof ( date ) , "%a, %d %b %Y %H:%M:%S GMT" , cur_p ) != 0 ) {
 evhttp_add_header ( headers , "Date" , date ) ;
 }
 }
 }
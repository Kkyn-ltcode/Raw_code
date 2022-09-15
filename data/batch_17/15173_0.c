static bool checkrtspprefix ( struct Curl_easy * data , const char * s ) {
 # ifdef CURL_DOES_CONVERSIONS char * scratch = strdup ( s ) ;
 if ( NULL == scratch ) {
 failf ( data , "Failed to allocate memory for conversion!" ) ;
 return FALSE ;
 }
 if ( CURLE_OK != Curl_convert_from_network ( data , scratch , strlen ( s ) + 1 ) ) {
 free ( scratch ) ;
 return FALSE ;
 }
 s = scratch ;
 # else ( void ) data ;
 # endif if ( checkprefix ( "RTSP/" , s ) ) return TRUE ;
 else return FALSE ;
 }
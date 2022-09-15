CURLcode Curl_auth_create_login_message ( struct Curl_easy * data , const char * valuep , char * * outptr , size_t * outlen ) {
 size_t vlen = strlen ( valuep ) ;
 if ( ! vlen ) {
 * outptr = strdup ( "=" ) ;
 if ( * outptr ) {
 * outlen = ( size_t ) 1 ;
 return CURLE_OK ;
 }
 * outlen = 0 ;
 return CURLE_OUT_OF_MEMORY ;
 }
 return Curl_base64_encode ( data , valuep , vlen , outptr , outlen ) ;
 }
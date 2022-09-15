CURLcode Curl_gmtime ( time_t intime , struct tm * store ) {
 const struct tm * tm ;
 # ifdef HAVE_GMTIME_R tm = ( struct tm * ) gmtime_r ( & intime , store ) ;
 # else tm = gmtime ( & intime ) ;
 if ( tm ) * store = * tm ;
 # endif if ( ! tm ) return CURLE_BAD_FUNCTION_ARGUMENT ;
 return CURLE_OK ;
 }
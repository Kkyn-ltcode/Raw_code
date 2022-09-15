static CURLcode header_append ( struct Curl_easy * data , struct SingleRequest * k , size_t length ) {
 if ( k -> hbuflen + length >= data -> state . headersize ) {
 char * newbuff ;
 size_t hbufp_index ;
 size_t newsize ;
 if ( k -> hbuflen + length > CURL_MAX_HTTP_HEADER ) {
 failf ( data , "Avoided giant realloc for header (max is %d)!" , CURL_MAX_HTTP_HEADER ) ;
 return CURLE_OUT_OF_MEMORY ;
 }
 newsize = CURLMAX ( ( k -> hbuflen + length ) * 3 / 2 , data -> state . headersize * 2 ) ;
 hbufp_index = k -> hbufp - data -> state . headerbuff ;
 newbuff = realloc ( data -> state . headerbuff , newsize ) ;
 if ( ! newbuff ) {
 failf ( data , "Failed to alloc memory for big header!" ) ;
 return CURLE_OUT_OF_MEMORY ;
 }
 data -> state . headersize = newsize ;
 data -> state . headerbuff = newbuff ;
 k -> hbufp = data -> state . headerbuff + hbufp_index ;
 }
 memcpy ( k -> hbufp , k -> str_start , length ) ;
 k -> hbufp += length ;
 k -> hbuflen += length ;
 * k -> hbufp = 0 ;
 return CURLE_OK ;
 }
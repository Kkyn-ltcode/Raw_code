CURLcode Curl_urldecode ( struct Curl_easy * data , const char * string , size_t length , char * * ostring , size_t * olen , bool reject_ctrl ) {
 size_t alloc = ( length ? length : strlen ( string ) ) + 1 ;
 char * ns = malloc ( alloc ) ;
 unsigned char in ;
 size_t strindex = 0 ;
 unsigned long hex ;
 CURLcode result ;
 if ( ! ns ) return CURLE_OUT_OF_MEMORY ;
 while ( -- alloc > 0 ) {
 in = * string ;
 if ( ( '%' == in ) && ( alloc > 2 ) && ISXDIGIT ( string [ 1 ] ) && ISXDIGIT ( string [ 2 ] ) ) {
 char hexstr [ 3 ] ;
 char * ptr ;
 hexstr [ 0 ] = string [ 1 ] ;
 hexstr [ 1 ] = string [ 2 ] ;
 hexstr [ 2 ] = 0 ;
 hex = strtoul ( hexstr , & ptr , 16 ) ;
 in = curlx_ultouc ( hex ) ;
 result = Curl_convert_from_network ( data , & in , 1 ) ;
 if ( result ) {
 free ( ns ) ;
 return result ;
 }
 string += 2 ;
 alloc -= 2 ;
 }
 if ( reject_ctrl && ( in < 0x20 ) ) {
 free ( ns ) ;
 return CURLE_URL_MALFORMAT ;
 }
 ns [ strindex ++ ] = in ;
 string ++ ;
 }
 ns [ strindex ] = 0 ;
 if ( olen ) * olen = strindex ;
 * ostring = ns ;
 return CURLE_OK ;
 }
static ssize_t _warc_rdlen ( const char * buf , size_t bsz ) {
 static const char _key [ ] = "\r\nContent-Length:" ;
 const char * val , * eol ;
 char * on = NULL ;
 long int len ;
 if ( ( val = xmemmem ( buf , bsz , _key , sizeof ( _key ) - 1U ) ) == NULL ) {
 return - 1 ;
 }
 val += sizeof ( _key ) - 1U ;
 if ( ( eol = _warc_find_eol ( val , buf + bsz - val ) ) == NULL ) {
 return - 1 ;
 }
 while ( val < eol && ( * val == ' ' || * val == '\t' ) ) val ++ ;
 if ( ! isdigit ( ( unsigned char ) * val ) ) return - 1 ;
 len = strtol ( val , & on , 10 ) ;
 if ( on != eol ) {
 return - 1 ;
 }
 return ( size_t ) len ;
 }
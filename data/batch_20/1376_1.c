int getulong ( const char * numstr , unsigned long int * result ) {
 long long int val ;
 char * endptr ;
 errno = 0 ;
 val = strtoll ( numstr , & endptr , 0 ) ;
 if ( ( '\0' == * numstr ) || ( '\0' != * endptr ) || ( ERANGE == errno ) || ( val != ( unsigned long int ) val ) ) {
 return 0 ;
 }
 * result = ( unsigned long int ) val ;
 return 1 ;
 }
static Asn1Generic * DecodeAsn1DerPrintableString ( const unsigned char * buffer , uint32_t max_size , uint8_t depth , uint32_t * errcode ) {
 const unsigned char * d_ptr = buffer ;
 uint32_t length , numbytes ;
 Asn1Generic * a ;
 unsigned char c ;
 d_ptr ++ ;
 c = d_ptr [ 0 ] ;
 if ( ( c & ( 1 << 7 ) ) >> 7 == 0 ) {
 length = c ;
 d_ptr ++ ;
 }
 else {
 numbytes = c & 0x7f ;
 d_ptr ++ ;
 if ( DecodeAsn1BuildValue ( & d_ptr , & length , numbytes , errcode ) == - 1 ) {
 return NULL ;
 }
 }
 if ( length > max_size ) return NULL ;
 a = Asn1GenericNew ( ) ;
 if ( a == NULL ) return NULL ;
 a -> type = ASN1_PRINTSTRING ;
 a -> strlen = length ;
 a -> str = SCMalloc ( length + 1 ) ;
 if ( a -> str == NULL ) {
 SCFree ( a ) ;
 return NULL ;
 }
 strlcpy ( a -> str , ( const char * ) d_ptr , length + 1 ) ;
 a -> str [ length ] = '\0' ;
 d_ptr += length ;
 a -> length = ( d_ptr - buffer ) ;
 return a ;
 }
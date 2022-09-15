static OFCondition parseMaxPDU ( DUL_MAXLENGTH * max , unsigned char * buf , unsigned long * itemLength , unsigned long availData ) {
 if ( availData < 8 ) return makeLengthError ( "Max PDU" , availData , 8 ) ;
 max -> type = * buf ++ ;
 max -> rsv1 = * buf ++ ;
 EXTRACT_SHORT_BIG ( buf , max -> length ) ;
 buf += 2 ;
 EXTRACT_LONG_BIG ( buf , max -> maxLength ) ;
 * itemLength = 2 + 2 + max -> length ;
 if ( max -> length != 4 ) DCMNET_WARN ( "Invalid length (" << max -> length << ") for maximum length item, must be 4" ) ;
 DCMNET_TRACE ( "Maximum PDU Length: " << ( unsigned long ) max -> maxLength ) ;
 return EC_Normal ;
 }
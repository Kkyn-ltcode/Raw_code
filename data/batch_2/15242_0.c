static OFCondition makeLengthError ( const char * pdu , unsigned long bufSize , unsigned long minSize , unsigned long length ) {
 OFStringStream stream ;
 stream << "DUL Illegal " << pdu << ". Got " << bufSize << " bytes of data" ;
 if ( length != 0 ) stream << " with a length field of " << length << " (data before length field is not included in length field)" ;
 if ( minSize != 0 ) stream << ". The minimum allowed size is " << minSize ;
 stream << "." << OFStringStream_ends ;
 OFCondition ret ;
 OFSTRINGSTREAM_GETSTR ( stream , tmpString ) ret = makeDcmnetCondition ( DULC_ILLEGALPDULENGTH , OF_error , tmpString ) ;
 OFSTRINGSTREAM_FREESTR ( tmpString ) return ret ;
 }
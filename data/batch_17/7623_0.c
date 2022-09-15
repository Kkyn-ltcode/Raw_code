static ha_checksum mi_byte_checksum ( const uchar * buf , uint length ) {
 ha_checksum crc ;
 const uchar * end = buf + length ;
 for ( crc = 0 ;
 buf != end ;
 buf ++ ) crc = ( ( crc << 1 ) + * ( ( uchar * ) buf ) ) + test ( crc & ( ( ( ha_checksum ) 1 ) << ( 8 * sizeof ( ha_checksum ) - 1 ) ) ) ;
 return crc ;
 }
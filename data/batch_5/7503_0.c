void copy_bits ( REP_SET * to , REP_SET * from ) {
 memcpy ( ( uchar * ) to -> bits , ( uchar * ) from -> bits , ( size_t ) ( sizeof ( uint ) * to -> size_of_bits ) ) ;
 }
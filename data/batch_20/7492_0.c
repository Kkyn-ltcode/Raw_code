int cmp_bits ( REP_SET * set1 , REP_SET * set2 ) {
 return memcmp ( set1 -> bits , set2 -> bits , sizeof ( uint ) * set1 -> size_of_bits ) ;
 }
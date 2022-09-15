REP_SET * make_new_set ( REP_SETS * sets ) {
 uint i , count , * bit_buffer ;
 REP_SET * set ;
 if ( sets -> extra ) {
 sets -> extra -- ;
 set = sets -> set + sets -> count ++ ;
 bzero ( ( char * ) set -> bits , sizeof ( uint ) * sets -> size_of_bits ) ;
 bzero ( ( char * ) & set -> next [ 0 ] , sizeof ( set -> next [ 0 ] ) * LAST_CHAR_CODE ) ;
 set -> found_offset = 0 ;
 set -> found_len = 0 ;
 set -> table_offset = ( uint ) ~ 0 ;
 set -> size_of_bits = sets -> size_of_bits ;
 return set ;
 }
 count = sets -> count + sets -> invisible + SET_MALLOC_HUNC ;
 if ( ! ( set = ( REP_SET * ) my_realloc ( ( uchar * ) sets -> set_buffer , sizeof ( REP_SET ) * count , MYF ( MY_WME ) ) ) ) return 0 ;
 sets -> set_buffer = set ;
 sets -> set = set + sets -> invisible ;
 if ( ! ( bit_buffer = ( uint * ) my_realloc ( ( uchar * ) sets -> bit_buffer , ( sizeof ( uint ) * sets -> size_of_bits ) * count , MYF ( MY_WME ) ) ) ) return 0 ;
 sets -> bit_buffer = bit_buffer ;
 for ( i = 0 ;
 i < count ;
 i ++ ) {
 sets -> set_buffer [ i ] . bits = bit_buffer ;
 bit_buffer += sets -> size_of_bits ;
 }
 sets -> extra = SET_MALLOC_HUNC ;
 return make_new_set ( sets ) ;
 }
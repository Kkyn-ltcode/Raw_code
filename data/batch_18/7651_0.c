static SORT_KEY_BLOCKS * alloc_key_blocks ( MI_CHECK * param , uint blocks , uint buffer_length ) {
 reg1 uint i ;
 SORT_KEY_BLOCKS * block ;
 DBUG_ENTER ( "alloc_key_blocks" ) ;
 if ( ! ( block = ( SORT_KEY_BLOCKS * ) my_malloc ( ( sizeof ( SORT_KEY_BLOCKS ) + buffer_length + IO_SIZE ) * blocks , MYF ( 0 ) ) ) ) {
 mi_check_print_error ( param , "Not enough memory for sort-key-blocks" ) ;
 return ( 0 ) ;
 }
 for ( i = 0 ;
 i < blocks ;
 i ++ ) {
 block [ i ] . inited = 0 ;
 block [ i ] . buff = ( uchar * ) ( block + blocks ) + ( buffer_length + IO_SIZE ) * i ;
 }
 DBUG_RETURN ( block ) ;
 }
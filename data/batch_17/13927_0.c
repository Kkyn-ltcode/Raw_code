bool add_terminator ( DYNAMIC_ARRAY * options ) {
 my_option empty_element = {
 0 , 0 , 0 , 0 , 0 , 0 , GET_NO_ARG , NO_ARG , 0 , 0 , 0 , 0 , 0 , 0 }
 ;
 return insert_dynamic ( options , ( uchar * ) & empty_element ) ;
 }
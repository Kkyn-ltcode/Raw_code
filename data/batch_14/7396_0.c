uint start_at_word ( char * pos ) {
 return ( ( ( ! memcmp ( pos , "\\b" , 2 ) && pos [ 2 ] ) || ! memcmp ( pos , "\\^" , 2 ) ) ? 1 : 0 ) ;
 }
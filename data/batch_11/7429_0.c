uint end_of_word ( char * pos ) {
 char * end = strend ( pos ) ;
 return ( ( end > pos + 2 && ! memcmp ( end - 2 , "\\b" , 2 ) ) || ( end >= pos + 2 && ! memcmp ( end - 2 , "\\$" , 2 ) ) ) ? 1 : 0 ;
 }
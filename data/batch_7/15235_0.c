static void trim_trailing_spaces ( char * s ) {
 char * p ;
 p = s ;
 while ( * p != '\0' ) p ++ ;
 if ( p == s ) return ;
 p -- ;
 while ( p >= s && * p == ' ' ) * p -- = '\0' ;
 }
static void mysql_end_timer ( ulong start_time , char * buff ) {
 buff [ 0 ] = ' ' ;
 buff [ 1 ] = '(' ;
 end_timer ( start_time , buff + 2 ) ;
 strmov ( strend ( buff ) , ")" ) ;
 }
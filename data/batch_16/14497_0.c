static void end_timer ( ulong start_time , char * buff ) {
 nice_time ( ( double ) ( start_timer ( ) - start_time ) / CLOCKS_PER_SEC , buff , 1 ) ;
 }
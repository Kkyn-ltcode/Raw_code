static void add_int_to_prompt ( int toadd ) {
 char buffer [ 16 ] ;
 int10_to_str ( toadd , buffer , 10 ) ;
 processed_prompt . append ( buffer ) ;
 }
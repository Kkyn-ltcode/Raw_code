void var_set_int ( const char * name , int value ) {
 char buf [ 21 ] ;
 my_snprintf ( buf , sizeof ( buf ) , "%d" , value ) ;
 var_set_string ( name , buf ) ;
 }
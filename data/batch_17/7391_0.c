void var_set_string ( const char * name , const char * value ) {
 var_set ( name , name + strlen ( name ) , value , value + strlen ( value ) ) ;
 }
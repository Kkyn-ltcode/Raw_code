static my_bool query_int_variable ( MYSQL * con , const char * var_name , int * var_value ) {
 char str [ 32 ] ;
 my_bool is_null = query_str_variable ( con , var_name , str , sizeof ( str ) ) ;
 if ( ! is_null ) * var_value = atoi ( str ) ;
 return is_null ;
 }
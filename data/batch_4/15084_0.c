static my_bool query_str_variable ( MYSQL * con , const char * var_name , char * str , size_t len ) {
 MYSQL_RES * rs ;
 MYSQL_ROW row ;
 char query_buffer [ MAX_TEST_QUERY_LENGTH ] ;
 my_bool is_null ;
 my_snprintf ( query_buffer , sizeof ( query_buffer ) , "SELECT %s" , var_name ) ;
 DIE_IF ( mysql_query ( con , query_buffer ) ) ;
 DIE_UNLESS ( rs = mysql_store_result ( con ) ) ;
 DIE_UNLESS ( row = mysql_fetch_row ( rs ) ) ;
 is_null = row [ 0 ] == NULL ;
 if ( ! is_null ) my_snprintf ( str , len , "%s" , row [ 0 ] ) ;
 mysql_free_result ( rs ) ;
 return is_null ;
 }
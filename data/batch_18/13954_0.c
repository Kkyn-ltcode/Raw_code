static int show_queries ( THD * thd , SHOW_VAR * var , char * buff ) {
 var -> type = SHOW_LONGLONG ;
 var -> value = ( char * ) & thd -> query_id ;
 return 0 ;
 }
static int show_starttime ( THD * thd , SHOW_VAR * var , char * buff ) {
 var -> type = SHOW_LONG ;
 var -> value = buff ;
 * ( ( long * ) buff ) = ( long ) ( thd -> query_start ( ) - server_start_time ) ;
 return 0 ;
 }
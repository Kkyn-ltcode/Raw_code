static int show_table_definitions ( THD * thd , SHOW_VAR * var , char * buff ) {
 var -> type = SHOW_LONG ;
 var -> value = buff ;
 * ( ( long * ) buff ) = ( long ) cached_table_definitions ( ) ;
 return 0 ;
 }
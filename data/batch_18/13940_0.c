static int show_open_tables ( THD * thd , SHOW_VAR * var , char * buff ) {
 var -> type = SHOW_LONG ;
 var -> value = buff ;
 * ( ( long * ) buff ) = ( long ) cached_open_tables ( ) ;
 return 0 ;
 }
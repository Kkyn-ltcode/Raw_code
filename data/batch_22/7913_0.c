static void dynstr_set_checked ( DYNAMIC_STRING * str , const char * init_str ) {
 if ( dynstr_set ( str , init_str ) ) die ( EX_MYSQLERR , DYNAMIC_STR_ERROR_MSG ) ;
 }
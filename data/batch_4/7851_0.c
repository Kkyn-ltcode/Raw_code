static void dynstr_append_mem_checked ( DYNAMIC_STRING * str , const char * append , uint length ) {
 if ( dynstr_append_mem ( str , append , length ) ) die ( EX_MYSQLERR , DYNAMIC_STR_ERROR_MSG ) ;
 }
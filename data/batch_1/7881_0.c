static void dynstr_realloc_checked ( DYNAMIC_STRING * str , ulong additional_size ) {
 if ( dynstr_realloc ( str , additional_size ) ) die ( EX_MYSQLERR , DYNAMIC_STR_ERROR_MSG ) ;
 }
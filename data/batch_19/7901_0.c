static void init_dynamic_string_checked ( DYNAMIC_STRING * str , const char * init_str , uint init_alloc , uint alloc_increment ) {
 if ( init_dynamic_string ( str , init_str , init_alloc , alloc_increment ) ) die ( EX_MYSQLERR , DYNAMIC_STR_ERROR_MSG ) ;
 }
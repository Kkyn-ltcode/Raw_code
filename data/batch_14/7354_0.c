void log_msg ( const char * fmt , ... ) {
 va_list args ;
 char buff [ 1024 ] ;
 size_t len ;
 DBUG_ENTER ( "log_msg" ) ;
 va_start ( args , fmt ) ;
 len = my_vsnprintf ( buff , sizeof ( buff ) - 1 , fmt , args ) ;
 va_end ( args ) ;
 dynstr_append_mem ( & ds_res , buff , len ) ;
 dynstr_append ( & ds_res , "\n" ) ;
 DBUG_VOID_RETURN ;
 }
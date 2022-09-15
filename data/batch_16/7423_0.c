void select_connection_name ( const char * name ) {
 DBUG_ENTER ( "select_connection_name" ) ;
 DBUG_PRINT ( "enter" , ( "name: '%s'" , name ) ) ;
 st_connection * con = find_connection_by_name ( name ) ;
 if ( ! con ) die ( "connection '%s' not found in connection pool" , name ) ;
 set_current_connection ( con ) ;
 if ( ! disable_connect_log && ! disable_query_log ) {
 DYNAMIC_STRING * ds = & ds_res ;
 dynstr_append_mem ( ds , "connection " , 11 ) ;
 replace_dynstr_append ( ds , name ) ;
 dynstr_append_mem ( ds , ";
\n" , 2 ) ;
 }
 DBUG_VOID_RETURN ;
 }
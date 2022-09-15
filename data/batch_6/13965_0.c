void close_connection ( THD * thd , uint sql_errno ) {
 DBUG_ENTER ( "close_connection" ) ;
 if ( sql_errno ) net_send_error ( thd , sql_errno , ER_DEFAULT ( sql_errno ) , NULL ) ;
 thd -> print_aborted_warning ( 3 , sql_errno ? ER_DEFAULT ( sql_errno ) : "CLOSE_CONNECTION" ) ;
 thd -> disconnect ( ) ;
 MYSQL_CONNECTION_DONE ( ( int ) sql_errno , thd -> thread_id ) ;
 if ( MYSQL_CONNECTION_DONE_ENABLED ( ) ) {
 sleep ( 0 ) ;
 }
 MYSQL_AUDIT_NOTIFY_CONNECTION_DISCONNECT ( thd , sql_errno ) ;
 DBUG_VOID_RETURN ;
 }
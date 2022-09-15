int mysql_real_query_for_lazy ( const char * buf , int length ) {
 for ( uint retry = 0 ;
 ;
 retry ++ ) {
 int error ;
 if ( ! mysql_real_query ( & mysql , buf , length ) ) return 0 ;
 error = put_error ( & mysql ) ;
 if ( mysql_errno ( & mysql ) != CR_SERVER_GONE_ERROR || retry > 1 || ! opt_reconnect ) return error ;
 if ( reconnect ( ) ) return error ;
 }
 }
int mysql_store_result_for_lazy ( MYSQL_RES * * result ) {
 if ( ( * result = mysql_store_result ( & mysql ) ) ) return 0 ;
 if ( mysql_error ( & mysql ) [ 0 ] ) return put_error ( & mysql ) ;
 return 0 ;
 }
static char * getTableName ( int reset ) {
 static MYSQL_RES * res = NULL ;
 MYSQL_ROW row ;
 if ( ! res ) {
 if ( ! ( res = mysql_list_tables ( mysql , NullS ) ) ) return ( NULL ) ;
 }
 if ( ( row = mysql_fetch_row ( res ) ) ) return ( ( char * ) row [ 0 ] ) ;
 if ( reset ) mysql_data_seek ( res , 0 ) ;
 else {
 mysql_free_result ( res ) ;
 res = NULL ;
 }
 return ( NULL ) ;
 }
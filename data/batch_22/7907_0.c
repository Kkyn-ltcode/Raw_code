static int do_unlock_tables ( MYSQL * mysql_con ) {
 return mysql_query_with_error_report ( mysql_con , 0 , "UNLOCK TABLES" ) ;
 }
static void enable_query_logs ( int truncate ) {
 int rc ;
 rc = mysql_query ( mysql , "set @save_global_general_log=@@global.general_log" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "set @save_global_slow_query_log=@@global.slow_query_log" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "set @@global.general_log=on" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "set @@global.slow_query_log=on" ) ;
 myquery ( rc ) ;
 if ( truncate ) {
 rc = mysql_query ( mysql , "truncate mysql.general_log" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "truncate mysql.slow_log" ) ;
 myquery ( rc ) ;
 }
 }
static void test_order_param ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 myheader ( "test_order_param" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1(a INT, b char(10))" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , "select sum(a) + 200, 1 from t1 " " union distinct " "select sum(a) + 200, 1 from t1 group by b " ) ;
 check_stmt ( stmt ) ;
 mysql_stmt_close ( stmt ) ;
 stmt = mysql_simple_prepare ( mysql , "select sum(a) + 200, ? from t1 group by b " " union distinct " "select sum(a) + 200, 1 from t1 group by b " ) ;
 check_stmt ( stmt ) ;
 mysql_stmt_close ( stmt ) ;
 stmt = mysql_simple_prepare ( mysql , "select sum(a) + 200, ? from t1 " " union distinct " "select sum(a) + 200, 1 from t1 group by b " ) ;
 check_stmt ( stmt ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 }
static void test_bug8722 ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 const char * stmt_text ;
 myheader ( "test_bug8722" ) ;
 stmt_text = "drop table if exists t1, v1" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 stmt_text = "CREATE TABLE t1 (c1 varchar(10), c2 varchar(10), c3 varchar(10)," " c4 varchar(10), c5 varchar(10), c6 varchar(10)," " c7 varchar(10), c8 varchar(10), c9 varchar(10)," "c10 varchar(10))" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 stmt_text = "INSERT INTO t1 VALUES (1,2,3,4,5,6,7,8,9,10)" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 stmt_text = "CREATE VIEW v1 AS SELECT * FROM t1" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 stmt_text = "select * from v1" ;
 rc = mysql_stmt_prepare ( stmt , stmt_text , strlen ( stmt_text ) ) ;
 check_execute ( stmt , rc ) ;
 mysql_stmt_close ( stmt ) ;
 stmt_text = "drop table if exists t1, v1" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 }
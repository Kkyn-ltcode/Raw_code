static void test_bug6761 ( void ) {
 const char * stmt_text ;
 MYSQL_RES * res ;
 int rc ;
 myheader ( "test_bug6761" ) ;
 stmt_text = "CREATE TABLE t1 (a int, b char(255), c decimal)" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 res = mysql_list_fields ( mysql , "t1" , "%" ) ;
 DIE_UNLESS ( res && mysql_num_fields ( res ) == 3 ) ;
 mysql_free_result ( res ) ;
 stmt_text = "DROP TABLE t1" ;
 rc = mysql_real_query ( mysql , stmt_text , strlen ( stmt_text ) ) ;
 myquery ( rc ) ;
 }
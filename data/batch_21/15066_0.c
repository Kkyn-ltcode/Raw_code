static void test_bug9735 ( ) {
 MYSQL_RES * res ;
 int rc ;
 myheader ( "test_bug9735" ) ;
 rc = mysql_query ( mysql , "drop table if exists t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1 (a mediumtext, b longtext) " "character set latin1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "select * from t1" ) ;
 myquery ( rc ) ;
 res = mysql_store_result ( mysql ) ;
 verify_prepare_field ( res , 0 , "a" , "a" , MYSQL_TYPE_BLOB , "t1" , "t1" , current_db , ( 1U << 24 ) - 1 , 0 ) ;
 verify_prepare_field ( res , 1 , "b" , "b" , MYSQL_TYPE_BLOB , "t1" , "t1" , current_db , ~ 0U , 0 ) ;
 mysql_free_result ( res ) ;
 rc = mysql_query ( mysql , "drop table t1" ) ;
 myquery ( rc ) ;
 }
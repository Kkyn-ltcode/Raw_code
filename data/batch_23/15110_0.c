static void test_bug53371 ( ) {
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_bug53371" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP DATABASE IF EXISTS bug53371" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP USER 'testbug'@localhost" ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 (a INT)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE DATABASE bug53371" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "GRANT SELECT ON bug53371.* to 'testbug'@localhost" ) ;
 myquery ( rc ) ;
 rc = mysql_change_user ( mysql , "testbug" , NULL , "bug53371" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "SHOW COLUMNS FROM client_test_db.t1" ) ;
 DIE_UNLESS ( rc ) ;
 DIE_UNLESS ( mysql_errno ( mysql ) == 1142 ) ;
 result = mysql_list_fields ( mysql , "../client_test_db/t1" , NULL ) ;
 DIE_IF ( result ) ;
 result = mysql_list_fields ( mysql , "#mysql50#/../client_test_db/t1" , NULL ) ;
 DIE_IF ( result ) ;
 rc = mysql_change_user ( mysql , opt_user , opt_password , current_db ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP DATABASE bug53371" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP USER 'testbug'@localhost" ) ;
 myquery ( rc ) ;
 }
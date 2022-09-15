static void test_bug21726 ( ) {
 const char * create_table [ ] = {
 "DROP TABLE IF EXISTS t1" , "CREATE TABLE t1 (i INT)" , "INSERT INTO t1 VALUES (1)" , }
 ;
 const char * update_query = "UPDATE t1 SET i= LAST_INSERT_ID(i + 1)" ;
 int rc ;
 my_ulonglong insert_id ;
 const char * select_query = "SELECT * FROM t1" ;
 MYSQL_RES * result ;
 DBUG_ENTER ( "test_bug21726" ) ;
 myheader ( "test_bug21726" ) ;
 fill_tables ( create_table , sizeof ( create_table ) / sizeof ( * create_table ) ) ;
 rc = mysql_query ( mysql , update_query ) ;
 myquery ( rc ) ;
 insert_id = mysql_insert_id ( mysql ) ;
 DIE_UNLESS ( insert_id == 2 ) ;
 rc = mysql_query ( mysql , update_query ) ;
 myquery ( rc ) ;
 insert_id = mysql_insert_id ( mysql ) ;
 DIE_UNLESS ( insert_id == 3 ) ;
 rc = mysql_query ( mysql , select_query ) ;
 myquery ( rc ) ;
 insert_id = mysql_insert_id ( mysql ) ;
 DIE_UNLESS ( insert_id == 3 ) ;
 result = mysql_store_result ( mysql ) ;
 mysql_free_result ( result ) ;
 DBUG_VOID_RETURN ;
 }
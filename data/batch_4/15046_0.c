static void test_field_names ( ) {
 int rc ;
 MYSQL_RES * result ;
 myheader ( "test_field_names" ) ;
 if ( ! opt_silent ) fprintf ( stdout , "\n %d, %d, %d" , MYSQL_TYPE_DECIMAL , MYSQL_TYPE_NEWDATE , MYSQL_TYPE_ENUM ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_field_names1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS test_field_names2" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_field_names1(id int, name varchar(50))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE test_field_names2(id int, name varchar(50))" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "SELECT id as 'id-alias' FROM test_field_names1" ) ;
 myquery ( rc ) ;
 result = mysql_use_result ( mysql ) ;
 mytest ( result ) ;
 rc = my_process_result_set ( result ) ;
 DIE_UNLESS ( rc == 0 ) ;
 mysql_free_result ( result ) ;
 rc = mysql_query ( mysql , "SELECT t1.id as 'id-alias', test_field_names2.name FROM test_field_names1 t1, test_field_names2" ) ;
 myquery ( rc ) ;
 result = mysql_use_result ( mysql ) ;
 mytest ( result ) ;
 rc = my_process_result_set ( result ) ;
 DIE_UNLESS ( rc == 0 ) ;
 mysql_free_result ( result ) ;
 }
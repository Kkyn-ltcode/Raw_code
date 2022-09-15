static void test_list_fields ( ) {
 MYSQL_RES * result ;
 int rc ;
 myheader ( "test_list_fields" ) ;
 rc = mysql_query ( mysql , "drop table if exists t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1(c1 int primary key auto_increment, c2 char(10) default 'mysql')" ) ;
 myquery ( rc ) ;
 result = mysql_list_fields ( mysql , "t1" , NULL ) ;
 mytest ( result ) ;
 rc = my_process_result_set ( result ) ;
 DIE_UNLESS ( rc == 0 ) ;
 verify_prepare_field ( result , 0 , "c1" , "c1" , MYSQL_TYPE_LONG , "t1" , "t1" , current_db , 11 , "0" ) ;
 verify_prepare_field ( result , 1 , "c2" , "c2" , MYSQL_TYPE_STRING , "t1" , "t1" , current_db , 10 , "mysql" ) ;
 mysql_free_result ( result ) ;
 myquery ( mysql_query ( mysql , "drop table t1" ) ) ;
 }
static void test_bug19671 ( ) {
 MYSQL_RES * result ;
 int rc ;
 myheader ( "test_bug19671" ) ;
 mysql_query ( mysql , "set sql_mode=''" ) ;
 rc = mysql_query ( mysql , "drop table if exists t1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "drop view if exists v1" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1(f1 int)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create view v1 as select va.* from t1 va" ) ;
 myquery ( rc ) ;
 result = mysql_list_fields ( mysql , "v1" , NULL ) ;
 mytest ( result ) ;
 rc = my_process_result_set ( result ) ;
 DIE_UNLESS ( rc == 0 ) ;
 verify_prepare_field ( result , 0 , "f1" , "f1" , MYSQL_TYPE_LONG , "v1" , "v1" , current_db , 11 , "0" ) ;
 mysql_free_result ( result ) ;
 myquery ( mysql_query ( mysql , "drop view v1" ) ) ;
 myquery ( mysql_query ( mysql , "drop table t1" ) ) ;
 }
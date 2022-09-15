static void test_bug28505 ( ) {
 my_ulonglong res ;
 myquery ( mysql_query ( mysql , "drop table if exists t1" ) ) ;
 myquery ( mysql_query ( mysql , "create table t1(f1 int primary key)" ) ) ;
 myquery ( mysql_query ( mysql , "insert into t1 values(1)" ) ) ;
 myquery ( mysql_query ( mysql , "insert into t1 values(1) on duplicate key update f1=1" ) ) ;
 res = mysql_affected_rows ( mysql ) ;
 DIE_UNLESS ( ! res ) ;
 myquery ( mysql_query ( mysql , "drop table t1" ) ) ;
 }
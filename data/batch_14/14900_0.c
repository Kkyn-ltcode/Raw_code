static void test_xjoin ( ) {
 MYSQL_STMT * stmt ;
 int rc , i ;
 const char * query = "select t.id, p1.value, n1.value, p2.value, n2.value from t3 t LEFT JOIN t1 p1 ON (p1.id=t.param1_id) LEFT JOIN t2 p2 ON (p2.id=t.param2_id) LEFT JOIN t4 n1 ON (n1.id=p1.name_id) LEFT JOIN t4 n2 ON (n2.id=p2.name_id) where t.id=1" ;
 myheader ( "test_xjoin" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1, t2, t3, t4" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t3 (id int(8), param1_id int(8), param2_id int(8)) ENGINE=InnoDB DEFAULT CHARSET=utf8" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1 ( id int(8), name_id int(8), value varchar(10)) ENGINE=InnoDB DEFAULT CHARSET=utf8" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t2 (id int(8), name_id int(8), value varchar(10)) ENGINE=InnoDB DEFAULT CHARSET=utf8;
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t4(id int(8), value varchar(10)) ENGINE=InnoDB DEFAULT CHARSET=utf8" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t3 values (1, 1, 1), (2, 2, null)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t1 values (1, 1, 'aaa'), (2, null, 'bbb')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t2 values (1, 2, 'ccc')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t4 values (1, 'Name1'), (2, null)" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 1 ) ;
 }
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1, t2, t3, t4" ) ;
 myquery ( rc ) ;
 }
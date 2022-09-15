static void test_union ( ) {
 MYSQL_STMT * stmt ;
 int rc ;
 myheader ( "test_union" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1, t2" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t1 " "(id INTEGER NOT NULL PRIMARY KEY, " " name VARCHAR(20) NOT NULL)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t1 (id, name) VALUES " "(2, 'Ja'), (3, 'Ede'), " "(4, 'Haag'), (5, 'Kabul'), " "(6, 'Almere'), (7, 'Utrecht'), " "(8, 'Qandahar'), (9, 'Amsterdam'), " "(10, 'Amersfoort'), (11, 'Constantine')" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "CREATE TABLE t2 " "(id INTEGER NOT NULL PRIMARY KEY, " " name VARCHAR(20) NOT NULL)" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "INSERT INTO t2 (id, name) VALUES " "(4, 'Guam'), (5, 'Aruba'), " "(6, 'Angola'), (7, 'Albania'), " "(8, 'Anguilla'), (9, 'Argentina'), " "(10, 'Azerbaijan'), (11, 'Afghanistan'), " "(12, 'Burkina Faso'), (13, 'Faroe Islands')" ) ;
 myquery ( rc ) ;
 stmt = mysql_simple_prepare ( mysql , "SELECT t1.name FROM t1 UNION " "SELECT t2.name FROM t2" ) ;
 check_stmt ( stmt ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 rc = my_process_stmt_result ( stmt ) ;
 DIE_UNLESS ( rc == 20 ) ;
 mysql_stmt_close ( stmt ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1, t2" ) ;
 myquery ( rc ) ;
 }
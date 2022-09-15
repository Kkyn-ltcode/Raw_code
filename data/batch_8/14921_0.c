static void test_basic_cursors ( ) {
 const char * basic_tables [ ] = {
 "DROP TABLE IF EXISTS t1, t2" , "CREATE TABLE t1 " "(id INTEGER NOT NULL PRIMARY KEY, " " name VARCHAR(20) NOT NULL)" , "INSERT INTO t1 (id, name) VALUES " " (2, 'Ja'), (3, 'Ede'), " " (4, 'Haag'), (5, 'Kabul'), " " (6, 'Almere'), (7, 'Utrecht'), " " (8, 'Qandahar'), (9, 'Amsterdam'), " " (10, 'Amersfoort'), (11, 'Constantine')" , "CREATE TABLE t2 " "(id INTEGER NOT NULL PRIMARY KEY, " " name VARCHAR(20) NOT NULL)" , "INSERT INTO t2 (id, name) VALUES " " (4, 'Guam'), (5, 'Aruba'), " " (6, 'Angola'), (7, 'Albania'), " " (8, 'Anguilla'), (9, 'Argentina'), " " (10, 'Azerbaijan'), (11, 'Afghanistan'), " " (12, 'Burkina Faso'), (13, 'Faroe Islands')" }
 ;
 const char * queries [ ] = {
 "SELECT * FROM t1" , "SELECT * FROM t2" }
 ;
 DBUG_ENTER ( "test_basic_cursors" ) ;
 myheader ( "test_basic_cursors" ) ;
 fill_tables ( basic_tables , sizeof ( basic_tables ) / sizeof ( * basic_tables ) ) ;
 fetch_n ( queries , sizeof ( queries ) / sizeof ( * queries ) , USE_ROW_BY_ROW_FETCH ) ;
 fetch_n ( queries , sizeof ( queries ) / sizeof ( * queries ) , USE_STORE_RESULT ) ;
 DBUG_VOID_RETURN ;
 }
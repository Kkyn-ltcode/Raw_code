static void test_cursors_with_union ( ) {
 const char * queries [ ] = {
 "SELECT t1.name FROM t1 UNION SELECT t2.name FROM t2" , "SELECT t1.id FROM t1 WHERE t1.id < 5" }
 ;
 myheader ( "test_cursors_with_union" ) ;
 fetch_n ( queries , sizeof ( queries ) / sizeof ( * queries ) , USE_ROW_BY_ROW_FETCH ) ;
 fetch_n ( queries , sizeof ( queries ) / sizeof ( * queries ) , USE_STORE_RESULT ) ;
 }
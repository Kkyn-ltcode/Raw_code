static void test_cursors_with_procedure ( ) {
 const char * queries [ ] = {
 "SELECT * FROM t1 procedure analyse()" }
 ;
 myheader ( "test_cursors_with_procedure" ) ;
 fetch_n ( queries , sizeof ( queries ) / sizeof ( * queries ) , USE_ROW_BY_ROW_FETCH ) ;
 fetch_n ( queries , sizeof ( queries ) / sizeof ( * queries ) , USE_STORE_RESULT ) ;
 }
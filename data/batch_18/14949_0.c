static void test_bug54041 ( ) {
 enable_query_logs ( 0 ) ;
 test_bug54041_impl ( ) ;
 disable_query_logs ( ) ;
 test_bug54041_impl ( ) ;
 restore_query_logs ( ) ;
 }
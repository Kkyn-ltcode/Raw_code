static void test_bug28075 ( ) {
 int rc ;
 DBUG_ENTER ( "test_bug28075" ) ;
 myheader ( "test_bug28075" ) ;
 rc = mysql_dump_debug_info ( mysql ) ;
 DIE_UNLESS ( rc == 0 ) ;
 rc = mysql_ping ( mysql ) ;
 DIE_UNLESS ( rc == 0 ) ;
 DBUG_VOID_RETURN ;
 }
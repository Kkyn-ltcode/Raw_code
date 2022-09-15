static void test_bug6059 ( ) {
 MYSQL_STMT * stmt ;
 const char * stmt_text ;
 myheader ( "test_bug6059" ) ;
 stmt_text = "SELECT 'foo' INTO OUTFILE 'x.3'" ;
 stmt = mysql_stmt_init ( mysql ) ;
 ( void ) mysql_stmt_prepare ( stmt , stmt_text , strlen ( stmt_text ) ) ;
 DIE_UNLESS ( mysql_stmt_field_count ( stmt ) == 0 ) ;
 mysql_stmt_close ( stmt ) ;
 }
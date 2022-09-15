static void test_bug6081 ( ) {
 int rc ;
 myheader ( "test_bug6081" ) ;
 rc = simple_command ( mysql , COM_DROP_DB , ( uchar * ) current_db , ( ulong ) strlen ( current_db ) , 0 ) ;
 if ( rc == 0 && mysql_errno ( mysql ) != ER_UNKNOWN_COM_ERROR ) {
 myerror ( NULL ) ;
 die ( __FILE__ , __LINE__ , "COM_DROP_DB failed" ) ;
 }
 rc = simple_command ( mysql , COM_DROP_DB , ( uchar * ) current_db , ( ulong ) strlen ( current_db ) , 0 ) ;
 myquery_r ( rc ) ;
 rc = simple_command ( mysql , COM_CREATE_DB , ( uchar * ) current_db , ( ulong ) strlen ( current_db ) , 0 ) ;
 if ( rc == 0 && mysql_errno ( mysql ) != ER_UNKNOWN_COM_ERROR ) {
 myerror ( NULL ) ;
 die ( __FILE__ , __LINE__ , "COM_CREATE_DB failed" ) ;
 }
 rc = simple_command ( mysql , COM_CREATE_DB , ( uchar * ) current_db , ( ulong ) strlen ( current_db ) , 0 ) ;
 myquery_r ( rc ) ;
 rc = mysql_select_db ( mysql , current_db ) ;
 myquery ( rc ) ;
 }
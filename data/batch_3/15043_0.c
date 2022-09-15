static void test_bug8378 ( ) {
 # if defined ( HAVE_CHARSET_gbk ) && ! defined ( EMBEDDED_LIBRARY ) MYSQL * lmysql ;
 char out [ 9 ] ;
 char buf [ 256 ] ;
 int len , rc ;
 myheader ( "test_bug8378" ) ;
 if ( ! opt_silent ) fprintf ( stdout , "\n Establishing a test connection ..." ) ;
 if ( ! ( lmysql = mysql_client_init ( NULL ) ) ) {
 myerror ( "mysql_client_init() failed" ) ;
 exit ( 1 ) ;
 }
 if ( mysql_options ( lmysql , MYSQL_SET_CHARSET_NAME , "gbk" ) ) {
 myerror ( "mysql_options() failed" ) ;
 exit ( 1 ) ;
 }
 if ( ! ( mysql_real_connect ( lmysql , opt_host , opt_user , opt_password , current_db , opt_port , opt_unix_socket , 0 ) ) ) {
 myerror ( "connection failed" ) ;
 exit ( 1 ) ;
 }
 if ( ! opt_silent ) fprintf ( stdout , "OK" ) ;
 rc = mysql_query ( lmysql , "SET SQL_MODE=''" ) ;
 myquery ( rc ) ;
 len = mysql_real_escape_string ( lmysql , out , TEST_BUG8378_IN , 4 ) ;
 DIE_UNLESS ( memcmp ( out , TEST_BUG8378_OUT , len ) == 0 ) ;
 sprintf ( buf , "SELECT '%s'" , out ) ;
 rc = mysql_real_query ( lmysql , buf , strlen ( buf ) ) ;
 myquery ( rc ) ;
 mysql_close ( lmysql ) ;
 # endif }
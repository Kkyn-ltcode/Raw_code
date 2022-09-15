static void test_bug10214 ( ) {
 int len ;
 char out [ 8 ] ;
 myheader ( "test_bug10214" ) ;
 DIE_UNLESS ( ! ( mysql -> server_status & SERVER_STATUS_NO_BACKSLASH_ESCAPES ) ) ;
 len = mysql_real_escape_string ( mysql , out , "a'b\\c" , 5 ) ;
 DIE_UNLESS ( memcmp ( out , "a\\'b\\\\c" , len ) == 0 ) ;
 mysql_query ( mysql , "set sql_mode='NO_BACKSLASH_ESCAPES'" ) ;
 DIE_UNLESS ( mysql -> server_status & SERVER_STATUS_NO_BACKSLASH_ESCAPES ) ;
 len = mysql_real_escape_string ( mysql , out , "a'b\\c" , 5 ) ;
 DIE_UNLESS ( memcmp ( out , "a''b\\c" , len ) == 0 ) ;
 mysql_query ( mysql , "set sql_mode=''" ) ;
 }
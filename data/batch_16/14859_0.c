static void test_bug17667 ( ) {
 int rc ;
 MYSQL_STMT * stmt ;
 enum query_type {
 QT_NORMAL , QT_PREPARED }
 ;
 struct buffer_and_length {
 enum query_type qt ;
 const char * buffer ;
 const uint length ;
 }
 statements [ ] = {
 {
 QT_NORMAL , "drop table if exists bug17667" , 29 }
 , {
 QT_NORMAL , "create table bug17667 (c varchar(20))" , 37 }
 , {
 QT_NORMAL , "insert into bug17667 (c) values ('regular') /* NUL=\0 with comment */" , 68 }
 , {
 QT_PREPARED , "insert into bug17667 (c) values ('prepared') /* NUL=\0 with comment */" , 69 , }
 , {
 QT_NORMAL , "insert into bug17667 (c) values ('NUL=\0 in value')" , 50 }
 , {
 QT_NORMAL , "insert into bug17667 (c) values ('5 NULs=\0\0\0\0\0')" , 48 }
 , {
 QT_PREPARED , "insert into bug17667 (c) values ('6 NULs=\0\0\0\0\0\0')" , 50 }
 , {
 QT_NORMAL , "/* NUL=\0 with comment */ insert into bug17667 (c) values ('encore')" , 67 }
 , {
 QT_NORMAL , "drop table bug17667" , 19 }
 , {
 QT_NORMAL , NULL , 0 }
 }
 ;
 struct buffer_and_length * statement_cursor ;
 FILE * log_file ;
 char * master_log_filename ;
 myheader ( "test_bug17667" ) ;
 master_log_filename = ( char * ) malloc ( strlen ( opt_vardir ) + strlen ( "/log/master.log" ) + 1 ) ;
 strxmov ( master_log_filename , opt_vardir , "/log/master.log" , NullS ) ;
 if ( ! opt_silent ) printf ( "Opening '%s'\n" , master_log_filename ) ;
 log_file = my_fopen ( master_log_filename , ( int ) ( O_RDONLY | O_BINARY ) , MYF ( 0 ) ) ;
 free ( master_log_filename ) ;
 if ( log_file == NULL ) {
 if ( ! opt_silent ) {
 printf ( "Could not find the log file, VARDIR/log/master.log, so " "test_bug17667 is not run.\n" "Run test from the mysql-test/mysql-test-run* program to set up " "correct environment for this test.\n\n" ) ;
 }
 return ;
 }
 enable_query_logs ( 1 ) ;
 for ( statement_cursor = statements ;
 statement_cursor -> buffer != NULL ;
 statement_cursor ++ ) {
 if ( statement_cursor -> qt == QT_NORMAL ) {
 rc = mysql_real_query ( mysql , statement_cursor -> buffer , statement_cursor -> length ) ;
 myquery ( rc ) ;
 }
 else if ( statement_cursor -> qt == QT_PREPARED ) {
 stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , statement_cursor -> buffer , statement_cursor -> length ) ;
 check_execute ( stmt , rc ) ;
 rc = mysql_stmt_execute ( stmt ) ;
 check_execute ( stmt , rc ) ;
 mysql_stmt_close ( stmt ) ;
 }
 else {
 DIE_UNLESS ( 0 == 1 ) ;
 }
 }
 rc = mysql_query ( mysql , "flush logs" ) ;
 myquery ( rc ) ;
 for ( statement_cursor = statements ;
 statement_cursor -> buffer != NULL ;
 statement_cursor ++ ) {
 int expected_hits = 1 , hits = 0 ;
 char line_buffer [ MAX_TEST_QUERY_LENGTH * 2 ] ;
 if ( statement_cursor -> qt == QT_PREPARED ) expected_hits ++ ;
 do {
 do {
 memset ( line_buffer , '/' , MAX_TEST_QUERY_LENGTH * 2 ) ;
 if ( fgets ( line_buffer , MAX_TEST_QUERY_LENGTH * 2 , log_file ) == NULL ) {
 if ( feof ( log_file ) ) DIE ( "Found EOF before all statements where found" ) ;
 fprintf ( stderr , "Got error %d while reading from file\n" , ferror ( log_file ) ) ;
 DIE ( "Read error" ) ;
 }
 }
 while ( my_memmem ( line_buffer , MAX_TEST_QUERY_LENGTH * 2 , statement_cursor -> buffer , statement_cursor -> length ) == NULL ) ;
 hits ++ ;
 }
 while ( hits < expected_hits ) ;
 if ( ! opt_silent ) printf ( "Found statement starting with \"%s\"\n" , statement_cursor -> buffer ) ;
 }
 restore_query_logs ( ) ;
 if ( ! opt_silent ) printf ( "success. All queries found intact in the log.\n" ) ;
 my_fclose ( log_file , MYF ( 0 ) ) ;
 }
static void test_create_drop ( ) {
 MYSQL_STMT * stmt_create , * stmt_drop , * stmt_select , * stmt_create_select ;
 char * query ;
 int rc , i ;
 myheader ( "test_table_manipulation" ) ;
 rc = mysql_query ( mysql , "DROP TABLE IF EXISTS t1, t2" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t2 (a int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "create table t1 (a int);
" ) ;
 myquery ( rc ) ;
 rc = mysql_query ( mysql , "insert into t2 values (3), (2), (1);
" ) ;
 myquery ( rc ) ;
 query = ( char * ) "create table t1 (a int)" ;
 stmt_create = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt_create ) ;
 query = ( char * ) "drop table t1" ;
 stmt_drop = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt_drop ) ;
 query = ( char * ) "select a in (select a from t2) from t1" ;
 stmt_select = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt_select ) ;
 rc = mysql_query ( mysql , "DROP TABLE t1" ) ;
 myquery ( rc ) ;
 query = ( char * ) "create table t1 select a from t2" ;
 stmt_create_select = mysql_simple_prepare ( mysql , query ) ;
 check_stmt ( stmt_create_select ) ;
 for ( i = 0 ;
 i < 3 ;
 i ++ ) {
 rc = mysql_stmt_execute ( stmt_create ) ;
 check_execute ( stmt_create , rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "created %i\n" , i ) ;
 rc = mysql_stmt_execute ( stmt_select ) ;
 check_execute ( stmt_select , rc ) ;
 rc = my_process_stmt_result ( stmt_select ) ;
 DIE_UNLESS ( rc == 0 ) ;
 rc = mysql_stmt_execute ( stmt_drop ) ;
 check_execute ( stmt_drop , rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "dropped %i\n" , i ) ;
 rc = mysql_stmt_execute ( stmt_create_select ) ;
 check_execute ( stmt_create , rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "created select %i\n" , i ) ;
 rc = mysql_stmt_execute ( stmt_select ) ;
 check_execute ( stmt_select , rc ) ;
 rc = my_process_stmt_result ( stmt_select ) ;
 DIE_UNLESS ( rc == 3 ) ;
 rc = mysql_stmt_execute ( stmt_drop ) ;
 check_execute ( stmt_drop , rc ) ;
 if ( ! opt_silent ) fprintf ( stdout , "dropped %i\n" , i ) ;
 }
 mysql_stmt_close ( stmt_create ) ;
 mysql_stmt_close ( stmt_drop ) ;
 mysql_stmt_close ( stmt_select ) ;
 mysql_stmt_close ( stmt_create_select ) ;
 rc = mysql_query ( mysql , "DROP TABLE t2" ) ;
 myquery ( rc ) ;
 }
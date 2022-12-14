static void test_bug20023 ( ) {
 MYSQL con ;
 int sql_big_selects_orig = 0 ;
 char max_join_size_orig [ 32 ] ;
 int sql_big_selects_2 = 0 ;
 int sql_big_selects_3 = 0 ;
 int sql_big_selects_4 = 0 ;
 int sql_big_selects_5 = 0 ;
 char query_buffer [ MAX_TEST_QUERY_LENGTH ] ;
 DIE_UNLESS ( mysql_client_init ( & con ) ) ;
 DIE_UNLESS ( mysql_real_connect ( & con , opt_host , opt_user , opt_password , opt_db ? opt_db : "test" , opt_port , opt_unix_socket , CLIENT_FOUND_ROWS ) ) ;
 query_int_variable ( & con , "@@session.sql_big_selects" , & sql_big_selects_orig ) ;
 query_str_variable ( & con , "@@global.max_join_size" , max_join_size_orig , sizeof ( max_join_size_orig ) ) ;
 bug20023_change_user ( & con ) ;
 query_int_variable ( & con , "@@session.sql_big_selects" , & sql_big_selects_2 ) ;
 DIE_UNLESS ( sql_big_selects_orig == sql_big_selects_2 ) ;
 DIE_IF ( mysql_query ( & con , "SET @@global.max_join_size = 10000" ) ) ;
 DIE_IF ( mysql_query ( & con , "SET @@session.max_join_size = default" ) ) ;
 bug20023_change_user ( & con ) ;
 query_int_variable ( & con , "@@session.sql_big_selects" , & sql_big_selects_3 ) ;
 DIE_UNLESS ( sql_big_selects_3 == 0 ) ;
 DIE_IF ( mysql_query ( & con , "SET @@global.max_join_size = cast(-1 as unsigned int)" ) ) ;
 DIE_IF ( mysql_query ( & con , "SET @@session.max_join_size = default" ) ) ;
 bug20023_change_user ( & con ) ;
 query_int_variable ( & con , "@@session.sql_big_selects" , & sql_big_selects_4 ) ;
 DIE_UNLESS ( sql_big_selects_4 == 1 ) ;
 my_snprintf ( query_buffer , sizeof ( query_buffer ) , "SET @@global.max_join_size = %s" , max_join_size_orig ) ;
 DIE_IF ( mysql_query ( & con , query_buffer ) ) ;
 DIE_IF ( mysql_query ( & con , "SET @@global.max_join_size = cast(-1 as unsigned int)" ) ) ;
 DIE_IF ( mysql_query ( & con , "SET @@session.max_join_size = default" ) ) ;
 bug20023_change_user ( & con ) ;
 query_int_variable ( & con , "@@session.sql_big_selects" , & sql_big_selects_5 ) ;
 DIE_UNLESS ( sql_big_selects_5 == sql_big_selects_orig ) ;
 mysql_close ( & con ) ;
 }
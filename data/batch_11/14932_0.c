static void test_bug16144 ( ) {
 const my_bool flag_orig = ( my_bool ) 0xde ;
 my_bool flag = flag_orig ;
 MYSQL_STMT * stmt ;
 myheader ( "test_bug16144" ) ;
 stmt = mysql_stmt_init ( mysql ) ;
 mysql_stmt_attr_set ( stmt , STMT_ATTR_UPDATE_MAX_LENGTH , ( const void * ) & flag ) ;
 mysql_stmt_attr_get ( stmt , STMT_ATTR_UPDATE_MAX_LENGTH , ( void * ) & flag ) ;
 DIE_UNLESS ( flag == flag_orig ) ;
 mysql_stmt_close ( stmt ) ;
 }
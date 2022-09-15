MYSQL_STMT * open_cursor ( const char * query ) {
 int rc ;
 const ulong type = ( ulong ) CURSOR_TYPE_READ_ONLY ;
 MYSQL_STMT * stmt = mysql_stmt_init ( mysql ) ;
 rc = mysql_stmt_prepare ( stmt , query , strlen ( query ) ) ;
 check_execute ( stmt , rc ) ;
 mysql_stmt_attr_set ( stmt , STMT_ATTR_CURSOR_TYPE , ( void * ) & type ) ;
 return stmt ;
 }
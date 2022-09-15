static int dump_tablespaces_for_databases ( char * * databases ) {
 DYNAMIC_STRING where ;
 int r ;
 int i ;
 init_dynamic_string_checked ( & where , " AND TABLESPACE_NAME IN (" "SELECT DISTINCT TABLESPACE_NAME FROM" " INFORMATION_SCHEMA.PARTITIONS" " WHERE" " TABLE_SCHEMA IN (" , 256 , 1024 ) ;
 for ( i = 0 ;
 databases [ i ] != NULL ;
 i ++ ) {
 char db_name_buff [ NAME_LEN * 2 + 3 ] ;
 mysql_real_escape_string ( mysql , db_name_buff , databases [ i ] , ( ulong ) strlen ( databases [ i ] ) ) ;
 dynstr_append_checked ( & where , "'" ) ;
 dynstr_append_checked ( & where , db_name_buff ) ;
 dynstr_append_checked ( & where , "'," ) ;
 }
 dynstr_trunc ( & where , 1 ) ;
 dynstr_append_checked ( & where , "))" ) ;
 DBUG_PRINT ( "info" , ( "Dump TS for DBs where: %s" , where . str ) ) ;
 r = dump_tablespaces ( where . str ) ;
 dynstr_free ( & where ) ;
 return r ;
 }
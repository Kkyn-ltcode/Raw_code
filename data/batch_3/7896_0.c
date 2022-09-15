static int dump_tablespaces_for_tables ( char * db , char * * table_names , int tables ) {
 DYNAMIC_STRING where ;
 int r ;
 int i ;
 char name_buff [ NAME_LEN * 2 + 3 ] ;
 mysql_real_escape_string ( mysql , name_buff , db , ( ulong ) strlen ( db ) ) ;
 init_dynamic_string_checked ( & where , " AND TABLESPACE_NAME IN (" "SELECT DISTINCT TABLESPACE_NAME FROM" " INFORMATION_SCHEMA.PARTITIONS" " WHERE" " TABLE_SCHEMA='" , 256 , 1024 ) ;
 dynstr_append_checked ( & where , name_buff ) ;
 dynstr_append_checked ( & where , "' AND TABLE_NAME IN (" ) ;
 for ( i = 0 ;
 i < tables ;
 i ++ ) {
 mysql_real_escape_string ( mysql , name_buff , table_names [ i ] , ( ulong ) strlen ( table_names [ i ] ) ) ;
 dynstr_append_checked ( & where , "'" ) ;
 dynstr_append_checked ( & where , name_buff ) ;
 dynstr_append_checked ( & where , "'," ) ;
 }
 dynstr_trunc ( & where , 1 ) ;
 dynstr_append_checked ( & where , "))" ) ;
 DBUG_PRINT ( "info" , ( "Dump TS for Tables where: %s" , where . str ) ) ;
 r = dump_tablespaces ( where . str ) ;
 dynstr_free ( & where ) ;
 return r ;
 }
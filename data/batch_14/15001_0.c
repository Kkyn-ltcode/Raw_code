static void bug30472_retrieve_charset_info ( MYSQL * con , char * character_set_name , char * character_set_client , char * character_set_results , char * collation_connection ) {
 MYSQL_RES * rs ;
 MYSQL_ROW row ;
 strcpy ( character_set_name , mysql_character_set_name ( con ) ) ;
 DIE_IF ( mysql_query ( con , "SHOW VARIABLES LIKE 'character_set_client'" ) ) ;
 DIE_UNLESS ( rs = mysql_store_result ( con ) ) ;
 DIE_UNLESS ( row = mysql_fetch_row ( rs ) ) ;
 strcpy ( character_set_client , row [ 1 ] ) ;
 mysql_free_result ( rs ) ;
 DIE_IF ( mysql_query ( con , "SHOW VARIABLES LIKE 'character_set_results'" ) ) ;
 DIE_UNLESS ( rs = mysql_store_result ( con ) ) ;
 DIE_UNLESS ( row = mysql_fetch_row ( rs ) ) ;
 strcpy ( character_set_results , row [ 1 ] ) ;
 mysql_free_result ( rs ) ;
 DIE_IF ( mysql_query ( con , "SHOW VARIABLES LIKE 'collation_connection'" ) ) ;
 DIE_UNLESS ( rs = mysql_store_result ( con ) ) ;
 DIE_UNLESS ( row = mysql_fetch_row ( rs ) ) ;
 strcpy ( collation_connection , row [ 1 ] ) ;
 mysql_free_result ( rs ) ;
 }
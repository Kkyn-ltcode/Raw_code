static void init_sql_statement_names ( ) {
 char * first_com = ( char * ) offsetof ( STATUS_VAR , com_stat [ 0 ] ) ;
 char * last_com = ( char * ) offsetof ( STATUS_VAR , com_stat [ ( uint ) SQLCOM_END ] ) ;
 int record_size = ( char * ) offsetof ( STATUS_VAR , com_stat [ 1 ] ) - ( char * ) offsetof ( STATUS_VAR , com_stat [ 0 ] ) ;
 char * ptr ;
 uint i ;
 uint com_index ;
 for ( i = 0 ;
 i < ( ( uint ) SQLCOM_END + 1 ) ;
 i ++ ) sql_statement_names [ i ] = empty_lex_str ;
 SHOW_VAR * var = & com_status_vars [ 0 ] ;
 while ( var -> name != NULL ) {
 ptr = var -> value ;
 if ( ( first_com <= ptr ) && ( ptr <= last_com ) ) {
 com_index = ( ( int ) ( ptr - first_com ) ) / record_size ;
 DBUG_ASSERT ( com_index < ( uint ) SQLCOM_END ) ;
 sql_statement_names [ com_index ] . str = const_cast < char * > ( var -> name ) ;
 sql_statement_names [ com_index ] . length = strlen ( var -> name ) ;
 }
 var ++ ;
 }
 DBUG_ASSERT ( strcmp ( sql_statement_names [ ( uint ) SQLCOM_SELECT ] . str , "select" ) == 0 ) ;
 DBUG_ASSERT ( strcmp ( sql_statement_names [ ( uint ) SQLCOM_SIGNAL ] . str , "signal" ) == 0 ) ;
 sql_statement_names [ ( uint ) SQLCOM_END ] . str = const_cast < char * > ( "error" ) ;
 }
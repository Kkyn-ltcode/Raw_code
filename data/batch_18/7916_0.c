static int switch_db_collation ( FILE * sql_file , const char * db_name , const char * delimiter , const char * current_db_cl_name , const char * required_db_cl_name , int * db_cl_altered ) {
 if ( strcmp ( current_db_cl_name , required_db_cl_name ) != 0 ) {
 char quoted_db_buf [ NAME_LEN * 2 + 3 ] ;
 char * quoted_db_name = quote_name ( db_name , quoted_db_buf , FALSE ) ;
 CHARSET_INFO * db_cl = get_charset_by_name ( required_db_cl_name , MYF ( 0 ) ) ;
 if ( ! db_cl ) return 1 ;
 fprintf ( sql_file , "ALTER DATABASE %s CHARACTER SET %s COLLATE %s %s\n" , ( const char * ) quoted_db_name , ( const char * ) db_cl -> csname , ( const char * ) db_cl -> name , ( const char * ) delimiter ) ;
 * db_cl_altered = 1 ;
 return 0 ;
 }
 * db_cl_altered = 0 ;
 return 0 ;
 }
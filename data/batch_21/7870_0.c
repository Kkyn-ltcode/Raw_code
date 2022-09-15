static void print_xml_row ( FILE * xml_file , const char * row_name , MYSQL_RES * tableRes , MYSQL_ROW * row , const char * str_create ) {
 uint i ;
 my_bool body_found __attribute__ ( ( unused ) ) = 0 ;
 char * create_stmt_ptr = NULL ;
 ulong create_stmt_len = 0 ;
 MYSQL_FIELD * field ;
 ulong * lengths = mysql_fetch_lengths ( tableRes ) ;
 fprintf ( xml_file , "\t\t<%s" , row_name ) ;
 check_io ( xml_file ) ;
 mysql_field_seek ( tableRes , 0 ) ;
 for ( i = 0 ;
 ( field = mysql_fetch_field ( tableRes ) ) ;
 i ++ ) {
 if ( ( * row ) [ i ] ) {
 if ( ( str_create ) && ( strcmp ( str_create , field -> name ) == 0 ) ) {
 create_stmt_ptr = ( * row ) [ i ] ;
 create_stmt_len = lengths [ i ] ;
 # ifndef DBUG_OFF body_found = 1 ;
 # endif }
 else {
 fputc ( ' ' , xml_file ) ;
 print_quoted_xml ( xml_file , field -> name , field -> name_length , 1 ) ;
 fputs ( "=\"" , xml_file ) ;
 print_quoted_xml ( xml_file , ( * row ) [ i ] , lengths [ i ] , 0 ) ;
 fputc ( '"' , xml_file ) ;
 check_io ( xml_file ) ;
 }
 }
 }
 if ( create_stmt_len ) {
 DBUG_ASSERT ( body_found ) ;
 fputs ( ">\n" , xml_file ) ;
 print_xml_cdata ( xml_file , create_stmt_ptr , create_stmt_len ) ;
 fprintf ( xml_file , "\t\t</%s>\n" , row_name ) ;
 }
 else fputs ( " />\n" , xml_file ) ;
 check_io ( xml_file ) ;
 }
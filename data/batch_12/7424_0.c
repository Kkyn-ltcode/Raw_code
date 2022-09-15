void close_files ( ) {
 DBUG_ENTER ( "close_files" ) ;
 for ( ;
 cur_file >= file_stack ;
 cur_file -- ) {
 if ( cur_file -> file && cur_file -> file != stdin ) {
 DBUG_PRINT ( "info" , ( "closing file: %s" , cur_file -> file_name ) ) ;
 fclose ( cur_file -> file ) ;
 }
 my_free ( cur_file -> file_name ) ;
 cur_file -> file_name = 0 ;
 }
 DBUG_VOID_RETURN ;
 }
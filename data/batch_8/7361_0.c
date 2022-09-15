static int get_list_files ( DYNAMIC_STRING * ds , const DYNAMIC_STRING * ds_dirname , const DYNAMIC_STRING * ds_wild ) {
 uint i ;
 MY_DIR * dir_info ;
 FILEINFO * file ;
 DBUG_ENTER ( "get_list_files" ) ;
 DBUG_PRINT ( "info" , ( "listing directory: %s" , ds_dirname -> str ) ) ;
 if ( ! ( dir_info = my_dir ( ds_dirname -> str , MYF ( 0 ) ) ) ) DBUG_RETURN ( 1 ) ;
 set_wild_chars ( 1 ) ;
 for ( i = 0 ;
 i < ( uint ) dir_info -> number_off_files ;
 i ++ ) {
 file = dir_info -> dir_entry + i ;
 if ( file -> name [ 0 ] == '.' && ( file -> name [ 1 ] == '\0' || ( file -> name [ 1 ] == '.' && file -> name [ 2 ] == '\0' ) ) ) continue ;
 if ( ds_wild && ds_wild -> length && wild_compare ( file -> name , ds_wild -> str , 0 ) ) continue ;
 replace_dynstr_append ( ds , file -> name ) ;
 dynstr_append ( ds , "\n" ) ;
 }
 set_wild_chars ( 0 ) ;
 my_dirend ( dir_info ) ;
 DBUG_RETURN ( 0 ) ;
 }
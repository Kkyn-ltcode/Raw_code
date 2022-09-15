static void test_read_format_mtree3 ( void ) {
 static char archive [ ] = "#mtree\n" "a type=file contents=file\n" "b type=link link=a\n" "c type=file contents=file\n" ;
 struct archive_entry * ae ;
 struct archive * a ;
 assertMakeDir ( "mtree3" , 0777 ) ;
 assertChdir ( "mtree3" ) ;
 assertMakeFile ( "file" , 0644 , "file contents" ) ;
 assert ( ( a = archive_read_new ( ) ) != NULL ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_support_filter_all ( a ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_support_format_all ( a ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_set_options ( a , "mtree:checkfs" ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_open_memory ( a , archive , sizeof ( archive ) ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "a" ) ;
 assertEqualInt ( archive_entry_filetype ( ae ) , AE_IFREG ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "b" ) ;
 assertEqualInt ( archive_entry_filetype ( ae ) , AE_IFLNK ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "c" ) ;
 assertEqualInt ( archive_entry_filetype ( ae ) , AE_IFREG ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_EOF , archive_read_next_header ( a , & ae ) ) ;
 assertEqualInt ( 3 , archive_file_count ( a ) ) ;
 assertEqualInt ( ARCHIVE_OK , archive_read_close ( a ) ) ;
 assertEqualInt ( ARCHIVE_OK , archive_read_free ( a ) ) ;
 assertChdir ( ".." ) ;
 }
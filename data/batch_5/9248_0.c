DEFINE_TEST ( test_read_format_mtree_filenames_only ) {
 static char archive [ ] = "/set type=file mode=0644\n" "./a\n" "./b\n" "./c\n" "./d\n" "./e\n" "./f mode=0444\n" ;
 struct archive_entry * ae ;
 struct archive * a ;
 assertMakeFile ( "file" , 0644 , "file contents" ) ;
 assert ( ( a = archive_read_new ( ) ) != NULL ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_support_filter_all ( a ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_support_format_all ( a ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_set_options ( a , "mtree:checkfs" ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_open_memory ( a , archive , sizeof ( archive ) ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "./a" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0644 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "./b" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0644 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "./c" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0644 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "./d" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0644 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "./e" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0644 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "./f" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0444 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_EOF , archive_read_next_header ( a , & ae ) ) ;
 assertEqualInt ( 6 , archive_file_count ( a ) ) ;
 assertEqualInt ( ARCHIVE_OK , archive_read_close ( a ) ) ;
 assertEqualInt ( ARCHIVE_OK , archive_read_free ( a ) ) ;
 }
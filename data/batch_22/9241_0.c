static void test_read_format_mtree1 ( void ) {
 const char reffile [ ] = "test_read_format_mtree.mtree" ;
 char buff [ 16 ] ;
 struct archive_entry * ae ;
 struct archive * a ;
 FILE * f ;
 static const long long max_int64 = ( ( ( ( long long ) 1 ) << 62 ) - 1 ) + ( ( ( long long ) 1 ) << 62 ) ;
 time_t min_time ;
 volatile time_t t ;
 extract_reference_file ( reffile ) ;
 assertMakeDir ( "dir" , 0775 ) ;
 assertMakeDir ( "dir2" , 0775 ) ;
 assert ( ( a = archive_read_new ( ) ) != NULL ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_support_filter_all ( a ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_support_format_all ( a ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_set_options ( a , "mtree:checkfs" ) ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_open_filename ( a , reffile , 11 ) ) ;
 f = fopen ( "file" , "wb" ) ;
 assert ( f != NULL ) ;
 assertEqualInt ( 3 , fwrite ( "hi\n" , 1 , 3 , f ) ) ;
 fclose ( f ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualInt ( archive_format ( a ) , ARCHIVE_FORMAT_MTREE ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "file" ) ;
 assertEqualInt ( archive_entry_uid ( ae ) , 18 ) ;
 assertEqualInt ( AE_IFREG , archive_entry_filetype ( ae ) ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0123 ) ;
 assertEqualInt ( archive_entry_size ( ae ) , 3 ) ;
 assertEqualInt ( 3 , archive_read_data ( a , buff , 3 ) ) ;
 assertEqualMem ( buff , "hi\n" , 3 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir" ) ;
 assertEqualInt ( AE_IFDIR , archive_entry_filetype ( ae ) ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir/file with space" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "file with space" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/dir3a" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/dir3a/indir3a" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/fullindir2" ) ;
 assertEqualInt ( archive_entry_mode ( ae ) , AE_IFREG | 0644 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/indir2" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/dir3b" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/dir3b/indir3b" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/dir3b/filename\\with_esc\b\t\fapes" ) ;
 assertEqualInt ( archive_entry_filetype ( ae ) , AE_IFREG ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "notindir" ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/emptyfile" ) ;
 assertEqualInt ( archive_entry_size ( ae ) , 0 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/smallfile" ) ;
 assertEqualInt ( archive_entry_size ( ae ) , 1 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/toosmallfile" ) ;
 assertEqualInt ( archive_entry_size ( ae ) , - 1 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/bigfile" ) ;
 assertEqualInt ( archive_entry_size ( ae ) , max_int64 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/toobigfile" ) ;
 assertEqualInt ( archive_entry_size ( ae ) , max_int64 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/veryoldfile" ) ;
 min_time = archive_entry_mtime ( ae ) ;
 assert ( min_time <= 0 ) ;
 t = min_time - 1 ;
 assert ( t > 0 ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_OK , archive_read_next_header ( a , & ae ) ) ;
 assertEqualString ( archive_entry_pathname ( ae ) , "dir2/toooldfile" ) ;
 assertEqualInt ( archive_entry_mtime ( ae ) , min_time ) ;
 assertEqualInt ( archive_entry_is_encrypted ( ae ) , 0 ) ;
 assertEqualIntA ( a , archive_read_has_encrypted_entries ( a ) , ARCHIVE_READ_FORMAT_ENCRYPTION_UNSUPPORTED ) ;
 assertEqualIntA ( a , ARCHIVE_EOF , archive_read_next_header ( a , & ae ) ) ;
 assertEqualInt ( 20 , archive_file_count ( a ) ) ;
 assertEqualInt ( ARCHIVE_OK , archive_read_close ( a ) ) ;
 assertEqualInt ( ARCHIVE_OK , archive_read_free ( a ) ) ;
 }
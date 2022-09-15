static void mode_pass ( struct cpio * cpio , const char * destdir ) {
 struct lafe_line_reader * lr ;
 const char * p ;
 int r ;
 cpio -> destdir = malloc ( strlen ( destdir ) + 8 ) ;
 strcpy ( cpio -> destdir , destdir ) ;
 if ( destdir [ strlen ( destdir ) - 1 ] != '/' ) strcat ( cpio -> destdir , "/" ) ;
 cpio -> archive = archive_write_disk_new ( ) ;
 if ( cpio -> archive == NULL ) lafe_errc ( 1 , 0 , "Failed to allocate archive object" ) ;
 r = archive_write_disk_set_options ( cpio -> archive , cpio -> extract_flags ) ;
 if ( r != ARCHIVE_OK ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive ) ) ;
 cpio -> linkresolver = archive_entry_linkresolver_new ( ) ;
 archive_write_disk_set_standard_lookup ( cpio -> archive ) ;
 cpio -> archive_read_disk = archive_read_disk_new ( ) ;
 if ( cpio -> archive_read_disk == NULL ) lafe_errc ( 1 , 0 , "Failed to allocate archive object" ) ;
 if ( cpio -> option_follow_links ) archive_read_disk_set_symlink_logical ( cpio -> archive_read_disk ) ;
 else archive_read_disk_set_symlink_physical ( cpio -> archive_read_disk ) ;
 archive_read_disk_set_standard_lookup ( cpio -> archive_read_disk ) ;
 lr = lafe_line_reader ( "-" , cpio -> option_null ) ;
 while ( ( p = lafe_line_reader_next ( lr ) ) != NULL ) file_to_archive ( cpio , p ) ;
 lafe_line_reader_free ( lr ) ;
 archive_entry_linkresolver_free ( cpio -> linkresolver ) ;
 r = archive_write_close ( cpio -> archive ) ;
 if ( cpio -> dot ) fprintf ( stderr , "\n" ) ;
 if ( r != ARCHIVE_OK ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive ) ) ;
 if ( ! cpio -> quiet ) {
 int64_t blocks = ( archive_filter_bytes ( cpio -> archive , 0 ) + 511 ) / 512 ;
 fprintf ( stderr , "%lu %s\n" , ( unsigned long ) blocks , blocks == 1 ? "block" : "blocks" ) ;
 }
 archive_write_free ( cpio -> archive ) ;
 }
static void mode_out ( struct cpio * cpio ) {
 struct archive_entry * entry , * spare ;
 struct lafe_line_reader * lr ;
 const char * p ;
 int r ;
 if ( cpio -> option_append ) lafe_errc ( 1 , 0 , "Append mode not yet supported." ) ;
 cpio -> archive_read_disk = archive_read_disk_new ( ) ;
 if ( cpio -> archive_read_disk == NULL ) lafe_errc ( 1 , 0 , "Failed to allocate archive object" ) ;
 if ( cpio -> option_follow_links ) archive_read_disk_set_symlink_logical ( cpio -> archive_read_disk ) ;
 else archive_read_disk_set_symlink_physical ( cpio -> archive_read_disk ) ;
 archive_read_disk_set_standard_lookup ( cpio -> archive_read_disk ) ;
 cpio -> archive = archive_write_new ( ) ;
 if ( cpio -> archive == NULL ) lafe_errc ( 1 , 0 , "Failed to allocate archive object" ) ;
 switch ( cpio -> compress ) {
 case OPTION_GRZIP : r = archive_write_add_filter_grzip ( cpio -> archive ) ;
 break ;
 case 'J' : r = archive_write_add_filter_xz ( cpio -> archive ) ;
 break ;
 case OPTION_LRZIP : r = archive_write_add_filter_lrzip ( cpio -> archive ) ;
 break ;
 case OPTION_LZ4 : r = archive_write_add_filter_lz4 ( cpio -> archive ) ;
 break ;
 case OPTION_LZMA : r = archive_write_add_filter_lzma ( cpio -> archive ) ;
 break ;
 case OPTION_LZOP : r = archive_write_add_filter_lzop ( cpio -> archive ) ;
 break ;
 case 'j' : case 'y' : r = archive_write_add_filter_bzip2 ( cpio -> archive ) ;
 break ;
 case 'z' : r = archive_write_add_filter_gzip ( cpio -> archive ) ;
 break ;
 case 'Z' : r = archive_write_add_filter_compress ( cpio -> archive ) ;
 break ;
 default : r = archive_write_add_filter_none ( cpio -> archive ) ;
 break ;
 }
 if ( r < ARCHIVE_WARN ) lafe_errc ( 1 , 0 , "Requested compression not available" ) ;
 switch ( cpio -> add_filter ) {
 case 0 : r = ARCHIVE_OK ;
 break ;
 case OPTION_B64ENCODE : r = archive_write_add_filter_b64encode ( cpio -> archive ) ;
 break ;
 case OPTION_UUENCODE : r = archive_write_add_filter_uuencode ( cpio -> archive ) ;
 break ;
 }
 if ( r < ARCHIVE_WARN ) lafe_errc ( 1 , 0 , "Requested filter not available" ) ;
 r = archive_write_set_format_by_name ( cpio -> archive , cpio -> format ) ;
 if ( r != ARCHIVE_OK ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive ) ) ;
 archive_write_set_bytes_per_block ( cpio -> archive , cpio -> bytes_per_block ) ;
 cpio -> linkresolver = archive_entry_linkresolver_new ( ) ;
 archive_entry_linkresolver_set_strategy ( cpio -> linkresolver , archive_format ( cpio -> archive ) ) ;
 if ( cpio -> passphrase != NULL ) r = archive_write_set_passphrase ( cpio -> archive , cpio -> passphrase ) ;
 else r = archive_write_set_passphrase_callback ( cpio -> archive , cpio , & passphrase_callback ) ;
 if ( r != ARCHIVE_OK ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive ) ) ;
 r = archive_write_open_filename ( cpio -> archive , cpio -> filename ) ;
 if ( r != ARCHIVE_OK ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive ) ) ;
 lr = lafe_line_reader ( "-" , cpio -> option_null ) ;
 while ( ( p = lafe_line_reader_next ( lr ) ) != NULL ) file_to_archive ( cpio , p ) ;
 lafe_line_reader_free ( lr ) ;
 entry = NULL ;
 archive_entry_linkify ( cpio -> linkresolver , & entry , & spare ) ;
 while ( entry != NULL ) {
 entry_to_archive ( cpio , entry ) ;
 archive_entry_free ( entry ) ;
 entry = NULL ;
 archive_entry_linkify ( cpio -> linkresolver , & entry , & spare ) ;
 }
 r = archive_write_close ( cpio -> archive ) ;
 if ( cpio -> dot ) fprintf ( stderr , "\n" ) ;
 if ( r != ARCHIVE_OK ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive ) ) ;
 if ( ! cpio -> quiet ) {
 int64_t blocks = ( archive_filter_bytes ( cpio -> archive , 0 ) + 511 ) / 512 ;
 fprintf ( stderr , "%lu %s\n" , ( unsigned long ) blocks , blocks == 1 ? "block" : "blocks" ) ;
 }
 archive_write_free ( cpio -> archive ) ;
 }
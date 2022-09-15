static int file_to_archive ( struct cpio * cpio , const char * srcpath ) {
 const char * destpath ;
 struct archive_entry * entry , * spare ;
 size_t len ;
 int r ;
 entry = archive_entry_new ( ) ;
 if ( entry == NULL ) lafe_errc ( 1 , 0 , "Couldn't allocate entry" ) ;
 archive_entry_copy_sourcepath ( entry , srcpath ) ;
 r = archive_read_disk_entry_from_file ( cpio -> archive_read_disk , entry , - 1 , NULL ) ;
 if ( r < ARCHIVE_FAILED ) lafe_errc ( 1 , 0 , "%s" , archive_error_string ( cpio -> archive_read_disk ) ) ;
 if ( r < ARCHIVE_OK ) lafe_warnc ( 0 , "%s" , archive_error_string ( cpio -> archive_read_disk ) ) ;
 if ( r <= ARCHIVE_FAILED ) {
 cpio -> return_value = 1 ;
 return ( r ) ;
 }
 if ( cpio -> uid_override >= 0 ) {
 archive_entry_set_uid ( entry , cpio -> uid_override ) ;
 archive_entry_set_uname ( entry , cpio -> uname_override ) ;
 }
 if ( cpio -> gid_override >= 0 ) {
 archive_entry_set_gid ( entry , cpio -> gid_override ) ;
 archive_entry_set_gname ( entry , cpio -> gname_override ) ;
 }
 destpath = srcpath ;
 if ( cpio -> destdir ) {
 len = strlen ( cpio -> destdir ) + strlen ( srcpath ) + 8 ;
 if ( len >= cpio -> pass_destpath_alloc ) {
 while ( len >= cpio -> pass_destpath_alloc ) {
 cpio -> pass_destpath_alloc += 512 ;
 cpio -> pass_destpath_alloc *= 2 ;
 }
 free ( cpio -> pass_destpath ) ;
 cpio -> pass_destpath = malloc ( cpio -> pass_destpath_alloc ) ;
 if ( cpio -> pass_destpath == NULL ) lafe_errc ( 1 , ENOMEM , "Can't allocate path buffer" ) ;
 }
 strcpy ( cpio -> pass_destpath , cpio -> destdir ) ;
 strcat ( cpio -> pass_destpath , remove_leading_slash ( srcpath ) ) ;
 destpath = cpio -> pass_destpath ;
 }
 if ( cpio -> option_rename ) destpath = cpio_rename ( destpath ) ;
 if ( destpath == NULL ) return ( 0 ) ;
 archive_entry_copy_pathname ( entry , destpath ) ;
 spare = NULL ;
 if ( cpio -> linkresolver != NULL && archive_entry_filetype ( entry ) != AE_IFDIR ) {
 archive_entry_linkify ( cpio -> linkresolver , & entry , & spare ) ;
 }
 if ( entry != NULL ) {
 r = entry_to_archive ( cpio , entry ) ;
 archive_entry_free ( entry ) ;
 if ( spare != NULL ) {
 if ( r == 0 ) r = entry_to_archive ( cpio , spare ) ;
 archive_entry_free ( spare ) ;
 }
 }
 return ( r ) ;
 }
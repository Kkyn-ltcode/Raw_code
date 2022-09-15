static void scan_dir ( GFile * dir , SourceInfo * source_info , CommonJob * job , GQueue * dirs , GHashTable * scanned ) {
 GFileInfo * info ;
 GError * error ;
 GFile * subdir ;
 GFileEnumerator * enumerator ;
 char * primary , * secondary , * details ;
 int response ;
 SourceInfo saved_info ;
 saved_info = * source_info ;
 retry : error = NULL ;
 enumerator = g_file_enumerate_children ( dir , G_FILE_ATTRIBUTE_STANDARD_NAME "," G_FILE_ATTRIBUTE_STANDARD_TYPE "," G_FILE_ATTRIBUTE_STANDARD_SIZE , G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS , job -> cancellable , & error ) ;
 if ( enumerator ) {
 error = NULL ;
 while ( ( info = g_file_enumerator_next_file ( enumerator , job -> cancellable , & error ) ) != NULL ) {
 g_autoptr ( GFile ) file = NULL ;
 g_autofree char * file_uri = NULL ;
 file = g_file_enumerator_get_child ( enumerator , info ) ;
 file_uri = g_file_get_uri ( file ) ;
 if ( ! g_hash_table_contains ( scanned , file_uri ) ) {
 g_hash_table_add ( scanned , g_strdup ( file_uri ) ) ;
 count_file ( info , job , source_info ) ;
 if ( g_file_info_get_file_type ( info ) == G_FILE_TYPE_DIRECTORY ) {
 subdir = g_file_get_child ( dir , g_file_info_get_name ( info ) ) ;
 g_queue_push_head ( dirs , subdir ) ;
 }
 }
 g_object_unref ( info ) ;
 }
 g_file_enumerator_close ( enumerator , job -> cancellable , NULL ) ;
 g_object_unref ( enumerator ) ;
 if ( error && IS_IO_ERROR ( error , CANCELLED ) ) {
 g_error_free ( error ) ;
 }
 else if ( error ) {
 primary = get_scan_primary ( source_info -> op ) ;
 details = NULL ;
 if ( IS_IO_ERROR ( error , PERMISSION_DENIED ) ) {
 secondary = f ( _ ( "Files in the folder “%B” cannot be handled because you do " "not have permissions to see them." ) , dir ) ;
 }
 else {
 secondary = f ( _ ( "There was an error getting information about the files in the folder “%B”." ) , dir ) ;
 details = error -> message ;
 }
 response = run_warning ( job , primary , secondary , details , FALSE , CANCEL , RETRY , SKIP , NULL ) ;
 g_error_free ( error ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( job ) ;
 }
 else if ( response == 1 ) {
 * source_info = saved_info ;
 goto retry ;
 }
 else if ( response == 2 ) {
 skip_readdir_error ( job , dir ) ;
 }
 else {
 g_assert_not_reached ( ) ;
 }
 }
 }
 else if ( job -> skip_all_error ) {
 g_error_free ( error ) ;
 skip_file ( job , dir ) ;
 }
 else if ( IS_IO_ERROR ( error , CANCELLED ) ) {
 g_error_free ( error ) ;
 }
 else {
 primary = get_scan_primary ( source_info -> op ) ;
 details = NULL ;
 if ( IS_IO_ERROR ( error , PERMISSION_DENIED ) ) {
 secondary = f ( _ ( "The folder “%B” cannot be handled because you do not have " "permissions to read it." ) , dir ) ;
 }
 else {
 secondary = f ( _ ( "There was an error reading the folder “%B”." ) , dir ) ;
 details = error -> message ;
 }
 response = run_warning ( job , primary , secondary , details , TRUE , CANCEL , SKIP_ALL , SKIP , RETRY , NULL ) ;
 g_error_free ( error ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( job ) ;
 }
 else if ( response == 1 || response == 2 ) {
 if ( response == 1 ) {
 job -> skip_all_error = TRUE ;
 }
 skip_file ( job , dir ) ;
 }
 else if ( response == 3 ) {
 goto retry ;
 }
 else {
 g_assert_not_reached ( ) ;
 }
 }
 }
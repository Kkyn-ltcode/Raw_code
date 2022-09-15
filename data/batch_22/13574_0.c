static CreateDestDirResult create_dest_dir ( CommonJob * job , GFile * src , GFile * * dest , gboolean same_fs , char * * dest_fs_type ) {
 GError * error ;
 GFile * new_dest , * dest_dir ;
 char * primary , * secondary , * details ;
 int response ;
 gboolean handled_invalid_filename ;
 gboolean res ;
 handled_invalid_filename = * dest_fs_type != NULL ;
 retry : error = NULL ;
 res = g_file_make_directory ( * dest , job -> cancellable , & error ) ;
 if ( res ) {
 GFile * real ;
 real = map_possibly_volatile_file_to_real ( * dest , job -> cancellable , & error ) ;
 if ( real == NULL ) {
 res = FALSE ;
 }
 else {
 g_object_unref ( * dest ) ;
 * dest = real ;
 }
 }
 if ( ! res ) {
 if ( IS_IO_ERROR ( error , CANCELLED ) ) {
 g_error_free ( error ) ;
 return CREATE_DEST_DIR_FAILED ;
 }
 else if ( IS_IO_ERROR ( error , INVALID_FILENAME ) && ! handled_invalid_filename ) {
 handled_invalid_filename = TRUE ;
 g_assert ( * dest_fs_type == NULL ) ;
 dest_dir = g_file_get_parent ( * dest ) ;
 if ( dest_dir != NULL ) {
 * dest_fs_type = query_fs_type ( dest_dir , job -> cancellable ) ;
 new_dest = get_target_file ( src , dest_dir , * dest_fs_type , same_fs ) ;
 g_object_unref ( dest_dir ) ;
 if ( ! g_file_equal ( * dest , new_dest ) ) {
 g_object_unref ( * dest ) ;
 * dest = new_dest ;
 g_error_free ( error ) ;
 return CREATE_DEST_DIR_RETRY ;
 }
 else {
 g_object_unref ( new_dest ) ;
 }
 }
 }
 primary = f ( _ ( "Error while copying." ) ) ;
 details = NULL ;
 if ( IS_IO_ERROR ( error , PERMISSION_DENIED ) ) {
 secondary = f ( _ ( "The folder “%B” cannot be copied because you do not have " "permissions to create it in the destination." ) , src ) ;
 }
 else {
 secondary = f ( _ ( "There was an error creating the folder “%B”." ) , src ) ;
 details = error -> message ;
 }
 response = run_warning ( job , primary , secondary , details , FALSE , CANCEL , SKIP , RETRY , NULL ) ;
 g_error_free ( error ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( job ) ;
 }
 else if ( response == 1 ) {
 }
 else if ( response == 2 ) {
 goto retry ;
 }
 else {
 g_assert_not_reached ( ) ;
 }
 return CREATE_DEST_DIR_FAILED ;
 }
 nautilus_file_changes_queue_file_added ( * dest ) ;
 if ( job -> undo_info != NULL ) {
 nautilus_file_undo_info_ext_add_origin_target_pair ( NAUTILUS_FILE_UNDO_INFO_EXT ( job -> undo_info ) , src , * dest ) ;
 }
 return CREATE_DEST_DIR_SUCCESS ;
 }
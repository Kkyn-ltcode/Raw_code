static void link_file ( CopyMoveJob * job , GFile * src , GFile * dest_dir , char * * dest_fs_type , GHashTable * debuting_files , GdkPoint * position , int files_left ) {
 GFile * src_dir , * dest , * new_dest ;
 g_autofree gchar * dest_uri = NULL ;
 int count ;
 char * path ;
 gboolean not_local ;
 GError * error ;
 CommonJob * common ;
 char * primary , * secondary , * details ;
 int response ;
 gboolean handled_invalid_filename ;
 common = ( CommonJob * ) job ;
 count = 0 ;
 src_dir = g_file_get_parent ( src ) ;
 if ( g_file_equal ( src_dir , dest_dir ) ) {
 count = 1 ;
 }
 g_object_unref ( src_dir ) ;
 handled_invalid_filename = * dest_fs_type != NULL ;
 dest = get_target_file_for_link ( src , dest_dir , * dest_fs_type , count ) ;
 retry : error = NULL ;
 not_local = FALSE ;
 path = get_abs_path_for_symlink ( src , dest ) ;
 if ( path == NULL ) {
 not_local = TRUE ;
 }
 else if ( g_file_make_symbolic_link ( dest , path , common -> cancellable , & error ) ) {
 if ( common -> undo_info != NULL ) {
 nautilus_file_undo_info_ext_add_origin_target_pair ( NAUTILUS_FILE_UNDO_INFO_EXT ( common -> undo_info ) , src , dest ) ;
 }
 g_free ( path ) ;
 if ( debuting_files ) {
 g_hash_table_replace ( debuting_files , g_object_ref ( dest ) , GINT_TO_POINTER ( TRUE ) ) ;
 }
 nautilus_file_changes_queue_file_added ( dest ) ;
 dest_uri = g_file_get_uri ( dest ) ;
 if ( position ) {
 nautilus_file_changes_queue_schedule_position_set ( dest , * position , common -> screen_num ) ;
 }
 else if ( eel_uri_is_desktop ( dest_uri ) ) {
 nautilus_file_changes_queue_schedule_position_remove ( dest ) ;
 }
 g_object_unref ( dest ) ;
 return ;
 }
 g_free ( path ) ;
 if ( error != NULL && IS_IO_ERROR ( error , INVALID_FILENAME ) && ! handled_invalid_filename ) {
 handled_invalid_filename = TRUE ;
 g_assert ( * dest_fs_type == NULL ) ;
 * dest_fs_type = query_fs_type ( dest_dir , common -> cancellable ) ;
 new_dest = get_target_file_for_link ( src , dest_dir , * dest_fs_type , count ) ;
 if ( ! g_file_equal ( dest , new_dest ) ) {
 g_object_unref ( dest ) ;
 dest = new_dest ;
 g_error_free ( error ) ;
 goto retry ;
 }
 else {
 g_object_unref ( new_dest ) ;
 }
 }
 if ( error != NULL && IS_IO_ERROR ( error , EXISTS ) ) {
 g_object_unref ( dest ) ;
 dest = get_target_file_for_link ( src , dest_dir , * dest_fs_type , count ++ ) ;
 g_error_free ( error ) ;
 goto retry ;
 }
 else if ( error != NULL && IS_IO_ERROR ( error , CANCELLED ) ) {
 g_error_free ( error ) ;
 }
 else if ( error != NULL ) {
 if ( common -> skip_all_error ) {
 goto out ;
 }
 primary = f ( _ ( "Error while creating link to %B." ) , src ) ;
 if ( not_local ) {
 secondary = f ( _ ( "Symbolic links only supported for local files" ) ) ;
 details = NULL ;
 }
 else if ( IS_IO_ERROR ( error , NOT_SUPPORTED ) ) {
 secondary = f ( _ ( "The target doesn’t support symbolic links." ) ) ;
 details = NULL ;
 }
 else {
 secondary = f ( _ ( "There was an error creating the symlink in %F." ) , dest_dir ) ;
 details = error -> message ;
 }
 response = run_warning ( common , primary , secondary , details , files_left > 1 , CANCEL , SKIP_ALL , SKIP , NULL ) ;
 if ( error ) {
 g_error_free ( error ) ;
 }
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( common ) ;
 }
 else if ( response == 1 ) {
 common -> skip_all_error = TRUE ;
 }
 else if ( response == 2 ) {
 }
 else {
 g_assert_not_reached ( ) ;
 }
 }
 out : g_object_unref ( dest ) ;
 }
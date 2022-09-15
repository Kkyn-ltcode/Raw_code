static void move_file_prepare ( CopyMoveJob * move_job , GFile * src , GFile * dest_dir , gboolean same_fs , char * * dest_fs_type , GHashTable * debuting_files , GdkPoint * position , GList * * fallback_files , int files_left ) {
 GFile * dest , * new_dest ;
 g_autofree gchar * dest_uri = NULL ;
 GError * error ;
 CommonJob * job ;
 gboolean overwrite ;
 char * primary , * secondary , * details ;
 int response ;
 GFileCopyFlags flags ;
 MoveFileCopyFallback * fallback ;
 gboolean handled_invalid_filename ;
 overwrite = FALSE ;
 handled_invalid_filename = * dest_fs_type != NULL ;
 job = ( CommonJob * ) move_job ;
 dest = get_target_file ( src , dest_dir , * dest_fs_type , same_fs ) ;
 if ( test_dir_is_parent ( dest_dir , src ) ) {
 if ( job -> skip_all_error ) {
 goto out ;
 }
 primary = move_job -> is_move ? g_strdup ( _ ( "You cannot move a folder into itself." ) ) : g_strdup ( _ ( "You cannot copy a folder into itself." ) ) ;
 secondary = g_strdup ( _ ( "The destination folder is inside the source folder." ) ) ;
 response = run_warning ( job , primary , secondary , NULL , files_left > 1 , CANCEL , SKIP_ALL , SKIP , NULL ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( job ) ;
 }
 else if ( response == 1 ) {
 job -> skip_all_error = TRUE ;
 }
 else if ( response == 2 ) {
 }
 else {
 g_assert_not_reached ( ) ;
 }
 goto out ;
 }
 retry : flags = G_FILE_COPY_NOFOLLOW_SYMLINKS | G_FILE_COPY_NO_FALLBACK_FOR_MOVE ;
 if ( overwrite ) {
 flags |= G_FILE_COPY_OVERWRITE ;
 }
 error = NULL ;
 if ( g_file_move ( src , dest , flags , job -> cancellable , NULL , NULL , & error ) ) {
 if ( debuting_files ) {
 g_hash_table_replace ( debuting_files , g_object_ref ( dest ) , GINT_TO_POINTER ( TRUE ) ) ;
 }
 nautilus_file_changes_queue_file_moved ( src , dest ) ;
 dest_uri = g_file_get_uri ( dest ) ;
 if ( position ) {
 nautilus_file_changes_queue_schedule_position_set ( dest , * position , job -> screen_num ) ;
 }
 else if ( eel_uri_is_desktop ( dest_uri ) ) {
 nautilus_file_changes_queue_schedule_position_remove ( dest ) ;
 }
 if ( job -> undo_info != NULL ) {
 nautilus_file_undo_info_ext_add_origin_target_pair ( NAUTILUS_FILE_UNDO_INFO_EXT ( job -> undo_info ) , src , dest ) ;
 }
 return ;
 }
 if ( IS_IO_ERROR ( error , INVALID_FILENAME ) && ! handled_invalid_filename ) {
 g_error_free ( error ) ;
 handled_invalid_filename = TRUE ;
 g_assert ( * dest_fs_type == NULL ) ;
 * dest_fs_type = query_fs_type ( dest_dir , job -> cancellable ) ;
 new_dest = get_target_file ( src , dest_dir , * dest_fs_type , same_fs ) ;
 if ( ! g_file_equal ( dest , new_dest ) ) {
 g_object_unref ( dest ) ;
 dest = new_dest ;
 goto retry ;
 }
 else {
 g_object_unref ( new_dest ) ;
 }
 }
 else if ( ! overwrite && IS_IO_ERROR ( error , EXISTS ) ) {
 gboolean is_merge ;
 FileConflictResponse * response ;
 g_error_free ( error ) ;
 is_merge = FALSE ;
 if ( is_dir ( dest ) && is_dir ( src ) ) {
 is_merge = TRUE ;
 }
 if ( ( is_merge && job -> merge_all ) || ( ! is_merge && job -> replace_all ) ) {
 overwrite = TRUE ;
 goto retry ;
 }
 if ( job -> skip_all_conflict ) {
 goto out ;
 }
 response = handle_copy_move_conflict ( job , src , dest , dest_dir ) ;
 if ( response -> id == GTK_RESPONSE_CANCEL || response -> id == GTK_RESPONSE_DELETE_EVENT ) {
 file_conflict_response_free ( response ) ;
 abort_job ( job ) ;
 }
 else if ( response -> id == CONFLICT_RESPONSE_SKIP ) {
 if ( response -> apply_to_all ) {
 job -> skip_all_conflict = TRUE ;
 }
 file_conflict_response_free ( response ) ;
 }
 else if ( response -> id == CONFLICT_RESPONSE_REPLACE ) {
 if ( response -> apply_to_all ) {
 if ( is_merge ) {
 job -> merge_all = TRUE ;
 }
 else {
 job -> replace_all = TRUE ;
 }
 }
 overwrite = TRUE ;
 file_conflict_response_free ( response ) ;
 goto retry ;
 }
 else if ( response -> id == CONFLICT_RESPONSE_RENAME ) {
 g_object_unref ( dest ) ;
 dest = get_target_file_for_display_name ( dest_dir , response -> new_name ) ;
 file_conflict_response_free ( response ) ;
 goto retry ;
 }
 else {
 g_assert_not_reached ( ) ;
 }
 }
 else if ( IS_IO_ERROR ( error , WOULD_RECURSE ) || IS_IO_ERROR ( error , WOULD_MERGE ) || IS_IO_ERROR ( error , NOT_SUPPORTED ) || ( overwrite && IS_IO_ERROR ( error , IS_DIRECTORY ) ) ) {
 g_error_free ( error ) ;
 fallback = move_copy_file_callback_new ( src , overwrite , position ) ;
 * fallback_files = g_list_prepend ( * fallback_files , fallback ) ;
 }
 else if ( IS_IO_ERROR ( error , CANCELLED ) ) {
 g_error_free ( error ) ;
 }
 else {
 if ( job -> skip_all_error ) {
 g_error_free ( error ) ;
 goto out ;
 }
 primary = f ( _ ( "Error while moving “%B”." ) , src ) ;
 secondary = f ( _ ( "There was an error moving the file into %F." ) , dest_dir ) ;
 details = error -> message ;
 response = run_warning ( job , primary , secondary , details , files_left > 1 , CANCEL , SKIP_ALL , SKIP , NULL ) ;
 g_error_free ( error ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( job ) ;
 }
 else if ( response == 1 ) {
 job -> skip_all_error = TRUE ;
 }
 else if ( response == 2 ) {
 }
 else {
 g_assert_not_reached ( ) ;
 }
 }
 out : g_object_unref ( dest ) ;
 }
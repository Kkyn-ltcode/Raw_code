static void trash_file ( CommonJob * job , GFile * file , gboolean * skipped_file , SourceInfo * source_info , TransferInfo * transfer_info , gboolean toplevel , GList * * to_delete ) {
 GError * error ;
 char * primary , * secondary , * details ;
 int response ;
 if ( should_skip_file ( job , file ) ) {
 * skipped_file = TRUE ;
 return ;
 }
 error = NULL ;
 if ( g_file_trash ( file , job -> cancellable , & error ) ) {
 transfer_info -> num_files ++ ;
 nautilus_file_changes_queue_file_removed ( file ) ;
 if ( job -> undo_info != NULL ) {
 nautilus_file_undo_info_trash_add_file ( NAUTILUS_FILE_UNDO_INFO_TRASH ( job -> undo_info ) , file ) ;
 }
 report_trash_progress ( job , source_info , transfer_info ) ;
 return ;
 }
 if ( job -> skip_all_error ) {
 * skipped_file = TRUE ;
 goto skip ;
 }
 if ( job -> delete_all ) {
 * to_delete = g_list_prepend ( * to_delete , file ) ;
 goto skip ;
 }
 primary = f ( _ ( "“%B” can’t be put in the trash. Do you want to delete it immediately?" ) , file ) ;
 details = NULL ;
 secondary = NULL ;
 if ( ! IS_IO_ERROR ( error , NOT_SUPPORTED ) ) {
 details = error -> message ;
 }
 else if ( ! g_file_is_native ( file ) ) {
 secondary = f ( _ ( "This remote location does not support sending items to the trash." ) ) ;
 }
 response = run_question ( job , primary , secondary , details , ( source_info -> num_files - transfer_info -> num_files ) > 1 , CANCEL , SKIP_ALL , SKIP , DELETE_ALL , DELETE , NULL ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 ( ( DeleteJob * ) job ) -> user_cancel = TRUE ;
 abort_job ( job ) ;
 }
 else if ( response == 1 ) {
 * skipped_file = TRUE ;
 job -> skip_all_error = TRUE ;
 }
 else if ( response == 2 ) {
 * skipped_file = TRUE ;
 job -> skip_all_error = TRUE ;
 }
 else if ( response == 3 ) {
 * to_delete = g_list_prepend ( * to_delete , file ) ;
 job -> delete_all = TRUE ;
 }
 else if ( response == 4 ) {
 * to_delete = g_list_prepend ( * to_delete , file ) ;
 }
 skip : g_error_free ( error ) ;
 }
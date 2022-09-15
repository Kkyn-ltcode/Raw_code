static void existing_file_removed_callback ( GFile * file , GError * error , gpointer callback_data ) {
 DeleteExistingFileData * data = callback_data ;
 CommonJob * job ;
 GFile * source ;
 GFileType file_type ;
 char * primary ;
 char * secondary ;
 char * details = NULL ;
 int response ;
 job = data -> job ;
 source = data -> source ;
 if ( error == NULL ) {
 nautilus_file_changes_queue_file_removed ( file ) ;
 return ;
 }
 if ( job_aborted ( job ) || job -> skip_all_error ) {
 return ;
 }
 primary = f ( _ ( "Error while copying “%B”." ) , source ) ;
 file_type = g_file_query_file_type ( file , G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS , job -> cancellable ) ;
 if ( file_type == G_FILE_TYPE_DIRECTORY ) {
 secondary = f ( _ ( "Could not remove the already existing folder %F." ) , file ) ;
 }
 else {
 secondary = f ( _ ( "Could not remove the already existing file %F." ) , file ) ;
 }
 details = error -> message ;
 response = run_warning ( job , primary , secondary , details , TRUE , CANCEL , SKIP_ALL , SKIP , NULL ) ;
 if ( response == 0 || response == GTK_RESPONSE_DELETE_EVENT ) {
 abort_job ( job ) ;
 }
 else if ( response == 1 ) {
 job -> skip_all_error = TRUE ;
 }
 }
static void extract_task_thread_func ( GTask * task , gpointer source_object , gpointer task_data , GCancellable * cancellable ) {
 ExtractJob * extract_job = task_data ;
 GList * l ;
 GList * existing_output_files = NULL ;
 gint total_files ;
 g_autofree guint64 * archive_compressed_sizes = NULL ;
 gint i ;
 g_timer_start ( extract_job -> common . time ) ;
 nautilus_progress_info_start ( extract_job -> common . progress ) ;
 nautilus_progress_info_set_details ( extract_job -> common . progress , _ ( "Preparing to extract" ) ) ;
 total_files = g_list_length ( extract_job -> source_files ) ;
 archive_compressed_sizes = g_malloc0_n ( total_files , sizeof ( guint64 ) ) ;
 extract_job -> total_compressed_size = 0 ;
 for ( l = extract_job -> source_files , i = 0 ;
 l != NULL && ! job_aborted ( ( CommonJob * ) extract_job ) ;
 l = l -> next , i ++ ) {
 GFile * source_file ;
 g_autoptr ( GFileInfo ) info = NULL ;
 source_file = G_FILE ( l -> data ) ;
 info = g_file_query_info ( source_file , G_FILE_ATTRIBUTE_STANDARD_SIZE , G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS , extract_job -> common . cancellable , NULL ) ;
 if ( info ) {
 archive_compressed_sizes [ i ] = g_file_info_get_size ( info ) ;
 extract_job -> total_compressed_size += archive_compressed_sizes [ i ] ;
 }
 }
 extract_job -> base_progress = 0 ;
 for ( l = extract_job -> source_files , i = 0 ;
 l != NULL && ! job_aborted ( ( CommonJob * ) extract_job ) ;
 l = l -> next , i ++ ) {
 g_autoptr ( AutoarExtractor ) extractor = NULL ;
 extractor = autoar_extractor_new ( G_FILE ( l -> data ) , extract_job -> destination_directory ) ;
 autoar_extractor_set_notify_interval ( extractor , PROGRESS_NOTIFY_INTERVAL ) ;
 g_signal_connect ( extractor , "error" , G_CALLBACK ( extract_job_on_error ) , extract_job ) ;
 g_signal_connect ( extractor , "decide-destination" , G_CALLBACK ( extract_job_on_decide_destination ) , extract_job ) ;
 g_signal_connect ( extractor , "progress" , G_CALLBACK ( extract_job_on_progress ) , extract_job ) ;
 g_signal_connect ( extractor , "completed" , G_CALLBACK ( extract_job_on_completed ) , extract_job ) ;
 extract_job -> archive_compressed_size = archive_compressed_sizes [ i ] ;
 autoar_extractor_start ( extractor , extract_job -> common . cancellable ) ;
 g_signal_handlers_disconnect_by_data ( extractor , extract_job ) ;
 extract_job -> base_progress += ( gdouble ) extract_job -> archive_compressed_size / ( gdouble ) extract_job -> total_compressed_size ;
 }
 if ( ! job_aborted ( ( CommonJob * ) extract_job ) ) {
 report_extract_final_progress ( extract_job , total_files ) ;
 }
 for ( l = extract_job -> output_files ;
 l != NULL ;
 l = l -> next ) {
 GFile * output_file ;
 output_file = G_FILE ( l -> data ) ;
 if ( g_file_query_exists ( output_file , NULL ) ) {
 existing_output_files = g_list_prepend ( existing_output_files , g_object_ref ( output_file ) ) ;
 }
 }
 g_list_free_full ( extract_job -> output_files , g_object_unref ) ;
 extract_job -> output_files = existing_output_files ;
 if ( extract_job -> common . undo_info ) {
 if ( extract_job -> output_files ) {
 NautilusFileUndoInfoExtract * undo_info ;
 undo_info = NAUTILUS_FILE_UNDO_INFO_EXTRACT ( extract_job -> common . undo_info ) ;
 nautilus_file_undo_info_extract_set_outputs ( undo_info , extract_job -> output_files ) ;
 }
 else {
 g_clear_object ( & extract_job -> common . undo_info ) ;
 }
 }
 }
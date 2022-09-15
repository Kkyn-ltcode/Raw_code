static void list_mime_enum_callback ( GObject * source_object , GAsyncResult * res , gpointer user_data ) {
 MimeListState * state ;
 GFileEnumerator * enumerator ;
 NautilusDirectory * directory ;
 GError * error ;
 state = user_data ;
 if ( g_cancellable_is_cancelled ( state -> cancellable ) ) {
 directory = state -> directory ;
 directory -> details -> mime_list_in_progress = NULL ;
 async_job_end ( directory , "MIME list" ) ;
 nautilus_directory_async_state_changed ( directory ) ;
 mime_list_state_free ( state ) ;
 return ;
 }
 error = NULL ;
 enumerator = g_file_enumerate_children_finish ( G_FILE ( source_object ) , res , & error ) ;
 if ( enumerator == NULL ) {
 mime_list_done ( state , FALSE ) ;
 g_error_free ( error ) ;
 mime_list_state_free ( state ) ;
 return ;
 }
 else {
 state -> enumerator = enumerator ;
 g_file_enumerator_next_files_async ( state -> enumerator , DIRECTORY_LOAD_ITEMS_PER_CALLBACK , G_PRIORITY_DEFAULT , state -> cancellable , mime_list_callback , state ) ;
 }
 }
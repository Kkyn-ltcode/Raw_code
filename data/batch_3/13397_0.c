static void count_children_callback ( GObject * source_object , GAsyncResult * res , gpointer user_data ) {
 DirectoryCountState * state ;
 GFileEnumerator * enumerator ;
 NautilusDirectory * directory ;
 GError * error ;
 state = user_data ;
 if ( g_cancellable_is_cancelled ( state -> cancellable ) ) {
 directory = state -> directory ;
 async_job_end ( directory , "directory count" ) ;
 nautilus_directory_async_state_changed ( directory ) ;
 directory_count_state_free ( state ) ;
 return ;
 }
 error = NULL ;
 enumerator = g_file_enumerate_children_finish ( G_FILE ( source_object ) , res , & error ) ;
 if ( enumerator == NULL ) {
 count_children_done ( state -> directory , state -> count_file , FALSE , 0 ) ;
 g_error_free ( error ) ;
 directory_count_state_free ( state ) ;
 return ;
 }
 else {
 state -> enumerator = enumerator ;
 g_file_enumerator_next_files_async ( state -> enumerator , DIRECTORY_LOAD_ITEMS_PER_CALLBACK , G_PRIORITY_DEFAULT , state -> cancellable , count_more_files_callback , state ) ;
 }
 }
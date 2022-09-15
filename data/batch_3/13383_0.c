static void more_files_callback ( GObject * source_object , GAsyncResult * res , gpointer user_data ) {
 DirectoryLoadState * state ;
 NautilusDirectory * directory ;
 GError * error ;
 GList * files , * l ;
 GFileInfo * info ;
 state = user_data ;
 if ( state -> directory == NULL ) {
 directory_load_state_free ( state ) ;
 return ;
 }
 directory = nautilus_directory_ref ( state -> directory ) ;
 g_assert ( directory -> details -> directory_load_in_progress != NULL ) ;
 g_assert ( directory -> details -> directory_load_in_progress == state ) ;
 error = NULL ;
 files = g_file_enumerator_next_files_finish ( state -> enumerator , res , & error ) ;
 for ( l = files ;
 l != NULL ;
 l = l -> next ) {
 info = l -> data ;
 directory_load_one ( directory , info ) ;
 g_object_unref ( info ) ;
 }
 if ( files == NULL ) {
 directory_load_done ( directory , error ) ;
 directory_load_state_free ( state ) ;
 }
 else {
 g_file_enumerator_next_files_async ( state -> enumerator , DIRECTORY_LOAD_ITEMS_PER_CALLBACK , G_PRIORITY_DEFAULT , state -> cancellable , more_files_callback , state ) ;
 }
 nautilus_directory_unref ( directory ) ;
 if ( error ) {
 g_error_free ( error ) ;
 }
 g_list_free ( files ) ;
 }
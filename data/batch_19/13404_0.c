static void mime_list_start ( NautilusDirectory * directory , NautilusFile * file , gboolean * doing_io ) {
 MimeListState * state ;
 GFile * location ;
 mime_list_stop ( directory ) ;
 if ( directory -> details -> mime_list_in_progress != NULL ) {
 * doing_io = TRUE ;
 return ;
 }
 if ( ! is_needy ( file , should_get_mime_list , REQUEST_MIME_LIST ) ) {
 return ;
 }
 * doing_io = TRUE ;
 if ( ! nautilus_file_is_directory ( file ) ) {
 g_list_free ( file -> details -> mime_list ) ;
 file -> details -> mime_list_failed = FALSE ;
 file -> details -> got_mime_list = FALSE ;
 file -> details -> mime_list_is_up_to_date = TRUE ;
 nautilus_directory_async_state_changed ( directory ) ;
 return ;
 }
 if ( ! async_job_start ( directory , "MIME list" ) ) {
 return ;
 }
 state = g_new0 ( MimeListState , 1 ) ;
 state -> mime_list_file = file ;
 state -> directory = nautilus_directory_ref ( directory ) ;
 state -> cancellable = g_cancellable_new ( ) ;
 state -> mime_list_hash = istr_set_new ( ) ;
 directory -> details -> mime_list_in_progress = state ;
 location = nautilus_file_get_location ( file ) ;
 # ifdef DEBUG_LOAD_DIRECTORY {
 char * uri ;
 uri = g_file_get_uri ( location ) ;
 g_message ( "load_directory called to get MIME list of %s" , uri ) ;
 g_free ( uri ) ;
 }
 # endif g_file_enumerate_children_async ( location , G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE , 0 , G_PRIORITY_LOW , state -> cancellable , list_mime_enum_callback , state ) ;
 g_object_unref ( location ) ;
 }
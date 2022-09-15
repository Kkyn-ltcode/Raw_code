static void mime_list_done ( MimeListState * state , gboolean success ) {
 NautilusFile * file ;
 NautilusDirectory * directory ;
 directory = state -> directory ;
 g_assert ( directory != NULL ) ;
 file = state -> mime_list_file ;
 file -> details -> mime_list_is_up_to_date = TRUE ;
 g_list_free_full ( file -> details -> mime_list , g_free ) ;
 if ( success ) {
 file -> details -> mime_list_failed = TRUE ;
 file -> details -> mime_list = NULL ;
 }
 else {
 file -> details -> got_mime_list = TRUE ;
 file -> details -> mime_list = istr_set_get_as_list ( state -> mime_list_hash ) ;
 }
 directory -> details -> mime_list_in_progress = NULL ;
 nautilus_file_changed ( file ) ;
 async_job_end ( directory , "MIME list" ) ;
 nautilus_directory_async_state_changed ( directory ) ;
 }
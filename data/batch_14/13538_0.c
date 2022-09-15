static void directory_load_one ( NautilusDirectory * directory , GFileInfo * info ) {
 if ( info == NULL ) {
 return ;
 }
 if ( g_file_info_get_name ( info ) == NULL ) {
 char * uri ;
 uri = nautilus_directory_get_uri ( directory ) ;
 g_warning ( "Got GFileInfo with NULL name in %s, ignoring. This shouldn't happen unless the gvfs backend is broken.\n" , uri ) ;
 g_free ( uri ) ;
 return ;
 }
 g_object_ref ( info ) ;
 directory -> details -> pending_file_info = g_list_prepend ( directory -> details -> pending_file_info , info ) ;
 nautilus_directory_schedule_dequeue_pending ( directory ) ;
 }
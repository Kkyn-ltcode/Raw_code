void nautilus_directory_monitor_add_internal ( NautilusDirectory * directory , NautilusFile * file , gconstpointer client , gboolean monitor_hidden_files , NautilusFileAttributes file_attributes , NautilusDirectoryCallback callback , gpointer callback_data ) {
 Monitor * monitor ;
 GList * file_list ;
 char * file_uri = NULL ;
 char * dir_uri = NULL ;
 g_assert ( NAUTILUS_IS_DIRECTORY ( directory ) ) ;
 if ( file != NULL ) {
 file_uri = nautilus_file_get_uri ( file ) ;
 }
 if ( directory != NULL ) {
 dir_uri = nautilus_directory_get_uri ( directory ) ;
 }
 nautilus_profile_start ( "uri %s file-uri %s client %p" , dir_uri , file_uri , client ) ;
 g_free ( dir_uri ) ;
 g_free ( file_uri ) ;
 remove_monitor ( directory , file , client ) ;
 monitor = g_new ( Monitor , 1 ) ;
 monitor -> file = file ;
 monitor -> monitor_hidden_files = monitor_hidden_files ;
 monitor -> client = client ;
 monitor -> request = nautilus_directory_set_up_request ( file_attributes ) ;
 if ( file == NULL ) {
 REQUEST_SET_TYPE ( monitor -> request , REQUEST_FILE_LIST ) ;
 }
 directory -> details -> monitor_list = g_list_prepend ( directory -> details -> monitor_list , monitor ) ;
 request_counter_add_request ( directory -> details -> monitor_counters , monitor -> request ) ;
 if ( callback != NULL ) {
 file_list = nautilus_directory_get_file_list ( directory ) ;
 ( * callback ) ( directory , file_list , callback_data ) ;
 nautilus_file_list_free ( file_list ) ;
 }
 if ( directory -> details -> monitor == NULL ) {
 directory -> details -> monitor = nautilus_monitor_directory ( directory -> details -> location ) ;
 }
 if ( REQUEST_WANTS_TYPE ( monitor -> request , REQUEST_FILE_INFO ) && directory -> details -> mime_db_monitor == 0 ) {
 directory -> details -> mime_db_monitor = g_signal_connect_object ( nautilus_signaller_get_current ( ) , "mime-data-changed" , G_CALLBACK ( mime_db_changed_callback ) , directory , 0 ) ;
 }
 if ( file != NULL ) {
 nautilus_directory_add_file_to_work_queue ( directory , file ) ;
 }
 else {
 add_all_files_to_work_queue ( directory ) ;
 }
 nautilus_directory_async_state_changed ( directory ) ;
 nautilus_profile_end ( NULL ) ;
 }
static void ready_callback_call ( NautilusDirectory * directory , const ReadyCallback * callback ) {
 GList * file_list ;
 if ( callback -> file != NULL ) {
 if ( callback -> callback . file ) {
 ( * callback -> callback . file ) ( callback -> file , callback -> callback_data ) ;
 }
 }
 else if ( callback -> callback . directory != NULL ) {
 if ( directory == NULL || ! REQUEST_WANTS_TYPE ( callback -> request , REQUEST_FILE_LIST ) ) {
 file_list = NULL ;
 }
 else {
 file_list = nautilus_directory_get_file_list ( directory ) ;
 }
 ( * callback -> callback . directory ) ( directory , file_list , callback -> callback_data ) ;
 nautilus_file_list_free ( file_list ) ;
 }
 }
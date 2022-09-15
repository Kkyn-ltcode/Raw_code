void nautilus_directory_cancel_callback_internal ( NautilusDirectory * directory , NautilusFile * file , NautilusDirectoryCallback directory_callback , NautilusFileCallback file_callback , gpointer callback_data ) {
 ReadyCallback callback ;
 GList * node ;
 if ( directory == NULL ) {
 return ;
 }
 g_assert ( NAUTILUS_IS_DIRECTORY ( directory ) ) ;
 g_assert ( file == NULL || NAUTILUS_IS_FILE ( file ) ) ;
 g_assert ( file != NULL || directory_callback != NULL ) ;
 g_assert ( file == NULL || file_callback != NULL ) ;
 callback . file = file ;
 if ( file == NULL ) {
 callback . callback . directory = directory_callback ;
 }
 else {
 callback . callback . file = file_callback ;
 }
 callback . callback_data = callback_data ;
 do {
 node = g_list_find_custom ( directory -> details -> call_when_ready_list , & callback , ready_callback_key_compare ) ;
 if ( node != NULL ) {
 remove_callback_link ( directory , node ) ;
 nautilus_directory_async_state_changed ( directory ) ;
 }
 }
 while ( node != NULL ) ;
 }
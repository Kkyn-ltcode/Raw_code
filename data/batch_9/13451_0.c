static gboolean dequeue_pending_idle_callback ( gpointer callback_data ) {
 NautilusDirectory * directory ;
 GList * pending_file_info ;
 GList * node , * next ;
 NautilusFile * file ;
 GList * changed_files , * added_files ;
 GFileInfo * file_info ;
 const char * mimetype , * name ;
 DirectoryLoadState * dir_load_state ;
 directory = NAUTILUS_DIRECTORY ( callback_data ) ;
 nautilus_directory_ref ( directory ) ;
 nautilus_profile_start ( "nitems %d" , g_list_length ( directory -> details -> pending_file_info ) ) ;
 directory -> details -> dequeue_pending_idle_id = 0 ;
 pending_file_info = g_list_reverse ( directory -> details -> pending_file_info ) ;
 directory -> details -> pending_file_info = NULL ;
 if ( ! nautilus_directory_is_file_list_monitored ( directory ) ) {
 nautilus_directory_async_state_changed ( directory ) ;
 goto drain ;
 }
 added_files = NULL ;
 changed_files = NULL ;
 dir_load_state = directory -> details -> directory_load_in_progress ;
 for ( node = pending_file_info ;
 node != NULL ;
 node = node -> next ) {
 file_info = node -> data ;
 name = g_file_info_get_name ( file_info ) ;
 if ( dir_load_state && ! should_skip_file ( directory , file_info ) ) {
 dir_load_state -> load_file_count += 1 ;
 mimetype = g_file_info_get_content_type ( file_info ) ;
 if ( mimetype != NULL ) {
 istr_set_insert ( dir_load_state -> load_mime_list_hash , mimetype ) ;
 }
 }
 file = nautilus_directory_find_file_by_name ( directory , name ) ;
 if ( file != NULL ) {
 set_file_unconfirmed ( file , FALSE ) ;
 if ( ! file -> details -> is_added ) {
 nautilus_file_ref ( file ) ;
 file -> details -> is_added = TRUE ;
 added_files = g_list_prepend ( added_files , file ) ;
 }
 else if ( nautilus_file_update_info ( file , file_info ) ) {
 nautilus_file_ref ( file ) ;
 changed_files = g_list_prepend ( changed_files , file ) ;
 }
 }
 else {
 file = nautilus_file_new_from_info ( directory , file_info ) ;
 nautilus_directory_add_file ( directory , file ) ;
 file -> details -> is_added = TRUE ;
 added_files = g_list_prepend ( added_files , file ) ;
 }
 }
 if ( directory -> details -> directory_loaded ) {
 for ( node = directory -> details -> file_list ;
 node != NULL ;
 node = next ) {
 file = NAUTILUS_FILE ( node -> data ) ;
 next = node -> next ;
 if ( file -> details -> unconfirmed ) {
 nautilus_file_ref ( file ) ;
 changed_files = g_list_prepend ( changed_files , file ) ;
 nautilus_file_mark_gone ( file ) ;
 }
 }
 }
 nautilus_directory_emit_change_signals ( directory , changed_files ) ;
 nautilus_file_list_free ( changed_files ) ;
 nautilus_directory_emit_files_added ( directory , added_files ) ;
 nautilus_file_list_free ( added_files ) ;
 if ( directory -> details -> directory_loaded && ! directory -> details -> directory_loaded_sent_notification ) {
 nautilus_directory_emit_done_loading ( directory ) ;
 if ( dir_load_state ) {
 file = dir_load_state -> load_directory_file ;
 file -> details -> directory_count = dir_load_state -> load_file_count ;
 file -> details -> directory_count_is_up_to_date = TRUE ;
 file -> details -> got_directory_count = TRUE ;
 file -> details -> got_mime_list = TRUE ;
 file -> details -> mime_list_is_up_to_date = TRUE ;
 g_list_free_full ( file -> details -> mime_list , g_free ) ;
 file -> details -> mime_list = istr_set_get_as_list ( dir_load_state -> load_mime_list_hash ) ;
 nautilus_file_changed ( file ) ;
 }
 nautilus_directory_async_state_changed ( directory ) ;
 directory -> details -> directory_loaded_sent_notification = TRUE ;
 }
 drain : g_list_free_full ( pending_file_info , g_object_unref ) ;
 nautilus_directory_async_state_changed ( directory ) ;
 nautilus_profile_end ( NULL ) ;
 nautilus_directory_unref ( directory ) ;
 return FALSE ;
 }
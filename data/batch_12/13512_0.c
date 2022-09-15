static void deep_count_start ( NautilusDirectory * directory , NautilusFile * file , gboolean * doing_io ) {
 GFile * location ;
 DeepCountState * state ;
 if ( directory -> details -> deep_count_in_progress != NULL ) {
 * doing_io = TRUE ;
 return ;
 }
 if ( ! is_needy ( file , lacks_deep_count , REQUEST_DEEP_COUNT ) ) {
 return ;
 }
 * doing_io = TRUE ;
 if ( ! nautilus_file_is_directory ( file ) ) {
 file -> details -> deep_counts_status = NAUTILUS_REQUEST_DONE ;
 nautilus_directory_async_state_changed ( directory ) ;
 return ;
 }
 if ( ! async_job_start ( directory , "deep count" ) ) {
 return ;
 }
 file -> details -> deep_counts_status = NAUTILUS_REQUEST_IN_PROGRESS ;
 file -> details -> deep_directory_count = 0 ;
 file -> details -> deep_file_count = 0 ;
 file -> details -> deep_unreadable_count = 0 ;
 file -> details -> deep_size = 0 ;
 directory -> details -> deep_count_file = file ;
 state = g_new0 ( DeepCountState , 1 ) ;
 state -> directory = directory ;
 state -> cancellable = g_cancellable_new ( ) ;
 state -> seen_deep_count_inodes = g_array_new ( FALSE , TRUE , sizeof ( guint64 ) ) ;
 state -> fs_id = NULL ;
 directory -> details -> deep_count_in_progress = state ;
 location = nautilus_file_get_location ( file ) ;
 g_file_query_info_async ( location , G_FILE_ATTRIBUTE_ID_FILESYSTEM , G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS , G_PRIORITY_DEFAULT , NULL , deep_count_got_info , state ) ;
 g_object_unref ( location ) ;
 }
void nautilus_directory_get_info_for_new_files ( NautilusDirectory * directory , GList * location_list ) {
 NewFilesState * state ;
 GFile * location ;
 GList * l ;
 if ( location_list == NULL ) {
 return ;
 }
 state = g_new ( NewFilesState , 1 ) ;
 state -> directory = directory ;
 state -> cancellable = g_cancellable_new ( ) ;
 state -> count = 0 ;
 for ( l = location_list ;
 l != NULL ;
 l = l -> next ) {
 location = l -> data ;
 state -> count ++ ;
 g_file_query_info_async ( location , NAUTILUS_FILE_DEFAULT_ATTRIBUTES , 0 , G_PRIORITY_DEFAULT , state -> cancellable , new_files_callback , state ) ;
 }
 directory -> details -> new_files_in_progress = g_list_prepend ( directory -> details -> new_files_in_progress , state ) ;
 }
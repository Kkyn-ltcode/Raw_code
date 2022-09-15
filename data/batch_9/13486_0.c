static void file_info_stop ( NautilusDirectory * directory ) {
 NautilusFile * file ;
 if ( directory -> details -> get_info_in_progress != NULL ) {
 file = directory -> details -> get_info_file ;
 if ( file != NULL ) {
 g_assert ( NAUTILUS_IS_FILE ( file ) ) ;
 g_assert ( file -> details -> directory == directory ) ;
 if ( is_needy ( file , lacks_info , REQUEST_FILE_INFO ) ) {
 return ;
 }
 }
 file_info_cancel ( directory ) ;
 }
 }
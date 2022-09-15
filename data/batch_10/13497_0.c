static void link_info_got_data ( NautilusDirectory * directory , NautilusFile * file , gboolean result , goffset bytes_read , char * file_contents ) {
 char * link_uri , * uri , * name ;
 GIcon * icon ;
 gboolean is_launcher ;
 gboolean is_foreign ;
 nautilus_directory_ref ( directory ) ;
 uri = NULL ;
 name = NULL ;
 icon = NULL ;
 is_launcher = FALSE ;
 is_foreign = FALSE ;
 if ( result ) {
 link_uri = nautilus_file_get_uri ( file ) ;
 nautilus_link_get_link_info_given_file_contents ( file_contents , bytes_read , link_uri , & uri , & name , & icon , & is_launcher , & is_foreign ) ;
 g_free ( link_uri ) ;
 }
 else {
 }
 nautilus_file_ref ( file ) ;
 link_info_done ( directory , file , uri , name , icon , is_launcher , is_foreign ) ;
 nautilus_file_changed ( file ) ;
 nautilus_file_unref ( file ) ;
 g_free ( uri ) ;
 g_free ( name ) ;
 if ( icon != NULL ) {
 g_object_unref ( icon ) ;
 }
 nautilus_directory_unref ( directory ) ;
 }
static void link_info_nautilus_link_read_callback ( GObject * source_object , GAsyncResult * res , gpointer user_data ) {
 LinkInfoReadState * state ;
 gsize file_size ;
 char * file_contents ;
 gboolean result ;
 NautilusDirectory * directory ;
 state = user_data ;
 if ( state -> directory == NULL ) {
 link_info_read_state_free ( state ) ;
 return ;
 }
 directory = nautilus_directory_ref ( state -> directory ) ;
 result = g_file_load_contents_finish ( G_FILE ( source_object ) , res , & file_contents , & file_size , NULL , NULL ) ;
 state -> directory -> details -> link_info_read_state = NULL ;
 async_job_end ( state -> directory , "link info" ) ;
 link_info_got_data ( state -> directory , state -> file , result , file_size , file_contents ) ;
 if ( result ) {
 g_free ( file_contents ) ;
 }
 link_info_read_state_free ( state ) ;
 nautilus_directory_unref ( directory ) ;
 }
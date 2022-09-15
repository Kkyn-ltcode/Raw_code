static void find_enclosing_mount_callback ( GObject * source_object , GAsyncResult * res , gpointer user_data ) {
 GMount * mount ;
 MountState * state ;
 GFile * location , * root ;
 state = user_data ;
 if ( state -> directory == NULL ) {
 mount_state_free ( state ) ;
 return ;
 }
 mount = g_file_find_enclosing_mount_finish ( G_FILE ( source_object ) , res , NULL ) ;
 if ( mount ) {
 root = g_mount_get_root ( mount ) ;
 location = nautilus_file_get_location ( state -> file ) ;
 if ( ! g_file_equal ( location , root ) ) {
 g_object_unref ( mount ) ;
 mount = NULL ;
 }
 g_object_unref ( root ) ;
 g_object_unref ( location ) ;
 }
 got_mount ( state , mount ) ;
 if ( mount ) {
 g_object_unref ( mount ) ;
 }
 }
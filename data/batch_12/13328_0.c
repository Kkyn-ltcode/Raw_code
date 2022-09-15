static void report_broken_symbolic_link ( GtkWindow * parent_window , NautilusFile * file ) {
 char * target_path ;
 char * display_name ;
 char * prompt ;
 char * detail ;
 GtkDialog * dialog ;
 GList file_as_list ;
 int response ;
 gboolean can_trash ;
 g_assert ( nautilus_file_is_broken_symbolic_link ( file ) ) ;
 display_name = nautilus_file_get_display_name ( file ) ;
 can_trash = nautilus_file_can_trash ( file ) && ! nautilus_file_is_in_trash ( file ) ;
 if ( can_trash ) {
 prompt = g_strdup_printf ( _ ( "The link “%s” is broken. Move it to Trash?" ) , display_name ) ;
 }
 else {
 prompt = g_strdup_printf ( _ ( "The link “%s” is broken." ) , display_name ) ;
 }
 g_free ( display_name ) ;
 target_path = nautilus_file_get_symbolic_link_target_path ( file ) ;
 if ( target_path == NULL ) {
 detail = g_strdup ( _ ( "This link cannot be used because it has no target." ) ) ;
 }
 else {
 detail = g_strdup_printf ( _ ( "This link cannot be used because its target " "“%s” doesn’t exist." ) , target_path ) ;
 }
 if ( ! can_trash ) {
 eel_run_simple_dialog ( GTK_WIDGET ( parent_window ) , FALSE , GTK_MESSAGE_WARNING , prompt , detail , _ ( "_Cancel" ) , NULL ) ;
 goto out ;
 }
 dialog = eel_show_yes_no_dialog ( prompt , detail , _ ( "Mo_ve to Trash" ) , _ ( "_Cancel" ) , parent_window ) ;
 gtk_dialog_set_default_response ( dialog , GTK_RESPONSE_CANCEL ) ;
 response = gtk_dialog_run ( dialog ) ;
 gtk_widget_destroy ( GTK_WIDGET ( dialog ) ) ;
 if ( response == GTK_RESPONSE_YES ) {
 file_as_list . data = file ;
 file_as_list . next = NULL ;
 file_as_list . prev = NULL ;
 trash_or_delete_files ( parent_window , & file_as_list , TRUE ) ;
 }
 out : g_free ( prompt ) ;
 g_free ( target_path ) ;
 g_free ( detail ) ;
 }
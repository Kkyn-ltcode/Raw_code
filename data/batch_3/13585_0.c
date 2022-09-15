static gboolean do_run_simple_dialog ( gpointer _data ) {
 RunSimpleDialogData * data = _data ;
 const char * button_title ;
 GtkWidget * dialog ;
 int result ;
 int response_id ;
 g_mutex_lock ( & data -> mutex ) ;
 dialog = gtk_message_dialog_new ( * data -> parent_window , 0 , data -> message_type , GTK_BUTTONS_NONE , NULL ) ;
 g_object_set ( dialog , "text" , data -> primary_text , "secondary-text" , data -> secondary_text , NULL ) ;
 for ( response_id = 0 ;
 data -> button_titles [ response_id ] != NULL ;
 response_id ++ ) {
 button_title = data -> button_titles [ response_id ] ;
 if ( ! data -> show_all && is_all_button_text ( button_title ) ) {
 continue ;
 }
 gtk_dialog_add_button ( GTK_DIALOG ( dialog ) , button_title , response_id ) ;
 gtk_dialog_set_default_response ( GTK_DIALOG ( dialog ) , response_id ) ;
 }
 if ( data -> details_text ) {
 eel_gtk_message_dialog_set_details_label ( GTK_MESSAGE_DIALOG ( dialog ) , data -> details_text ) ;
 }
 result = gtk_dialog_run ( GTK_DIALOG ( dialog ) ) ;
 while ( ( result == GTK_RESPONSE_NONE || result == GTK_RESPONSE_DELETE_EVENT ) && data -> ignore_close_box ) {
 result = gtk_dialog_run ( GTK_DIALOG ( dialog ) ) ;
 }
 gtk_widget_destroy ( dialog ) ;
 data -> result = result ;
 data -> completed = TRUE ;
 g_cond_signal ( & data -> cond ) ;
 g_mutex_unlock ( & data -> mutex ) ;
 return FALSE ;
 }
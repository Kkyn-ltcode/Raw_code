static gint prompt_empty_trash ( GtkWindow * parent_window ) {
 gint result ;
 GtkWidget * dialog ;
 GdkScreen * screen ;
 screen = NULL ;
 if ( parent_window != NULL ) {
 screen = gtk_widget_get_screen ( GTK_WIDGET ( parent_window ) ) ;
 }
 dialog = gtk_message_dialog_new ( NULL , GTK_DIALOG_MODAL , GTK_MESSAGE_QUESTION , GTK_BUTTONS_NONE , _ ( "Do you want to empty the trash before you unmount?" ) ) ;
 gtk_message_dialog_format_secondary_text ( GTK_MESSAGE_DIALOG ( dialog ) , _ ( "In order to regain the " "free space on this volume " "the trash must be emptied. " "All trashed items on the volume " "will be permanently lost." ) ) ;
 gtk_dialog_add_buttons ( GTK_DIALOG ( dialog ) , _ ( "Do _not Empty Trash" ) , GTK_RESPONSE_REJECT , CANCEL , GTK_RESPONSE_CANCEL , _ ( "Empty _Trash" ) , GTK_RESPONSE_ACCEPT , NULL ) ;
 gtk_dialog_set_default_response ( GTK_DIALOG ( dialog ) , GTK_RESPONSE_ACCEPT ) ;
 gtk_window_set_title ( GTK_WINDOW ( dialog ) , "" ) ;
 gtk_window_set_skip_taskbar_hint ( GTK_WINDOW ( dialog ) , TRUE ) ;
 if ( screen ) {
 gtk_window_set_screen ( GTK_WINDOW ( dialog ) , screen ) ;
 }
 atk_object_set_role ( gtk_widget_get_accessible ( dialog ) , ATK_ROLE_ALERT ) ;
 gtk_window_set_wmclass ( GTK_WINDOW ( dialog ) , "empty_trash" , "Nautilus" ) ;
 gtk_widget_realize ( dialog ) ;
 if ( screen != NULL ) {
 gdk_window_set_transient_for ( gtk_widget_get_window ( GTK_WIDGET ( dialog ) ) , gdk_screen_get_root_window ( screen ) ) ;
 }
 result = gtk_dialog_run ( GTK_DIALOG ( dialog ) ) ;
 gtk_widget_destroy ( dialog ) ;
 return result ;
 }
static ActivationAction get_executable_text_file_action ( GtkWindow * parent_window , NautilusFile * file ) {
 GtkDialog * dialog ;
 char * file_name ;
 char * prompt ;
 char * detail ;
 int preferences_value ;
 int response ;
 g_assert ( nautilus_file_contains_text ( file ) ) ;
 preferences_value = g_settings_get_enum ( nautilus_preferences , NAUTILUS_PREFERENCES_EXECUTABLE_TEXT_ACTIVATION ) ;
 switch ( preferences_value ) {
 case NAUTILUS_EXECUTABLE_TEXT_LAUNCH : {
 return ACTIVATION_ACTION_LAUNCH ;
 }
 case NAUTILUS_EXECUTABLE_TEXT_DISPLAY : {
 return ACTIVATION_ACTION_OPEN_IN_APPLICATION ;
 }
 case NAUTILUS_EXECUTABLE_TEXT_ASK : {
 }
 break ;
 default : g_warning ( "Unknown value %d for NAUTILUS_PREFERENCES_EXECUTABLE_TEXT_ACTIVATION" , preferences_value ) ;
 }
 file_name = nautilus_file_get_display_name ( file ) ;
 prompt = g_strdup_printf ( _ ( "Do you want to run “%s”, or display its contents?" ) , file_name ) ;
 detail = g_strdup_printf ( _ ( "“%s” is an executable text file." ) , file_name ) ;
 g_free ( file_name ) ;
 dialog = eel_create_question_dialog ( prompt , detail , _ ( "Run in _Terminal" ) , RESPONSE_RUN_IN_TERMINAL , _ ( "_Display" ) , RESPONSE_DISPLAY , parent_window ) ;
 gtk_dialog_add_button ( dialog , _ ( "_Cancel" ) , GTK_RESPONSE_CANCEL ) ;
 gtk_dialog_add_button ( dialog , _ ( "_Run" ) , RESPONSE_RUN ) ;
 gtk_dialog_set_default_response ( dialog , GTK_RESPONSE_CANCEL ) ;
 gtk_widget_show ( GTK_WIDGET ( dialog ) ) ;
 g_free ( prompt ) ;
 g_free ( detail ) ;
 response = gtk_dialog_run ( dialog ) ;
 gtk_widget_destroy ( GTK_WIDGET ( dialog ) ) ;
 switch ( response ) {
 case RESPONSE_RUN : {
 return ACTIVATION_ACTION_LAUNCH ;
 }
 case RESPONSE_RUN_IN_TERMINAL : {
 return ACTIVATION_ACTION_LAUNCH_IN_TERMINAL ;
 }
 case RESPONSE_DISPLAY : {
 return ACTIVATION_ACTION_OPEN_IN_APPLICATION ;
 }
 default : return ACTIVATION_ACTION_DO_NOTHING ;
 }
 }
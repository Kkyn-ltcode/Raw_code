static void application_unhandled_file_install ( GtkDialog * dialog , gint response_id , ActivateParametersInstall * parameters_install ) {
 char * mime_type ;
 gtk_widget_destroy ( GTK_WIDGET ( dialog ) ) ;
 parameters_install -> dialog = NULL ;
 if ( response_id == GTK_RESPONSE_YES ) {
 mime_type = nautilus_file_get_mime_type ( parameters_install -> file ) ;
 search_for_application_mime_type ( parameters_install , mime_type ) ;
 g_free ( mime_type ) ;
 }
 else {
 activate_parameters_install_free ( parameters_install ) ;
 }
 }
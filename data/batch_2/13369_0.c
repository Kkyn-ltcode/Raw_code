static void search_for_application_dbus_call_notify_cb ( GDBusProxy * proxy , GAsyncResult * result , gpointer user_data ) {
 ActivateParametersInstall * parameters_install = user_data ;
 GVariant * variant ;
 GError * error = NULL ;
 variant = g_dbus_proxy_call_finish ( proxy , result , & error ) ;
 if ( variant == NULL ) {
 if ( ! g_dbus_error_is_remote_error ( error ) || g_strcmp0 ( g_dbus_error_get_remote_error ( error ) , "org.freedesktop.PackageKit.Modify.Failed" ) == 0 ) {
 char * message ;
 message = g_strdup_printf ( "%s\n%s" , _ ( "There was an internal error trying to search for applications:" ) , error -> message ) ;
 eel_show_error_dialog ( _ ( "Unable to search for application" ) , message , parameters_install -> parent_window ) ;
 g_free ( message ) ;
 }
 else {
 g_warning ( "Error while trying to search for applications: %s" , error -> message ) ;
 }
 g_error_free ( error ) ;
 activate_parameters_install_free ( parameters_install ) ;
 return ;
 }
 g_variant_unref ( variant ) ;
 nautilus_mime_activate_files ( parameters_install -> parent_window , parameters_install -> slot , parameters_install -> files , parameters_install -> activation_directory , parameters_install -> flags , parameters_install -> user_confirmation ) ;
 activate_parameters_install_free ( parameters_install ) ;
 }
static void application_unhandled_uri ( ActivateParameters * parameters , char * uri ) {
 gboolean show_install_mime ;
 char * mime_type ;
 NautilusFile * file ;
 ActivateParametersInstall * parameters_install ;
 file = nautilus_file_get_by_uri ( uri ) ;
 mime_type = nautilus_file_get_mime_type ( file ) ;
 parameters_install = g_new0 ( ActivateParametersInstall , 1 ) ;
 parameters_install -> slot = parameters -> slot ;
 g_object_add_weak_pointer ( G_OBJECT ( parameters_install -> slot ) , ( gpointer * ) & parameters_install -> slot ) ;
 if ( parameters -> parent_window ) {
 parameters_install -> parent_window = parameters -> parent_window ;
 g_object_add_weak_pointer ( G_OBJECT ( parameters_install -> parent_window ) , ( gpointer * ) & parameters_install -> parent_window ) ;
 }
 parameters_install -> activation_directory = g_strdup ( parameters -> activation_directory ) ;
 parameters_install -> file = file ;
 parameters_install -> files = get_file_list_for_launch_locations ( parameters -> locations ) ;
 parameters_install -> flags = parameters -> flags ;
 parameters_install -> user_confirmation = parameters -> user_confirmation ;
 parameters_install -> uri = g_strdup ( uri ) ;
 # ifdef ENABLE_PACKAGEKIT show_install_mime = g_settings_get_boolean ( nautilus_preferences , NAUTILUS_PREFERENCES_INSTALL_MIME_ACTIVATION ) ;
 # else show_install_mime = FALSE ;
 # endif if ( g_content_type_is_unknown ( mime_type ) ) {
 show_install_mime = FALSE ;
 }
 g_free ( mime_type ) ;
 if ( ! show_install_mime ) {
 goto out ;
 }
 g_dbus_proxy_new_for_bus ( G_BUS_TYPE_SESSION , G_DBUS_PROXY_FLAGS_NONE , NULL , "org.freedesktop.PackageKit" , "/org/freedesktop/PackageKit" , "org.freedesktop.PackageKit.Modify" , NULL , pk_proxy_appeared_cb , parameters_install ) ;
 return ;
 out : show_unhandled_type_error ( parameters_install ) ;
 }
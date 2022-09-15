static void search_for_application_mime_type ( ActivateParametersInstall * parameters_install , const gchar * mime_type ) {
 GdkWindow * window ;
 guint xid = 0 ;
 const char * mime_types [ 2 ] ;
 g_assert ( parameters_install -> proxy != NULL ) ;
 window = gtk_widget_get_window ( GTK_WIDGET ( parameters_install -> parent_window ) ) ;
 if ( window != NULL ) {
 xid = GDK_WINDOW_XID ( window ) ;
 }
 mime_types [ 0 ] = mime_type ;
 mime_types [ 1 ] = NULL ;
 g_dbus_proxy_call ( parameters_install -> proxy , "InstallMimeTypes" , g_variant_new ( "(u^ass)" , xid , mime_types , "hide-confirm-search" ) , G_DBUS_CALL_FLAGS_NONE , G_MAXINT , NULL , ( GAsyncReadyCallback ) search_for_application_dbus_call_notify_cb , parameters_install ) ;
 DEBUG ( "InstallMimeType method invoked for %s" , mime_type ) ;
 }
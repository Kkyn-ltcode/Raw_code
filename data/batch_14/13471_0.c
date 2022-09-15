static gboolean should_skip_file ( NautilusDirectory * directory , GFileInfo * info ) {
 static gboolean show_hidden_files_changed_callback_installed = FALSE ;
 if ( ! show_hidden_files_changed_callback_installed ) {
 g_signal_connect_swapped ( gtk_filechooser_preferences , "changed::" NAUTILUS_PREFERENCES_SHOW_HIDDEN_FILES , G_CALLBACK ( show_hidden_files_changed_callback ) , NULL ) ;
 show_hidden_files_changed_callback_installed = TRUE ;
 show_hidden_files_changed_callback ( NULL ) ;
 }
 if ( ! show_hidden_files && ( g_file_info_get_is_hidden ( info ) || g_file_info_get_is_backup ( info ) ) ) {
 return TRUE ;
 }
 return FALSE ;
 }
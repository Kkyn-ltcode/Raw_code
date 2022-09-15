static void activate_files ( ActivateParameters * parameters ) {
 NautilusFile * file ;
 NautilusWindow * window ;
 NautilusWindowOpenFlags flags ;
 g_autoptr ( GList ) open_in_app_parameters = NULL ;
 g_autoptr ( GList ) unhandled_open_in_app_uris = NULL ;
 ApplicationLaunchParameters * one_parameters ;
 int count ;
 g_autofree char * old_working_dir = NULL ;
 GdkScreen * screen ;
 gint num_apps ;
 gint num_unhandled ;
 gint num_files ;
 gboolean open_files ;
 gboolean closed_window ;
 g_autoptr ( GQueue ) launch_desktop_files = NULL ;
 g_autoptr ( GQueue ) launch_files = NULL ;
 g_autoptr ( GQueue ) launch_in_terminal_files = NULL ;
 g_autoptr ( GQueue ) open_in_app_uris = NULL ;
 g_autoptr ( GQueue ) open_in_view_files = NULL ;
 GList * l ;
 ActivationAction action ;
 LaunchLocation * location ;
 launch_desktop_files = g_queue_new ( ) ;
 launch_files = g_queue_new ( ) ;
 launch_in_terminal_files = g_queue_new ( ) ;
 open_in_view_files = g_queue_new ( ) ;
 open_in_app_uris = g_queue_new ( ) ;
 for ( l = parameters -> locations ;
 l != NULL ;
 l = l -> next ) {
 location = l -> data ;
 file = location -> file ;
 if ( file_was_cancelled ( file ) ) {
 continue ;
 }
 action = get_activation_action ( file ) ;
 if ( action == ACTIVATION_ACTION_ASK ) {
 pause_activation_timed_cancel ( parameters ) ;
 action = get_executable_text_file_action ( parameters -> parent_window , file ) ;
 unpause_activation_timed_cancel ( parameters ) ;
 }
 switch ( action ) {
 case ACTIVATION_ACTION_LAUNCH_DESKTOP_FILE : {
 g_queue_push_tail ( launch_desktop_files , file ) ;
 }
 break ;
 case ACTIVATION_ACTION_LAUNCH : {
 g_queue_push_tail ( launch_files , file ) ;
 }
 break ;
 case ACTIVATION_ACTION_LAUNCH_IN_TERMINAL : {
 g_queue_push_tail ( launch_in_terminal_files , file ) ;
 }
 break ;
 case ACTIVATION_ACTION_OPEN_IN_VIEW : {
 g_queue_push_tail ( open_in_view_files , file ) ;
 }
 break ;
 case ACTIVATION_ACTION_OPEN_IN_APPLICATION : {
 g_queue_push_tail ( open_in_app_uris , location -> uri ) ;
 }
 break ;
 case ACTIVATION_ACTION_DO_NOTHING : {
 }
 break ;
 case ACTIVATION_ACTION_EXTRACT : {
 g_assert_not_reached ( ) ;
 }
 break ;
 case ACTIVATION_ACTION_ASK : {
 g_assert_not_reached ( ) ;
 }
 break ;
 }
 }
 for ( l = g_queue_peek_head_link ( launch_desktop_files ) ;
 l != NULL ;
 l = l -> next ) {
 file = NAUTILUS_FILE ( l -> data ) ;
 activate_desktop_file ( parameters , file ) ;
 }
 if ( parameters -> activation_directory && ( ! g_queue_is_empty ( launch_files ) || ! g_queue_is_empty ( launch_in_terminal_files ) ) ) {
 old_working_dir = g_get_current_dir ( ) ;
 g_chdir ( parameters -> activation_directory ) ;
 }
 screen = gtk_widget_get_screen ( GTK_WIDGET ( parameters -> parent_window ) ) ;
 for ( l = g_queue_peek_head_link ( launch_files ) ;
 l != NULL ;
 l = l -> next ) {
 g_autofree char * uri = NULL ;
 g_autofree char * executable_path = NULL ;
 g_autofree char * quoted_path = NULL ;
 file = NAUTILUS_FILE ( l -> data ) ;
 uri = nautilus_file_get_activation_uri ( file ) ;
 executable_path = g_filename_from_uri ( uri , NULL , NULL ) ;
 quoted_path = g_shell_quote ( executable_path ) ;
 DEBUG ( "Launching file path %s" , quoted_path ) ;
 nautilus_launch_application_from_command ( screen , quoted_path , FALSE , NULL ) ;
 }
 for ( l = g_queue_peek_head_link ( launch_in_terminal_files ) ;
 l != NULL ;
 l = l -> next ) {
 g_autofree char * uri = NULL ;
 g_autofree char * executable_path = NULL ;
 g_autofree char * quoted_path = NULL ;
 file = NAUTILUS_FILE ( l -> data ) ;
 uri = nautilus_file_get_activation_uri ( file ) ;
 executable_path = g_filename_from_uri ( uri , NULL , NULL ) ;
 quoted_path = g_shell_quote ( executable_path ) ;
 DEBUG ( "Launching in terminal file quoted path %s" , quoted_path ) ;
 nautilus_launch_application_from_command ( screen , quoted_path , TRUE , NULL ) ;
 }
 if ( old_working_dir != NULL ) {
 g_chdir ( old_working_dir ) ;
 }
 count = g_queue_get_length ( open_in_view_files ) ;
 flags = parameters -> flags ;
 if ( count > 1 ) {
 if ( ( parameters -> flags & NAUTILUS_WINDOW_OPEN_FLAG_NEW_WINDOW ) == 0 ) {
 if ( ( parameters -> flags & NAUTILUS_WINDOW_OPEN_FLAG_CLOSE_BEHIND ) != 0 ) {
 flags |= NAUTILUS_WINDOW_OPEN_FLAG_NEW_WINDOW ;
 }
 else {
 flags |= NAUTILUS_WINDOW_OPEN_FLAG_NEW_TAB ;
 }
 }
 else {
 flags |= NAUTILUS_WINDOW_OPEN_FLAG_NEW_WINDOW ;
 }
 }
 else {
 if ( ( parameters -> flags & NAUTILUS_WINDOW_OPEN_FLAG_CLOSE_BEHIND ) != 0 ) {
 flags |= NAUTILUS_WINDOW_OPEN_FLAG_NEW_WINDOW ;
 }
 }
 if ( parameters -> slot != NULL && ( ! parameters -> user_confirmation || confirm_multiple_windows ( parameters -> parent_window , count , ( flags & NAUTILUS_WINDOW_OPEN_FLAG_NEW_TAB ) != 0 ) ) ) {
 if ( ( flags & NAUTILUS_WINDOW_OPEN_FLAG_NEW_TAB ) != 0 && g_settings_get_enum ( nautilus_preferences , NAUTILUS_PREFERENCES_NEW_TAB_POSITION ) == NAUTILUS_NEW_TAB_POSITION_AFTER_CURRENT_TAB ) {
 g_queue_reverse ( open_in_view_files ) ;
 }
 closed_window = FALSE ;
 for ( l = g_queue_peek_head_link ( open_in_view_files ) ;
 l != NULL ;
 l = l -> next ) {
 g_autofree char * uri = NULL ;
 g_autoptr ( GFile ) location = NULL ;
 g_autoptr ( GFile ) location_with_permissions = NULL ;
 file = NAUTILUS_FILE ( l -> data ) ;
 uri = nautilus_file_get_activation_uri ( file ) ;
 location = g_file_new_for_uri ( uri ) ;
 if ( g_file_is_native ( location ) && ( nautilus_file_is_in_admin ( file ) || ! nautilus_file_can_read ( file ) || ! nautilus_file_can_execute ( file ) ) ) {
 g_autofree gchar * file_path = NULL ;
 g_free ( uri ) ;
 file_path = g_file_get_path ( location ) ;
 uri = g_strconcat ( "admin://" , file_path , NULL ) ;
 }
 location_with_permissions = g_file_new_for_uri ( uri ) ;
 nautilus_application_open_location_full ( NAUTILUS_APPLICATION ( g_application_get_default ( ) ) , location_with_permissions , flags , NULL , NULL , parameters -> slot ) ;
 if ( ! closed_window && ( flags & NAUTILUS_WINDOW_OPEN_FLAG_CLOSE_BEHIND ) != 0 ) {
 flags &= ( ~ NAUTILUS_WINDOW_OPEN_FLAG_CLOSE_BEHIND ) ;
 if ( ( parameters -> flags & NAUTILUS_WINDOW_OPEN_FLAG_NEW_WINDOW ) == 0 ) {
 flags &= ( ~ NAUTILUS_WINDOW_OPEN_FLAG_NEW_WINDOW ) ;
 flags |= NAUTILUS_WINDOW_OPEN_FLAG_NEW_TAB ;
 }
 closed_window = TRUE ;
 }
 }
 }
 if ( open_in_app_uris != NULL ) {
 open_in_app_parameters = make_activation_parameters ( g_queue_peek_head_link ( open_in_app_uris ) , & unhandled_open_in_app_uris ) ;
 }
 num_apps = g_list_length ( open_in_app_parameters ) ;
 num_unhandled = g_list_length ( unhandled_open_in_app_uris ) ;
 num_files = g_queue_get_length ( open_in_app_uris ) ;
 open_files = TRUE ;
 if ( g_queue_is_empty ( open_in_app_uris ) && ( ! parameters -> user_confirmation || num_files + num_unhandled > SILENT_OPEN_LIMIT ) && num_apps > 1 ) {
 GtkDialog * dialog ;
 char * prompt ;
 g_autofree char * detail = NULL ;
 int response ;
 pause_activation_timed_cancel ( parameters ) ;
 prompt = _ ( "Are you sure you want to open all files?" ) ;
 detail = g_strdup_printf ( ngettext ( "This will open %d separate application." , "This will open %d separate applications." , num_apps ) , num_apps ) ;
 dialog = eel_show_yes_no_dialog ( prompt , detail , _ ( "_OK" ) , _ ( "_Cancel" ) , parameters -> parent_window ) ;
 response = gtk_dialog_run ( dialog ) ;
 gtk_widget_destroy ( GTK_WIDGET ( dialog ) ) ;
 unpause_activation_timed_cancel ( parameters ) ;
 if ( response != GTK_RESPONSE_YES ) {
 open_files = FALSE ;
 }
 }
 if ( open_files ) {
 for ( l = open_in_app_parameters ;
 l != NULL ;
 l = l -> next ) {
 one_parameters = l -> data ;
 nautilus_launch_application_by_uri ( one_parameters -> application , one_parameters -> uris , parameters -> parent_window ) ;
 application_launch_parameters_free ( one_parameters ) ;
 }
 for ( l = unhandled_open_in_app_uris ;
 l != NULL ;
 l = l -> next ) {
 char * uri = l -> data ;
 application_unhandled_uri ( parameters , uri ) ;
 }
 }
 window = NULL ;
 if ( parameters -> slot != NULL ) {
 window = nautilus_window_slot_get_window ( parameters -> slot ) ;
 }
 if ( open_in_app_parameters != NULL || unhandled_open_in_app_uris != NULL ) {
 if ( ( parameters -> flags & NAUTILUS_WINDOW_OPEN_FLAG_CLOSE_BEHIND ) != 0 && window != NULL ) {
 nautilus_window_close ( window ) ;
 }
 }
 activation_parameters_free ( parameters ) ;
 }
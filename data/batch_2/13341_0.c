static void activation_get_activation_uris ( ActivateParameters * parameters ) {
 GList * l , * files ;
 NautilusFile * file ;
 LaunchLocation * location ;
 for ( l = parameters -> locations ;
 l != NULL ;
 l = l -> next ) {
 location = l -> data ;
 file = location -> file ;
 if ( file_was_cancelled ( file ) ) {
 launch_location_free ( location ) ;
 parameters -> locations = g_list_delete_link ( parameters -> locations , l ) ;
 continue ;
 }
 }
 if ( parameters -> locations == NULL ) {
 activation_parameters_free ( parameters ) ;
 return ;
 }
 files = get_file_list_for_launch_locations ( parameters -> locations ) ;
 nautilus_file_list_call_when_ready ( files , nautilus_mime_actions_get_required_file_attributes ( ) , & parameters -> files_handle , activate_activation_uris_ready_callback , parameters ) ;
 nautilus_file_list_free ( files ) ;
 }
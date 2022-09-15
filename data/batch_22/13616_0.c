static GFile * get_target_file_with_custom_name ( GFile * src , GFile * dest_dir , const char * dest_fs_type , gboolean same_fs , const gchar * custom_name ) {
 char * basename ;
 GFile * dest ;
 GFileInfo * info ;
 char * copyname ;
 dest = NULL ;
 if ( custom_name != NULL ) {
 copyname = g_strdup ( custom_name ) ;
 make_file_name_valid_for_dest_fs ( copyname , dest_fs_type ) ;
 dest = g_file_get_child_for_display_name ( dest_dir , copyname , NULL ) ;
 g_free ( copyname ) ;
 }
 if ( dest == NULL && ! same_fs ) {
 info = g_file_query_info ( src , G_FILE_ATTRIBUTE_STANDARD_COPY_NAME "," G_FILE_ATTRIBUTE_TRASH_ORIG_PATH , 0 , NULL , NULL ) ;
 if ( info ) {
 copyname = NULL ;
 if ( g_file_has_uri_scheme ( src , "trash" ) ) {
 copyname = g_path_get_basename ( g_file_info_get_attribute_byte_string ( info , G_FILE_ATTRIBUTE_TRASH_ORIG_PATH ) ) ;
 }
 if ( copyname == NULL ) {
 copyname = g_strdup ( g_file_info_get_attribute_string ( info , G_FILE_ATTRIBUTE_STANDARD_COPY_NAME ) ) ;
 }
 if ( copyname ) {
 make_file_name_valid_for_dest_fs ( copyname , dest_fs_type ) ;
 dest = g_file_get_child_for_display_name ( dest_dir , copyname , NULL ) ;
 g_free ( copyname ) ;
 }
 g_object_unref ( info ) ;
 }
 }
 if ( dest == NULL ) {
 basename = g_file_get_basename ( src ) ;
 make_file_name_valid_for_dest_fs ( basename , dest_fs_type ) ;
 dest = g_file_get_child ( dest_dir , basename ) ;
 g_free ( basename ) ;
 }
 return dest ;
 }
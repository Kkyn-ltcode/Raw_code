GList * nautilus_mime_types_group_get_mimetypes ( gint group_index ) {
 GList * mimetypes ;
 gint i ;
 g_return_val_if_fail ( group_index < G_N_ELEMENTS ( mimetype_groups ) , NULL ) ;
 mimetypes = NULL ;
 for ( i = 0 ;
 mimetype_groups [ group_index ] . mimetypes [ i ] ;
 i ++ ) {
 mimetypes = g_list_append ( mimetypes , mimetype_groups [ group_index ] . mimetypes [ i ] ) ;
 }
 return mimetypes ;
 }
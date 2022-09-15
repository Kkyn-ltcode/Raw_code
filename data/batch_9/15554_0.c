static void proto_tree_set_system_id ( field_info * fi , const guint8 * value_ptr , gint length ) {
 GByteArray * bytes ;
 DISSECTOR_ASSERT ( value_ptr != NULL || length == 0 ) ;
 bytes = g_byte_array_new ( ) ;
 if ( length > 0 ) {
 g_byte_array_append ( bytes , value_ptr , length ) ;
 }
 fvalue_set_byte_array ( & fi -> value , bytes ) ;
 }
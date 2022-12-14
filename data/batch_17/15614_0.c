proto_item * proto_tree_add_string ( proto_tree * tree , int hfindex , tvbuff_t * tvb , gint start , gint length , const char * value ) {
 proto_item * pi ;
 header_field_info * hfinfo ;
 CHECK_FOR_NULL_TREE ( tree ) ;
 TRY_TO_FAKE_THIS_ITEM ( tree , hfindex , hfinfo ) ;
 DISSECTOR_ASSERT_FIELD_TYPE_IS_STRING ( hfinfo ) ;
 if ( hfinfo -> display == STR_UNICODE ) {
 DISSECTOR_ASSERT ( g_utf8_validate ( value , - 1 , NULL ) ) ;
 }
 pi = proto_tree_add_pi ( tree , hfinfo , tvb , start , & length ) ;
 DISSECTOR_ASSERT ( length >= 0 ) ;
 proto_tree_set_string ( PNODE_FINFO ( pi ) , value ) ;
 return pi ;
 }
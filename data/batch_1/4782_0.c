static int parse_VariantColVector ( tvbuff_t * tvb , int offset , proto_tree * tree , guint64 base_address , gboolean is_64bit , struct CRowVariant * variant , struct vtype_data * vt_list_type ) {
 guint32 i = 0 ;
 guint64 count = 0 ;
 int buf_offset = 0 ;
 proto_tree * sub_tree ;
 wmem_strbuf_t * strbuf ;
 offset = parse_CRowVariantArrayInfo ( tvb , offset , tree , is_64bit , variant ) ;
 if ( is_64bit ) {
 buf_offset = ( int ) ( variant -> content . array_vector . i64 . array_address - base_address ) ;
 count = variant -> content . array_vector . i64 . count ;
 }
 else {
 buf_offset = ( int ) ( variant -> content . array_vector . i32 . array_address - base_address ) ;
 count = variant -> content . array_vector . i32 . count ;
 }
 sub_tree = proto_tree_add_subtree ( tree , tvb , buf_offset , 0 , ett_CRowVariant_Vector , NULL , "values" ) ;
 for ( i = 0 ;
 i < count ;
 i ++ ) {
 guint64 item_address = 0 ;
 gint address_of_address = 0 ;
 int size ;
 union vt_single value ;
 int len ;
 if ( is_64bit ) {
 size = 8 ;
 address_of_address = buf_offset + ( i * size ) ;
 item_address = tvb_get_letoh64 ( tvb , address_of_address ) ;
 proto_tree_add_uint64_format ( sub_tree , hf_mswsp_rowvariant_item_address64 , tvb , address_of_address , size , item_address , "address[%d] 0x%" G_GINT64_MODIFIER "x" , i , item_address ) ;
 }
 else {
 size = 4 ;
 item_address = tvb_get_letohl ( tvb , buf_offset + ( i * size ) ) ;
 proto_tree_add_uint_format ( sub_tree , hf_mswsp_rowvariant_item_address32 , tvb , address_of_address , size , ( guint32 ) item_address , "address[%d] 0x%x" , i , ( guint32 ) item_address ) ;
 }
 strbuf = wmem_strbuf_new ( wmem_packet_scope ( ) , "" ) ;
 if ( vt_list_type -> size == - 1 ) {
 DISSECTOR_ASSERT_HINT ( vt_list_type -> tvb_get_value_only != 0 , "appears this is a vector of dynamic types that we don't know yet how to handle, please submit a bug with trace" ) ;
 len = vt_list_type -> tvb_get_value_only ( tvb , ( int ) ( item_address - base_address ) , 0 , & value ) ;
 vt_list_type -> strbuf_append ( strbuf , & value ) ;
 }
 else {
 len = vt_list_type -> size ;
 DISSECTOR_ASSERT_HINT ( vt_list_type -> tvb_get != 0 , "appears this is a vector of fixed types that we don't know yet how to handle, please submit a bug with trace" ) ;
 vt_list_type -> tvb_get ( tvb , ( int ) ( item_address - base_address ) , & value ) ;
 vt_list_type -> strbuf_append ( strbuf , & value ) ;
 }
 proto_tree_add_string ( sub_tree , hf_mswsp_rowvariant_item_value , tvb , ( gint ) ( item_address - base_address ) , len , wmem_strbuf_get_str ( strbuf ) ) ;
 }
 return offset ;
 }
static int parse_CDbProp ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , struct GuidPropertySet * propset , const char * fmt , ... ) {
 static const value_string EMPTY_VS [ ] = {
 {
 0 , NULL }
 }
 ;
 const value_string * vs = ( propset && propset -> id_map ) ? propset -> id_map : EMPTY_VS ;
 guint32 id , opt , status ;
 struct CBaseStorageVariant value ;
 proto_item * item ;
 proto_tree * tree ;
 const char * str , * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CDbProp , & item , txt ) ;
 id = tvb_get_letohl ( tvb , offset ) ;
 str = val_to_str ( id , vs , "0x%08x" ) ;
 proto_tree_add_string_format_value ( tree , hf_mswsp_cdbprop_id , tvb , offset , 4 , str , "%s (0x%08x)" , ( str [ 0 ] == '0' ? "" : str ) , id ) ;
 offset += 4 ;
 proto_item_append_text ( item , " Id: %s" , str ) ;
 opt = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_cdbprop_options , tvb , offset , 4 , opt ) ;
 offset += 4 ;
 status = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_cdbprop_status , tvb , offset , 4 , status ) ;
 offset += 4 ;
 offset = parse_CDbColId ( tvb , offset , tree , pad_tree , "colid" ) ;
 offset = parse_CBaseStorageVariant ( tvb , pinfo , offset , tree , pad_tree , & value , "vValue" ) ;
 str = str_CBaseStorageVariant ( & value , TRUE ) ;
 proto_item_append_text ( item , " %s" , str ) ;
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
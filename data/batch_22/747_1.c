int parse_CCategSpec ( tvbuff_t * tvb , int offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 proto_item * item ;
 proto_tree * tree ;
 va_list ap ;
 guint32 type ;
 const char * txt ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CCategSpec , & item , txt ) ;
 type = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_ccategspec_type , tvb , offset , 4 , type ) ;
 proto_item_append_text ( item , " Type %u" , type ) ;
 offset += 4 ;
 offset = parse_CSort ( tvb , offset , tree , pad_tree , "CSort" ) ;
 offset = parse_CRangeCategSpec ( tvb , offset , tree , pad_tree , "CRangeCategSpec" ) ;
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
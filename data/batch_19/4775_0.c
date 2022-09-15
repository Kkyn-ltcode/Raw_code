static int parse_CCoercionRestriction ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , struct CCoercionRestriction * v , const char * fmt , ... ) {
 proto_tree * tree ;
 proto_item * item ;
 const char * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CCoercionRestriction , & item , txt ) ;
 v -> value = tvb_get_letohieee_float ( tvb , offset ) ;
 proto_tree_add_float ( tree , hf_mswsp_ccoercerestrict_value , tvb , offset , 4 , v -> value ) ;
 offset += 4 ;
 offset = parse_CRestriction ( tvb , pinfo , offset , tree , pad_tree , & v -> child , "child" ) ;
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
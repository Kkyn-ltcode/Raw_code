static int parse_CNodeRestriction ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , struct CNodeRestriction * v , const char * fmt , ... ) {
 proto_tree * tree ;
 proto_item * item ;
 unsigned i ;
 const char * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CNodeRestriction , & item , txt ) ;
 v -> cNode = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_cnoderestrict_cnode , tvb , offset , 4 , v -> cNode ) ;
 offset += 4 ;
 for ( i = 0 ;
 i < v -> cNode ;
 i ++ ) {
 struct CRestriction r ;
 ZERO_STRUCT ( r ) ;
 offset = parse_CRestriction ( tvb , pinfo , offset , tree , pad_tree , & r , "paNode[%u]" , i ) ;
 offset = parse_padding ( tvb , offset , 4 , tree , "padding_paNode[%u]" , i ) ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
int parse_CRangeCategSpec ( tvbuff_t * tvb , int offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 proto_item * item ;
 proto_tree * tree ;
 va_list ap ;
 unsigned i ;
 const char * txt ;
 guint32 cRange ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CRangeCategSpec , & item , txt ) ;
 offset = parse_lcid ( tvb , offset , tree , "lcid" ) ;
 cRange = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_crangecategspec_crange , tvb , offset , 4 , cRange ) ;
 offset += 4 ;
 for ( i = 0 ;
 i < cRange ;
 i ++ ) {
 offset = parse_RANGEBOUNDARY ( tvb , offset , tree , pad_tree , "aRangeBegin[%u]" , i ) ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
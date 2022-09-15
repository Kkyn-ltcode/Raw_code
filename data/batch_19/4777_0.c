static int parse_CInGroupSortAggregSets ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 guint32 cCount , i ;
 proto_item * item ;
 proto_tree * tree ;
 const char * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CInGroupSortAggregSets , & item , txt ) ;
 cCount = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_cingroupsortaggregsets_count , tvb , offset , 4 , cCount ) ;
 offset += 4 ;
 for ( i = 0 ;
 i < cCount ;
 i ++ ) {
 offset = parse_CInGroupSortAggregSet ( tvb , pinfo , offset , tree , pad_tree , "SortSets[%u]" , i ) ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
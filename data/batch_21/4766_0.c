static int parse_CPropertyRestriction ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , struct CPropertyRestriction * v , const char * fmt , ... ) {
 proto_tree * tree ;
 proto_item * item ;
 const char * txt , * str = NULL ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CPropertyRestriction , & item , txt ) ;
 offset = parse_relop ( tvb , offset , tree , & v -> relop , & str ) ;
 proto_item_append_text ( item , " Op: %s" , str ) ;
 offset = parse_CFullPropSpec ( tvb , offset , tree , pad_tree , & v -> property , "Property" ) ;
 offset = parse_CBaseStorageVariant ( tvb , pinfo , offset , tree , pad_tree , & v -> prval , "prval" ) ;
 offset = parse_padding ( tvb , offset , 4 , pad_tree , "padding_lcid" ) ;
 v -> lcid = tvb_get_letohl ( tvb , offset ) ;
 offset = parse_lcid ( tvb , offset , tree , "lcid" ) ;
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
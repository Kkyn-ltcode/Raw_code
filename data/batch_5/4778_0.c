static int parse_CRestrictionArray ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 guint8 present , count ;
 proto_tree * tree ;
 proto_item * item ;
 const char * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CRestrictionArray , & item , txt ) ;
 pad_tree = tree ;
 count = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_crestrictarray_count , tvb , offset , 1 , count ) ;
 offset += 1 ;
 present = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_crestrictarray_present , tvb , offset , 1 , present ) ;
 offset += 1 ;
 if ( present ) {
 unsigned i ;
 offset = parse_padding ( tvb , offset , 4 , pad_tree , "paddingCRestrictionPresent" ) ;
 for ( i = 0 ;
 i < count ;
 i ++ ) {
 struct CRestriction r ;
 offset = parse_CRestriction ( tvb , pinfo , offset , tree , pad_tree , & r , "Restriction[%d]" , i ) ;
 }
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
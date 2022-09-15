static int parse_CDbPropSet ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 int i , num ;
 e_guid_t guid ;
 struct GuidPropertySet * pset ;
 proto_item * item ;
 proto_tree * tree ;
 const char * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CDbPropSet , & item , txt ) ;
 offset = parse_guid ( tvb , offset , tree , & guid , "guidPropertySet" ) ;
 pset = GuidPropertySet_find_guid ( & guid ) ;
 if ( pset ) {
 proto_item_append_text ( item , " \"%s\" (%s)" , pset -> desc , pset -> def ) ;
 }
 else {
 const char * guid_str = guid_to_str ( wmem_packet_scope ( ) , & guid ) ;
 proto_item_append_text ( item , " {
%s}
" , guid_str ) ;
 }
 offset = parse_padding ( tvb , offset , 4 , pad_tree , "guidPropertySet" ) ;
 num = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_mswsp_cdbpropset_cprops , tvb , offset , 4 , num ) ;
 offset += 4 ;
 proto_item_append_text ( item , " Num: %d" , num ) ;
 for ( i = 0 ;
 i < num ;
 i ++ ) {
 offset = parse_padding ( tvb , offset , 4 , pad_tree , "aProp[%d]" , i ) ;
 offset = parse_CDbProp ( tvb , pinfo , offset , tree , pad_tree , pset , "aProp[%d]" , i ) ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
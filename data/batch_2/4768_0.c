static int parse_PropertySetArray ( tvbuff_t * tvb , packet_info * pinfo , int offset , int size_offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 const int offset_in = offset ;
 guint32 size , num ;
 int i ;
 proto_tree * tree ;
 proto_item * item ;
 const char * txt ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_CDbPropSet_Array , & item , txt ) ;
 size = tvb_get_letohl ( tvb , size_offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_ConnectIn_Blob1 , tvb , size_offset , 4 , ENC_LITTLE_ENDIAN ) ;
 num = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_msg_ConnectIn_PropSets_num , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 for ( i = 0 ;
 i < ( int ) num ;
 i ++ ) {
 offset = parse_CDbPropSet ( tvb , pinfo , offset , tree , pad_tree , "PropertySet[%d]" , i ) ;
 }
 proto_item_set_end ( item , tvb , offset ) ;
 DISSECTOR_ASSERT ( offset - offset_in == ( int ) size ) ;
 return offset ;
 }
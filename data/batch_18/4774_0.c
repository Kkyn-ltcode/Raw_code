int parse_RANGEBOUNDARY ( tvbuff_t * tvb , packet_info * pinfo , int offset , proto_tree * parent_tree , proto_tree * pad_tree , const char * fmt , ... ) {
 guint32 ulType ;
 guint8 labelPresent ;
 proto_item * item ;
 proto_tree * tree ;
 const char * txt ;
 struct CBaseStorageVariant prval ;
 va_list ap ;
 va_start ( ap , fmt ) ;
 txt = wmem_strdup_vprintf ( wmem_packet_scope ( ) , fmt , ap ) ;
 va_end ( ap ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , 0 , ett_RANGEBOUNDARY , & item , txt ) ;
 ulType = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_rangeboundry_ultype , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 proto_item_append_text ( item , ": Type 0x%08x" , ulType ) ;
 offset += 4 ;
 ZERO_STRUCT ( prval ) ;
 offset = parse_CBaseStorageVariant ( tvb , pinfo , offset , tree , pad_tree , & prval , "prVal" ) ;
 labelPresent = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_mswsp_rangeboundry_labelpresent , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 1 ;
 if ( labelPresent ) {
 guint32 ccLabel ;
 const guint8 * label ;
 offset = parse_padding ( tvb , offset , 4 , pad_tree , "paddingLabelPresent" ) ;
 ccLabel = tvb_get_letohl ( tvb , offset ) ;
 proto_tree_add_item_ret_uint ( tree , hf_mswsp_rangeboundry_cclabel , tvb , offset , 4 , ENC_LITTLE_ENDIAN , & ccLabel ) ;
 offset += 4 ;
 proto_tree_add_item_ret_string ( tree , hf_mswsp_rangeboundry_label , tvb , offset , 2 * ccLabel , ENC_LITTLE_ENDIAN | ENC_UCS_2 , wmem_packet_scope ( ) , & label ) ;
 proto_item_append_text ( item , " Label: \"%s\"" , label ) ;
 offset += 2 * ccLabel ;
 }
 proto_item_append_text ( item , " Val: %s" , str_CBaseStorageVariant ( & prval , TRUE ) ) ;
 proto_item_set_end ( item , tvb , offset ) ;
 return offset ;
 }
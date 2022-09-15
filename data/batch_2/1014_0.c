void parseExtensionObject ( proto_tree * tree , tvbuff_t * tvb , packet_info * pinfo , gint * pOffset , const char * szFieldName ) {
 static const int * extobj_mask [ ] = {
 & hf_opcua_extobj_mask_binbodyflag , & hf_opcua_extobj_mask_xmlbodyflag , NULL }
 ;
 gint iOffset = * pOffset ;
 guint8 EncodingMask ;
 guint32 TypeId ;
 proto_tree * extobj_tree ;
 proto_item * ti ;
 guint opcua_nested_count ;
 extobj_tree = proto_tree_add_subtree_format ( tree , tvb , * pOffset , - 1 , ett_opcua_extensionobject , & ti , "%s: ExtensionObject" , szFieldName ) ;
 opcua_nested_count = GPOINTER_TO_UINT ( p_get_proto_data ( pinfo -> pool , pinfo , proto_opcua , 0 ) ) ;
 if ( ++ opcua_nested_count > MAX_NESTING_DEPTH ) {
 expert_add_info ( pinfo , ti , & ei_nesting_depth ) ;
 return ;
 }
 p_add_proto_data ( pinfo -> pool , pinfo , proto_opcua , 0 , GUINT_TO_POINTER ( opcua_nested_count ) ) ;
 TypeId = getExtensionObjectType ( tvb , & iOffset ) ;
 parseExpandedNodeId ( extobj_tree , tvb , pinfo , & iOffset , "TypeId" ) ;
 EncodingMask = tvb_get_guint8 ( tvb , iOffset ) ;
 proto_tree_add_bitmask ( extobj_tree , tvb , iOffset , hf_opcua_extobj_mask , ett_opcua_extensionobject_encodingmask , extobj_mask , ENC_LITTLE_ENDIAN ) ;
 iOffset ++ ;
 if ( EncodingMask & EXTOBJ_ENCODINGMASK_BINBODY_FLAG ) {
 dispatchExtensionObjectType ( extobj_tree , tvb , pinfo , & iOffset , TypeId ) ;
 }
 proto_item_set_end ( ti , tvb , iOffset ) ;
 * pOffset = iOffset ;
 }
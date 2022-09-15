void parseVariant ( proto_tree * tree , tvbuff_t * tvb , packet_info * pinfo , gint * pOffset , const char * szFieldName ) {
 proto_item * ti ;
 proto_tree * subtree = proto_tree_add_subtree_format ( tree , tvb , * pOffset , - 1 , ett_opcua_variant , & ti , "%s: Variant" , szFieldName ) ;
 gint iOffset = * pOffset ;
 guint8 EncodingMask ;
 gint32 ArrayDimensions = 0 ;
 guint opcua_nested_count ;
 opcua_nested_count = GPOINTER_TO_UINT ( p_get_proto_data ( pinfo -> pool , pinfo , proto_opcua , 0 ) ) ;
 if ( ++ opcua_nested_count > MAX_NESTING_DEPTH ) {
 expert_add_info ( pinfo , ti , & ei_nesting_depth ) ;
 return ;
 }
 p_add_proto_data ( pinfo -> pool , pinfo , proto_opcua , 0 , GUINT_TO_POINTER ( opcua_nested_count ) ) ;
 EncodingMask = tvb_get_guint8 ( tvb , iOffset ) ;
 proto_tree_add_item ( subtree , hf_opcua_variant_encodingmask , tvb , iOffset , 1 , ENC_LITTLE_ENDIAN ) ;
 iOffset ++ ;
 if ( EncodingMask & VARIANT_ARRAYMASK ) {
 switch ( EncodingMask & 0x3f ) {
 case OpcUaType_Null : break ;
 case OpcUaType_Boolean : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Boolean" , "Boolean" , hf_opcua_Boolean , parseBoolean , ett_opcua_array_Boolean ) ;
 break ;
 case OpcUaType_SByte : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "SByte" , "SByte" , hf_opcua_SByte , parseSByte , ett_opcua_array_SByte ) ;
 break ;
 case OpcUaType_Byte : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Byte" , "Byte" , hf_opcua_Byte , parseByte , ett_opcua_array_Byte ) ;
 break ;
 case OpcUaType_Int16 : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Int16" , "Int16" , hf_opcua_Int16 , parseInt16 , ett_opcua_array_Int16 ) ;
 break ;
 case OpcUaType_UInt16 : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "UInt16" , "UInt16" , hf_opcua_UInt16 , parseUInt16 , ett_opcua_array_UInt16 ) ;
 break ;
 case OpcUaType_Int32 : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Int32" , "Int32" , hf_opcua_Int32 , parseInt32 , ett_opcua_array_Int32 ) ;
 break ;
 case OpcUaType_UInt32 : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "UInt32" , "UInt32" , hf_opcua_UInt32 , parseUInt32 , ett_opcua_array_UInt32 ) ;
 break ;
 case OpcUaType_Int64 : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Int64" , "Int64" , hf_opcua_Int64 , parseInt64 , ett_opcua_array_Int64 ) ;
 break ;
 case OpcUaType_UInt64 : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "UInt64" , "UInt64" , hf_opcua_UInt64 , parseUInt64 , ett_opcua_array_UInt64 ) ;
 break ;
 case OpcUaType_Float : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Float" , "Float" , hf_opcua_Float , parseFloat , ett_opcua_array_Float ) ;
 break ;
 case OpcUaType_Double : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Double" , "Double" , hf_opcua_Double , parseDouble , ett_opcua_array_Double ) ;
 break ;
 case OpcUaType_String : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "String" , "String" , hf_opcua_String , parseString , ett_opcua_array_String ) ;
 break ;
 case OpcUaType_DateTime : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "DateTime" , "DateTime" , hf_opcua_DateTime , parseDateTime , ett_opcua_array_DateTime ) ;
 break ;
 case OpcUaType_Guid : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "Guid" , "Guid" , hf_opcua_Guid , parseGuid , ett_opcua_array_Guid ) ;
 break ;
 case OpcUaType_ByteString : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "ByteString" , "ByteString" , hf_opcua_ByteString , parseByteString , ett_opcua_array_ByteString ) ;
 break ;
 case OpcUaType_XmlElement : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "XmlElement" , "XmlElement" , hf_opcua_XmlElement , parseXmlElement , ett_opcua_array_XmlElement ) ;
 break ;
 case OpcUaType_NodeId : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "NodeId" , "NodeId" , parseNodeId , ett_opcua_array_NodeId ) ;
 break ;
 case OpcUaType_ExpandedNodeId : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "ExpandedNodeId" , "ExpandedNodeId" , parseExpandedNodeId , ett_opcua_array_ExpandedNodeId ) ;
 break ;
 case OpcUaType_StatusCode : parseArraySimple ( subtree , tvb , pinfo , & iOffset , "StatusCode" , "StatusCode" , hf_opcua_StatusCode , parseStatusCode , ett_opcua_array_StatusCode ) ;
 break ;
 case OpcUaType_DiagnosticInfo : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "DiagnosticInfo" , "DiagnosticInfo" , parseDiagnosticInfo , ett_opcua_array_DiagnosticInfo ) ;
 break ;
 case OpcUaType_QualifiedName : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "QualifiedName" , "QualifiedName" , parseQualifiedName , ett_opcua_array_QualifiedName ) ;
 break ;
 case OpcUaType_LocalizedText : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "LocalizedText" , "LocalizedText" , parseLocalizedText , ett_opcua_array_LocalizedText ) ;
 break ;
 case OpcUaType_ExtensionObject : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "ExtensionObject" , "ExtensionObject" , parseExtensionObject , ett_opcua_array_ExtensionObject ) ;
 break ;
 case OpcUaType_DataValue : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "DataValue" , "DataValue" , parseDataValue , ett_opcua_array_DataValue ) ;
 break ;
 case OpcUaType_Variant : parseArrayComplex ( subtree , tvb , pinfo , & iOffset , "Variant" , "Variant" , parseVariant , ett_opcua_array_Variant ) ;
 break ;
 }
 if ( EncodingMask & VARIANT_ARRAYDIMENSIONS ) {
 proto_item * ti_2 ;
 proto_tree * subtree_2 = proto_tree_add_subtree ( subtree , tvb , iOffset , - 1 , ett_opcua_variant_arraydims , & ti_2 , "ArrayDimensions" ) ;
 int i ;
 ArrayDimensions = tvb_get_letohl ( tvb , iOffset ) ;
 proto_tree_add_item ( subtree_2 , hf_opcua_ArraySize , tvb , iOffset , 4 , ENC_LITTLE_ENDIAN ) ;
 if ( ArrayDimensions > MAX_ARRAY_LEN ) {
 proto_tree_add_expert_format ( subtree_2 , pinfo , & ei_array_length , tvb , iOffset , 4 , "ArrayDimensions length %d too large to process" , ArrayDimensions ) ;
 return ;
 }
 iOffset += 4 ;
 for ( i = 0 ;
 i < ArrayDimensions ;
 i ++ ) {
 parseInt32 ( subtree_2 , tvb , pinfo , & iOffset , hf_opcua_Int32 ) ;
 }
 proto_item_set_end ( ti_2 , tvb , iOffset ) ;
 }
 }
 else {
 switch ( EncodingMask & 0x3f ) {
 case OpcUaType_Null : break ;
 case OpcUaType_Boolean : parseBoolean ( subtree , tvb , pinfo , & iOffset , hf_opcua_Boolean ) ;
 break ;
 case OpcUaType_SByte : parseSByte ( subtree , tvb , pinfo , & iOffset , hf_opcua_SByte ) ;
 break ;
 case OpcUaType_Byte : parseByte ( subtree , tvb , pinfo , & iOffset , hf_opcua_Byte ) ;
 break ;
 case OpcUaType_Int16 : parseInt16 ( subtree , tvb , pinfo , & iOffset , hf_opcua_Int16 ) ;
 break ;
 case OpcUaType_UInt16 : parseUInt16 ( subtree , tvb , pinfo , & iOffset , hf_opcua_UInt16 ) ;
 break ;
 case OpcUaType_Int32 : parseInt32 ( subtree , tvb , pinfo , & iOffset , hf_opcua_Int32 ) ;
 break ;
 case OpcUaType_UInt32 : parseUInt32 ( subtree , tvb , pinfo , & iOffset , hf_opcua_UInt32 ) ;
 break ;
 case OpcUaType_Int64 : parseInt64 ( subtree , tvb , pinfo , & iOffset , hf_opcua_Int64 ) ;
 break ;
 case OpcUaType_UInt64 : parseUInt64 ( subtree , tvb , pinfo , & iOffset , hf_opcua_UInt64 ) ;
 break ;
 case OpcUaType_Float : parseFloat ( subtree , tvb , pinfo , & iOffset , hf_opcua_Float ) ;
 break ;
 case OpcUaType_Double : parseDouble ( subtree , tvb , pinfo , & iOffset , hf_opcua_Double ) ;
 break ;
 case OpcUaType_String : parseString ( subtree , tvb , pinfo , & iOffset , hf_opcua_String ) ;
 break ;
 case OpcUaType_DateTime : parseDateTime ( subtree , tvb , pinfo , & iOffset , hf_opcua_DateTime ) ;
 break ;
 case OpcUaType_Guid : parseGuid ( subtree , tvb , pinfo , & iOffset , hf_opcua_Guid ) ;
 break ;
 case OpcUaType_ByteString : parseByteString ( subtree , tvb , pinfo , & iOffset , hf_opcua_ByteString ) ;
 break ;
 case OpcUaType_XmlElement : parseXmlElement ( subtree , tvb , pinfo , & iOffset , hf_opcua_XmlElement ) ;
 break ;
 case OpcUaType_NodeId : parseNodeId ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_ExpandedNodeId : parseExpandedNodeId ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_StatusCode : parseStatusCode ( subtree , tvb , pinfo , & iOffset , hf_opcua_StatusCode ) ;
 break ;
 case OpcUaType_DiagnosticInfo : parseDiagnosticInfo ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_QualifiedName : parseQualifiedName ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_LocalizedText : parseLocalizedText ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_ExtensionObject : parseExtensionObject ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_DataValue : parseDataValue ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 case OpcUaType_Variant : parseVariant ( subtree , tvb , pinfo , & iOffset , "Value" ) ;
 break ;
 }
 }
 proto_item_set_end ( ti , tvb , iOffset ) ;
 * pOffset = iOffset ;
 }
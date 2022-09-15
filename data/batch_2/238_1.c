void registerSimpleTypes ( int proto ) {
 expert_module_t * expert_proto ;
 static hf_register_info hf [ ] = {
 {
 & hf_opcua_diag_mask , {
 "EncodingMask" , "opcua.diag.mask" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_symbolicflag , {
 "has symbolic id" , "opcua.diag.has_symbolic_id" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_SYMBOLICID_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_namespaceflag , {
 "has namespace" , "opcua.diag.has_namespace" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_NAMESPACE_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_localizedtextflag , {
 "has localizedtext" , "opcua.diag.has_localizedtext" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_LOCALIZEDTEXT_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_localeflag , {
 "has locale" , "opcua.diag.has_locale" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_LOCALE_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_additionalinfoflag , {
 "has additional info" , "opcua.diag.has_additional_info" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_ADDITIONALINFO_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_innerstatuscodeflag , {
 "has inner statuscode" , "opcua.diag.has_inner_statuscode" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_INNERSTATUSCODE_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_mask_innerdiaginfoflag , {
 "has inner diagnostic info" , "opcua.diag.has_inner_diagnostic_code" , FT_BOOLEAN , 8 , NULL , DIAGNOSTICINFO_ENCODINGMASK_INNERDIAGNOSTICINFO_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_loctext_mask , {
 "EncodingMask" , "opcua.loctext.mask" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_loctext_mask_localeflag , {
 "has locale information" , "opcua.loctext.has_locale_information" , FT_BOOLEAN , 8 , NULL , LOCALIZEDTEXT_ENCODINGBYTE_LOCALE , NULL , HFILL }
 }
 , {
 & hf_opcua_loctext_mask_textflag , {
 "has text" , "opcua.loctext.has_text" , FT_BOOLEAN , 8 , NULL , LOCALIZEDTEXT_ENCODINGBYTE_TEXT , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeid_encodingmask , {
 "EncodingMask" , "opcua.nodeid.encodingmask" , FT_UINT8 , BASE_HEX , VALS ( g_nodeidmasks ) , 0x0F , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeid_nsindex , {
 "Namespace Index" , "opcua.nodeid.nsindex" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeid_numeric , {
 "Identifier Numeric" , "opcua.nodeid.numeric" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeid_string , {
 "Identifier String" , "opcua.nodeid.string" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeid_guid , {
 "Identifier Guid" , "opcua.nodeid.guid" , FT_GUID , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeid_bytestring , {
 "Identifier ByteString" , "opcua.nodeid.bytestring" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_expandednodeid_mask , {
 "EncodingMask" , "opcua.expandednodeid.mask" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_expandednodeid_mask_namespaceuri , {
 "has namespace uri" , "opcua.expandednodeid.has_namespace_uri" , FT_BOOLEAN , 8 , NULL , NODEID_NAMESPACEURIFLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_expandednodeid_mask_serverindex , {
 "has server index" , "opcua.expandednodeid.has_server_index" , FT_BOOLEAN , 8 , NULL , NODEID_SERVERINDEXFLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_localizedtext_locale , {
 "Locale" , "opcua.loctext.Locale" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_localizedtext_text , {
 "Text" , "opcua.loctext.Text" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_qualifiedname_id , {
 "Id" , "opcua.qualname.Id" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_qualifiedname_name , {
 "Name" , "opcua.qualname.Name" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask , {
 "EncodingMask" , "opcua.datavalue.mask" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask_valueflag , {
 "has value" , "opcua.datavalue.has_value" , FT_BOOLEAN , 8 , NULL , DATAVALUE_ENCODINGBYTE_VALUE , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask_statuscodeflag , {
 "has statuscode" , "opcua.datavalue.has_statuscode" , FT_BOOLEAN , 8 , NULL , DATAVALUE_ENCODINGBYTE_STATUSCODE , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask_sourcetimestampflag , {
 "has source timestamp" , "opcua.datavalue.has_source_timestamp" , FT_BOOLEAN , 8 , NULL , DATAVALUE_ENCODINGBYTE_SOURCETIMESTAMP , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask_servertimestampflag , {
 "has server timestamp" , "opcua.datavalue.has_server_timestamp" , FT_BOOLEAN , 8 , NULL , DATAVALUE_ENCODINGBYTE_SERVERTIMESTAMP , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask_sourcepicoseconds , {
 "has source picoseconds" , "opcua.datavalue.has_source_picoseconds" , FT_BOOLEAN , 8 , NULL , DATAVALUE_ENCODINGBYTE_SOURCEPICOSECONDS , NULL , HFILL }
 }
 , {
 & hf_opcua_datavalue_mask_serverpicoseconds , {
 "has server picoseconds" , "opcua.datavalue.has_server_picoseconds" , FT_BOOLEAN , 8 , NULL , DATAVALUE_ENCODINGBYTE_SERVERPICOSECONDS , NULL , HFILL }
 }
 , {
 & hf_opcua_variant_encodingmask , {
 "Variant Type" , "opcua.variant.has_value" , FT_UINT8 , BASE_HEX , VALS ( g_VariantTypes ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_SourceTimestamp , {
 "SourceTimestamp" , "opcua.datavalue.SourceTimestamp" , FT_ABSOLUTE_TIME , ABSOLUTE_TIME_LOCAL , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_SourcePicoseconds , {
 "SourcePicoseconds" , "opcua.datavalue.SourcePicoseconds" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_ServerTimestamp , {
 "ServerTimestamp" , "opcua.datavalue.ServerTimestamp" , FT_ABSOLUTE_TIME , ABSOLUTE_TIME_LOCAL , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_ServerPicoseconds , {
 "ServerPicoseconds" , "opcua.datavalue.ServerPicoseconds" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_symbolicid , {
 "SymbolicId" , "opcua.diag.SymbolicId" , FT_INT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_namespace , {
 "Namespace" , "opcua.diag.Namespace" , FT_INT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_localizedtext , {
 "LocalizedText" , "opcua.diag.LocalizedText" , FT_INT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_locale , {
 "Locale" , "opcua.diag.Locale" , FT_INT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_additionalinfo , {
 "AdditionalInfo" , "opcua.diag.AdditionalInfo" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_diag_innerstatuscode , {
 "InnerStatusCode" , "opcua.diag.InnerStatusCode" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_extobj_mask , {
 "EncodingMask" , "opcua.extobj.mask" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_extobj_mask_binbodyflag , {
 "has binary body" , "opcua.extobj.has_binary_body" , FT_BOOLEAN , 8 , NULL , EXTOBJ_ENCODINGMASK_BINBODY_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_extobj_mask_xmlbodyflag , {
 "has xml body" , "opcua.extobj.has_xml_body" , FT_BOOLEAN , 8 , NULL , EXTOBJ_ENCODINGMASK_XMLBODY_FLAG , NULL , HFILL }
 }
 , {
 & hf_opcua_ArraySize , {
 "ArraySize" , "opcua.variant.ArraySize" , FT_INT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_ServerIndex , {
 "ServerIndex" , "opcua.expandednodeid.ServerIndex" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_status_StructureChanged , {
 "StructureChanged" , "opcua.statuscode.structureChanged" , FT_BOOLEAN , 16 , NULL , STATUSCODE_STRUCTURECHANGED , NULL , HFILL }
 }
 , {
 & hf_opcua_status_SemanticsChanged , {
 "SemanticsChanged" , "opcua.statuscode.semanticsChanged" , FT_BOOLEAN , 16 , NULL , STATUSCODE_SEMANTICSCHANGED , NULL , HFILL }
 }
 , {
 & hf_opcua_status_InfoBit_Limit_Overflow , {
 "Overflow" , "opcua.statuscode.overflow" , FT_BOOLEAN , 16 , NULL , STATUSCODE_INFOBIT_OVERFLOW , NULL , HFILL }
 }
 , {
 & hf_opcua_status_InfoBit_Historian_Partial , {
 "HistorianBit: Partial" , "opcua.statuscode.historian.partial" , FT_BOOLEAN , 16 , NULL , STATUSCODE_INFOBIT_HISTORIAN_PARTIAL , NULL , HFILL }
 }
 , {
 & hf_opcua_status_InfoBit_Historian_ExtraData , {
 "HistorianBit: ExtraData" , "opcua.statuscode.historian.extraData" , FT_BOOLEAN , 16 , NULL , STATUSCODE_INFOBIT_HISTORIAN_EXTRADATA , NULL , HFILL }
 }
 , {
 & hf_opcua_status_InfoBit_Historian_MultiValue , {
 "HistorianBit: MultiValue" , "opcua.statuscode.historian.multiValue" , FT_BOOLEAN , 16 , NULL , STATUSCODE_INFOBIT_HISTORIAN_MULTIVALUE , NULL , HFILL }
 }
 , {
 & hf_opcua_status_InfoType , {
 "InfoType" , "opcua.statuscode.infoType" , FT_UINT16 , BASE_HEX , VALS ( g_infotype ) , 0x0C00 , NULL , HFILL }
 }
 , {
 & hf_opcua_status_Limit , {
 "Limit" , "opcua.statuscode.limit" , FT_UINT16 , BASE_HEX , VALS ( g_limit ) , 0x0300 , NULL , HFILL }
 }
 , {
 & hf_opcua_status_Historian , {
 "Historian" , "opcua.statuscode.historian" , FT_UINT16 , BASE_HEX , VALS ( g_historian ) , 0x0003 , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag , {
 "Return Diagnostics" , "opcua.returndiag" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_sl_symbolicId , {
 "ServiceLevel / SymbolicId" , "opcua.returndiag.servicelevel.symbolicid" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_SERVICELEVEL_SYMBOLICID , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_sl_localizedText , {
 "ServiceLevel / LocalizedText" , "opcua.returndiag.servicelevel.localizedtext" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_SERVICELEVEL_LOCALIZEDTEXT , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_sl_additionalinfo , {
 "ServiceLevel / AdditionalInfo" , "opcua.returndiag.servicelevel.additionalinfo" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_SERVICELEVEL_ADDITIONALINFO , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_sl_innerstatuscode , {
 "ServiceLevel / Inner StatusCode" , "opcua.returndiag.servicelevel.innerstatuscode" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_SERVICELEVEL_INNERSTATUSCODE , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_sl_innerdiagnostics , {
 "ServiceLevel / Inner Diagnostics" , "opcua.returndiag.servicelevel.innerdiagnostics" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_SERVICELEVEL_INNERDIAGNOSTICS , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_ol_symbolicId , {
 "OperationLevel / SymbolicId" , "opcua.returndiag.operationlevel.symbolicid" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_OPERATIONLEVEL_SYMBOLICID , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_ol_localizedText , {
 "OperationLevel / LocalizedText" , "opcua.returndiag.operationlevel.localizedtext" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_OPERATIONLEVEL_LOCALIZEDTEXT , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_ol_additionalinfo , {
 "OperationLevel / AdditionalInfo" , "opcua.returndiag.operationlevel.additionalinfo" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_OPERATIONLEVEL_ADDITIONALINFO , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_ol_innerstatuscode , {
 "OperationLevel / Inner StatusCode" , "opcua.returndiag.operationlevel.innerstatuscode" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_OPERATIONLEVEL_INNERSTATUSCODE , NULL , HFILL }
 }
 , {
 & hf_opcua_returnDiag_mask_ol_innerdiagnostics , {
 "OperationLevel / Inner Diagnostics" , "opcua.returndiag.operationlevel.innerdiagnostics" , FT_BOOLEAN , 16 , NULL , RETURNDIAGNOSTICS_OPERATIONLEVEL_INNERDIAGNOSTICS , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask , {
 "Node Class Mask" , "opcua.nodeclassmask" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_all , {
 "Node Class Mask" , "opcua.nodeclassmask.all" , FT_UINT32 , BASE_HEX , VALS ( g_NodeClassMask ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_object , {
 "Object" , "opcua.nodeclassmask.object" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_OBJECT , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_variable , {
 "Variable" , "opcua.nodeclassmask.variable" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_VARIABLE , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_method , {
 "Method" , "opcua.nodeclassmask.method" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_METHOD , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_objecttype , {
 "ObjectType" , "opcua.nodeclassmask.objecttype" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_OBJECTTYPE , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_variabletype , {
 "VariableType" , "opcua.nodeclassmask.variabletype" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_VARIABLETYPE , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_referencetype , {
 "ReferenceType" , "opcua.nodeclassmask.referencetype" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_REFERENCETYPE , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_datatype , {
 "DataType" , "opcua.nodeclassmask.datatype" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_DATATYPE , NULL , HFILL }
 }
 , {
 & hf_opcua_nodeClassMask_view , {
 "View" , "opcua.nodeclassmask.view" , FT_BOOLEAN , 16 , NULL , NODECLASSMASK_VIEW , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask , {
 "Result Mask" , "opcua.resultmask" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_referencetype , {
 "Reference Type" , "opcua.resultmask.referencetype" , FT_BOOLEAN , 16 , NULL , RESULTMASK_REFERENCETYPE , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_isforward , {
 "Is Forward" , "opcua.resultmask.isforward" , FT_BOOLEAN , 16 , NULL , RESULTMASK_ISFORWARD , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_nodeclass , {
 "Node Class" , "opcua.resultmask.nodeclass" , FT_BOOLEAN , 16 , NULL , RESULTMASK_NODECLASS , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_browsename , {
 "Browse Name" , "opcua.resultmask.browsename" , FT_BOOLEAN , 16 , NULL , RESULTMASK_BROWSENAME , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_displayname , {
 "Display Name" , "opcua.resultmask.displayname" , FT_BOOLEAN , 16 , NULL , RESULTMASK_DISPLAYNAME , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_typedefinition , {
 "Type Definiton" , "opcua.resultmask.typedefinition" , FT_BOOLEAN , 16 , NULL , RESULTMASK_TYPEDEFINITION , NULL , HFILL }
 }
 , {
 & hf_opcua_resultMask_all , {
 "Result Mask" , "opcua.resultmask.all" , FT_UINT32 , BASE_HEX , VALS ( g_ResultMask ) , 0x0 , NULL , HFILL }
 }
 , }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_array_length , {
 "opcua.array.length" , PI_UNDECODED , PI_ERROR , "Max array length exceeded" , EXPFILL }
 }
 , }
 ;
 proto_register_field_array ( proto , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_proto = expert_register_protocol ( proto ) ;
 expert_register_field_array ( expert_proto , ei , array_length ( ei ) ) ;
 }
void proto_register_mswsp ( void ) {
 expert_module_t * expert_mswsp = NULL ;
 static hf_register_info hf [ ] = {
 {
 & hf_mswsp_hdr , {
 "Header" , "mswsp.hdr" , FT_NONE , BASE_NONE , NULL , 0 , "Message header" , HFILL }
 }
 , {
 & hf_mswsp_hdr_msg , {
 "Msg id" , "mswsp.hdr.id" , FT_UINT32 , BASE_HEX , VALS ( msg_ids ) , 0 , "Message id" , HFILL }
 }
 , {
 & hf_mswsp_hdr_status , {
 "Status" , "mswsp.hdr.status" , FT_UINT32 , BASE_HEX , VALS ( dcom_hresult_vals ) , 0 , "Message Status" , HFILL }
 }
 , {
 & hf_mswsp_hdr_checksum , {
 "checksum" , "mswsp.hdr.checksum" , FT_UINT32 , BASE_HEX , NULL , 0 , "Message Checksum" , HFILL }
 }
 , {
 & hf_mswsp_hdr_reserved , {
 "Reserved" , "mswsp.hdr.reserved" , FT_UINT32 , BASE_HEX , NULL , 0 , "Reserved bytes" , HFILL }
 }
 , {
 & hf_mswsp_msg , {
 "msg" , "mswsp.msg" , FT_NONE , BASE_NONE , NULL , 0 , "Message" , HFILL }
 }
 , {
 & hf_mswsp_msg_Connect_Version , {
 "Version" , "mswsp.Connect.version" , FT_UINT32 , BASE_HEX , VALS ( version_vals ) , 0 , "OS Version" , HFILL }
 }
 , {
 & hf_mswsp_msg_ConnectIn_ClientIsRemote , {
 "Remote" , "mswsp.ConnectIn.isRemote" , FT_BOOLEAN , BASE_HEX , NULL , 0 , "Client is remote" , HFILL }
 }
 , {
 & hf_mswsp_msg_ConnectIn_Blob1 , {
 "Size" , "mswsp.ConnectIn.propset.size" , FT_UINT32 , BASE_DEC , NULL , 0 , "Size of PropSet fields" , HFILL }
 }
 , {
 & hf_mswsp_msg_ConnectIn_MachineName , {
 "Remote machine" , "mswsp.ConnectIn.machine" , FT_STRINGZ , BASE_NONE , NULL , 0 , "Name of remote machine" , HFILL }
 }
 , {
 & hf_mswsp_msg_ConnectIn_UserName , {
 "User" , "mswsp.ConnectIn.user" , FT_STRINGZ , BASE_NONE , NULL , 0 , "Name of remote user" , HFILL }
 }
 , {
 & hf_mswsp_msg_ConnectIn_PropSets_num , {
 "Num" , "mswsp.ConnectIn.propset.num" , FT_UINT32 , BASE_DEC , NULL , 0 , "Number of Property Sets" , HFILL }
 }
 , {
 & hf_mswsp_bool_options , {
 "uBooleanOptions" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions" , FT_UINT32 , BASE_HEX , NULL , 0 , "Boolean options" , HFILL }
 }
 , {
 & hf_mswsp_bool_options_cursor , {
 "Cursor" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions" , FT_UINT32 , BASE_HEX , VALS ( cursor_vals ) , 0x0000000007 , "Cursor Type" , HFILL }
 }
 , {
 & hf_mswsp_bool_options_async , {
 "eAsynchronous" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eAsyncronous" , FT_BOOLEAN , 32 , NULL , eAsynchronous , "The client will not wait for execution completion" , HFILL }
 }
 , {
 & hf_mswsp_bool_options_firstrows , {
 "eFirstRows" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eFirstRows" , FT_BOOLEAN , 32 , NULL , eFirstRows , "Return the first rows encountered, not the best matches." , HFILL }
 }
 , {
 & hf_mswsp_bool_options_holdrows , {
 "eHoldRows" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eHoldRows" , FT_BOOLEAN , 32 , NULL , eHoldRows , "The server MUST NOT discard rows until the client is done with a query." , HFILL }
 }
 , {
 & hf_mswsp_bool_options_chaptered , {
 "eChaptered" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eChaptered" , FT_BOOLEAN , 32 , NULL , eChaptered , "The rowset supports chapters." , HFILL }
 }
 , {
 & hf_mswsp_bool_options_useci , {
 "eUseCI" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eUseCI" , FT_BOOLEAN , 32 , NULL , eUseCI , "Use the inverted index to evaluate content restrictions even if it is out of date." , HFILL }
 }
 , {
 & hf_mswsp_bool_options_defertrim , {
 "eDeferTrimming" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eDeferTrimming" , FT_BOOLEAN , 32 , NULL , eDeferTrimming , "Defer Non-indexed trimming operations like scoping or security checking which can be expensive." , HFILL }
 }
 , {
 & hf_mswsp_bool_options_rowsetevents , {
 "eEnableRowsetEvents" , "mswsp.RowSetProperties.CPMCreateQuery.uBooleanOptions.eEnableRowsetEvents" , FT_BOOLEAN , 32 , NULL , eEnableRowsetEvents , "Enables storage of rowset events on the server side." , HFILL }
 }
 , {
 & hf_mswsp_bool_options_dontcomputeexpensive , {
 "eDoNotComputeExpensiveProps" , "mswsp.CPMCreateQuery.RowSetProperties.uBooleanOptions.eDoNotComputeExpensiveProps" , FT_BOOLEAN , 32 , NULL , eDoNotComputeExpensiveProps , "Prevents computation of expensive properties." , HFILL }
 }
 , {
 & hf_mswsp_guid_time_low , {
 "time-low" , "mswsp.guid.time_low" , FT_UINT32 , BASE_HEX , NULL , 0 , "time low value" , HFILL }
 }
 , {
 & hf_mswsp_guid_time_mid , {
 "time-mid" , "mswsp.guid.time_mid" , FT_UINT16 , BASE_HEX , NULL , 0 , "time mid value" , HFILL }
 }
 , {
 & hf_mswsp_guid_time_high , {
 "time-high" , "mswsp.guid.time_high" , FT_UINT16 , BASE_HEX , NULL , 0 , "time high value" , HFILL }
 }
 , {
 & hf_mswsp_guid_time_clock_hi , {
 "clock_seq_hi_and_reserved" , "mswsp.guid.time_clock_high" , FT_UINT8 , BASE_HEX , NULL , 0 , "time clock high value" , HFILL }
 }
 , {
 & hf_mswsp_guid_time_clock_low , {
 "clock_seq_low" , "mswsp.guid.time_clock_low" , FT_UINT8 , BASE_HEX , NULL , 0 , "time clock high low" , HFILL }
 }
 , {
 & hf_mswsp_guid_node , {
 "node" , "mswsp.guid.node" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_lcid , {
 "lcid" , "mswsp.lcid" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_lcid_sortid , {
 "Sort ID" , "mswsp.lcid.sortid" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_lcid_langid , {
 "Language ID" , "mswsp.lcid.langid" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cscort_column , {
 "column" , "mswsp.csort.column" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cscort_order , {
 "order" , "mswsp.csort.order" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cscort_individual , {
 "inidvidual" , "mswsp.csort.individual" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cscortset_count , {
 "count" , "mswsp.csortset.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_vtype , {
 "vType" , "mswsp.ctablecolumn.vtype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_aggused , {
 "AggreagateUsed" , "mswsp.ctablecolumn.aggused" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_aggtype , {
 "AggreagateType" , "mswsp.ctablecolumn.aggtype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_valused , {
 "ValueUsed" , "mswsp.ctablecolumn.valused" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_valoffset , {
 "ValueOffset" , "mswsp.ctablecolumn.valused" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_valsize , {
 "ValueSize" , "mswsp.ctablecolumn.valsize" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_statused , {
 "StatusUsed" , "mswsp.ctablecolumn.statused" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_statoffset , {
 "StatusOffset" , "mswsp.ctablecolumn.statoffset" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_lenused , {
 "LengthUsed" , "mswsp.ctablecolumn.lenused" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_lenoffset , {
 "LengthOffset" , "mswsp.ctablecolumn.lenoffset" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cfullpropspec_kind , {
 "ulKind" , "mswsp.cfullpropspec.kind" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cfullpropspec_propid , {
 "propid" , "mswsp.cfullpropspec.propid" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cfullpropspec_propname , {
 "propname" , "mswsp.cfullpropspec.propname" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cproprestrict_relop , {
 "relop" , "mswsp.cproprestrict.relop" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccoercerestrict_value , {
 "value" , "mswsp.ccoercerestrict.value" , FT_FLOAT , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccontentrestrict_cc , {
 "cc" , "mswsp.ccontentrestrict.cc" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccontentrestrict_phrase , {
 "phrase" , "mswsp.ccontentrestrict.phrase" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccontentrestrict_method , {
 "method" , "mswsp.ccontentrestrict.method" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_natlangrestrict_cc , {
 "cc" , "mswsp.ccontentrestrict.cc" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_natlangrestrict_phrase , {
 "phrase" , "mswsp.ccontentrestrict.phrase" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crestrict_ultype , {
 "ulType" , "mswsp.crestrict.ultype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crestrict_weight , {
 "Weight" , "mswsp.crestrict.weight" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crestrictarray_count , {
 "count" , "mswsp.crestrictarray.count" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crestrictarray_present , {
 "present" , "mswsp.crestrictarray.present" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cnoderestrict_cnode , {
 "Weight" , "mswsp.cnoderestrict.cnode" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_vtype , {
 "vType" , "mswsp.cbasestorvariant.vtype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_vvalue , {
 "vValue" , "mswsp.cbasestorvariant.vvalue" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_vdata1 , {
 "vData1" , "mswsp.cbasestorvariant.vdata1" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_vdata2 , {
 "vData2" , "mswsp.cbasestorvariant.vdata2" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_num , {
 "num" , "mswsp.cbasestorvariant.num" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_cdims , {
 "cDims" , "mswsp.cbasestorvariant.cdims" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_ffeatures , {
 "fFeatures" , "mswsp.cbasestorvariant.ffeatures" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_cbelements , {
 "cbElements" , "mswsp.cbasestorvariant.cbelements" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cbasestorvariant_rgsabound , {
 "Rgsabound" , "mswsp.cbasestorvariant.rgsabound" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbcolid_ekind , {
 "eKind" , "mswsp.cdbcolid.ekind" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbcolid_ulid , {
 "ulId" , "mswsp.cdbcolid.ulid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbcolid_vstring , {
 "vString" , "mswsp.cdbcolid.vstring" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbprop_id , {
 "Id" , "mswsp.cdbprop.id" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbprop_options , {
 "Options" , "mswsp.cdbprop.options" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbprop_status , {
 "Status" , "mswsp.cdbprop.status" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cdbpropset_cprops , {
 "cProperties" , "mswsp.cdbpropset.cprops" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rangeboundry_ultype , {
 "ulType" , "mswsp.rangeboundry.ultype" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rangeboundry_labelpresent , {
 "labelPresent" , "mswsp.rangeboundry.labelpresent" , FT_BOOLEAN , 8 , NULL , 0x01 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rangeboundry_cclabel , {
 "ccLabel" , "mswsp.rangeboundry.cclabel" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rangeboundry_label , {
 "Label" , "mswsp.rangeboundry.label" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crangecategspec_crange , {
 "cRange" , "mswsp.crangecategspec.crange" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccategspec_type , {
 "type" , "mswsp.ccategspec.type" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_caggregspec_type , {
 "type" , "mswsp.caggregspec.type" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_caggregspec_ccalias , {
 "ccAlias" , "mswsp.caggregspec.ccalias" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_caggregspec_alias , {
 "Alias" , "mswsp.caggregspec.alias" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_caggregspec_idcolumn , {
 "idColumn" , "mswsp.caggregspec.idcolumn" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_caggregset_count , {
 "count" , "mswsp.caggregset.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_caggregsortkey_order , {
 "order" , "mswsp.caggregsortkey.order" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_csortaggregset_count , {
 "count" , "mswsp.csortaggregset.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cingroupsortaggregset_type , {
 "Type" , "mswsp.cingroupsortaggregset.type" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cingroupsortaggregsets_count , {
 "count" , "mswsp.cingroupsortaggregsets.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_categorizationspec_cmaxres , {
 "cMaxResults" , "mswsp.categorizationspec.cmaxres" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowsetprops_ulmaxopenrows , {
 "ulMaxOpenRows (ignored)" , "mswsp.crowsetprops.ulmaxopenrows" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowsetprops_ulmemusage , {
 "ulMemUsage (ignored)" , "mswsp.crowsetprops.ulmemusage" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowsetprops_cmaxresults , {
 "cMaxResults" , "mswsp.crowsetprops.cmaxresults" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowsetprops_ccmdtimeout , {
 "cCmdTimeout" , "mswsp.crowsetprops.ccmdtimeout" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_cpidmapper_count , {
 "count" , "mswsp.cpidmapper.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccolumngroup_count , {
 "count" , "mswsp.ccolumngroup.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccolumngroup_grouppid , {
 "groupPid" , "mswsp.ccolumngroup.grouppid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccolumngroup_pid , {
 "pid" , "mswsp.ccolumngroup.pid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ccolumngrouparray_count , {
 "count" , "mswsp.ccolumngrouparray.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_int32array_value , {
 "value" , "mswsp.int32array.value" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseeknext_cskip , {
 "cskip" , "mswsp.crowseeknext.cskip" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekat_bmkoffset , {
 "bmkoffset" , "mswsp.crowseekat.bmkoffset" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekat_skip , {
 "skip" , "mswsp.crowseekat.skip" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekat_hregion , {
 "hregion" , "mswsp.crowseekat.hregion" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekatratio_ulnumerator , {
 "ulnumerator" , "mswsp.crowseekatratio.ulnumerator" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekatratio_uldenominator , {
 "uldenominator" , "mswsp.crowseekatratio.uldenominator" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekatratio_hregion , {
 "hregion" , "mswsp.crowseekatratio.hregion" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekbybookmark_cbookmarks , {
 "cbookmarks" , "mswsp.crowseekbybookmark.cbookmarks" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowseekbybookmark_maxret , {
 "maxret" , "mswsp.crowseekbybookmark.maxret" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowvariantinfo_count64 , {
 "count" , "mswsp.crowvariantinfo.count64" , FT_UINT64 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_arrayvector_address64 , {
 "address of array" , "mswsp.arrayvector.address64" , FT_UINT64 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_crowvariantinfo_count32 , {
 "count" , "mswsp.crowvariantinfo.count32" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_arrayvector_address32 , {
 "address of array" , "mswsp.arrayvector.address" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rowvariant_item_address64 , {
 "address" , "mswsp.rowvariant.item.address64" , FT_UINT64 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rowvariant_item_address32 , {
 "address" , "mswsp.rowvariant.item.address32" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rowvariant_item_value , {
 "value" , "mswsp.rowvariant.item.value" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rowvariant_vtype , {
 "vtype" , "mswsp.rowvariant.vtype" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rowvariant_reserved1 , {
 "reserved1" , "mswsp.rowvariant.reserved1" , FT_UINT16 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_rowvariant_reserved2 , {
 "reserved2" , "mswsp.rowvariant.reserved2" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_status , {
 "status" , "mswsp.ctablecolumn.name" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_ctablecolumn_length , {
 "length" , "mswsp.ctablecolumn.length" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_size , {
 "size" , "mswsp.cpmcreatequery.size" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_ccolumnsetpresent , {
 "CColumnSetPresent" , "mswsp.cpmcreatequery.ccolumnsetpresent" , FT_BOOLEAN , 8 , NULL , 0x01 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_crestrictionpresent , {
 "CRestrictionPresent" , "mswsp.cpmcreatequery.crestrictionpresent" , FT_BOOLEAN , 8 , NULL , 0x01 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_csortpresent , {
 "CSortPresent" , "mswsp.cpmcreatequery.csortpresent" , FT_BOOLEAN , 8 , NULL , 0x01 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_ccategpresent , {
 "CCategorizationSetPresent" , "mswsp.cpmcreatequery.ccategpresent" , FT_BOOLEAN , 8 , NULL , 0x01 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_ccateg_count , {
 "count" , "mswsp.cpmcreatequery.ccateg.count" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_trueseq , {
 "TrueSequential" , "mswsp.cpmcreatequery.trueseq" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_workid , {
 "WorkId" , "mswsp.cpmcreatequery.trueseq" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcreatequery_cursors , {
 "Cursors" , "mswsp.cpmcreatequery.cursors" , FT_BYTES , SEP_SPACE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_hcursor , {
 "hCursor" , "mswsp.msg.cpmgetrows.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_rowstotransfer , {
 "cRowsToTransfer" , "mswsp.msg.cpmgetrows.rowstotransfer" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_rowwidth , {
 "cbRowWidth" , "mswsp.msg.cpmgetrows.rowswidth" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_cbseek , {
 "cbSeek" , "mswsp.msg.cpmgetrows.cbseek" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_cbreserved , {
 "cbReserved" , "mswsp.msg.cpmgetrows.cbreserved" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_cbreadbuffer , {
 "cbReadBuffer" , "mswsp.msg.cpmgetrows.cbreadbuffer" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_ulclientbase , {
 "ulClientBase" , "mswsp.msg.cpmgetrows.ulclientbase" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_fbwdfetch , {
 "fBwdFetch" , "mswsp.msg.cpmgetrows.fbwdfetch" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_etype , {
 "eType" , "mswsp.msg.cpmgetrows.etype" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_chapt , {
 "chapt" , "mswsp.msg.cpmgetrows.chapt" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrows_crowsreturned , {
 "cRowsReturned" , "mswsp.msg.cpmgetrows.crowsreturned" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmratiofinished_hcursor , {
 "hCursor" , "mswsp.msg.cpmratiofinished_hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmratiofinished_fquick , {
 "fQuick" , "mswsp.msg.cpmratiofinished_fquick" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmratiofinished_ulnumerator , {
 "ulNumerator" , "mswsp.msg.cpmratiofinished_ulnumerator" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmratiofinished_uldenominator , {
 "ulDenominator" , "mswsp.msg.cpmratiofinished_uldenominator" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmratiofinished_crows , {
 "cRows" , "mswsp.msg.cpmratiofinished_crows" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmratiofinished_fnewrows , {
 "fNewRows" , "mswsp.msg.cpmratiofinished_fnewrows" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcomparebmk_hcursor , {
 "hCursor" , "mswsp.msg.cpmcomparebmk.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcomparebmk_chapt , {
 "chapt" , "mswsp.msg.cpmcomparebmk.chapt" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcomparebmk_bmkfirst , {
 "bmkFirst" , "mswsp.msg.cpmcomparebmk.bmkfirst" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcomparebmk_bmksecond , {
 "bmkSecond" , "mswsp.msg.cpmcomparebmk.bmksecond" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcomparebmk_dwcomparison , {
 "dwComparison" , "mswsp.msg.cpmcomparebmk.dwcomparison" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetapproxpos_hcursor , {
 "hCursor" , "mswsp.msg.cpmgetapproxpos.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetapproxpos_chapt , {
 "chapt" , "mswsp.msg.cpmgetapproxpos.chapt" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetapproxpos_bmk , {
 "bmk" , "mswsp.msg.cpmgetapproxpos.bmk" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetapproxpos_numerator , {
 "numerator" , "mswsp.msg.cpmgetapproxpos.numerator" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetapproxpos_denominator , {
 "denominator" , "mswsp.msg.cpmgetapproxpos.denominator" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetbinding_hcursor , {
 "hCursor" , "mswsp.msg.cpmsetbinding.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetbinding_cbrow , {
 "cBrow" , "mswsp.msg.cpmsetbinding.cbrow" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetbinding_desc , {
 "cbBindingDesc" , "mswsp.msg.cpmsetbinding.desc" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetbinding_dummy , {
 "dummy" , "mswsp.msg.cpmsetbinding.dummy" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetbinding_ccolumns , {
 "cColumns" , "mswsp.msg.cpmsetbinding.ccolumns" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetbinding_acolumns , {
 "aColumns" , "mswsp.msg.cpmsetbinding.acolumns" , FT_BYTES , SEP_DOT , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsendnotify_watchnotify , {
 "watchNotify" , "mswsp.msg.cpmsendnotify.watchnotify" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetquerystatus_hcursor , {
 "hCursor" , "mswsp.msg.cpmquerystatus.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetquerystatus_qstatus , {
 "QStatus" , "mswsp.msg.cpmquerystatus.qstatus" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cbstruct , {
 "cbStruct" , "mswsp.msg.cpmcistate.cbstruct" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cwordlist , {
 "cbWordList" , "mswsp.msg.cpmcistate.cbwordlist" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cpersistindex , {
 "cbPersistentIndex" , "mswsp.msg.cpmcistate.cbpersistindex" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cqueries , {
 "cQueries" , "mswsp.msg.cpmcistate.cqueries" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cfreshtest , {
 "cFreshTest" , "mswsp.msg.cpmcistate.cfreshtest" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_dwmergeprogress , {
 "dwMergeProgress" , "mswsp.msg.cpmcistate.dwmergeprogress" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_estate , {
 "eState" , "mswsp.msg.cpmcistate.estate" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cfiltereddocs , {
 "cFilteredDocuments" , "mswsp.msg.cpmcistate.cfiltereddocs" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_ctotaldocs , {
 "cTotalDocuments" , "mswsp.msg.cpmcistate.ctotaldocs" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cpendingscans , {
 "cPendingScans" , "mswsp.msg.cpmcistate.cpendingscans" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_dwindexsize , {
 "dwIndexSize" , "mswsp.msg.cpmcistate.dwindexsize" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_cuniquekeys , {
 "cUniqueKeys" , "mswsp.msg.cpmcistate.cuniquekeys" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_csecqdocuments , {
 "cSecQDocuments" , "mswsp.msg.cpmcistate.csecqdocuments" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmcistate_dwpropcachesize , {
 "dwPropCacheSize" , "mswsp.msg.cpmcistate.dwpropcachesize" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_wid , {
 "wid" , "mswsp.msg.cpmfetchvalue.wid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_cbsofar , {
 "cbSoFar" , "mswsp.msg.cpmfetchvalue.cbsofar" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_cbpropspec , {
 "cbPropSpec" , "mswsp.msg.cpmfetchvalue.cbpropspec" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_cbchunk , {
 "cbChunk" , "mswsp.msg.cpmfetchvalue.chunk" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_cbvalue , {
 "cbValue" , "mswsp.msg.cpmfetchvalue.cbvalue" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_fmoreexists , {
 "fMoreExists" , "mswsp.msg.cpmfetchvalue.fmoreexists" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_fvalueexists , {
 "fValueExists" , "mswsp.msg.cpmfetchvalue.fvalueexists" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfetchvalue_vvalue , {
 "vvalue" , "mswsp.msg.cpmfetchvalue.vvalue" , FT_BYTES , SEP_SPACE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_qstatus , {
 "qStatus" , "mswsp.msg.cpmquerystatusex.qstatus" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_hcursor , {
 "hCursor" , "mswsp.msg.cpmquerystatusex.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_bmk , {
 "bmk" , "mswsp.msg.cpmquerystatusex.bmk" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_cfiltereddocs , {
 "cFilteredDocuments" , "mswsp.msg.cpmquerystatusex.cfiltereddocs" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_cdocstofilter , {
 "cDocumentsToFilter" , "mswsp.msg.cpmquerystatusex.cdocstofilter" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_dwratiodenom , {
 "dwRatioFinishedDenomenator" , "mswsp.msg.cpmquerystatusex.dwratiodenom" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_dwrationumer , {
 "dwRatioFinishedNumerator" , "mswsp.msg.cpmquerystatusex.dwrationumer" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_irowbmk , {
 "iRowBmk" , "mswsp.msg.cpmquerystatusex.irowbmk" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_crowstotal , {
 "cRowsTotal" , "mswsp.msg.cpmquerystatusex.crowstotal" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_maxrank , {
 "maxRank" , "mswsp.msg.cpmquerystatusex.maxrank" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_cresultsfound , {
 "cResultsFound" , "mswsp.msg.cpmquerystatusex.cresultsfound" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmquerystatusex_whereid , {
 "whereId" , "mswsp.msg.cpmquerystatusex.whereid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmrestartposition_hcursor , {
 "hCursor" , "mswsp.msg.cpmrestartposition.hcursor" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmrestartposition_chapt , {
 "chapt" , "mswsp.msg.cpmrestartposition.chapt" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_wid , {
 "wid" , "mswsp.msg.cpmgetrowsetnotify.wid" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_moreevents , {
 "moreEvents" , "mswsp.msg.cpmgetrowsetnotify.moreevents" , FT_BOOLEAN , 8 , NULL , 0x01 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_eventtype , {
 "eventType" , "mswsp.msg.cpmgetrowsetnotify.eventType" , FT_UINT8 , BASE_DEC , NULL , 0xFE , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_rowsetitemstate , {
 "rowSetItemState" , "mswsp.msg.cpmgetrowsetnotify.rowsetitemstate" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_changeditemstate , {
 "changedItemState" , "mswsp.msg.cpmgetrowsetnotify.changeditemState" , FT_UINT8 , BASE_DEC , NULL , 0 , 0 , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_rowsetevent , {
 "rowSetEvent" , "mswsp.msg.cpmgetrowsetnotify.rowsetevent" , FT_UINT8 , BASE_DEC , NULL , 0 , 0 , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_rowseteventdata1 , {
 "rowSetEventdata1" , "mswsp.msg.cpmgetrowsetnotify.rowseteventdata1" , FT_UINT64 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmgetrowsetnotify_rowseteventdata2 , {
 "rowSetEventdata2" , "mswsp.msg.cpmgetrowsetnotify.rowseteventdata2" , FT_UINT64 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfindindices_cwids , {
 "cWids" , "mswsp.msg.cpmfindindices.cwids" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfindindices_cdepthprev , {
 "cDepthPrev" , "mswsp.msg.cpmfindindices.cdepthprev" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmfindindices_cdepthnext , {
 "cDepthNext" , "mswsp.msg.cpmfindindices.cdepthnext" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetscopeprioritization_priority , {
 "priority" , "mswsp.msg.cpmsetscopeprioritization.priority" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetscopeprioritization_eventfreq , {
 "eventFrequency" , "mswsp.msg.cpmsetscopeprioritization.eventfreq" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetscopestatisics_dwindexitems , {
 "dwIndexedItems" , "mswsp.msg.cpmsetscopestatistics.dwindexitems" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetscopestatisics_dwoutstandingadds , {
 "dwOutstandingAdds" , "mswsp.msg.cpmsetscopestatistics.dwoutstandingadds" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mswsp_msg_cpmsetscopestatisics_dwoutstandingmodifies , {
 "dwOutstandingModifies" , "mswsp.msg.cpmsetscopestatistics.dwoutstandingmodifies" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 }
 ;
 static gint * ett [ ] = {
 & ett_mswsp , & ett_mswsp_hdr , & ett_mswsp_msg , & ett_mswsp_pad , & ett_mswsp_property_restriction , & ett_CRestrictionArray , & ett_CBaseStorageVariant , & ett_CBaseStorageVariant_Vector , & ett_CBaseStorageVariant_Array , & ett_CDbColId , & ett_GUID , & ett_CDbProp , & ett_CDbPropSet , & ett_CDbPropSet_Array , & ett_CRestriction , & ett_CNodeRestriction , & ett_CPropertyRestriction , & ett_CCoercionRestriction , & ett_CContentRestriction , & ett_RANGEBOUNDARY , & ett_CRangeCategSpec , & ett_CCategSpec , & ett_CAggregSpec , & ett_CAggregSet , & ett_CCategorizationSpec , & ett_CAggregSortKey , & ett_CSortAggregSet , & ett_CInGroupSortAggregSet , & ett_CInGroupSortAggregSets , & ett_CRowsetProperties , & ett_CFullPropSpec , & ett_CPidMapper , & ett_CSort , & ett_CSortSet , & ett_CNatLanguageRestriction , & ett_CColumnGroup , & ett_CColumnGroupArray , & ett_LCID , & ett_CTableColumn , & ett_Array , & ett_SeekDescription , & ett_CRowsSeekNext , & ett_CRowsSeekAt , & ett_CRowsSeekAtRatio , & ett_CRowsSeekByBookmark , & ett_GetRowsRow , & ett_GetRowsColumn , & ett_CRowVariant , & ett_CRowVariant_Vector , & ett_mswsp_bool_options , & ett_mswsp_uin32_array , & ett_mswsp_msg_padding , & ett_mswsp_msg_creusewhere }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_mswsp_invalid_variant_type , {
 "mswsp.invalid_variant_type" , PI_PROTOCOL , PI_ERROR , "Invalid variant type" , EXPFILL }
 }
 , {
 & ei_missing_msg_context , {
 "mswsp.msg.cpmgetrows.missing_msg_context" , PI_SEQUENCE , PI_WARN , "previous messages needed for context not captured" , EXPFILL }
 }
 , {
 & ei_mswsp_msg_cpmsetbinding_ccolumns , {
 "mswsp.msg.cpmsetbinding.ccolumns.invalude" , PI_PROTOCOL , PI_WARN , "Invalid number of cColumns for packet" , EXPFILL }
 }
 }
 ;
 int i ;
 proto_mswsp = proto_register_protocol ( "Windows Search Protocol" , "MS-WSP" , "mswsp" ) ;
 proto_register_field_array ( proto_mswsp , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_mswsp = expert_register_protocol ( proto_mswsp ) ;
 expert_register_field_array ( expert_mswsp , ei , array_length ( ei ) ) ;
 for ( i = 0 ;
 i < ( int ) array_length ( GuidPropertySet ) ;
 i ++ ) {
 guids_add_guid ( & GuidPropertySet [ i ] . guid , GuidPropertySet [ i ] . def ) ;
 }
 }
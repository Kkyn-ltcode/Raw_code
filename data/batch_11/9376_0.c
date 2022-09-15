static int SpoolssEnumPrinterData_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 guint32 value_len , type ;
 char * value ;
 proto_item * value_item ;
 proto_tree * value_subtree ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_printerdata , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 value_subtree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_printerdata_value , & value_item , "Value" ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , value_subtree , di , drep , hf_enumprinterdata_value_len , & value_len ) ;
 if ( value_len ) {
 dissect_spoolss_uint16uni ( tvb , offset , pinfo , value_subtree , drep , & value , hf_value_name ) ;
 offset += value_len * 2 ;
 if ( value && value [ 0 ] ) col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , value ) ;
 proto_item_append_text ( value_item , ": %s" , value ) ;
 hidden_item = proto_tree_add_string ( tree , hf_printerdata_value , tvb , offset , 0 , value ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 g_free ( value ) ;
 }
 proto_item_set_len ( value_item , value_len * 2 + 4 ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , value_subtree , di , drep , hf_enumprinterdata_value_needed , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printerdata_type , & type ) ;
 offset = dissect_printerdata_data ( tvb , offset , pinfo , tree , di , drep , type ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_enumprinterdata_data_needed , NULL ) ;
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }
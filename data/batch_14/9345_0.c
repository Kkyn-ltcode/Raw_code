static int SpoolssSetPrinterData_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 char * value_name ;
 guint32 type ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_printerdata , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 value_name = NULL ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_printerdata_value , TRUE , & value_name ) ;
 if ( ! pinfo -> fd -> flags . visited ) {
 if ( ! dcv -> se_data ) {
 dcv -> se_data = wmem_strdup_printf ( wmem_file_scope ( ) , "%s" , value_name ? value_name : "" ) ;
 }
 }
 if ( dcv -> se_data ) {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , ( char * ) dcv -> se_data ) ;
 }
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printerdata_type , & type ) ;
 offset = dissect_printerdata_data ( tvb , offset , pinfo , tree , di , drep , type ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_offered , NULL ) ;
 return offset ;
 }
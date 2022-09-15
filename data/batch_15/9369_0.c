static int SpoolssGetPrinterData_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 char * value_name ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_printerdata , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 value_name = NULL ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_printerdata_value , TRUE , value_name ? NULL : & value_name ) ;
 if ( ! pinfo -> fd -> flags . visited ) {
 if ( ! dcv -> se_data ) {
 if ( value_name ) {
 dcv -> se_data = wmem_strdup ( wmem_file_scope ( ) , value_name ) ;
 }
 }
 }
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , value_name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_offered , NULL ) ;
 return offset ;
 }
static int SpoolssGetForm_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 proto_item * hidden_item ;
 guint32 level ;
 char * name ;
 hidden_item = proto_tree_add_uint ( tree , hf_form , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_form_name , TRUE , & name ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_form_level , & level ) ;
 if ( ! pinfo -> fd -> flags . visited ) {
 dcv -> se_data = GUINT_TO_POINTER ( ( int ) level ) ;
 }
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", level %d" , level ) ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_offered , NULL ) ;
 return offset ;
 }
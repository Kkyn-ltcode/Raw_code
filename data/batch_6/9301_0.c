static int SpoolssSetPrinterDataEx_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 char * key_name , * value_name ;
 guint32 max_len ;
 proto_item * hidden_item ;
 hidden_item = proto_tree_add_uint ( tree , hf_printerdata , tvb , offset , 0 , 1 ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_printerdata_key , TRUE , & key_name ) ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_printerdata_value , TRUE , & value_name ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s/%s" , key_name , value_name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printerdata_type , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_setprinterdataex_max_len , & max_len ) ;
 offset = dissect_ndr_uint8s ( tvb , offset , pinfo , tree , di , drep , hf_setprinterdataex_data , max_len , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_setprinterdataex_real_len , NULL ) ;
 return offset ;
 }
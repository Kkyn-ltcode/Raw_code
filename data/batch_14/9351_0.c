static int SpoolssEnumPrinterKey_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 char * key_name ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_printerdata_key , TRUE , & key_name ) ;
 if ( ! key_name [ 0 ] ) key_name = "\"\"" ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , key_name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 return offset ;
 }
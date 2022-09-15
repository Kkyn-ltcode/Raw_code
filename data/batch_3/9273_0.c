static int SpoolssGetPrinterDriver2_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 e_ctx_hnd policy_hnd ;
 char * pol_name ;
 guint32 level ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , & policy_hnd , NULL , FALSE , FALSE ) ;
 dcerpc_fetch_polhnd_data ( & policy_hnd , & pol_name , NULL , NULL , NULL , pinfo -> num ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , pol_name ) ;
 offset = dissect_ndr_str_pointer_item ( tvb , offset , pinfo , tree , di , drep , NDR_POINTER_UNIQUE , "Environment" , hf_environment , 0 ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_level , & level ) ;
 if ( ! pinfo -> fd -> flags . visited ) {
 dcv -> se_data = GUINT_TO_POINTER ( ( int ) level ) ;
 }
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", level %d" , level ) ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_offered , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_clientmajorversion , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_clientminorversion , NULL ) ;
 return offset ;
 }
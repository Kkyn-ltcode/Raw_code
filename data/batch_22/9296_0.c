static int SpoolssRFFPCNEX_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 guint32 flags ;
 static const int * hf_flags [ ] = {
 & hf_rffpcnex_flags_timeout , & hf_rffpcnex_flags_delete_driver , & hf_rffpcnex_flags_set_driver , & hf_rffpcnex_flags_add_driver , & hf_rffpcnex_flags_delete_print_processor , & hf_rffpcnex_flags_add_print_processor , & hf_rffpcnex_flags_delete_port , & hf_rffpcnex_flags_configure_port , & hf_rffpcnex_flags_add_port , & hf_rffpcnex_flags_delete_form , & hf_rffpcnex_flags_set_form , & hf_rffpcnex_flags_add_form , & hf_rffpcnex_flags_write_job , & hf_rffpcnex_flags_delete_job , & hf_rffpcnex_flags_set_job , & hf_rffpcnex_flags_add_job , & hf_rffpcnex_flags_failed_printer_connection , & hf_rffpcnex_flags_delete_printer , & hf_rffpcnex_flags_set_printer , & hf_rffpcnex_flags_add_printer , NULL }
 ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , NULL , NULL , FALSE , FALSE ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , - 1 , & flags ) ;
 proto_tree_add_bitmask_value ( tree , tvb , offset - 4 , hf_rffpcnex_flags , ett_rffpcnex_flags , hf_flags , flags ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_rffpcnex_options , NULL ) ;
 offset = dissect_ndr_str_pointer_item ( tvb , offset , pinfo , tree , di , drep , NDR_POINTER_UNIQUE , "Server" , hf_servername , 0 ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printerlocal , NULL ) ;
 offset = dissect_ndr_pointer ( tvb , offset , pinfo , tree , di , drep , dissect_NOTIFY_OPTIONS_ARRAY_CTR , NDR_POINTER_UNIQUE , "Notify Options Container" , - 1 ) ;
 return offset ;
 }
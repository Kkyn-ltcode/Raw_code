static int SpoolssWritePrinter_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 e_ctx_hnd policy_hnd ;
 char * pol_name ;
 guint32 size ;
 proto_item * item ;
 proto_tree * subtree ;
 offset = dissect_nt_policy_hnd ( tvb , offset , pinfo , tree , di , drep , hf_hnd , & policy_hnd , NULL , FALSE , FALSE ) ;
 dcerpc_fetch_polhnd_data ( & policy_hnd , & pol_name , NULL , NULL , NULL , pinfo -> num ) ;
 if ( pol_name ) col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , pol_name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_buffer_size , & size ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %d bytes" , size ) ;
 subtree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_writeprinter_buffer , & item , "Buffer" ) ;
 offset = dissect_ndr_uint8s ( tvb , offset , pinfo , subtree , di , drep , hf_buffer_data , size , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_buffer_size , NULL ) ;
 proto_item_set_len ( item , size + 4 ) ;
 return offset ;
 }
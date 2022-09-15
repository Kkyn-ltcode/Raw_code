static int SpoolssGetPrinterDriverDirectory_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 guint32 level ;
 offset = dissect_ndr_str_pointer_item ( tvb , offset , pinfo , tree , di , drep , NDR_POINTER_UNIQUE , "Name" , hf_servername , 0 ) ;
 offset = dissect_ndr_str_pointer_item ( tvb , offset , pinfo , tree , di , drep , NDR_POINTER_UNIQUE , "Environment" , hf_environment , 0 ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_level , & level ) ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_offered , NULL ) ;
 return offset ;
 }
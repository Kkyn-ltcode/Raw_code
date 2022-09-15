static int dissect_notify_info_data_buffer ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 guint32 len ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_buffer_len , & len ) ;
 offset = dissect_ndr_uint16s ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_buffer_data , len ) ;
 return offset ;
 }
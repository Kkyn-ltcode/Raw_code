static int SpoolssStartDocPrinter_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_job_id , NULL ) ;
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }
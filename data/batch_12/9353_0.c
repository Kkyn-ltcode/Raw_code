static int SpoolssReplyOpenPrinter_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 guint32 printerlocal ;
 char * name ;
 name = NULL ;
 offset = dissect_ndr_cvstring ( tvb , offset , pinfo , tree , di , drep , sizeof ( guint16 ) , hf_servername , TRUE , & name ) ;
 if ( ! pinfo -> fd -> flags . visited ) {
 if ( ! dcv -> se_data ) {
 if ( name ) {
 dcv -> se_data = wmem_strdup ( wmem_file_scope ( ) , name ) ;
 }
 }
 }
 if ( name ) col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , name ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printerlocal , & printerlocal ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printerdata_type , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_replyopenprinter_unk0 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_replyopenprinter_unk1 , NULL ) ;
 return offset ;
 }
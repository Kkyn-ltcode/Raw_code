static int SpoolssGetJob_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 gint32 level = GPOINTER_TO_UINT ( dcv -> se_data ) ;
 BUFFER buffer ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , & buffer ) ;
 if ( buffer . tvb ) {
 int buffer_offset = 0 ;
 switch ( level ) {
 case 1 : dissect_spoolss_JOB_INFO_1 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 2 : default : proto_tree_add_expert_format ( buffer . tree , pinfo , & ei_job_info_level , buffer . tvb , buffer_offset , - 1 , "Unknown job info level %d" , level ) ;
 break ;
 }
 }
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }
static int SpoolssEnumJobs_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 gint16 level = GPOINTER_TO_UINT ( dcv -> se_data ) ;
 BUFFER buffer ;
 guint32 num_jobs , i ;
 int buffer_offset ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , & buffer ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_enumjobs_numjobs , & num_jobs ) ;
 buffer_offset = 0 ;
 for ( i = 0 ;
 i < num_jobs ;
 i ++ ) {
 switch ( level ) {
 case 1 : buffer_offset = dissect_spoolss_JOB_INFO_1 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 2 : buffer_offset = dissect_spoolss_JOB_INFO_2 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 default : proto_tree_add_expert_format ( buffer . tree , pinfo , & ei_job_info_level , buffer . tvb , 0 , - 1 , "Unknown job info level %d" , level ) ;
 break ;
 }
 }
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }
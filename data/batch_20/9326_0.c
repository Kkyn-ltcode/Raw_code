static int dissect_NOTIFY_INFO_DATA_job ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , proto_item * item , dcerpc_info * di , guint8 * drep , guint16 field ) {
 guint32 value1 ;
 proto_item * hidden_item ;
 switch ( field ) {
 case JOB_NOTIFY_PRINTER_NAME : case JOB_NOTIFY_MACHINE_NAME : case JOB_NOTIFY_PORT_NAME : case JOB_NOTIFY_USER_NAME : case JOB_NOTIFY_NOTIFY_NAME : case JOB_NOTIFY_DATATYPE : case JOB_NOTIFY_PRINT_PROCESSOR : case JOB_NOTIFY_PARAMETERS : case JOB_NOTIFY_DRIVER_NAME : case JOB_NOTIFY_STATUS_STRING : case JOB_NOTIFY_DOCUMENT : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_bufsize , & value1 ) ;
 offset = dissect_ndr_pointer_cb ( tvb , offset , pinfo , tree , di , drep , dissect_notify_info_data_buffer , NDR_POINTER_UNIQUE , "String" , hf_notify_info_data_buffer , cb_notify_str_postprocess , GINT_TO_POINTER ( job_notify_hf_index ( field ) ) ) ;
 break ;
 case JOB_NOTIFY_STATUS : offset = dissect_job_status ( tvb , offset , pinfo , tree , di , drep ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_notify_info_data_value2 , NULL ) ;
 break ;
 case JOB_NOTIFY_SUBMITTED : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_buffer_len , NULL ) ;
 offset = dissect_ndr_pointer_cb ( tvb , offset , pinfo , tree , di , drep , dissect_SYSTEM_TIME_ptr , NDR_POINTER_UNIQUE , "Time submitted" , - 1 , notify_job_time_cb , NULL ) ;
 break ;
 case JOB_NOTIFY_PRIORITY : case JOB_NOTIFY_POSITION : case JOB_NOTIFY_TOTAL_PAGES : case JOB_NOTIFY_PAGES_PRINTED : case JOB_NOTIFY_TOTAL_BYTES : case JOB_NOTIFY_BYTES_PRINTED : {
 guint32 value ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_value1 , & value ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_value2 , NULL ) ;
 proto_item_append_text ( item , ": %d" , value ) ;
 hidden_item = proto_tree_add_uint ( tree , job_notify_hf_index ( field ) , tvb , offset , 4 , value ) ;
 PROTO_ITEM_SET_HIDDEN ( hidden_item ) ;
 break ;
 }
 case JOB_NOTIFY_DEVMODE : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_bufsize , & value1 ) ;
 offset = dissect_ndr_pointer ( tvb , offset , pinfo , tree , di , drep , dissect_notify_info_data_buffer , NDR_POINTER_UNIQUE , "Buffer" , hf_notify_info_data_buffer ) ;
 break ;
 default : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_value1 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_value2 , NULL ) ;
 }
 return offset ;
 }
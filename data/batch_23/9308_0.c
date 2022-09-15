static int dissect_NOTIFY_INFO_DATA_printer ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , proto_item * item , dcerpc_info * di , guint8 * drep , guint16 field ) {
 guint32 value1 ;
 switch ( field ) {
 case PRINTER_NOTIFY_SERVER_NAME : case PRINTER_NOTIFY_PRINTER_NAME : case PRINTER_NOTIFY_SHARE_NAME : case PRINTER_NOTIFY_DRIVER_NAME : case PRINTER_NOTIFY_COMMENT : case PRINTER_NOTIFY_LOCATION : case PRINTER_NOTIFY_SEPFILE : case PRINTER_NOTIFY_PRINT_PROCESSOR : case PRINTER_NOTIFY_PARAMETERS : case PRINTER_NOTIFY_DATATYPE : case PRINTER_NOTIFY_PORT_NAME : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_bufsize , & value1 ) ;
 offset = dissect_ndr_pointer_cb ( tvb , offset , pinfo , tree , di , drep , dissect_notify_info_data_buffer , NDR_POINTER_UNIQUE , "String" , hf_notify_info_data_buffer , cb_notify_str_postprocess , GINT_TO_POINTER ( printer_notify_hf_index ( field ) ) ) ;
 break ;
 case PRINTER_NOTIFY_ATTRIBUTES : offset = dissect_printer_attributes ( tvb , offset , pinfo , tree , di , drep ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_notify_info_data_value2 , NULL ) ;
 break ;
 case PRINTER_NOTIFY_STATUS : {
 guint32 status ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printer_status , & status ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_notify_info_data_value2 , NULL ) ;
 proto_item_append_text ( item , ": %s" , val_to_str_ext_const ( status , & printer_status_vals_ext , "Unknown" ) ) ;
 break ;
 }
 case PRINTER_NOTIFY_SECURITY_DESCRIPTOR : case PRINTER_NOTIFY_DEVMODE : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_bufsize , & value1 ) ;
 offset = dissect_ndr_pointer ( tvb , offset , pinfo , tree , di , drep , dissect_notify_info_data_buffer , NDR_POINTER_UNIQUE , "Buffer" , hf_notify_info_data_buffer ) ;
 break ;
 default : offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_value1 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_notify_info_data_value2 , NULL ) ;
 break ;
 }
 return offset ;
 }
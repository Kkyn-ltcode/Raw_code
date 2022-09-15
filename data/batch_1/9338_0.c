static int dissect_NOTIFY_INFO_DATA ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 proto_item * item ;
 proto_tree * subtree ;
 guint32 count ;
 guint16 type , field ;
 const char * field_string ;
 subtree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_NOTIFY_INFO_DATA , & item , "" ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_notify_info_data_type , & type ) ;
 offset = dissect_notify_field ( tvb , offset , pinfo , subtree , di , drep , type , & field ) ;
 switch ( type ) {
 case PRINTER_NOTIFY_TYPE : field_string = val_to_str_ext ( field , & printer_notify_option_data_vals_ext , "Unknown (%d)" ) ;
 break ;
 case JOB_NOTIFY_TYPE : field_string = val_to_str_ext ( field , & job_notify_option_data_vals_ext , "Unknown (%d)" ) ;
 break ;
 default : field_string = "Unknown field" ;
 break ;
 }
 proto_item_append_text ( item , "%s, %s" , val_to_str ( type , printer_notify_types , "Unknown (%d)" ) , field_string ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_notify_info_data_count , & count ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_notify_info_data_id , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_notify_info_data_count , NULL ) ;
 switch ( type ) {
 case PRINTER_NOTIFY_TYPE : offset = dissect_NOTIFY_INFO_DATA_printer ( tvb , offset , pinfo , subtree , item , di , drep , field ) ;
 break ;
 case JOB_NOTIFY_TYPE : offset = dissect_NOTIFY_INFO_DATA_job ( tvb , offset , pinfo , subtree , item , di , drep , field ) ;
 break ;
 default : expert_add_info ( pinfo , item , & ei_notify_info_data_type ) ;
 break ;
 }
 return offset ;
 }
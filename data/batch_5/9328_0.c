static int SpoolssEnumPrinterDrivers_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 guint32 level = GPOINTER_TO_UINT ( dcv -> se_data ) , num_drivers , i ;
 int buffer_offset ;
 BUFFER buffer ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , & buffer ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_returned , & num_drivers ) ;
 buffer_offset = 0 ;
 for ( i = 0 ;
 i < num_drivers ;
 i ++ ) {
 switch ( level ) {
 case 1 : buffer_offset = dissect_DRIVER_INFO_1 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 2 : buffer_offset = dissect_DRIVER_INFO_2 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 3 : buffer_offset = dissect_DRIVER_INFO_3 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 6 : buffer_offset = dissect_DRIVER_INFO_6 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 101 : dissect_DRIVER_INFO_101 ( buffer . tvb , buffer_offset , pinfo , buffer . tree , di , drep ) ;
 goto done ;
 default : proto_tree_add_expert_format ( buffer . tree , pinfo , & ei_driver_info_level , buffer . tvb , buffer_offset , - 1 , "Unknown driver info level %d" , level ) ;
 goto done ;
 }
 }
 done : offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }
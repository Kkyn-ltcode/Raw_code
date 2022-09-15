static int SpoolssGetPrinterDriver2_r ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 guint32 level = GPOINTER_TO_UINT ( dcv -> se_data ) ;
 BUFFER buffer ;
 offset = dissect_spoolss_buffer ( tvb , offset , pinfo , tree , di , drep , & buffer ) ;
 if ( buffer . tvb ) {
 switch ( level ) {
 case 1 : dissect_DRIVER_INFO_1 ( buffer . tvb , 0 , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 2 : dissect_DRIVER_INFO_2 ( buffer . tvb , 0 , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 3 : dissect_DRIVER_INFO_3 ( buffer . tvb , 0 , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 6 : dissect_DRIVER_INFO_6 ( buffer . tvb , 0 , pinfo , buffer . tree , di , drep ) ;
 break ;
 case 101 : dissect_DRIVER_INFO_101 ( buffer . tvb , 0 , pinfo , buffer . tree , di , drep ) ;
 break ;
 default : proto_tree_add_expert_format ( buffer . tree , pinfo , & ei_driver_info_level , buffer . tvb , 0 , - 1 , "Unknown driver info level %d" , level ) ;
 break ;
 }
 }
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_needed , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_servermajorversion , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_serverminorversion , NULL ) ;
 offset = dissect_doserror ( tvb , offset , pinfo , tree , di , drep , hf_rc , NULL ) ;
 return offset ;
 }
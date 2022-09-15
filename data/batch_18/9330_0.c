static int SpoolssOpenPrinterEx_q ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep _U_ ) {
 dcerpc_call_value * dcv = ( dcerpc_call_value * ) di -> call_data ;
 char * name ;
 dcv -> private_data = NULL ;
 offset = dissect_ndr_pointer_cb ( tvb , offset , pinfo , tree , di , drep , dissect_ndr_wchar_cvstring , NDR_POINTER_UNIQUE , "Printer name" , hf_printername , cb_wstr_postprocess , GINT_TO_POINTER ( CB_STR_COL_INFO | CB_STR_SAVE | 1 ) ) ;
 name = ( char * ) dcv -> private_data ;
 if ( ! pinfo -> fd -> flags . visited ) {
 if ( ! dcv -> se_data ) {
 dcv -> se_data = wmem_strdup_printf ( wmem_file_scope ( ) , "%s" , name ? name : "" ) ;
 }
 }
 offset = dissect_ndr_pointer ( tvb , offset , pinfo , tree , di , drep , dissect_PRINTER_DATATYPE , NDR_POINTER_UNIQUE , "Printer datatype" , - 1 ) ;
 offset = dissect_DEVMODE_CTR ( tvb , offset , pinfo , tree , di , drep ) ;
 name = ( char * ) dcv -> se_data ;
 if ( name ) {
 if ( name [ 0 ] == '\\' && name [ 1 ] == '\\' ) name += 2 ;
 if ( strchr ( name , '\\' ) ) offset = dissect_nt_access_mask ( tvb , offset , pinfo , tree , di , drep , hf_access_required , & spoolss_printer_access_mask_info , NULL ) ;
 else offset = dissect_nt_access_mask ( tvb , offset , pinfo , tree , di , drep , hf_access_required , & spoolss_printserver_access_mask_info , NULL ) ;
 }
 else {
 offset = dissect_nt_access_mask ( tvb , offset , pinfo , tree , di , drep , hf_access_required , NULL , NULL ) ;
 }
 offset = dissect_USER_LEVEL_CTR ( tvb , offset , pinfo , tree , di , drep ) ;
 return offset ;
 }
static int dissect_PRINTER_INFO_2 ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 guint32 devmode_offset , secdesc_offset ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_servername , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_printername , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_sharename , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_portname , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_drivername , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_printercomment , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_printerlocation , 0 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_offset , & devmode_offset ) ;
 dissect_DEVMODE ( tvb , devmode_offset - 4 , pinfo , tree , di , drep ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_sepfile , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_printprocessor , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_datatype , 0 , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , tree , di , drep , hf_parameters , 0 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_offset , & secdesc_offset ) ;
 dissect_nt_sec_desc ( tvb , secdesc_offset , pinfo , tree , drep , FALSE , - 1 , & spoolss_printer_access_mask_info ) ;
 offset = dissect_printer_attributes ( tvb , offset , pinfo , tree , di , drep ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_printer_priority , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_printer_default_priority , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_start_time , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_end_time , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , tree , di , drep , hf_printer_status , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_printer_jobs , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , NULL , di , drep , hf_printer_averageppm , NULL ) ;
 return offset ;
 }
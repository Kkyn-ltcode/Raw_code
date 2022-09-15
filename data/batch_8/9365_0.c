static int dissect_DRIVER_INFO_6 ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 proto_tree * subtree ;
 int struct_start = offset ;
 subtree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_DRIVER_INFO_6 , NULL , "Driver info level 6" ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_driverinfo_cversion , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_drivername , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_environment , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_driverpath , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_datafile , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_configfile , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_helpfile , struct_start , NULL ) ;
 offset = dissect_spoolss_relstrarray ( tvb , offset , pinfo , subtree , di , drep , hf_dependentfiles , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_monitorname , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_defaultdatatype , struct_start , NULL ) ;
 offset = dissect_spoolss_relstrarray ( tvb , offset , pinfo , subtree , di , drep , hf_previousdrivernames , struct_start , NULL ) ;
 offset = dissect_ndr_nt_NTTIME ( tvb , offset , pinfo , subtree , di , drep , hf_driverdate ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_padding , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_driver_version_low , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_driver_version_high , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_mfgname , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_oemurl , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_hardwareid , struct_start , NULL ) ;
 offset = dissect_spoolss_relstr ( tvb , offset , pinfo , subtree , di , drep , hf_provider , struct_start , NULL ) ;
 return offset ;
 }
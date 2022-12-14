static int dissect_DEVMODE ( tvbuff_t * tvb , int offset , packet_info * pinfo , proto_tree * tree , dcerpc_info * di , guint8 * drep ) {
 proto_item * item ;
 proto_tree * subtree ;
 guint16 driver_extra ;
 gint16 print_quality ;
 guint32 fields ;
 int struct_start = offset ;
 if ( di -> conformant_run ) return offset ;
 subtree = proto_tree_add_subtree ( tree , tvb , offset , 0 , ett_DEVMODE , & item , "Devicemode" ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_size , NULL ) ;
 dissect_spoolss_uint16uni ( tvb , offset , pinfo , subtree , drep , NULL , hf_devmode_devicename ) ;
 offset += 64 ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_spec_version , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_driver_version , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_size2 , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_driver_extra_len , & driver_extra ) ;
 offset = dissect_DEVMODE_fields ( tvb , offset , pinfo , subtree , di , drep , & fields ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_orientation , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_paper_size , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_paper_length , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_paper_width , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_scale , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_copies , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_default_source , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , NULL , di , drep , hf_devmode_print_quality , & print_quality ) ;
 if ( print_quality < 0 ) proto_tree_add_item ( subtree , hf_devmode_print_quality , tvb , offset - 2 , 2 , DREP_ENC_INTEGER ( drep ) ) ;
 else proto_tree_add_uint_format_value ( subtree , hf_devmode_print_quality , tvb , offset - 4 , 4 , print_quality , "%d dpi" , print_quality ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_color , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_duplex , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_y_resolution , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_tt_option , NULL ) ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_collate , NULL ) ;
 dissect_spoolss_uint16uni ( tvb , offset , pinfo , subtree , drep , NULL , hf_devmode_form_name ) ;
 offset += 64 ;
 offset = dissect_ndr_uint16 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_log_pixels , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_bits_per_pel , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_pels_width , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_pels_height , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_display_flags , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_display_freq , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_icm_method , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_icm_intent , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_media_type , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_dither_type , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_reserved1 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_reserved2 , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_panning_width , NULL ) ;
 offset = dissect_ndr_uint32 ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_panning_height , NULL ) ;
 if ( driver_extra ) offset = dissect_ndr_uint8s ( tvb , offset , pinfo , subtree , di , drep , hf_devmode_driver_extra , driver_extra , NULL ) ;
 proto_item_set_len ( item , offset - struct_start ) ;
 return offset ;
 }
static gint dissect_usb_audio_descriptor ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data ) {
 gint offset = 0 ;
 usb_conv_info_t * usb_conv_info ;
 proto_tree * desc_tree = NULL ;
 proto_item * desc_tree_item ;
 guint8 desc_len ;
 guint8 desc_type ;
 guint8 desc_subtype ;
 const gchar * subtype_str ;
 usb_conv_info = ( usb_conv_info_t * ) data ;
 if ( ! usb_conv_info || usb_conv_info -> interfaceClass != IF_CLASS_AUDIO ) return 0 ;
 desc_len = tvb_get_guint8 ( tvb , offset ) ;
 desc_type = tvb_get_guint8 ( tvb , offset + 1 ) ;
 if ( desc_type == CS_INTERFACE && usb_conv_info -> interfaceSubclass == AUDIO_IF_SUBCLASS_AUDIOCONTROL ) {
 desc_tree = proto_tree_add_subtree ( tree , tvb , offset , desc_len , ett_usb_audio_desc , & desc_tree_item , "Class-specific Audio Control Interface Descriptor" ) ;
 dissect_usb_descriptor_header ( desc_tree , tvb , offset , & aud_descriptor_type_vals_ext ) ;
 offset += 2 ;
 desc_subtype = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( desc_tree , hf_ac_if_desc_subtype , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 subtype_str = try_val_to_str_ext ( desc_subtype , & ac_subtype_vals_ext ) ;
 if ( subtype_str ) proto_item_append_text ( desc_tree_item , ": %s" , subtype_str ) ;
 offset ++ ;
 switch ( desc_subtype ) {
 case AC_SUBTYPE_HEADER : dissect_ac_if_hdr_body ( tvb , offset , pinfo , desc_tree , usb_conv_info ) ;
 break ;
 case AC_SUBTYPE_INPUT_TERMINAL : dissect_ac_if_input_terminal ( tvb , offset , pinfo , desc_tree , usb_conv_info ) ;
 break ;
 case AC_SUBTYPE_OUTPUT_TERMINAL : dissect_ac_if_output_terminal ( tvb , offset , pinfo , desc_tree , usb_conv_info ) ;
 break ;
 case AC_SUBTYPE_FEATURE_UNIT : dissect_ac_if_feature_unit ( tvb , offset , pinfo , desc_tree , usb_conv_info ) ;
 break ;
 default : proto_tree_add_expert ( desc_tree , pinfo , & ei_usb_audio_undecoded , tvb , offset - 3 , desc_len ) ;
 break ;
 }
 }
 else if ( desc_type == CS_INTERFACE && usb_conv_info -> interfaceSubclass == AUDIO_IF_SUBCLASS_AUDIOSTREAMING ) {
 desc_tree = proto_tree_add_subtree ( tree , tvb , offset , desc_len , ett_usb_audio_desc , & desc_tree_item , "Class-specific Audio Streaming Interface Descriptor" ) ;
 dissect_usb_descriptor_header ( desc_tree , tvb , offset , & aud_descriptor_type_vals_ext ) ;
 offset += 2 ;
 desc_subtype = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( desc_tree , hf_as_if_desc_subtype , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 subtype_str = try_val_to_str_ext ( desc_subtype , & as_subtype_vals_ext ) ;
 if ( subtype_str ) proto_item_append_text ( desc_tree_item , ": %s" , subtype_str ) ;
 offset ++ ;
 switch ( desc_subtype ) {
 case AS_SUBTYPE_GENERAL : dissect_as_if_general_body ( tvb , offset , pinfo , desc_tree , usb_conv_info ) ;
 break ;
 case AS_SUBTYPE_FORMAT_TYPE : dissect_as_if_format_type_body ( tvb , offset , pinfo , desc_tree , usb_conv_info ) ;
 break ;
 default : proto_tree_add_expert ( desc_tree , pinfo , & ei_usb_audio_undecoded , tvb , offset - 3 , desc_len ) ;
 break ;
 }
 }
 else if ( desc_type == CS_ENDPOINT && usb_conv_info -> interfaceSubclass == AUDIO_IF_SUBCLASS_AUDIOSTREAMING ) {
 desc_tree = proto_tree_add_subtree ( tree , tvb , offset , desc_len , ett_usb_audio_desc , & desc_tree_item , "Class-specific Audio Streaming Endpoint Descriptor" ) ;
 dissect_usb_descriptor_header ( desc_tree , tvb , offset , & aud_descriptor_type_vals_ext ) ;
 offset += 2 ;
 proto_tree_add_item ( desc_tree , hf_as_ep_desc_subtype , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 }
 else return 0 ;
 return desc_len ;
 }
static int dissect_usb_vid_interrupt ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data ) {
 usb_conv_info_t * usb_conv_info ;
 gint bytes_available ;
 int offset = 0 ;
 usb_conv_info = ( usb_conv_info_t * ) data ;
 bytes_available = tvb_reported_length_remaining ( tvb , offset ) ;
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "USBVIDEO" ) ;
 if ( bytes_available > 0 ) {
 guint8 originating_interface ;
 guint8 originating_entity ;
 originating_interface = tvb_get_guint8 ( tvb , offset ) & INT_ORIGINATOR_MASK ;
 proto_tree_add_item ( tree , hf_usb_vid_interrupt_bStatusType , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 originating_entity = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_usb_vid_interrupt_bOriginator , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 if ( originating_interface == INT_VIDEOCONTROL ) {
 guint8 control_sel ;
 guint8 attribute ;
 const gchar * control_name ;
 proto_tree_add_item ( tree , hf_usb_vid_control_interrupt_bEvent , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 control_sel = tvb_get_guint8 ( tvb , offset ) ;
 control_name = get_control_selector_name ( originating_entity , control_sel , usb_conv_info ) ;
 if ( ! control_name ) control_name = "Unknown" ;
 proto_tree_add_uint_format_value ( tree , hf_usb_vid_control_selector , tvb , offset , 1 , control_sel , "%s (0x%02x)" , control_name , control_sel ) ;
 offset ++ ;
 attribute = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_usb_vid_interrupt_bAttribute , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 switch ( attribute ) {
 case CONTROL_CHANGE_FAILURE : proto_tree_add_item ( tree , hf_usb_vid_request_error , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 break ;
 case CONTROL_CHANGE_INFO : offset = dissect_usb_vid_control_info ( tree , tvb , offset ) ;
 break ;
 case CONTROL_CHANGE_VALUE : case CONTROL_CHANGE_MIN : case CONTROL_CHANGE_MAX : dissect_usb_vid_control_value ( tree , tvb , offset , attribute ) ;
 offset += tvb_reported_length_remaining ( tvb , offset ) ;
 break ;
 default : proto_tree_add_item ( tree , hf_usb_vid_value_data , tvb , offset , - 1 , ENC_NA ) ;
 offset += tvb_reported_length_remaining ( tvb , offset ) ;
 break ;
 }
 }
 else if ( originating_interface == INT_VIDEOSTREAMING ) {
 }
 }
 else offset = - 2 ;
 return offset ;
 }
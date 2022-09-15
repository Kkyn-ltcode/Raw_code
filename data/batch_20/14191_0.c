static int dissect_usb_vid_get_set ( packet_info * pinfo , proto_tree * tree , tvbuff_t * tvb , int offset , gboolean is_request , usb_trans_info_t * usb_trans_info , usb_conv_info_t * usb_conv_info ) {
 const gchar * short_name = NULL ;
 guint8 control_sel ;
 guint8 entity_id ;
 entity_id = usb_trans_info -> setup . wIndex >> 8 ;
 control_sel = usb_trans_info -> setup . wValue >> 8 ;
 col_append_str ( pinfo -> cinfo , COL_INFO , " [" ) ;
 short_name = get_control_selector_name ( entity_id , control_sel , usb_conv_info ) ;
 if ( short_name ) col_append_str ( pinfo -> cinfo , COL_INFO , short_name ) ;
 else {
 short_name = "Unknown" ;
 if ( entity_id == 0 ) {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "Interface %u control 0x%x" , usb_conv_info -> interfaceNum , control_sel ) ;
 }
 else {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "Unit %u control 0x%x" , entity_id , control_sel ) ;
 }
 }
 col_append_str ( pinfo -> cinfo , COL_INFO , "]" ) ;
 col_set_fence ( pinfo -> cinfo , COL_INFO ) ;
 if ( is_request ) {
 offset ++ ;
 proto_tree_add_uint_format_value ( tree , hf_usb_vid_control_selector , tvb , offset , 1 , control_sel , "%s (0x%02x)" , short_name , control_sel ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_usb_vid_control_interface , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_usb_vid_control_entity , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_usb_vid_length , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 }
 else {
 proto_item * ti ;
 ti = proto_tree_add_uint ( tree , hf_usb_vid_control_interface , tvb , 0 , 0 , usb_trans_info -> setup . wIndex & 0xFF ) ;
 PROTO_ITEM_SET_GENERATED ( ti ) ;
 ti = proto_tree_add_uint ( tree , hf_usb_vid_control_entity , tvb , 0 , 0 , entity_id ) ;
 PROTO_ITEM_SET_GENERATED ( ti ) ;
 ti = proto_tree_add_uint_format_value ( tree , hf_usb_vid_control_selector , tvb , 0 , 0 , control_sel , "%s (0x%02x)" , short_name , control_sel ) ;
 PROTO_ITEM_SET_GENERATED ( ti ) ;
 }
 if ( ! is_request || ( usb_trans_info -> setup . request == USB_SETUP_SET_CUR ) ) {
 gint value_size = tvb_reported_length_remaining ( tvb , offset ) ;
 if ( value_size != 0 ) {
 if ( ( entity_id == 0 ) && ( usb_conv_info -> interfaceSubclass == SC_VIDEOSTREAMING ) ) {
 if ( ( control_sel == VS_PROBE_CONTROL ) || ( control_sel == VS_COMMIT_CONTROL ) ) {
 int old_offset = offset ;
 offset = dissect_usb_vid_probe ( tree , tvb , offset ) ;
 value_size -= ( offset - old_offset ) ;
 }
 }
 else {
 if ( usb_trans_info -> setup . request == USB_SETUP_GET_INFO ) {
 dissect_usb_vid_control_info ( tree , tvb , offset ) ;
 offset ++ ;
 value_size -- ;
 }
 else if ( usb_trans_info -> setup . request == USB_SETUP_GET_LEN ) {
 proto_tree_add_item ( tree , hf_usb_vid_control_length , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 value_size -= 2 ;
 }
 else if ( ( usb_trans_info -> setup . request == USB_SETUP_GET_CUR ) && ( entity_id == 0 ) && ( usb_conv_info -> interfaceSubclass == SC_VIDEOCONTROL ) && ( control_sel == VC_REQUEST_ERROR_CODE_CONTROL ) ) {
 proto_tree_add_item ( tree , hf_usb_vid_request_error , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 value_size -- ;
 }
 else {
 dissect_usb_vid_control_value ( tree , tvb , offset , usb_trans_info -> setup . request ) ;
 offset += value_size ;
 value_size = 0 ;
 }
 }
 if ( value_size > 0 ) {
 proto_tree_add_item ( tree , hf_usb_vid_control_data , tvb , offset , - 1 , ENC_NA ) ;
 offset += value_size ;
 }
 }
 }
 return offset ;
 }
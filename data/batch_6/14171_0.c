static value_string_ext * get_control_selector_values ( guint8 entity_id , usb_conv_info_t * usb_conv_info ) {
 video_conv_info_t * video_conv_info ;
 video_entity_t * entity = NULL ;
 value_string_ext * selectors = NULL ;
 if ( usb_conv_info == NULL ) return NULL ;
 video_conv_info = ( video_conv_info_t * ) usb_conv_info -> class_data ;
 if ( video_conv_info ) entity = ( video_entity_t * ) wmem_tree_lookup32 ( video_conv_info -> entities , entity_id ) ;
 if ( entity_id == 0 ) {
 switch ( usb_conv_info -> interfaceSubclass ) {
 case SC_VIDEOCONTROL : selectors = & cs_control_interface_ext ;
 break ;
 case SC_VIDEOSTREAMING : selectors = & cs_streaming_interface_ext ;
 break ;
 default : break ;
 }
 }
 else if ( entity ) {
 switch ( entity -> subtype ) {
 case VC_INPUT_TERMINAL : if ( entity -> terminalType == ITT_CAMERA ) {
 selectors = & cs_camera_terminal_ext ;
 }
 break ;
 case VC_PROCESSING_UNIT : selectors = & cs_processing_unit_ext ;
 break ;
 case VC_SELECTOR_UNIT : selectors = & cs_selector_unit_ext ;
 break ;
 default : break ;
 }
 }
 return selectors ;
 }
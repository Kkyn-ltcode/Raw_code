static gboolean dissect_u3v_heur ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data ) {
 guint32 prefix ;
 usb_conv_info_t * usb_conv_info ;
 if ( tvb_reported_length ( tvb ) < 4 ) return FALSE ;
 prefix = tvb_get_letohl ( tvb , 0 ) ;
 usb_conv_info = ( usb_conv_info_t * ) data ;
 if ( ! usb_conv_info ) return FALSE ;
 if ( ( U3V_STREAM_LEADER_PREFIX == prefix ) || ( U3V_STREAM_TRAILER_PREFIX == prefix ) || ( U3V_CONTROL_PREFIX == prefix ) || ( U3V_EVENT_PREFIX == prefix ) || ( ( usb_conv_info -> interfaceClass == IF_CLASS_MISCELLANEOUS && usb_conv_info -> interfaceSubclass == IF_SUBCLASS_MISC_U3V ) ) ) {
 dissect_u3v ( tvb , pinfo , tree , data ) ;
 return TRUE ;
 }
 return FALSE ;
 }
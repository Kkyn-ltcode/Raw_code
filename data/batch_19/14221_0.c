static int dissect_usb_audio_bulk ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * parent_tree , void * data ) {
 usb_conv_info_t * usb_conv_info ;
 proto_tree * tree ;
 proto_item * ti ;
 gint offset , length ;
 gint i ;
 if ( data == NULL ) return 0 ;
 usb_conv_info = ( usb_conv_info_t * ) data ;
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "USBAUDIO" ) ;
 ti = proto_tree_add_protocol_format ( parent_tree , proto_usb_audio , tvb , 0 , - 1 , "USB Audio" ) ;
 tree = proto_item_add_subtree ( ti , ett_usb_audio ) ;
 length = tvb_reported_length ( tvb ) ;
 offset = 0 ;
 switch ( usb_conv_info -> interfaceSubclass ) {
 case AUDIO_IF_SUBCLASS_MIDISTREAMING : col_set_str ( pinfo -> cinfo , COL_INFO , "USB-MIDI Event Packets" ) ;
 for ( i = 0 ;
 i < length / 4 ;
 i ++ ) {
 dissect_usb_midi_event ( tvb , pinfo , tree , parent_tree , offset ) ;
 offset += 4 ;
 }
 break ;
 default : proto_tree_add_expert ( tree , pinfo , & ei_usb_audio_undecoded , tvb , offset , length ) ;
 }
 return length ;
 }
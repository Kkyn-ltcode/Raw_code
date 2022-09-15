static void dissect_usb_midi_event ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * usb_audio_tree , proto_tree * parent_tree , gint offset ) {
 guint8 code ;
 guint8 cable ;
 gboolean save_fragmented ;
 proto_tree * tree = NULL ;
 col_set_str ( pinfo -> cinfo , COL_INFO , "USB-MIDI Event Packets" ) ;
 code = tvb_get_guint8 ( tvb , offset ) ;
 cable = ( code & 0xF0 ) >> 4 ;
 code &= 0x0F ;
 if ( parent_tree ) {
 proto_item * ti ;
 ti = proto_tree_add_protocol_format ( usb_audio_tree , proto_usb_audio , tvb , offset , 4 , "USB Midi Event Packet" ) ;
 tree = proto_item_add_subtree ( ti , ett_usb_audio ) ;
 proto_tree_add_item ( tree , hf_midi_cable_number , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_midi_code_index , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_midi_event , tvb , offset + 1 , 3 , ENC_BIG_ENDIAN ) ;
 }
 save_fragmented = pinfo -> fragmented ;
 if ( is_sysex_code ( code ) ) {
 tvbuff_t * new_tvb = NULL ;
 fragment_head * frag_sysex_msg = NULL ;
 pinfo -> fragmented = TRUE ;
 if ( code == 0x04 ) {
 frag_sysex_msg = fragment_add_seq_next ( & midi_data_reassembly_table , tvb , offset + 1 , pinfo , cable , NULL , 3 , TRUE ) ;
 }
 else {
 frag_sysex_msg = fragment_add_seq_next ( & midi_data_reassembly_table , tvb , offset + 1 , pinfo , cable , NULL , ( gint ) ( code - 4 ) , FALSE ) ;
 }
 if ( is_last_sysex_packet_in_tvb ( tvb , offset ) ) {
 new_tvb = process_reassembled_data ( tvb , offset + 1 , pinfo , "Reassembled Message" , frag_sysex_msg , & sysex_msg_frag_items , NULL , usb_audio_tree ) ;
 if ( code != 0x04 ) {
 col_append_str ( pinfo -> cinfo , COL_INFO , " (SysEx Reassembled)" ) ;
 }
 else {
 col_append_str ( pinfo -> cinfo , COL_INFO , " (SysEx fragment)" ) ;
 }
 if ( new_tvb ) {
 call_dissector ( sysex_handle , new_tvb , pinfo , parent_tree ) ;
 }
 }
 }
 pinfo -> fragmented = save_fragmented ;
 }
static int dissect_usb_vid_probe ( proto_tree * parent_tree , tvbuff_t * tvb , int offset ) {
 proto_tree * tree ;
 static const int * hint_bits [ ] = {
 & hf_usb_vid_probe_hint_D [ 0 ] , & hf_usb_vid_probe_hint_D [ 1 ] , & hf_usb_vid_probe_hint_D [ 2 ] , & hf_usb_vid_probe_hint_D [ 3 ] , & hf_usb_vid_probe_hint_D [ 4 ] , NULL }
 ;
 DISSECTOR_ASSERT ( array_length ( hint_bits ) == ( 1 + array_length ( hf_usb_vid_probe_hint_D ) ) ) ;
 tree = proto_tree_add_subtree ( parent_tree , tvb , offset , - 1 , ett_video_probe , NULL , "Probe/Commit Info" ) ;
 proto_tree_add_bitmask ( tree , tvb , offset , hf_usb_vid_probe_hint , ett_probe_hint , hint_bits , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_format_index , tvb , offset + 2 , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_index , tvb , offset + 3 , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_interval , tvb , offset + 4 , 4 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_key_frame_rate , tvb , offset + 8 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_p_frame_rate , tvb , offset + 10 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_comp_quality , tvb , offset + 12 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_comp_window , tvb , offset + 14 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_delay , tvb , offset + 16 , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_max_frame_sz , tvb , offset + 18 , 4 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_max_payload_sz , tvb , offset + 22 , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 26 ;
 if ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 static const int * framing_bits [ ] = {
 & hf_usb_vid_probe_framing_D [ 0 ] , & hf_usb_vid_probe_framing_D [ 1 ] , NULL }
 ;
 DISSECTOR_ASSERT ( array_length ( framing_bits ) == ( 1 + array_length ( hf_usb_vid_probe_framing_D ) ) ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_clock_freq , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_bitmask ( tree , tvb , offset , hf_usb_vid_probe_framing , ett_probe_framing , framing_bits , ENC_NA ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_preferred_ver , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_min_ver , tvb , offset + 1 , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_probe_max_ver , tvb , offset + 2 , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 }
 return offset ;
 }
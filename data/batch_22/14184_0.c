static int dissect_usb_video_processing_unit ( proto_tree * tree , tvbuff_t * tvb , int offset ) {
 static const int * control_bits [ ] = {
 & hf_usb_vid_proc_control_D [ 0 ] , & hf_usb_vid_proc_control_D [ 1 ] , & hf_usb_vid_proc_control_D [ 2 ] , & hf_usb_vid_proc_control_D [ 3 ] , & hf_usb_vid_proc_control_D [ 4 ] , & hf_usb_vid_proc_control_D [ 5 ] , & hf_usb_vid_proc_control_D [ 6 ] , & hf_usb_vid_proc_control_D [ 7 ] , & hf_usb_vid_proc_control_D [ 8 ] , & hf_usb_vid_proc_control_D [ 9 ] , & hf_usb_vid_proc_control_D [ 10 ] , & hf_usb_vid_proc_control_D [ 11 ] , & hf_usb_vid_proc_control_D [ 12 ] , & hf_usb_vid_proc_control_D [ 13 ] , & hf_usb_vid_proc_control_D [ 14 ] , & hf_usb_vid_proc_control_D [ 15 ] , & hf_usb_vid_proc_control_D [ 16 ] , & hf_usb_vid_proc_control_D [ 17 ] , & hf_usb_vid_proc_control_D [ 18 ] , NULL }
 ;
 DISSECTOR_ASSERT ( array_length ( control_bits ) == ( 1 + array_length ( hf_usb_vid_proc_control_D ) ) ) ;
 proto_tree_add_item ( tree , hf_usb_vid_control_ifdesc_src_id , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_max_multiplier , tvb , offset + 1 , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 offset = dissect_bmControl ( tree , tvb , offset , ett_processing_controls , control_bits ) ;
 proto_tree_add_item ( tree , hf_usb_vid_iProcessing , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 ++ offset ;
 if ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 static const int * standard_bits [ ] = {
 & hf_usb_vid_proc_standards_D [ 0 ] , & hf_usb_vid_proc_standards_D [ 1 ] , & hf_usb_vid_proc_standards_D [ 2 ] , & hf_usb_vid_proc_standards_D [ 3 ] , & hf_usb_vid_proc_standards_D [ 4 ] , & hf_usb_vid_proc_standards_D [ 5 ] , NULL }
 ;
 DISSECTOR_ASSERT ( array_length ( standard_bits ) == ( 1 + array_length ( hf_usb_vid_proc_standards_D ) ) ) ;
 proto_tree_add_bitmask ( tree , tvb , offset , hf_usb_vid_proc_standards , ett_video_standards , standard_bits , ENC_NA ) ;
 ++ offset ;
 }
 return offset ;
 }
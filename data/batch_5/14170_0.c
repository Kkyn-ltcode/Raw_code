static int dissect_usb_video_extension_unit ( proto_tree * tree , tvbuff_t * tvb , int offset ) {
 guint8 num_inputs ;
 guint8 control_size ;
 proto_tree_add_item ( tree , hf_usb_vid_exten_guid , tvb , offset , 16 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_exten_num_controls , tvb , offset + 16 , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 17 ;
 num_inputs = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_usb_vid_num_inputs , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 ++ offset ;
 if ( num_inputs > 0 ) {
 proto_tree_add_item ( tree , hf_usb_vid_sources , tvb , offset , num_inputs , ENC_NA ) ;
 offset += num_inputs ;
 }
 control_size = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_usb_vid_bControlSize , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 ++ offset ;
 if ( control_size > 0 ) {
 if ( control_size <= proto_registrar_get_length ( hf_usb_vid_bmControl ) ) {
 proto_tree_add_item ( tree , hf_usb_vid_bmControl , tvb , offset , control_size , ENC_LITTLE_ENDIAN ) ;
 }
 else {
 proto_tree_add_bytes_format ( tree , hf_usb_vid_bmControl_bytes , tvb , offset , control_size , NULL , "bmControl" ) ;
 }
 offset += control_size ;
 }
 proto_tree_add_item ( tree , hf_usb_vid_iExtension , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 ++ offset ;
 return offset ;
 }
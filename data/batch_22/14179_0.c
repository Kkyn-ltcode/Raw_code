static int dissect_usb_video_frame ( proto_tree * tree , tvbuff_t * tvb , int offset , guint8 subtype ) {
 static const int * capability_bits [ ] = {
 & hf_usb_vid_frame_stills_supported , & hf_usb_vid_frame_fixed_frame_rate , NULL }
 ;
 proto_item * desc_item ;
 guint8 bFrameIntervalType ;
 guint8 frame_index ;
 guint16 frame_width ;
 guint16 frame_height ;
 frame_index = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_index , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_bitmask ( tree , tvb , offset , hf_usb_vid_frame_capabilities , ett_frame_capability_flags , capability_bits , ENC_NA ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_width , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_height , tvb , offset + 2 , 2 , ENC_LITTLE_ENDIAN ) ;
 frame_width = tvb_get_letohs ( tvb , offset ) ;
 frame_height = tvb_get_letohs ( tvb , offset + 2 ) ;
 desc_item = proto_tree_get_parent ( tree ) ;
 proto_item_append_text ( desc_item , " (Index %2u): %4u x %4u" , frame_index , frame_width , frame_height ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_min_bit_rate , tvb , offset + 4 , 4 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_max_bit_rate , tvb , offset + 8 , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 12 ;
 if ( subtype != VS_FRAME_FRAME_BASED ) {
 proto_tree_add_item ( tree , hf_usb_vid_frame_max_frame_sz , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 }
 proto_tree_add_item ( tree , hf_usb_vid_frame_default_interval , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 bFrameIntervalType = tvb_get_guint8 ( tvb , offset ) ;
 if ( bFrameIntervalType == 0 ) {
 proto_tree_add_uint_format_value ( tree , hf_usb_vid_frame_interval_type , tvb , offset , 1 , bFrameIntervalType , "Continuous (0)" ) ;
 offset ++ ;
 if ( subtype == VS_FRAME_FRAME_BASED ) {
 proto_tree_add_item ( tree , hf_usb_vid_frame_bytes_per_line , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 }
 proto_tree_add_item ( tree , hf_usb_vid_frame_min_interval , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_max_interval , tvb , offset + 4 , 4 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_frame_step_interval , tvb , offset + 8 , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 12 ;
 }
 else {
 guint8 i ;
 proto_tree_add_uint_format_value ( tree , hf_usb_vid_frame_interval_type , tvb , offset , 1 , bFrameIntervalType , "Discrete (%u choice%s)" , bFrameIntervalType , ( bFrameIntervalType > 1 ) ? "s" : "" ) ;
 offset ++ ;
 if ( subtype == VS_FRAME_FRAME_BASED ) {
 proto_tree_add_item ( tree , hf_usb_vid_frame_bytes_per_line , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 }
 for ( i = 0 ;
 i < bFrameIntervalType ;
 ++ i ) {
 proto_tree_add_item ( tree , hf_usb_vid_frame_interval , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 }
 }
 return offset ;
 }
static int dissect_usb_video_format ( proto_tree * tree , tvbuff_t * tvb , int offset , guint8 subtype ) {
 static const int * interlace_bits [ ] = {
 & hf_usb_vid_is_interlaced , & hf_usb_vid_interlaced_fields , & hf_usb_vid_field_1_first , & hf_usb_vid_field_pattern , NULL }
 ;
 proto_item * desc_item ;
 guint8 format_index ;
 format_index = tvb_get_guint8 ( tvb , offset ) ;
 desc_item = proto_tree_get_parent ( tree ) ;
 proto_item_append_text ( desc_item , " (Format %u)" , format_index ) ;
 proto_tree_add_item ( tree , hf_usb_vid_format_index , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_format_num_frame_descriptors , tvb , offset + 1 , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( ( subtype == VS_FORMAT_UNCOMPRESSED ) || ( subtype == VS_FORMAT_FRAME_BASED ) ) {
 char fourcc [ 5 ] ;
 tvb_memcpy ( tvb , ( guint8 * ) fourcc , offset , 4 ) ;
 fourcc [ 4 ] = '\0' ;
 proto_item_append_text ( desc_item , ": %s" , fourcc ) ;
 proto_tree_add_item ( tree , hf_usb_vid_format_guid , tvb , offset , 16 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_format_bits_per_pixel , tvb , offset + 16 , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 17 ;
 }
 else if ( subtype == VS_FORMAT_MJPEG ) {
 static const int * flags [ ] = {
 & hf_usb_vid_mjpeg_fixed_samples , NULL }
 ;
 proto_tree_add_bitmask ( tree , tvb , offset , hf_usb_vid_mjpeg_flags , ett_mjpeg_flags , flags , ENC_NA ) ;
 offset ++ ;
 }
 else {
 DISSECTOR_ASSERT_NOT_REACHED ( ) ;
 }
 proto_tree_add_item ( tree , hf_usb_vid_default_frame_index , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_aspect_ratio_x , tvb , offset + 1 , 1 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_usb_vid_aspect_ratio_y , tvb , offset + 2 , 1 , ENC_LITTLE_ENDIAN ) ;
 offset += 3 ;
 # if 0 if ( something ) proto_tree_add_uint_format_value ( tree , hf_usb_vid_interlace_flags , tvb , offset , 1 , tvb_get_guint8 ( tvb , offset ) , "Not applicable" ) ;
 # endif proto_tree_add_bitmask ( tree , tvb , offset , hf_usb_vid_interlace_flags , ett_interlace_flags , interlace_bits , ENC_NA ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_usb_vid_copy_protect , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 if ( subtype == VS_FORMAT_FRAME_BASED ) {
 proto_tree_add_item ( tree , hf_usb_vid_variable_size , tvb , offset , 1 , ENC_NA ) ;
 offset ++ ;
 }
 return offset ;
 }
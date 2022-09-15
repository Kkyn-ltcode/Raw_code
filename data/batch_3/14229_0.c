static gint dissect_as_if_general_body ( tvbuff_t * tvb , gint offset , packet_info * pinfo _U_ , proto_tree * tree , usb_conv_info_t * usb_conv_info ) {
 audio_conv_info_t * audio_conv_info ;
 gint offset_start ;
 audio_conv_info = ( audio_conv_info_t * ) usb_conv_info -> class_data ;
 if ( ! audio_conv_info ) return 0 ;
 offset_start = offset ;
 if ( audio_conv_info -> ver_major == 1 ) {
 proto_tree_add_item ( tree , hf_as_if_gen_term_id , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_as_if_gen_delay , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 proto_tree_add_item ( tree , hf_as_if_gen_format , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 }
 return offset - offset_start ;
 }
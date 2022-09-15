static void dissect_usb_ms_get_max_lun ( packet_info * pinfo _U_ , proto_tree * tree , tvbuff_t * tvb , int offset , gboolean is_request , usb_trans_info_t * usb_trans_info _U_ , usb_conv_info_t * usb_conv_info _U_ ) {
 if ( is_request ) {
 proto_tree_add_item ( tree , hf_usb_ms_value , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( tree , hf_usb_ms_index , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( tree , hf_usb_ms_length , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 }
 else {
 proto_tree_add_item ( tree , hf_usb_ms_maxlun , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 }
 }
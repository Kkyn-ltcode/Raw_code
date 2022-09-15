static void dissect_u3v_stream_payload ( proto_tree * u3v_telegram_tree , tvbuff_t * tvb , packet_info * pinfo , usb_conv_info_t * usb_conv_info _U_ ) {
 proto_item * item = NULL ;
 item = proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_payload , tvb , 0 , - 1 , ENC_NA ) ;
 u3v_telegram_tree = proto_item_add_subtree ( item , ett_u3v_stream_payload ) ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_data , tvb , 0 , - 1 , ENC_NA ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "Stream Payload" ) ;
 }
static void dissect_u3v_stream_leader ( proto_tree * u3v_telegram_tree , tvbuff_t * tvb , packet_info * pinfo , usb_conv_info_t * usb_conv_info _U_ ) {
 guint32 offset = 0 ;
 guint32 payload_type = 0 ;
 guint64 block_id = 0 ;
 proto_item * item = NULL ;
 item = proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_leader , tvb , 0 , - 1 , ENC_NA ) ;
 u3v_telegram_tree = proto_item_add_subtree ( item , ett_u3v_stream_leader ) ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_prefix , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_reserved , tvb , offset , 2 , ENC_NA ) ;
 offset += 2 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_leader_size , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 block_id = tvb_get_letoh64 ( tvb , offset ) ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_block_id , tvb , offset , 8 , ENC_LITTLE_ENDIAN ) ;
 offset += 8 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_reserved , tvb , offset , 2 , ENC_NA ) ;
 offset += 2 ;
 payload_type = tvb_get_letohs ( tvb , offset ) ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_payload_type , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "Stream Leader [ Block ID: %" G_GINT64_MODIFIER "u , Type %s]" , block_id , val_to_str ( payload_type , payload_type_names , "Unknown Payload Type" ) ) ;
 if ( payload_type == U3V_STREAM_PAYLOAD_IMAGE || payload_type == U3V_STREAM_PAYLOAD_IMAGE_EXT_CHUNK || payload_type == U3V_STREAM_PAYLOAD_CHUNK ) {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_timestamp , tvb , offset , 8 , ENC_LITTLE_ENDIAN ) ;
 offset += 8 ;
 }
 if ( payload_type == U3V_STREAM_PAYLOAD_IMAGE || payload_type == U3V_STREAM_PAYLOAD_IMAGE_EXT_CHUNK ) {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_pixel_format , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_size_x , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_size_y , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_offset_x , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_offset_y , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_padding_x , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_stream_reserved , tvb , offset , 2 , ENC_NA ) ;
 }
 }
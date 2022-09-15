static void dissect_q931_number_ie ( tvbuff_t * tvb , int offset , int len , proto_tree * tree , int hfindex , e164_info_t e164_info , q931_packet_info * q931_pi ) {
 guint8 octet ;
 gint number_plan ;
 if ( len == 0 ) return ;
 octet = tvb_get_guint8 ( tvb , offset ) ;
 number_plan = octet & 0x0f ;
 e164_info . nature_of_address = ( octet & 0x70 ) >> 4 ;
 proto_tree_add_uint ( tree , hf_q931_numbering_plan , tvb , offset , 1 , octet ) ;
 proto_tree_add_uint ( tree , hf_q931_number_type , tvb , offset , 1 , octet ) ;
 proto_tree_add_boolean ( tree , hf_q931_extension_ind , tvb , offset , 1 , octet ) ;
 offset += 1 ;
 len -= 1 ;
 if ( ! ( octet & Q931_IE_VL_EXTENSION ) ) {
 if ( len == 0 ) return ;
 octet = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_uint ( tree , hf_q931_screening_ind , tvb , offset , 1 , octet ) ;
 proto_tree_add_uint ( tree , hf_q931_presentation_ind , tvb , offset , 1 , octet ) ;
 proto_tree_add_boolean ( tree , hf_q931_extension_ind , tvb , offset , 1 , octet ) ;
 offset += 1 ;
 len -= 1 ;
 }
 if ( ! ( octet & Q931_IE_VL_EXTENSION ) ) {
 if ( len == 0 ) return ;
 proto_tree_add_item ( tree , hf_q931_extension_reason , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset += 1 ;
 len -= 1 ;
 }
 if ( len == 0 ) return ;
 proto_tree_add_item ( tree , hfindex , tvb , offset , len , ENC_ASCII | ENC_NA ) ;
 proto_item_append_text ( proto_tree_get_parent ( tree ) , ": '%s'" , tvb_format_text ( tvb , offset , len ) ) ;
 if ( number_plan == 1 ) {
 if ( e164_info . e164_number_type != NONE ) {
 e164_info . E164_number_str = tvb_get_string_enc ( wmem_packet_scope ( ) , tvb , offset , len , ENC_ASCII | ENC_NA ) ;
 e164_info . E164_number_length = len ;
 dissect_e164_number ( tvb , tree , offset , len , e164_info ) ;
 }
 }
 if ( e164_info . e164_number_type == CALLING_PARTY_NUMBER && q931_pi ) q931_pi -> calling_number = tvb_get_string_enc ( wmem_packet_scope ( ) , tvb , offset , len , ENC_ASCII | ENC_NA ) ;
 if ( e164_info . e164_number_type == CALLED_PARTY_NUMBER && q931_pi ) q931_pi -> called_number = tvb_get_string_enc ( wmem_packet_scope ( ) , tvb , offset , len , ENC_ASCII | ENC_NA ) ;
 }
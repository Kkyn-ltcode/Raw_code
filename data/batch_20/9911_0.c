static void dissect_rsvp_tspec ( proto_item * ti , packet_info * pinfo , proto_tree * rsvp_object_tree , tvbuff_t * tvb , int offset , int obj_length , int rsvp_class _U_ , int type ) {
 int offset2 = offset + 4 ;
 int mylen ;
 proto_tree * tspec_tree , * ti2 = NULL ;
 guint8 signal_type ;
 mylen = obj_length - 4 ;
 switch ( type ) {
 case 2 : proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "2 - Integrated Services" ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_message_format_version , tvb , offset2 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_data_length , tvb , offset2 + 2 , 2 , tvb_get_ntohs ( tvb , offset2 + 2 ) , "%u words, not including header" , tvb_get_ntohs ( tvb , offset2 + 2 ) ) ;
 mylen -= 4 ;
 offset2 += 4 ;
 proto_item_set_text ( ti , "SENDER TSPEC: IntServ, " ) ;
 while ( mylen > 0 ) {
 guint8 service_num ;
 guint8 param_id ;
 guint param_len , raw_len ;
 guint param_len_processed ;
 guint length ;
 service_num = tvb_get_guint8 ( tvb , offset2 ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_service_header , tvb , offset2 , 1 , ENC_BIG_ENDIAN ) ;
 length = tvb_get_ntohs ( tvb , offset2 + 2 ) ;
 proto_tree_add_uint_format ( rsvp_object_tree , hf_rsvp_data_length , tvb , offset2 + 2 , 2 , length , "Length of service %u data: %u words, not including header" , service_num , length ) ;
 mylen -= 4 ;
 offset2 += 4 ;
 param_len_processed = 0 ;
 while ( param_len_processed < length ) {
 param_id = tvb_get_guint8 ( tvb , offset2 ) ;
 ti2 = proto_tree_add_item ( rsvp_object_tree , hf_rsvp_parameter , tvb , offset2 , 1 , ENC_NA ) ;
 raw_len = tvb_get_ntohs ( tvb , offset2 + 2 ) ;
 param_len = raw_len + 1 ;
 switch ( param_id ) {
 case 127 : proto_item_set_len ( ti2 , param_len * 4 ) ;
 tspec_tree = proto_item_add_subtree ( ti2 , TREE ( TT_TSPEC_SUBTREE ) ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_parameter_flags , tvb , offset2 + 1 , 1 , ENC_NA ) ;
 proto_tree_add_uint_format_value ( tspec_tree , hf_rsvp_parameter_length , tvb , offset2 + 2 , 2 , raw_len , "%u words, not including header" , raw_len ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_tspec_token_bucket_rate , tvb , offset2 + 4 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_tspec_token_bucket_size , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_tspec_peak_data_rate , tvb , offset2 + 12 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_minimum_policed_unit , tvb , offset2 + 16 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_maximum_packet_size , tvb , offset2 + 20 , 4 , ENC_BIG_ENDIAN ) ;
 proto_item_append_text ( ti , "Token Bucket, %.10g bytes/sec. " , tvb_get_ntohieee_float ( tvb , offset2 + 4 ) ) ;
 proto_item_append_text ( ti2 , "Rate=%.10g Burst=%.10g Peak=%.10g m=%u M=%u" , tvb_get_ntohieee_float ( tvb , offset2 + 4 ) , tvb_get_ntohieee_float ( tvb , offset2 + 8 ) , tvb_get_ntohieee_float ( tvb , offset2 + 12 ) , tvb_get_ntohl ( tvb , offset2 + 16 ) , tvb_get_ntohl ( tvb , offset2 + 20 ) ) ;
 break ;
 case 128 : proto_item_set_len ( ti2 , param_len * 4 ) ;
 tspec_tree = proto_item_add_subtree ( ti2 , TREE ( TT_TSPEC_SUBTREE ) ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_parameter_flags , tvb , offset2 + 1 , 1 , ENC_NA ) ;
 proto_tree_add_uint_format_value ( tspec_tree , hf_rsvp_parameter_length , tvb , offset2 + 2 , 2 , raw_len , "%u words, not including header" , raw_len ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_maximum_packet_size , tvb , offset2 + 4 , 4 , ENC_BIG_ENDIAN ) ;
 proto_item_append_text ( ti , "Null Service. M=%u" , tvb_get_ntohl ( tvb , offset2 + 4 ) ) ;
 proto_item_append_text ( ti2 , "Max pkt size=%u" , tvb_get_ntohl ( tvb , offset2 + 4 ) ) ;
 break ;
 case 126 : proto_item_set_len ( ti2 , param_len * 4 ) ;
 tspec_tree = proto_item_add_subtree ( ti2 , TREE ( TT_TSPEC_SUBTREE ) ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_parameter_flags , tvb , offset2 + 1 , 1 , ENC_NA ) ;
 proto_tree_add_uint_format_value ( tspec_tree , hf_rsvp_parameter_length , tvb , offset2 + 2 , 2 , raw_len , "%u words, not including header" , raw_len ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_tspec_hint , tvb , offset2 + 4 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_compression_factor , tvb , offset2 + 4 , 4 , ENC_BIG_ENDIAN ) ;
 proto_item_append_text ( ti , "Compression Hint. Hint=%u, Factor=%u" , tvb_get_ntohl ( tvb , offset2 + 4 ) , tvb_get_ntohl ( tvb , offset2 + 8 ) ) ;
 proto_item_append_text ( ti2 , "Hint=%u, Factor=%u" , tvb_get_ntohl ( tvb , offset2 + 4 ) , tvb_get_ntohl ( tvb , offset2 + 8 ) ) ;
 break ;
 default : proto_item_set_len ( ti2 , param_len * 4 ) ;
 expert_add_info_format ( pinfo , ti2 , & ei_rsvp_parameter , "Unknown parameter %d, %d words" , param_id , param_len ) ;
 break ;
 }
 param_len_processed += param_len ;
 offset2 += param_len * 4 ;
 }
 mylen -= length * 4 ;
 }
 break ;
 case 4 : proto_item_set_text ( ti , "SENDER TSPEC: SONET/SDH, " ) ;
 proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "4 - SONET/SDH" ) ;
 signal_type = tvb_get_guint8 ( tvb , offset2 ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_signal_type_sonet , tvb , offset2 , 1 , ENC_BIG_ENDIAN ) ;
 ti2 = proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_requested_concatenation , tvb , offset2 + 1 , 1 , ENC_BIG_ENDIAN ) ;
 tspec_tree = proto_item_add_subtree ( ti2 , TREE ( TT_TSPEC_SUBTREE ) ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_standard_contiguous_concatenation , tvb , offset2 + 1 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_arbitrary_contiguous_concatenation , tvb , offset2 + 1 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_number_of_contiguous_components , tvb , offset2 + 2 , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_number_of_virtual_components , tvb , offset2 + 4 , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_multiplier , tvb , offset2 + 6 , 2 , ENC_BIG_ENDIAN ) ;
 ti2 = proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 tspec_tree = proto_item_add_subtree ( ti2 , TREE ( TT_TSPEC_SUBTREE ) ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_regenerator_section , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_multiplex_section , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_J0_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_SOH_RSOH_DCC_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_LOH_MSOH_DCC_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_LOH_MSOH_extended_DCC_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_K1_K2_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_E1_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_F1_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_E2_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_B1_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_B2_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_M0_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tspec_tree , hf_rsvp_sender_tspec_M1_transparency , tvb , offset2 + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_profile , tvb , offset2 + 12 , 4 , ENC_BIG_ENDIAN ) ;
 proto_item_append_text ( ti , "Signal [%s], RCC %d, NCC %d, NVC %d, MT %d, Transparency %d, Profile %d" , val_to_str_ext_const ( signal_type , & gmpls_sonet_signal_type_str_ext , "Unknown" ) , tvb_get_guint8 ( tvb , offset2 + 1 ) , tvb_get_ntohs ( tvb , offset2 + 2 ) , tvb_get_ntohs ( tvb , offset2 + 4 ) , tvb_get_ntohs ( tvb , offset2 + 6 ) , tvb_get_ntohl ( tvb , offset2 + 8 ) , tvb_get_ntohl ( tvb , offset2 + 12 ) ) ;
 break ;
 case 5 : proto_item_set_text ( ti , "SENDER TSPEC: G.709, " ) ;
 proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "5 - G.709" ) ;
 signal_type = tvb_get_guint8 ( tvb , offset2 ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_signal_type_g709 , tvb , offset2 , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_number_of_multiplexed_components , tvb , offset2 + 2 , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_number_of_virtual_components , tvb , offset2 + 4 , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_multiplier , tvb , offset2 + 6 , 2 , ENC_BIG_ENDIAN ) ;
 proto_item_append_text ( ti , "Signal [%s], NMC %d, NVC %d, MT %d" , rval_to_str ( signal_type , gmpls_g709_signal_type_rvals , "Unknown" ) , tvb_get_ntohs ( tvb , offset2 + 2 ) , tvb_get_ntohs ( tvb , offset2 + 4 ) , tvb_get_ntohs ( tvb , offset2 + 6 ) ) ;
 break ;
 case 6 : proto_item_set_text ( ti , "SENDER TSPEC: Ethernet, " ) ;
 proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "6 - Ethernet" ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_switching_granularity , tvb , offset2 , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_mtu , tvb , offset2 + 2 , 2 , ENC_BIG_ENDIAN ) ;
 dissect_rsvp_eth_tspec_tlv ( ti , pinfo , rsvp_object_tree , tvb , offset + 8 , obj_length - 8 , TREE ( TT_TSPEC_SUBTREE ) ) ;
 break ;
 default : proto_tree_add_uint_format_value ( rsvp_object_tree , hf_rsvp_ctype , tvb , offset + 3 , 1 , type , "Unknown (%u)" , type ) ;
 proto_tree_add_item ( rsvp_object_tree , hf_rsvp_tspec_data , tvb , offset2 , obj_length - 4 , ENC_NA ) ;
 break ;
 }
 }
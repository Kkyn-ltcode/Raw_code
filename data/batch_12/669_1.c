static void process_rtp_payload ( tvbuff_t * newtvb , packet_info * pinfo , proto_tree * tree , proto_tree * rtp_tree , unsigned int payload_type ) {
 struct _rtp_conversation_info * p_conv_data = NULL ;
 gboolean found_match = FALSE ;
 int payload_len ;
 struct srtp_info * srtp_info ;
 int offset = 0 ;
 payload_len = tvb_length_remaining ( newtvb , offset ) ;
 p_conv_data = ( struct _rtp_conversation_info * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_rtp , 0 ) ;
 if ( p_conv_data && p_conv_data -> srtp_info ) {
 srtp_info = p_conv_data -> srtp_info ;
 payload_len -= srtp_info -> mki_len + srtp_info -> auth_tag_len ;
 # if 0 # error Currently the srtp_info structure contains no cipher data , see packet - sdp . c adding dummy_srtp_info structure if ( p_conv_data -> srtp_info -> encryption_algorithm == SRTP_ENC_ALG_NULL ) {
 if ( rtp_tree ) proto_tree_add_text ( rtp_tree , newtvb , offset , payload_len , "SRTP Payload with NULL encryption" ) ;
 }
 else # endif {
 if ( rtp_tree ) proto_tree_add_item ( rtp_tree , hf_srtp_encrypted_payload , newtvb , offset , payload_len , ENC_NA ) ;
 found_match = TRUE ;
 }
 offset += payload_len ;
 if ( srtp_info -> mki_len ) {
 proto_tree_add_item ( rtp_tree , hf_srtp_mki , newtvb , offset , srtp_info -> mki_len , ENC_NA ) ;
 offset += srtp_info -> mki_len ;
 }
 if ( srtp_info -> auth_tag_len ) {
 proto_tree_add_item ( rtp_tree , hf_srtp_auth_tag , newtvb , offset , srtp_info -> auth_tag_len , ENC_NA ) ;
 }
 }
 else if ( p_conv_data && ! p_conv_data -> bta2dp_info && ! p_conv_data -> btvdp_info && payload_type >= PT_UNDF_96 && payload_type <= PT_UNDF_127 ) {
 if ( p_conv_data && p_conv_data -> rtp_dyn_payload ) {
 gchar * payload_type_str = NULL ;
 encoding_name_and_rate_t * encoding_name_and_rate_pt = NULL ;
 encoding_name_and_rate_pt = ( encoding_name_and_rate_t * ) g_hash_table_lookup ( p_conv_data -> rtp_dyn_payload , & payload_type ) ;
 if ( encoding_name_and_rate_pt ) {
 payload_type_str = encoding_name_and_rate_pt -> encoding_name ;
 }
 if ( payload_type_str ) {
 found_match = dissector_try_string ( rtp_dyn_pt_dissector_table , payload_type_str , newtvb , pinfo , tree , NULL ) ;
 if ( found_match == FALSE ) proto_tree_add_item ( rtp_tree , hf_rtp_data , newtvb , 0 , - 1 , ENC_NA ) ;
 return ;
 }
 }
 }
 else if ( p_conv_data && p_conv_data -> bta2dp_info ) {
 tvbuff_t * nexttvb ;
 gint suboffset = 0 ;
 found_match = TRUE ;
 if ( p_conv_data -> bta2dp_info -> content_protection_type == BTAVDTP_CONTENT_PROTECTION_TYPE_SCMS_T ) {
 nexttvb = tvb_new_subset ( newtvb , 0 , 1 , 1 ) ;
 call_dissector ( bta2dp_content_protection_header_scms_t , nexttvb , pinfo , tree ) ;
 suboffset = 1 ;
 }
 nexttvb = tvb_new_subset_remaining ( newtvb , suboffset ) ;
 if ( p_conv_data -> bta2dp_info -> codec_dissector ) call_dissector ( p_conv_data -> bta2dp_info -> codec_dissector , nexttvb , pinfo , tree ) ;
 else call_dissector ( data_handle , nexttvb , pinfo , tree ) ;
 }
 else if ( p_conv_data && p_conv_data -> btvdp_info ) {
 tvbuff_t * nexttvb ;
 gint suboffset = 0 ;
 found_match = TRUE ;
 if ( p_conv_data -> btvdp_info -> content_protection_type == BTAVDTP_CONTENT_PROTECTION_TYPE_SCMS_T ) {
 nexttvb = tvb_new_subset ( newtvb , 0 , 1 , 1 ) ;
 call_dissector ( bta2dp_content_protection_header_scms_t , nexttvb , pinfo , tree ) ;
 suboffset = 1 ;
 }
 nexttvb = tvb_new_subset_remaining ( newtvb , suboffset ) ;
 if ( p_conv_data -> btvdp_info -> codec_dissector ) call_dissector ( p_conv_data -> btvdp_info -> codec_dissector , nexttvb , pinfo , tree ) ;
 else call_dissector ( data_handle , nexttvb , pinfo , tree ) ;
 }
 if ( ! found_match && ! dissector_try_uint ( rtp_pt_dissector_table , payload_type , newtvb , pinfo , tree ) ) proto_tree_add_item ( rtp_tree , hf_rtp_data , newtvb , 0 , - 1 , ENC_NA ) ;
 }
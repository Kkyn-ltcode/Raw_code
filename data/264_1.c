guint16 de_mid ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo , guint32 offset , guint len , gchar * add_string , int string_len ) {
 guint8 oct ;
 guint32 curr_offset ;
 guint32 value ;
 gboolean odd ;
 const gchar * digit_str ;
 proto_item * ti ;
 curr_offset = offset ;
 oct = tvb_get_guint8 ( tvb , curr_offset ) ;
 switch ( oct & 0x07 ) {
 case 0 : proto_tree_add_item ( tree , hf_gsm_a_unused , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_mobile_identity_type , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 if ( add_string ) g_snprintf ( add_string , string_len , " - No Identity Code" ) ;
 curr_offset ++ ;
 if ( len > 1 ) {
 expert_add_info ( pinfo , tree , & ei_gsm_a_format_not_supported ) ;
 }
 curr_offset += len - 1 ;
 break ;
 case 3 : case 1 : odd = oct & 0x08 ;
 proto_tree_add_item ( tree , hf_gsm_a_id_dig_1 , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_mobile_identity_type , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 if ( ( oct & 0x07 ) == 3 ) {
 digit_str = tvb_bcd_dig_to_wmem_packet_str ( tvb , curr_offset , len - ( curr_offset - offset ) , NULL , TRUE ) ;
 proto_tree_add_string_format ( tree , hf_gsm_a_imeisv , tvb , curr_offset , len - ( curr_offset - offset ) , digit_str , "BCD Digits: %s" , digit_str ) ;
 }
 else {
 digit_str = dissect_e212_imsi ( tvb , pinfo , tree , curr_offset , len - ( curr_offset - offset ) , TRUE ) ;
 }
 if ( sccp_assoc && ! sccp_assoc -> calling_party ) {
 sccp_assoc -> calling_party = wmem_strdup_printf ( wmem_file_scope ( ) , ( ( oct & 0x07 ) == 3 ) ? "IMEISV: %s" : "IMSI: %s" , digit_str ) ;
 }
 if ( add_string ) g_snprintf ( add_string , string_len , " - %s (%s)" , ( ( oct & 0x07 ) == 3 ) ? "IMEISV" : "IMSI" , digit_str ) ;
 curr_offset += len - ( curr_offset - offset ) ;
 if ( ! odd ) {
 proto_tree_add_item ( tree , hf_gsm_a_filler , tvb , curr_offset - 1 , 1 , ENC_NA ) ;
 }
 break ;
 case 2 : proto_tree_add_uint_format_value ( tree , hf_gsm_a_identity_digit1 , tvb , curr_offset , 1 , oct , "%c" , Dgt1_9_bcd . out [ ( oct & 0xf0 ) >> 4 ] ) ;
 proto_tree_add_item ( tree , hf_gsm_a_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_mobile_identity_type , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 curr_offset ++ ;
 if ( curr_offset - offset >= len ) return ( curr_offset - offset ) ;
 digit_str = tvb_bcd_dig_to_wmem_packet_str ( tvb , curr_offset , len - ( curr_offset - offset ) , NULL , FALSE ) ;
 proto_tree_add_string_format ( tree , hf_gsm_a_imei , tvb , curr_offset , len - ( curr_offset - offset ) , digit_str , "BCD Digits: %s" , digit_str ) ;
 if ( add_string ) g_snprintf ( add_string , string_len , " - IMEI (%s)" , digit_str ) ;
 curr_offset += len - ( curr_offset - offset ) ;
 break ;
 case 4 : proto_tree_add_item ( tree , hf_gsm_a_unused , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_mobile_identity_type , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 curr_offset ++ ;
 value = tvb_get_ntohl ( tvb , curr_offset ) ;
 proto_tree_add_uint ( tree , hf_gsm_a_tmsi , tvb , curr_offset , 4 , value ) ;
 if ( add_string ) g_snprintf ( add_string , string_len , " - TMSI/P-TMSI (0x%04x)" , value ) ;
 curr_offset += 4 ;
 break ;
 case 5 : proto_tree_add_bits_item ( tree , hf_gsm_a_spare_bits , tvb , curr_offset << 3 , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_mbs_ses_id_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_tmgi_mcc_mnc_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_mobile_identity_type , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 curr_offset ++ ;
 proto_tree_add_item ( tree , hf_gsm_a_mbs_service_id , tvb , curr_offset , 3 , ENC_BIG_ENDIAN ) ;
 curr_offset += 3 ;
 if ( ( oct & 0x10 ) == 0x10 ) {
 curr_offset = dissect_e212_mcc_mnc ( tvb , pinfo , tree , curr_offset , E212_NONE , TRUE ) ;
 }
 if ( ( oct & 0x20 ) == 0x20 ) {
 proto_tree_add_item ( tree , hf_gsm_a_mbs_session_id , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 curr_offset ++ ;
 }
 break ;
 default : proto_tree_add_item ( tree , hf_gsm_a_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 ti = proto_tree_add_item ( tree , hf_gsm_a_mobile_identity_type , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 expert_add_info_format ( pinfo , ti , & ei_gsm_a_mobile_identity_type , "Unknown format %u" , ( oct & 0x07 ) ) ;
 if ( add_string ) g_snprintf ( add_string , string_len , " - Format Unknown" ) ;
 curr_offset += len ;
 break ;
 }
 EXTRANEOUS_DATA_CHECK ( len , curr_offset - offset , pinfo , & ei_gsm_a_extraneous_data ) ;
 return ( curr_offset - offset ) ;
 }
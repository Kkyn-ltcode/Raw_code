static guint16 de_sub_addr ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo , guint32 offset , guint len , gchar * * extracted_address ) {
 guint32 curr_offset , ia5_string_len , i ;
 guint8 type_of_sub_addr , afi , dig1 , dig2 , oct ;
 gchar * ia5_string ;
 gboolean invalid_ia5_char ;
 proto_item * item ;
 curr_offset = offset ;
 * extracted_address = NULL ;
 proto_tree_add_item ( tree , hf_gsm_a_extension , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_dtap_type_of_sub_addr , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tree , hf_gsm_a_dtap_odd_even_ind , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_bits_item ( tree , hf_gsm_a_spare_bits , tvb , ( curr_offset << 3 ) + 5 , 3 , ENC_BIG_ENDIAN ) ;
 type_of_sub_addr = ( tvb_get_guint8 ( tvb , curr_offset ) & 0x70 ) >> 4 ;
 curr_offset ++ ;
 NO_MORE_DATA_CHECK ( len ) ;
 if ( ! type_of_sub_addr ) {
 afi = tvb_get_guint8 ( tvb , curr_offset ) ;
 proto_tree_add_item ( tree , hf_gsm_a_dtap_afi , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 curr_offset ++ ;
 NO_MORE_DATA_CHECK ( len ) ;
 if ( afi == 0x50 ) {
 ia5_string_len = len - ( curr_offset - offset ) ;
 ia5_string = ( guint8 * ) tvb_memdup ( wmem_packet_scope ( ) , tvb , curr_offset , ia5_string_len ) ;
 * extracted_address = ( gchar * ) wmem_alloc ( wmem_packet_scope ( ) , ia5_string_len + 1 ) ;
 invalid_ia5_char = FALSE ;
 for ( i = 0 ;
 i < ia5_string_len ;
 i ++ ) {
 dig1 = ( ia5_string [ i ] & 0xf0 ) >> 4 ;
 dig2 = ia5_string [ i ] & 0x0f ;
 oct = ( dig1 * 10 ) + dig2 + 32 ;
 if ( oct > 127 ) invalid_ia5_char = TRUE ;
 ia5_string [ i ] = oct ;
 }
 IA5_7BIT_decode ( * extracted_address , ia5_string , ia5_string_len ) ;
 item = proto_tree_add_string ( tree , hf_gsm_a_dtap_subaddress , tvb , curr_offset , len - ( curr_offset - offset ) , * extracted_address ) ;
 if ( invalid_ia5_char ) expert_add_info ( pinfo , item , & ei_gsm_a_dtap_invalid_ia5_character ) ;
 return ( len ) ;
 }
 }
 proto_tree_add_item ( tree , hf_gsm_a_dtap_subaddress_information , tvb , curr_offset , len - ( curr_offset - offset ) , ENC_NA ) ;
 return ( len ) ;
 }
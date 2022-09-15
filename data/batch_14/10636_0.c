static void dtap_bcc_imm_setup2 ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo _U_ , guint32 offset , guint len ) {
 guint32 curr_offset ;
 guint32 consumed ;
 guint curr_len ;
 guint8 oct ;
 proto_tree * subtree ;
 curr_offset = offset ;
 curr_len = len ;
 oct = tvb_get_guint8 ( tvb , curr_offset ) ;
 proto_tree_add_bits_item ( tree , hf_gsm_a_spare_bits , tvb , curr_offset << 3 , 4 , ENC_BIG_ENDIAN ) ;
 subtree = proto_tree_add_subtree ( tree , tvb , curr_offset , 1 , ett_gsm_common_elem [ DE_CIPH_KEY_SEQ_NUM ] , NULL , val_to_str_ext_const ( DE_CIPH_KEY_SEQ_NUM , & gsm_common_elem_strings_ext , "" ) ) ;
 proto_tree_add_bits_item ( subtree , hf_gsm_a_spare_bits , tvb , ( curr_offset << 3 ) + 4 , 1 , ENC_BIG_ENDIAN ) ;
 switch ( oct & 0x07 ) {
 case 0x07 : proto_tree_add_uint_format_value ( subtree , hf_gsm_a_dtap_ciphering_key_sequence_number , tvb , curr_offset , 1 , oct , "No key is available" ) ;
 break ;
 default : proto_tree_add_item ( subtree , hf_gsm_a_dtap_ciphering_key_sequence_number , tvb , curr_offset , 1 , ENC_BIG_ENDIAN ) ;
 break ;
 }
 curr_offset ++ ;
 curr_len -- ;
 ELEM_MAND_LV ( GSM_A_PDU_TYPE_COMMON , DE_MS_CM_2 , NULL ) ;
 ELEM_MAND_V ( GSM_A_PDU_TYPE_RR , DE_TMSI_STAT , NULL ) ELEM_MAND_V ( GSM_A_PDU_TYPE_DTAP , DE_BCC_CALL_REF , "(Group identity)" ) ;
 ELEM_MAND_V ( GSM_A_PDU_TYPE_DTAP , DE_BCC_COMPR_OTDI , NULL ) ;
 }
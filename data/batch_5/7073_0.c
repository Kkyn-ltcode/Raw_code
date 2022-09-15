static int dissect_pcp_message_desc ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , int offset ) {
 proto_item * pcp_desc_item ;
 proto_tree * pcp_desc_tree ;
 proto_item * pcp_desc_units_item ;
 proto_tree * pcp_desc_units_tree ;
 guint32 bits_offset ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "[%s]" , val_to_str ( PCP_PDU_DESC , packettypenames , "Unknown Type:0x%02x" ) ) ;
 pcp_desc_item = proto_tree_add_item ( tree , hf_pcp_desc , tvb , offset , 4 , ENC_NA ) ;
 pcp_desc_tree = proto_item_add_subtree ( pcp_desc_item , ett_pcp ) ;
 offset = dissect_pcp_partial_pmid ( tvb , pinfo , pcp_desc_tree , offset ) ;
 proto_tree_add_item ( pcp_desc_tree , hf_pcp_pmid_type , tvb , offset , 4 , ENC_BIG_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( pcp_desc_tree , hf_pcp_instance_indom , tvb , offset , 4 , ENC_BIG_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( pcp_desc_tree , hf_pcp_pmid_sem , tvb , offset , 4 , ENC_BIG_ENDIAN ) ;
 offset += 4 ;
 bits_offset = offset * 8 ;
 pcp_desc_units_item = proto_tree_add_item ( pcp_desc_tree , hf_pcp_units , tvb , offset , - 1 , ENC_NA ) ;
 pcp_desc_units_tree = proto_item_add_subtree ( pcp_desc_units_item , ett_pcp ) ;
 proto_tree_add_bits_item ( pcp_desc_units_tree , hf_pcp_units_dimspace , tvb , bits_offset , 4 , ENC_BIG_ENDIAN ) ;
 bits_offset += 4 ;
 proto_tree_add_bits_item ( pcp_desc_units_tree , hf_pcp_units_dimtime , tvb , bits_offset , 4 , ENC_BIG_ENDIAN ) ;
 bits_offset += 4 ;
 proto_tree_add_bits_item ( pcp_desc_units_tree , hf_pcp_units_dimcount , tvb , bits_offset , 4 , ENC_BIG_ENDIAN ) ;
 bits_offset += 4 ;
 proto_tree_add_bits_item ( pcp_desc_units_tree , hf_pcp_units_scalespace , tvb , bits_offset , 4 , ENC_BIG_ENDIAN ) ;
 bits_offset += 4 ;
 proto_tree_add_bits_item ( pcp_desc_units_tree , hf_pcp_units_scaletime , tvb , bits_offset , 4 , ENC_BIG_ENDIAN ) ;
 bits_offset += 4 ;
 proto_tree_add_bits_item ( pcp_desc_units_tree , hf_pcp_units_scalecount , tvb , bits_offset , 4 , ENC_BIG_ENDIAN ) ;
 offset += 3 ;
 proto_tree_add_item ( pcp_desc_units_tree , hf_pcp_pdu_padding , tvb , offset , 1 , ENC_NA ) ;
 offset += 1 ;
 return offset ;
 }
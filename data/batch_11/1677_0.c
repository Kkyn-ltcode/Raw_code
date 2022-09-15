int dissect_ber_constrained_bitstring ( gboolean implicit_tag , asn1_ctx_t * actx , proto_tree * parent_tree , tvbuff_t * tvb , int offset , gint32 min_len , gint32 max_len , const asn_namedbit * named_bits , gint hf_id , gint ett_id , tvbuff_t * * out_tvb ) {
 gint8 ber_class ;
 gboolean pc , ind ;
 gint32 tag ;
 guint32 len , byteno ;
 guint8 pad = 0 , b0 , b1 , val , * bitstring ;
 int end_offset ;
 int hoffset ;
 proto_item * item = NULL ;
 proto_item * cause ;
 proto_tree * tree = NULL ;
 const char * sep ;
 gboolean term ;
 const asn_namedbit * nb ;
 if ( ! implicit_tag ) {
 hoffset = offset ;
 offset = dissect_ber_identifier ( actx -> pinfo , parent_tree , tvb , offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( actx -> pinfo , parent_tree , tvb , offset , & len , & ind ) ;
 end_offset = offset + len ;
 if ( ! implicit_tag && ( ber_class != BER_CLASS_APP ) ) {
 if ( ( ber_class != BER_CLASS_UNI ) || ( tag != BER_UNI_TAG_BITSTRING ) ) {
 tvb_ensure_bytes_exist ( tvb , hoffset , 2 ) ;
 cause = proto_tree_add_string_format_value ( parent_tree , hf_ber_error , tvb , offset , len , "bitstring_expected" , "BitString expected but class:%s(%d) %s tag:%d was unexpected" , val_to_str_const ( ber_class , ber_class_codes , "Unknown" ) , ber_class , pc ? ber_pc_codes_short . true_string : ber_pc_codes_short . false_string , tag ) ;
 expert_add_info ( actx -> pinfo , cause , & ei_ber_expected_bitstring ) ;
 if ( decode_unexpected ) {
 proto_tree * unknown_tree = proto_item_add_subtree ( cause , ett_ber_unknown ) ;
 dissect_unknown_ber ( actx -> pinfo , tvb , hoffset , unknown_tree ) ;
 }
 return end_offset ;
 }
 }
 }
 else {
 pc = 0 ;
 len = tvb_reported_length_remaining ( tvb , offset ) ;
 end_offset = offset + len ;
 }
 actx -> created_item = NULL ;
 if ( pc ) {
 }
 else {
 pad = tvb_get_guint8 ( tvb , offset ) ;
 if ( ( pad == 0 ) && ( len == 1 ) ) {
 proto_tree_add_item ( parent_tree , hf_ber_bitstring_empty , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 }
 else {
 proto_item * pad_item = proto_tree_add_item ( parent_tree , hf_ber_bitstring_padding , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 if ( pad > 7 ) {
 expert_add_info_format ( actx -> pinfo , pad_item , & ei_ber_illegal_padding , "Illegal padding (0 .. 7): %d" , pad ) ;
 }
 }
 offset ++ ;
 len -- ;
 if ( hf_id >= 0 ) {
 item = proto_tree_add_item ( parent_tree , hf_id , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 actx -> created_item = item ;
 if ( ett_id != - 1 ) {
 tree = proto_item_add_subtree ( item , ett_id ) ;
 }
 }
 if ( out_tvb ) {
 * out_tvb = ber_tvb_new_subset_length ( tvb , offset , len ) ;
 }
 }
 if ( named_bits ) {
 sep = " (" ;
 term = FALSE ;
 nb = named_bits ;
 bitstring = ( guint8 * ) tvb_memdup ( wmem_packet_scope ( ) , tvb , offset , len ) ;
 while ( nb -> p_id ) {
 if ( ( len > 0 ) && ( pad < 8 * len ) && ( nb -> bit < ( 8 * len - pad ) ) ) {
 val = tvb_get_guint8 ( tvb , offset + nb -> bit / 8 ) ;
 bitstring [ ( nb -> bit / 8 ) ] &= ~ ( 0x80 >> ( nb -> bit % 8 ) ) ;
 val &= 0x80 >> ( nb -> bit % 8 ) ;
 b0 = ( nb -> gb0 == - 1 ) ? nb -> bit / 8 : ( ( guint32 ) nb -> gb0 ) / 8 ;
 b1 = ( nb -> gb1 == - 1 ) ? nb -> bit / 8 : ( ( guint32 ) nb -> gb1 ) / 8 ;
 proto_tree_add_item ( tree , * ( nb -> p_id ) , tvb , offset + b0 , b1 - b0 + 1 , ENC_BIG_ENDIAN ) ;
 }
 else {
 val = 0 ;
 proto_tree_add_boolean ( tree , * ( nb -> p_id ) , tvb , offset + len , 0 , 0x00 ) ;
 }
 if ( val ) {
 if ( item && nb -> tstr ) {
 proto_item_append_text ( item , "%s%s" , sep , nb -> tstr ) ;
 sep = ", " ;
 term = TRUE ;
 }
 }
 else {
 if ( item && nb -> fstr ) {
 proto_item_append_text ( item , "%s%s" , sep , nb -> fstr ) ;
 sep = ", " ;
 term = TRUE ;
 }
 }
 nb ++ ;
 }
 if ( term ) proto_item_append_text ( item , ")" ) ;
 for ( byteno = 0 ;
 byteno < len ;
 byteno ++ ) {
 if ( bitstring [ byteno ] ) {
 expert_add_info_format ( actx -> pinfo , item , & ei_ber_bits_unknown , "Unknown bit(s): 0x%s" , bytes_to_str ( wmem_packet_scope ( ) , bitstring , len ) ) ;
 break ;
 }
 }
 }
 if ( ( pad > 0 ) && ( pad < 8 ) && ( len > 0 ) ) {
 guint8 bits_in_pad = tvb_get_guint8 ( tvb , offset + len - 1 ) & ( 0xFF >> ( 8 - pad ) ) ;
 if ( bits_in_pad ) {
 expert_add_info_format ( actx -> pinfo , item , & ei_ber_bits_set_padded , "Bits set in padded area: 0x%02x" , bits_in_pad ) ;
 }
 }
 ber_check_length ( 8 * len - pad , min_len , max_len , actx , item , TRUE ) ;
 return end_offset ;
 }
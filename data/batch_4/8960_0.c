static int dissect_pbb_tlvblock ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , guint offset , guint maxoffset , gint8 addrCount , guint tlvCat ) {
 guint16 tlvblockLength ;
 guint tlvblockEnd ;
 proto_tree * tlvblock_tree = NULL ;
 proto_tree * tlv_tree = NULL ;
 proto_tree * tlv_flags_tree = NULL ;
 proto_tree * tlvValue_tree = NULL ;
 proto_item * tlvBlock_item = NULL ;
 proto_item * tlv_item = NULL ;
 proto_item * tlvFlags_item = NULL ;
 proto_item * tlvValue_item = NULL ;
 proto_item * ti = NULL ;
 int tlvCount = 0 ;
 int hf_packetbb_tlv_type = 0 ;
 const value_string * tlv_type_vals = NULL ;
 if ( maxoffset < offset + 2 ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for minimal tlvblock" ) ;
 return maxoffset ;
 }
 tlvblockLength = tvb_get_ntohs ( tvb , offset ) ;
 tlvblockEnd = offset + 2 + tlvblockLength ;
 if ( maxoffset < tlvblockEnd ) {
 proto_tree_add_expert_format ( tree , pinfo , & ei_packetbb_error , tvb , offset , maxoffset - offset , "Not enough octets for tlvblock" ) ;
 return maxoffset ;
 }
 tlvBlock_item = proto_tree_add_item ( tree , hf_packetbb_tlvblock , tvb , offset , tlvblockEnd - offset , ENC_NA ) ;
 tlvblock_tree = proto_item_add_subtree ( tlvBlock_item , ett_packetbb_tlvblock ) ;
 proto_tree_add_item ( tlvblock_tree , hf_packetbb_tlvblock_length , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 offset += 2 ;
 while ( offset < tlvblockEnd ) {
 guint tlvStart , tlvLength ;
 guint8 tlvType , tlvFlags , tlvExtType , indexStart , indexEnd ;
 guint16 length = 0 ;
 tlvStart = offset ;
 tlvType = tvb_get_guint8 ( tvb , offset ++ ) ;
 tlvFlags = tvb_get_guint8 ( tvb , offset ++ ) ;
 indexStart = 0 ;
 indexEnd = addrCount ? ( addrCount - 1 ) : 0 ;
 tlvExtType = 0 ;
 if ( ( tlvFlags & TLV_HAS_TYPEEXT ) != 0 ) {
 tlvExtType = tvb_get_guint8 ( tvb , offset ++ ) ;
 }
 if ( ( tlvFlags & TLV_HAS_SINGLEINDEX ) != 0 ) {
 indexStart = indexEnd = tvb_get_guint8 ( tvb , offset ++ ) ;
 }
 else if ( ( tlvFlags & TLV_HAS_MULTIINDEX ) != 0 ) {
 indexStart = tvb_get_guint8 ( tvb , offset ++ ) ;
 indexEnd = tvb_get_guint8 ( tvb , offset ++ ) ;
 }
 if ( ( tlvFlags & TLV_HAS_VALUE ) != 0 ) {
 if ( ( tlvFlags & TLV_HAS_EXTLEN ) != 0 ) {
 length = tvb_get_ntohs ( tvb , offset ++ ) ;
 }
 else {
 length = tvb_get_guint8 ( tvb , offset ++ ) ;
 }
 }
 tlvLength = offset - tlvStart + length ;
 offset = tlvStart ;
 tlv_item = proto_tree_add_item ( tlvBlock_item , hf_packetbb_tlv , tvb , tlvStart , tlvLength , ENC_NA ) ;
 tlv_tree = proto_item_add_subtree ( tlv_item , ett_packetbb_tlv [ tlvType ] ) ;
 if ( tlvCat == TLV_CAT_PACKET ) {
 hf_packetbb_tlv_type = hf_packetbb_pkttlv_type ;
 tlv_type_vals = pkttlv_type_vals ;
 }
 else if ( tlvCat == TLV_CAT_MESSAGE ) {
 hf_packetbb_tlv_type = hf_packetbb_msgtlv_type ;
 tlv_type_vals = msgtlv_type_vals ;
 }
 else {
 hf_packetbb_tlv_type = hf_packetbb_addrtlv_type ;
 tlv_type_vals = addrtlv_type_vals ;
 }
 if ( ( tlvFlags & TLV_HAS_TYPEEXT ) == 0 ) {
 proto_item_append_text ( tlv_item , " (%s)" , val_to_str_const ( tlvType , tlv_type_vals , "Unknown type" ) ) ;
 }
 else {
 proto_item_append_text ( tlv_item , " (%s / %d)" , val_to_str_const ( tlvType , tlv_type_vals , "Unknown type" ) , tlvExtType ) ;
 }
 proto_tree_add_item ( tlv_tree , hf_packetbb_tlv_type , tvb , offset ++ , 1 , ENC_BIG_ENDIAN ) ;
 tlvFlags_item = proto_tree_add_item ( tlv_tree , hf_packetbb_tlv_flags , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 tlv_flags_tree = proto_item_add_subtree ( tlvFlags_item , ett_packetbb_tlv_flags ) ;
 proto_tree_add_item ( tlv_flags_tree , hf_packetbb_tlv_flags_hastypext , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tlv_flags_tree , hf_packetbb_tlv_flags_hassingleindex , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tlv_flags_tree , hf_packetbb_tlv_flags_hasmultiindex , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tlv_flags_tree , hf_packetbb_tlv_flags_hasvalue , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tlv_flags_tree , hf_packetbb_tlv_flags_hasextlen , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( tlv_flags_tree , hf_packetbb_tlv_flags_hasmultivalue , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 offset ++ ;
 if ( ( tlvFlags & TLV_HAS_TYPEEXT ) != 0 ) {
 proto_tree_add_item ( tlv_tree , hf_packetbb_tlv_typeext , tvb , offset ++ , 1 , ENC_BIG_ENDIAN ) ;
 }
 if ( addrCount > 0 ) {
 if ( ( tlvFlags & TLV_HAS_SINGLEINDEX ) != 0 ) {
 proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_indexstart , tvb , offset ++ , 1 , indexStart ) ;
 ti = proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_indexend , tvb , offset , 0 , indexEnd ) ;
 proto_item_append_text ( ti , " (implicit)" ) ;
 }
 else if ( ( tlvFlags & TLV_HAS_MULTIINDEX ) != 0 ) {
 proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_indexstart , tvb , offset ++ , 1 , indexStart ) ;
 proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_indexend , tvb , offset ++ , 1 , indexEnd ) ;
 }
 else {
 ti = proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_indexstart , tvb , offset , 0 , indexStart ) ;
 proto_item_append_text ( ti , " (implicit)" ) ;
 ti = proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_indexend , tvb , offset , 0 , indexEnd ) ;
 proto_item_append_text ( ti , " (implicit)" ) ;
 }
 }
 if ( ( tlvFlags & TLV_HAS_VALUE ) != 0 ) {
 if ( ( tlvFlags & TLV_HAS_EXTLEN ) != 0 ) {
 proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_length , tvb , offset , 2 , length ) ;
 offset += 2 ;
 }
 else {
 proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_length , tvb , offset ++ , 1 , length ) ;
 }
 }
 else {
 ti = proto_tree_add_uint ( tlv_tree , hf_packetbb_tlv_length , tvb , offset , 0 , 0 ) ;
 proto_item_append_text ( ti , " (implicit)" ) ;
 }
 if ( length > 0 ) {
 tlvValue_item = proto_tree_add_item ( tlv_tree , hf_packetbb_tlv_value , tvb , offset , length , ENC_NA ) ;
 if ( ( tlvFlags & TLV_HAS_MULTIVALUE ) == 0 ) {
 offset += length ;
 }
 else {
 int i ;
 guint c = indexEnd - indexStart + 1 ;
 if ( c > 0 ) {
 tlvValue_tree = proto_item_add_subtree ( tlvValue_item , ett_packetbb_tlv_value ) ;
 for ( i = indexStart ;
 i <= indexEnd ;
 i ++ ) {
 proto_tree_add_item ( tlvValue_tree , hf_packetbb_tlv_multivalue , tvb , offset , length / c , ENC_NA ) ;
 offset += ( length / c ) ;
 }
 }
 }
 }
 tlvCount ++ ;
 }
 proto_item_append_text ( tlvBlock_item , " (%d TLVs)" , tlvCount ) ;
 return offset ;
 }
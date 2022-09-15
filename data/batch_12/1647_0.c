static int try_dissect_unknown_ber ( packet_info * pinfo , tvbuff_t * tvb , volatile int offset , proto_tree * tree , gint nest_level ) {
 int start_offset ;
 gint8 ber_class ;
 gboolean pc , ind ;
 gint32 tag ;
 guint32 len ;
 int hdr_len ;
 proto_item * item = NULL ;
 proto_tree * next_tree = NULL ;
 guint8 c ;
 guint32 i ;
 gboolean is_printable ;
 volatile gboolean is_decoded_as ;
 proto_item * pi , * cause ;
 asn1_ctx_t asn1_ctx ;
 if ( nest_level > BER_MAX_NESTING ) {
 THROW ( ReportedBoundsError ) ;
 }
 start_offset = offset ;
 asn1_ctx_init ( & asn1_ctx , ASN1_ENC_BER , TRUE , pinfo ) ;
 offset = get_ber_identifier ( tvb , offset , & ber_class , & pc , & tag ) ;
 offset = get_ber_length ( tvb , offset , & len , & ind ) ;
 if ( len > ( guint32 ) tvb_reported_length_remaining ( tvb , offset ) ) {
 if ( show_internal_ber_fields ) {
 offset = dissect_ber_identifier ( pinfo , tree , tvb , start_offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( pinfo , tree , tvb , offset , & len , NULL ) ;
 }
 cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset , len , "illegal_length" , "length:%u longer than tvb_reported_length_remaining:%d" , len , tvb_reported_length_remaining ( tvb , offset ) ) ;
 expert_add_info ( pinfo , cause , & ei_ber_error_length ) ;
 return tvb_reported_length ( tvb ) ;
 }
 switch ( pc ) {
 case FALSE : switch ( ber_class ) {
 case BER_CLASS_UNI : switch ( tag ) {
 case BER_UNI_TAG_EOC : break ;
 case BER_UNI_TAG_INTEGER : offset = dissect_ber_integer ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_INTEGER , NULL ) ;
 break ;
 case BER_UNI_TAG_REAL : offset = dissect_ber_real ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_REAL , NULL ) ;
 break ;
 case BER_UNI_TAG_BITSTRING : offset = dissect_ber_bitstring ( FALSE , & asn1_ctx , tree , tvb , start_offset , NULL , hf_ber_unknown_BITSTRING , - 1 , NULL ) ;
 break ;
 case BER_UNI_TAG_ENUMERATED : offset = dissect_ber_integer ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_ENUMERATED , NULL ) ;
 break ;
 case BER_UNI_TAG_GraphicString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_GraphicString , NULL ) ;
 break ;
 case BER_UNI_TAG_OCTETSTRING : is_decoded_as = FALSE ;
 if ( decode_octetstring_as_ber && ( len >= 2 ) ) {
 volatile int ber_offset = 0 ;
 guint32 ber_len = 0 ;
 TRY {
 ber_offset = get_ber_identifier ( tvb , offset , NULL , & pc , NULL ) ;
 ber_offset = get_ber_length ( tvb , ber_offset , & ber_len , NULL ) ;
 }
 CATCH_ALL {
 }
 ENDTRY ;
 if ( pc && ( ber_len > 0 ) && ( ber_len + ( ber_offset - offset ) == len ) ) {
 is_decoded_as = TRUE ;
 if ( show_internal_ber_fields ) {
 offset = dissect_ber_identifier ( pinfo , tree , tvb , start_offset , NULL , NULL , NULL ) ;
 offset = dissect_ber_length ( pinfo , tree , tvb , offset , NULL , NULL ) ;
 }
 item = ber_proto_tree_add_item ( pinfo , tree , hf_ber_unknown_BER_OCTETSTRING , tvb , offset , len , ENC_NA ) ;
 next_tree = proto_item_add_subtree ( item , ett_ber_octet_string ) ;
 offset = try_dissect_unknown_ber ( pinfo , tvb , offset , next_tree , nest_level + 1 ) ;
 }
 }
 if ( ! is_decoded_as ) {
 offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_OCTETSTRING , NULL ) ;
 }
 break ;
 case BER_UNI_TAG_OID : offset = dissect_ber_object_identifier_str ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_OID , NULL ) ;
 break ;
 case BER_UNI_TAG_RELATIVE_OID : offset = dissect_ber_relative_oid_str ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_relative_OID , NULL ) ;
 break ;
 case BER_UNI_TAG_NumericString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_NumericString , NULL ) ;
 break ;
 case BER_UNI_TAG_PrintableString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_PrintableString , NULL ) ;
 break ;
 case BER_UNI_TAG_TeletexString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_TeletexString , NULL ) ;
 break ;
 case BER_UNI_TAG_VisibleString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_VisibleString , NULL ) ;
 break ;
 case BER_UNI_TAG_GeneralString : offset = dissect_ber_GeneralString ( & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_GeneralString , NULL , 0 ) ;
 break ;
 case BER_UNI_TAG_BMPString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_BMPString , NULL ) ;
 break ;
 case BER_UNI_TAG_UniversalString : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_UniversalString , NULL ) ;
 break ;
 case BER_UNI_TAG_IA5String : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_IA5String , NULL ) ;
 break ;
 case BER_UNI_TAG_UTCTime : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_UTCTime , NULL ) ;
 break ;
 case BER_UNI_TAG_NULL : proto_tree_add_item ( tree , hf_ber_null_tag , tvb , offset , len , ENC_NA ) ;
 break ;
 case BER_UNI_TAG_UTF8String : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_UTF8String , NULL ) ;
 break ;
 case BER_UNI_TAG_GeneralizedTime : offset = dissect_ber_octet_string ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_GeneralizedTime , NULL ) ;
 break ;
 case BER_UNI_TAG_BOOLEAN : offset = dissect_ber_boolean ( FALSE , & asn1_ctx , tree , tvb , start_offset , hf_ber_unknown_BOOLEAN , NULL ) ;
 break ;
 default : offset = dissect_ber_identifier ( pinfo , tree , tvb , start_offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( pinfo , tree , tvb , offset , & len , NULL ) ;
 cause = proto_tree_add_string_format_value ( tree , hf_ber_error , tvb , offset , len , "unknown_universal_tag" , "can not handle universal tag:%d" , tag ) ;
 expert_add_info ( pinfo , cause , & ei_ber_universal_tag_unknown ) ;
 offset += len ;
 }
 break ;
 case BER_CLASS_APP : case BER_CLASS_CON : case BER_CLASS_PRI : default : if ( show_internal_ber_fields ) {
 offset = dissect_ber_identifier ( pinfo , tree , tvb , start_offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( pinfo , tree , tvb , offset , & len , NULL ) ;
 }
 pi = proto_tree_add_none_format ( tree , hf_ber_unknown_BER_primitive , tvb , offset , len , "[%s %d] " , val_to_str_const ( ber_class , ber_class_codes , "Unknown" ) , tag ) ;
 is_decoded_as = FALSE ;
 if ( decode_primitive_as_ber && ( len >= 2 ) ) {
 volatile int ber_offset = 0 ;
 guint32 ber_len = 0 ;
 TRY {
 ber_offset = get_ber_identifier ( tvb , offset , NULL , & pc , NULL ) ;
 ber_offset = get_ber_length ( tvb , ber_offset , & ber_len , NULL ) ;
 }
 CATCH_ALL {
 }
 ENDTRY ;
 if ( pc && ( ber_len > 0 ) && ( ber_len + ( ber_offset - offset ) == len ) ) {
 is_decoded_as = TRUE ;
 proto_item_append_text ( pi , "[BER encoded]" ) ;
 next_tree = proto_item_add_subtree ( pi , ett_ber_primitive ) ;
 offset = try_dissect_unknown_ber ( pinfo , tvb , offset , next_tree , nest_level + 1 ) ;
 }
 }
 if ( ! is_decoded_as && len ) {
 is_printable = TRUE ;
 for ( i = 0 ;
 i < len ;
 i ++ ) {
 c = tvb_get_guint8 ( tvb , offset + i ) ;
 if ( is_printable && ! g_ascii_isprint ( c ) ) is_printable = FALSE ;
 proto_item_append_text ( pi , "%02x" , c ) ;
 }
 if ( is_printable ) {
 proto_item_append_text ( pi , " (" ) ;
 for ( i = 0 ;
 i < len ;
 i ++ ) {
 proto_item_append_text ( pi , "%c" , tvb_get_guint8 ( tvb , offset + i ) ) ;
 }
 proto_item_append_text ( pi , ")" ) ;
 }
 offset += len ;
 }
 break ;
 }
 break ;
 case TRUE : if ( show_internal_ber_fields ) {
 offset = dissect_ber_identifier ( pinfo , tree , tvb , start_offset , & ber_class , & pc , & tag ) ;
 offset = dissect_ber_length ( pinfo , tree , tvb , offset , & len , NULL ) ;
 }
 hdr_len = offset - start_offset ;
 switch ( ber_class ) {
 case BER_CLASS_UNI : next_tree = proto_tree_add_subtree ( tree , tvb , offset , len , ett_ber_SEQUENCE , NULL , val_to_str_ext_const ( tag , & ber_uni_tag_codes_ext , "Unknown" ) ) ;
 while ( offset < ( int ) ( start_offset + len + hdr_len ) ) offset = try_dissect_unknown_ber ( pinfo , tvb , offset , next_tree , nest_level + 1 ) ;
 break ;
 case BER_CLASS_APP : case BER_CLASS_CON : case BER_CLASS_PRI : default : next_tree = proto_tree_add_subtree_format ( tree , tvb , offset , len , ett_ber_SEQUENCE , NULL , "[%s %d]" , val_to_str_const ( ber_class , ber_class_codes , "Unknown" ) , tag ) ;
 while ( offset < ( int ) ( start_offset + len + hdr_len ) ) offset = try_dissect_unknown_ber ( pinfo , tvb , offset , next_tree , nest_level + 1 ) ;
 break ;
 }
 break ;
 }
 return offset ;
 }
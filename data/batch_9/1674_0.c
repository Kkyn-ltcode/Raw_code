void proto_register_ber ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_ber_id_class , {
 "Class" , "ber.id.class" , FT_UINT8 , BASE_DEC , VALS ( ber_class_codes ) , 0xc0 , "Class of BER TLV Identifier" , HFILL }
 }
 , {
 & hf_ber_bitstring_padding , {
 "Padding" , "ber.bitstring.padding" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "Number of unused bits in the last octet of the bitstring" , HFILL }
 }
 , {
 & hf_ber_bitstring_empty , {
 "Empty" , "ber.bitstring.empty" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "This is an empty bitstring" , HFILL }
 }
 , {
 & hf_ber_id_pc , {
 "P/C" , "ber.id.pc" , FT_BOOLEAN , 8 , TFS ( & ber_pc_codes ) , 0x20 , "Primitive or Constructed BER encoding" , HFILL }
 }
 , {
 & hf_ber_id_uni_tag , {
 "Tag" , "ber.id.uni_tag" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & ber_uni_tag_codes_ext , 0x1f , "Universal tag type" , HFILL }
 }
 , {
 & hf_ber_id_uni_tag_ext , {
 "Tag" , "ber.id.uni_tag" , FT_UINT32 , BASE_DEC , NULL , 0 , "Universal tag type" , HFILL }
 }
 , {
 & hf_ber_id_tag , {
 "Tag" , "ber.id.tag" , FT_UINT8 , BASE_DEC , NULL , 0x1f , "Tag value for non-Universal classes" , HFILL }
 }
 , {
 & hf_ber_id_tag_ext , {
 "Tag" , "ber.id.tag" , FT_UINT32 , BASE_DEC , NULL , 0 , "Tag value for non-Universal classes" , HFILL }
 }
 , {
 & hf_ber_length , {
 "Length" , "ber.length" , FT_UINT32 , BASE_DEC , NULL , 0 , "Length of contents" , HFILL }
 }
 , {
 & hf_ber_unknown_OCTETSTRING , {
 "OCTETSTRING" , "ber.unknown.OCTETSTRING" , FT_BYTES , BASE_NONE , NULL , 0 , "This is an unknown OCTETSTRING" , HFILL }
 }
 , {
 & hf_ber_unknown_BER_OCTETSTRING , {
 "OCTETSTRING [BER encoded]" , "ber.unknown.OCTETSTRING" , FT_NONE , BASE_NONE , NULL , 0 , "This is an BER encoded OCTETSTRING" , HFILL }
 }
 , {
 & hf_ber_unknown_BER_primitive , {
 "Primitive [BER encoded]" , "ber.unknown.primitive" , FT_NONE , BASE_NONE , NULL , 0 , "This is a BER encoded Primitive" , HFILL }
 }
 , {
 & hf_ber_unknown_OID , {
 "OID" , "ber.unknown.OID" , FT_OID , BASE_NONE , NULL , 0 , "This is an unknown Object Identifier" , HFILL }
 }
 , {
 & hf_ber_unknown_relative_OID , {
 "OID" , "ber.unknown.relative_OID" , FT_REL_OID , BASE_NONE , NULL , 0 , "This is an unknown relative Object Identifier" , HFILL }
 }
 , {
 & hf_ber_unknown_GraphicString , {
 "GRAPHICSTRING" , "ber.unknown.GRAPHICSTRING" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown GRAPHICSTRING" , HFILL }
 }
 , {
 & hf_ber_unknown_NumericString , {
 "NumericString" , "ber.unknown.NumericString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown NumericString" , HFILL }
 }
 , {
 & hf_ber_unknown_PrintableString , {
 "PrintableString" , "ber.unknown.PrintableString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown PrintableString" , HFILL }
 }
 , {
 & hf_ber_unknown_TeletexString , {
 "TeletexString" , "ber.unknown.TeletexString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown TeletexString" , HFILL }
 }
 , {
 & hf_ber_unknown_VisibleString , {
 "VisibleString" , "ber.unknown.VisibleString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown VisibleString" , HFILL }
 }
 , {
 & hf_ber_unknown_GeneralString , {
 "GeneralString" , "ber.unknown.GeneralString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown GeneralString" , HFILL }
 }
 , {
 & hf_ber_unknown_UniversalString , {
 "UniversalString" , "ber.unknown.UniversalString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown UniversalString" , HFILL }
 }
 , {
 & hf_ber_unknown_BMPString , {
 "BMPString" , "ber.unknown.BMPString" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown BMPString" , HFILL }
 }
 , {
 & hf_ber_unknown_IA5String , {
 "IA5String" , "ber.unknown.IA5String" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown IA5String" , HFILL }
 }
 , {
 & hf_ber_unknown_UTCTime , {
 "UTCTime" , "ber.unknown.UTCTime" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown UTCTime" , HFILL }
 }
 , {
 & hf_ber_unknown_UTF8String , {
 "UTF8String" , "ber.unknown.UTF8String" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown UTF8String" , HFILL }
 }
 , {
 & hf_ber_unknown_GeneralizedTime , {
 "GeneralizedTime" , "ber.unknown.GeneralizedTime" , FT_STRING , BASE_NONE , NULL , 0 , "This is an unknown GeneralizedTime" , HFILL }
 }
 , {
 & hf_ber_unknown_INTEGER , {
 "INTEGER" , "ber.unknown.INTEGER" , FT_INT64 , BASE_DEC , NULL , 0 , "This is an unknown INTEGER" , HFILL }
 }
 , {
 & hf_ber_unknown_REAL , {
 "REAL" , "ber.unknown.REAL" , FT_DOUBLE , BASE_NONE , NULL , 0 , "This is an unknown REAL" , HFILL }
 }
 , {
 & hf_ber_unknown_BITSTRING , {
 "BITSTRING" , "ber.unknown.BITSTRING" , FT_BYTES , BASE_NONE , NULL , 0 , "This is an unknown BITSTRING" , HFILL }
 }
 , {
 & hf_ber_unknown_BOOLEAN , {
 "BOOLEAN" , "ber.unknown.BOOLEAN" , FT_UINT8 , BASE_HEX , NULL , 0 , "This is an unknown BOOLEAN" , HFILL }
 }
 , {
 & hf_ber_unknown_ENUMERATED , {
 "ENUMERATED" , "ber.unknown.ENUMERATED" , FT_UINT32 , BASE_DEC , NULL , 0 , "This is an unknown ENUMERATED" , HFILL }
 }
 , {
 & hf_ber_error , {
 "BER Error" , "ber.error" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_ber_direct_reference , {
 "direct-reference" , "ber.direct_reference" , FT_OID , BASE_NONE , NULL , 0 , "ber.OBJECT_IDENTIFIER" , HFILL }
 }
 , {
 & hf_ber_indirect_reference , {
 "indirect-reference" , "ber.indirect_reference" , FT_INT32 , BASE_DEC , NULL , 0 , "ber.INTEGER" , HFILL }
 }
 , {
 & hf_ber_data_value_descriptor , {
 "data-value-descriptor" , "ber.data_value_descriptor" , FT_STRING , BASE_NONE , NULL , 0 , "ber.ObjectDescriptor" , HFILL }
 }
 , {
 & hf_ber_encoding , {
 "encoding" , "ber.encoding" , FT_UINT32 , BASE_DEC , VALS ( ber_T_encoding_vals ) , 0 , "ber.T_encoding" , HFILL }
 }
 , {
 & hf_ber_octet_aligned , {
 "octet-aligned" , "ber.octet_aligned" , FT_BYTES , BASE_NONE , NULL , 0 , "ber.T_octet_aligned" , HFILL }
 }
 , {
 & hf_ber_arbitrary , {
 "arbitrary" , "ber.arbitrary" , FT_BYTES , BASE_NONE , NULL , 0 , "ber.T_arbitrary" , HFILL }
 }
 , {
 & hf_ber_single_ASN1_type , {
 "single-ASN1-type" , "ber.single_ASN1_type" , FT_NONE , BASE_NONE , NULL , 0 , "ber.T_single_ASN1_type" , HFILL }
 }
 , {
 & hf_ber_fragments , {
 "OCTET STRING fragments" , "ber.octet_string.fragments" , FT_NONE , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment , {
 "OCTET STRING fragment" , "ber.octet_string.fragment" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment_overlap , {
 "OCTET STRING fragment overlap" , "ber.octet_string.fragment.overlap" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment_overlap_conflicts , {
 "OCTET STRING fragment overlapping with conflicting data" , "ber.octet_string.fragment.overlap.conflicts" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment_multiple_tails , {
 "OCTET STRING has multiple tail fragments" , "ber.octet_string.fragment.multiple_tails" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment_too_long_fragment , {
 "OCTET STRING fragment too long" , "ber.octet_string.fragment.too_long_fragment" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment_error , {
 "OCTET STRING defragmentation error" , "ber.octet_string.fragment.error" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_ber_fragment_count , {
 "OCTET STRING fragment count" , "ber.octet_string.fragment.count" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_ber_reassembled_in , {
 "Reassembled in" , "ber.octet_string.reassembled.in" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_ber_reassembled_length , {
 "Reassembled OCTET STRING length" , "ber.octet_string.reassembled.length" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_ber_null_tag , {
 "NULL tag" , "ber.null_tag" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_unknown_data , {
 "Unknown Data" , "ber.unknown_data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_unknown_octetstring , {
 "Unknown OctetString" , "ber.unknown_octetstring" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_seq_field_eoc , {
 "SEQ FIELD EOC" , "ber.seq_field_eoc" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_seq_eoc , {
 "SEQ EOC" , "ber.seq_eoc" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_set_field_eoc , {
 "SET FIELD EOC" , "ber.set_field_eoc" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_set_eoc , {
 "SET EOC" , "ber.set_eoc" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_choice_eoc , {
 "CHOICE EOC" , "ber.choice_eoc" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_seq_of_eoc , {
 "SEQ OF EOC" , "ber.seq_of_eoc" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ber_64bit_uint_as_bytes , {
 "64bits unsigned integer" , "ber.64bit_uint_as_bytes" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , }
 ;
 static gint * ett [ ] = {
 & ett_ber_octet_string , & ett_ber_reassembled_octet_string , & ett_ber_primitive , & ett_ber_unknown , & ett_ber_SEQUENCE , & ett_ber_EXTERNAL , & ett_ber_T_encoding , & ett_ber_fragment , & ett_ber_fragments }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_ber_size_constraint_string , {
 "ber.size_constraint.string" , PI_PROTOCOL , PI_WARN , "Size constraint: string" , EXPFILL }
 }
 , {
 & ei_ber_size_constraint_value , {
 "ber.size_constraint.value" , PI_PROTOCOL , PI_WARN , "Size constraint: values" , EXPFILL }
 }
 , {
 & ei_ber_size_constraint_items , {
 "ber.size_constraint.items" , PI_PROTOCOL , PI_WARN , "Size constraint: items" , EXPFILL }
 }
 , {
 & ei_ber_sequence_field_wrong , {
 "ber.error.sequence.field_wrong" , PI_MALFORMED , PI_WARN , "BER Error: Wrong field in SEQUENCE" , EXPFILL }
 }
 , {
 & ei_ber_expected_octet_string , {
 "ber.error.expected.octet_string" , PI_MALFORMED , PI_WARN , "BER Error: OctetString expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_null , {
 "ber.error.expected.null" , PI_MALFORMED , PI_WARN , "BER Error: NULL expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_null_zero_length , {
 "ber.error.expected.null_zero_length" , PI_MALFORMED , PI_WARN , "BER Error: NULL expect zero length" , EXPFILL }
 }
 , {
 & ei_ber_expected_sequence , {
 "ber.error.expected.sequence" , PI_MALFORMED , PI_WARN , "BER Error: Sequence expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_set , {
 "ber.error.expected.set" , PI_MALFORMED , PI_WARN , "BER Error: SET expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_string , {
 "ber.error.expected.string" , PI_MALFORMED , PI_WARN , "BER Error: String expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_object_identifier , {
 "ber.error.expected.object_identifier" , PI_MALFORMED , PI_WARN , "BER Error: Object Identifier expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_generalized_time , {
 "ber.error.expected.generalized_time" , PI_MALFORMED , PI_WARN , "BER Error: GeneralizedTime expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_utc_time , {
 "ber.error.expected.utc_time" , PI_MALFORMED , PI_WARN , "BER Error: UTCTime expected" , EXPFILL }
 }
 , {
 & ei_ber_expected_bitstring , {
 "ber.error.expected.bitstring" , PI_MALFORMED , PI_WARN , "BER Error: BitString expected" , EXPFILL }
 }
 , {
 & ei_ber_error_length , {
 "ber.error.length" , PI_MALFORMED , PI_WARN , "BER Error length" , EXPFILL }
 }
 , {
 & ei_ber_wrong_tag_in_tagged_type , {
 "ber.error.wrong_tag_in_tagged_type" , PI_MALFORMED , PI_WARN , "BER Error: Wrong tag in tagged type" , EXPFILL }
 }
 , {
 & ei_ber_universal_tag_unknown , {
 "ber.error.universal_tag_unknown" , PI_MALFORMED , PI_WARN , "BER Error: can not handle universal" , EXPFILL }
 }
 , {
 & ei_ber_no_oid , {
 "ber.error.no_oid" , PI_MALFORMED , PI_WARN , "BER Error: No OID supplied to call_ber_oid_callback" , EXPFILL }
 }
 , {
 & ei_ber_oid_not_implemented , {
 "ber.error.oid_not_implemented" , PI_UNDECODED , PI_WARN , "BER: Dissector for OID not implemented. Contact Wireshark developers if you want this supported" , EXPFILL }
 }
 , {
 & ei_ber_syntax_not_implemented , {
 "ber.error.syntax_not_implemented" , PI_UNDECODED , PI_WARN , "BER: Syntax not implemented" , EXPFILL }
 }
 , {
 & ei_ber_value_too_many_bytes , {
 "ber.error.value_too_many_bytes" , PI_MALFORMED , PI_WARN , "Value is encoded with too many bytes" , EXPFILL }
 }
 , {
 & ei_ber_unknown_field_sequence , {
 "ber.error.unknown_field.sequence" , PI_MALFORMED , PI_WARN , "BER Error: Unknown field in Sequence" , EXPFILL }
 }
 , {
 & ei_ber_unknown_field_set , {
 "ber.error.unknown_field.set" , PI_MALFORMED , PI_WARN , "BER Error: Unknown field in SET" , EXPFILL }
 }
 , {
 & ei_ber_missing_field_set , {
 "ber.error.missing_field.set" , PI_MALFORMED , PI_WARN , "BER Error: Missing field in SET" , EXPFILL }
 }
 , {
 & ei_ber_empty_choice , {
 "ber.error.empty_choice" , PI_MALFORMED , PI_WARN , "BER Error: Empty choice was found" , EXPFILL }
 }
 , {
 & ei_ber_choice_not_found , {
 "ber.error.choice_not_found" , PI_MALFORMED , PI_WARN , "BER Error: This choice field was not found" , EXPFILL }
 }
 , {
 & ei_ber_bits_unknown , {
 "ber.error.bits_unknown" , PI_UNDECODED , PI_WARN , "BER Error: Bits unknown" , EXPFILL }
 }
 , {
 & ei_ber_bits_set_padded , {
 "ber.error.bits_set_padded" , PI_UNDECODED , PI_WARN , "BER Error: Bits set in padded area" , EXPFILL }
 }
 , {
 & ei_ber_illegal_padding , {
 "ber.error.illegal_padding" , PI_UNDECODED , PI_WARN , "Illegal padding" , EXPFILL }
 }
 , {
 & ei_ber_invalid_format_generalized_time , {
 "ber.error.invalid_format.generalized_time" , PI_MALFORMED , PI_WARN , "BER Error: GeneralizedTime invalid format" , EXPFILL }
 }
 , {
 & ei_ber_invalid_format_utctime , {
 "ber.error.invalid_format.utctime" , PI_MALFORMED , PI_WARN , "BER Error: malformed UTCTime encoding" , EXPFILL }
 }
 , {
 & ei_hf_field_not_integer_type , {
 "ber.error.hf_field_not_integer_type" , PI_PROTOCOL , PI_ERROR , "Was passed a HF field that was not integer type" , EXPFILL }
 }
 , }
 ;
 static build_valid_func ber_da_build_value [ 1 ] = {
 ber_value }
 ;
 static decode_as_value_t ber_da_values = {
 ber_prompt , 1 , ber_da_build_value }
 ;
 static decode_as_t ber_da = {
 "ber" , "ASN.1" , "ber.syntax" , 1 , 0 , & ber_da_values , NULL , NULL , ber_populate_list , ber_decode_as_reset , ber_decode_as_change , NULL }
 ;
 module_t * ber_module ;
 expert_module_t * expert_ber ;
 uat_t * users_uat = uat_new ( "OID Tables" , sizeof ( oid_user_t ) , "oid" , FALSE , & oid_users , & num_oid_users , UAT_AFFECTS_DISSECTION , "ChObjectIdentifiers" , oid_copy_cb , NULL , oid_free_cb , ber_update_oids , users_flds ) ;
 proto_ber = proto_register_protocol ( "Basic Encoding Rules (ASN.1 X.690)" , "BER" , "ber" ) ;
 ber_handle = new_register_dissector ( "ber" , dissect_ber , proto_ber ) ;
 proto_register_field_array ( proto_ber , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_ber = expert_register_protocol ( proto_ber ) ;
 expert_register_field_array ( expert_ber , ei , array_length ( ei ) ) ;
 proto_set_cant_toggle ( proto_ber ) ;
 ber_module = prefs_register_protocol ( proto_ber , NULL ) ;
 prefs_register_bool_preference ( ber_module , "show_internals" , "Show internal BER encapsulation tokens" , "Whether the dissector should also display internal" " ASN.1 BER details such as Identifier and Length fields" , & show_internal_ber_fields ) ;
 prefs_register_bool_preference ( ber_module , "decode_unexpected" , "Decode unexpected tags as BER encoded data" , "Whether the dissector should decode unexpected tags as" " ASN.1 BER encoded data" , & decode_unexpected ) ;
 prefs_register_bool_preference ( ber_module , "decode_octetstring" , "Decode OCTET STRING as BER encoded data" , "Whether the dissector should try decoding OCTET STRINGs as" " constructed ASN.1 BER encoded data" , & decode_octetstring_as_ber ) ;
 prefs_register_bool_preference ( ber_module , "decode_primitive" , "Decode Primitive as BER encoded data" , "Whether the dissector should try decoding unknown primitive as" " constructed ASN.1 BER encoded data" , & decode_primitive_as_ber ) ;
 prefs_register_bool_preference ( ber_module , "warn_too_many_bytes" , "Warn if too many leading zero bits in encoded data" , "Whether the dissector should warn if excessive leading zero (0) bits" , & decode_warning_leading_zero_bits ) ;
 prefs_register_uat_preference ( ber_module , "oid_table" , "Object Identifiers" , "A table that provides names for object identifiers" " and the syntax of any associated values" , users_uat ) ;
 ber_oid_dissector_table = register_dissector_table ( "ber.oid" , "BER OID Dissectors" , FT_STRING , BASE_NONE , DISSECTOR_TABLE_ALLOW_DUPLICATE ) ;
 ber_syntax_dissector_table = register_dissector_table ( "ber.syntax" , "BER syntax" , FT_STRING , BASE_NONE , DISSECTOR_TABLE_ALLOW_DUPLICATE ) ;
 syntax_table = g_hash_table_new ( g_str_hash , g_str_equal ) ;
 register_ber_syntax_dissector ( "ASN.1" , proto_ber , dissect_ber_syntax ) ;
 register_init_routine ( ber_defragment_init ) ;
 register_cleanup_routine ( ber_defragment_cleanup ) ;
 register_decode_as ( & ber_da ) ;
 }
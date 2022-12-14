void proto_register_AllJoyn ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_alljoyn_ns_header , {
 "Header" , "alljoyn.header" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_sender_version , {
 "Sender Version" , "alljoyn.header.sendversion" , FT_UINT8 , BASE_DEC , NULL , 0xF0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_message_version , {
 "Message Version" , "alljoyn.header.messageversion" , FT_UINT8 , BASE_DEC , NULL , 0x0F , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_questions , {
 "Questions" , "alljoyn.header.questions" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_answers , {
 "Answers" , "alljoyn.header.answers" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_timer , {
 "Timer" , "alljoyn.header.timer" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_whohas , {
 "Who-Has Message" , "alljoyn.whohas" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_whohas_t_flag , {
 "TCP" , "alljoyn.whohas.T" , FT_BOOLEAN , 8 , NULL , WHOHAS_T , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_whohas_u_flag , {
 "UDP" , "alljoyn.whohas.U" , FT_BOOLEAN , 8 , NULL , WHOHAS_U , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_whohas_s_flag , {
 "IPv6" , "alljoyn.whohas.S" , FT_BOOLEAN , 8 , NULL , WHOHAS_S , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_whohas_f_flag , {
 "IPv4" , "alljoyn.whohas.F" , FT_BOOLEAN , 8 , NULL , WHOHAS_F , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_whohas_count , {
 "Count" , "alljoyn.whohas.count" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_answer , {
 "Is-At Message" , "alljoyn.isat" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_isat_entry , {
 "Advertisement Entry" , "alljoyn.isat_entry" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_isat_guid_string , {
 "GUID String" , "alljoyn.isat_guid_string" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_g_flag , {
 "GUID" , "alljoyn.isat.G" , FT_BOOLEAN , 8 , NULL , ISAT_G , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_c_flag , {
 "Complete" , "alljoyn.isat.C" , FT_BOOLEAN , 8 , NULL , ISAT_C , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_count , {
 "Count" , "alljoyn.isat.count" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_ipv6 , {
 "IPv6 Address" , "alljoyn.isat.ipv6" , FT_IPv6 , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_ipv4 , {
 "IPv4 Address" , "alljoyn.isat.ipv4" , FT_IPv4 , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_t_flag , {
 "TCP" , "alljoyn.isat.T" , FT_BOOLEAN , 8 , NULL , ISAT_T , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_u_flag , {
 "UDP" , "alljoyn.isat.U" , FT_BOOLEAN , 8 , NULL , ISAT_U , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_s_flag , {
 "IPv6" , "alljoyn.isat.S" , FT_BOOLEAN , 8 , NULL , ISAT_S , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_f_flag , {
 "IPv4" , "alljoyn.isat.F" , FT_BOOLEAN , 8 , NULL , ISAT_F , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_port , {
 "Port" , "alljoyn.isat.port" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_u6_flag , {
 "IPv6 UDP" , "alljoyn.isat.U6" , FT_BOOLEAN , 8 , NULL , ISAT_U6 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_r6_flag , {
 "IPv6 TCP" , "alljoyn.isat.R6" , FT_BOOLEAN , 8 , NULL , ISAT_R6 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_u4_flag , {
 "IPv4 UDP" , "alljoyn.isat.U4" , FT_BOOLEAN , 8 , NULL , ISAT_U4 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_r4_flag , {
 "IPv4 TCP" , "alljoyn.isat.R4" , FT_BOOLEAN , 8 , NULL , ISAT_R4 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask , {
 "Transport Mask" , "alljoyn.isat.TransportMask" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_local , {
 "Local Transport" , "alljoyn.isat.TransportMask.Local" , FT_BOOLEAN , 16 , NULL , TRANSPORT_LOCAL , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_bluetooth , {
 "Bluetooth Transport" , "alljoyn.isat.TransportMask.Bluetooth" , FT_BOOLEAN , 16 , NULL , TRANSPORT_BLUETOOTH , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_tcp , {
 "TCP Transport" , "alljoyn.isat.TransportMask.TCP" , FT_BOOLEAN , 16 , NULL , TRANSPORT_TCP , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_wwan , {
 "Wirelesss WAN Transport" , "alljoyn.isat.TransportMask.WWAN" , FT_BOOLEAN , 16 , NULL , TRANSPORT_WWAN , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_lan , {
 "Wired LAN Transport" , "alljoyn.isat.TransportMask.LAN" , FT_BOOLEAN , 16 , NULL , TRANSPORT_LAN , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_ice , {
 "ICE protocol Transport" , "alljoyn.isat.TransportMask.ICE" , FT_BOOLEAN , 16 , NULL , TRANSPORT_ICE , NULL , HFILL }
 }
 , {
 & hf_alljoyn_ns_isat_transport_mask_wfd , {
 "Wi-Fi Direct Transport" , "alljoyn.isat.TransportMask.WFD" , FT_BOOLEAN , 16 , NULL , TRANSPORT_WFD , NULL , HFILL }
 }
 , {
 & hf_alljoyn_connect_byte_value , {
 "Connect Initial Byte" , "alljoyn.InitialByte" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_sasl_command , {
 "SASL command" , "alljoyn.SASL.command" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_sasl_parameter , {
 "SASL parameter" , "alljoyn.SASL.parameter" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header , {
 "Message Header" , "alljoyn.mess_header" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_endian , {
 "Endianness" , "alljoyn.mess_header.endianess" , FT_UINT8 , BASE_DEC , VALS ( endian_encoding_vals ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_type , {
 "Message type" , "alljoyn.mess_header.type" , FT_UINT8 , BASE_DEC , VALS ( message_header_encoding_vals ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags , {
 "Flags" , "alljoyn.mess_header.flags" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_no_reply , {
 "No reply expected" , "alljoyn.mess_header.flags.noreply" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_NO_REPLY_EXPECTED , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_no_auto_start , {
 "No auto start" , "alljoyn.mess_header.flags.noautostart" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_NO_AUTO_START , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_allow_remote_msg , {
 "Allow remote messages" , "alljoyn.mess_header.flags.allowremotemessages" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_ALLOW_REMOTE_MSG , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_sessionless , {
 "Sessionless" , "alljoyn.mess_header.flags.sessionless" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_SESSIONLESS , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_global_broadcast , {
 "Allow global broadcast" , "alljoyn.mess_header.flags.globalbroadcast" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_GLOBAL_BROADCAST , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_compressed , {
 "Compressed" , "alljoyn.mess_header.flags.compressed" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_COMPRESSED , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_flags_encrypted , {
 "Encrypted" , "alljoyn.mess_header.flags.encrypted" , FT_BOOLEAN , 8 , NULL , MESSAGE_HEADER_FLAG_ENCRYPTED , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_majorversion , {
 "Major version" , "alljoyn.mess_header.majorversion" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_body_length , {
 "Body length" , "alljoyn.mess_header.bodylength" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_serial , {
 "Serial number" , "alljoyn.mess_header.serial" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_header_length , {
 "Header length" , "alljoyn.mess_header.headerlength" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_fields , {
 "Header fields" , "alljoyn.mess_header.fields" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_header_field , {
 "Header field" , "alljoyn.mess_header.field" , FT_UINT8 , BASE_HEX , VALS ( mess_header_field_encoding_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_header_fieldcode , {
 "Field code" , "alljoyn.message.fieldcode" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_header_typeid , {
 "Type ID" , "alljoyn.message.typeid" , FT_UINT8 , BASE_CUSTOM , CF_FUNC ( alljoyn_typeid ) , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_parameters , {
 "Parameters" , "alljoyn.parameters" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_array , {
 "Array" , "alljoyn.array" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_structure , {
 "struct" , "alljoyn.structure" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_dictionary_entry , {
 "dictionary entry" , "alljoyn.dictionary_entry" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_variant , {
 "Variant '" , "alljoyn.variant" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_signature_length , {
 "Signature length" , "alljoyn.parameter.signature_length" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_mess_body_signature , {
 "Signature" , "alljoyn.parameter.signature" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_boolean , {
 "Boolean" , "alljoyn.boolean" , FT_BOOLEAN , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_uint8 , {
 "Unsigned byte" , "alljoyn.uint8" , FT_UINT8 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_int16 , {
 "Signed int16" , "alljoyn.int16" , FT_INT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_uint16 , {
 "Unsigned int16" , "alljoyn.uint16" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_handle , {
 "Handle" , "alljoyn.handle" , FT_UINT32 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_int32 , {
 "Signed int32" , "alljoyn.int32" , FT_INT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_uint32 , {
 "Unsigned int32" , "alljoyn.uint32" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_int64 , {
 "Signed int64" , "alljoyn.int64" , FT_INT64 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_uint64 , {
 "Unsigned int64" , "alljoyn.uint64" , FT_UINT64 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_double , {
 "Double" , "alljoyn.double" , FT_DOUBLE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_padding , {
 "Padding" , "alljoyn.padding" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_string , {
 "Bus Name" , "alljoyn.string" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_string_size_8bit , {
 "String Size 8-bit" , "alljoyn.string.size8bit" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_string_size_32bit , {
 "String Size 32-bit" , "alljoyn.string.size32bit" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_alljoyn_string_data , {
 "String Data" , "alljoyn.string.data" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_syn_flag , {
 "SYN" , "ardp.hdr.SYN" , FT_BOOLEAN , 8 , NULL , ARDP_SYN , NULL , HFILL }
 }
 , {
 & hf_ardp_ack_flag , {
 "ACK" , "ardp.hdr.ACK" , FT_BOOLEAN , 8 , NULL , ARDP_ACK , NULL , HFILL }
 }
 , {
 & hf_ardp_eak_flag , {
 "EAK" , "ardp.hdr.EAK" , FT_BOOLEAN , 8 , NULL , ARDP_EAK , NULL , HFILL }
 }
 , {
 & hf_ardp_rst_flag , {
 "RST" , "ardp.hdr.RST" , FT_BOOLEAN , 8 , NULL , ARDP_RST , NULL , HFILL }
 }
 , {
 & hf_ardp_nul_flag , {
 "NUL" , "ardp.hdr.NUL" , FT_BOOLEAN , 8 , NULL , ARDP_NUL , NULL , HFILL }
 }
 , {
 & hf_ardp_unused_flag , {
 "UNUSED" , "ardp.hdr.UNUSED" , FT_BOOLEAN , 8 , NULL , ARDP_UNUSED , NULL , HFILL }
 }
 , {
 & hf_ardp_version_field , {
 "VER" , "ardp.hdr.ver" , FT_UINT8 , BASE_HEX , NULL , ARDP_VER , NULL , HFILL }
 }
 , {
 & hf_ardp_hlen , {
 "Header Length" , "ardp.hdr.hlen" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_src , {
 "Source Port" , "ardp.hdr.src" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_dst , {
 "Destination Port" , "ardp.hdr.dst" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_dlen , {
 "Data Length" , "ardp.hdr.dlen" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_seq , {
 "Sequence" , "ardp.hdr.seq" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_ack , {
 "Acknowledge" , "ardp.hdr.ack" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_ttl , {
 "Time to Live" , "ardp.hdr.ttl" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_lcs , {
 "Last Consumed Sequence" , "ardp.hdr.lcs" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_nsa , {
 "Next Sequence to ACK" , "ardp.hdr.nsa" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_fss , {
 "Fragment Starting Sequence" , "ardp.hdr.fss" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_fcnt , {
 "Fragment Count" , "ardp.hdr.fcnt" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_bmp , {
 "EACK Bitmap" , "ardp.hdr.bmp" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_segmax , {
 "Segment Max" , "ardp.hdr.segmentmax" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_segbmax , {
 "Segment Buffer Max" , "ardp.hdr.segmentbmax" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_dackt , {
 "Receiver's delayed ACK timeout" , "ardp.hdr.dackt" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_ardp_options , {
 "Options" , "ardp.hdr.options" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , }
 ;
 static gint * ett [ ] = {
 & ett_alljoyn_ns , & ett_alljoyn_ns_header , & ett_alljoyn_ns_answers , & ett_alljoyn_ns_guid_string , & ett_alljoyn_ns_isat_entry , & ett_alljoyn_ns_string , & ett_alljoyn_whohas , & ett_alljoyn_string , & ett_alljoyn_isat_entry , & ett_alljoyn_mess , & ett_alljoyn_header , & ett_alljoyn_header_flags , & ett_alljoyn_mess_header_field , & ett_alljoyn_mess_header , & ett_alljoyn_mess_body_parameters , & ett_alljoyn_ardp }
 ;
 proto_AllJoyn_ns = proto_register_protocol ( "AllJoyn Name Service Protocol" , "AllJoyn NS" , "ajns" ) ;
 proto_AllJoyn_mess = proto_register_protocol ( "AllJoyn Message Protocol" , "AllJoyn" , "aj" ) ;
 proto_register_field_array ( proto_AllJoyn_ns , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 proto_AllJoyn_ardp = proto_register_protocol ( "AllJoyn Reliable Datagram Protocol" , "AllJoyn ARDP" , "ardp" ) ;
 }
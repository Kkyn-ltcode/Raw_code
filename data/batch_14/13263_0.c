void proto_register_t38 ( void ) {
 static hf_register_info hf [ ] = {
 # line 1 "../../asn1/t38/packet-t38-hfarr.c" {
 & hf_t38_IFPPacket_PDU , {
 "IFPPacket" , "t38.IFPPacket_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_UDPTLPacket_PDU , {
 "UDPTLPacket" , "t38.UDPTLPacket_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_type_of_msg , {
 "type-of-msg" , "t38.type_of_msg" , FT_UINT32 , BASE_DEC , VALS ( t38_Type_of_msg_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_data_field , {
 "data-field" , "t38.data_field" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_t30_indicator , {
 "t30-indicator" , "t38.t30_indicator" , FT_UINT32 , BASE_DEC , VALS ( t38_T30_indicator_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_t30_data , {
 "t30-data" , "t38.t30_data" , FT_UINT32 , BASE_DEC , VALS ( t38_T30_data_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_Data_Field_item , {
 "Data-Field item" , "t38.Data_Field_item_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_field_type , {
 "field-type" , "t38.field_type" , FT_UINT32 , BASE_DEC , VALS ( t38_T_field_type_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_field_data , {
 "field-data" , "t38.field_data" , FT_BYTES , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_seq_number , {
 "seq-number" , "t38.seq_number" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_primary_ifp_packet , {
 "primary-ifp-packet" , "t38.primary_ifp_packet_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_error_recovery , {
 "error-recovery" , "t38.error_recovery" , FT_UINT32 , BASE_DEC , VALS ( t38_T_error_recovery_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_secondary_ifp_packets , {
 "secondary-ifp-packets" , "t38.secondary_ifp_packets" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_secondary_ifp_packets_item , {
 "secondary-ifp-packets item" , "t38.secondary_ifp_packets_item_element" , FT_NONE , BASE_NONE , NULL , 0 , "OpenType_IFPPacket" , HFILL }
 }
 , {
 & hf_t38_fec_info , {
 "fec-info" , "t38.fec_info_element" , FT_NONE , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_fec_npackets , {
 "fec-npackets" , "t38.fec_npackets" , FT_INT32 , BASE_DEC , NULL , 0 , "INTEGER" , HFILL }
 }
 , {
 & hf_t38_fec_data , {
 "fec-data" , "t38.fec_data" , FT_UINT32 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_t38_fec_data_item , {
 "fec-data item" , "t38.fec_data_item" , FT_BYTES , BASE_NONE , NULL , 0 , "OCTET_STRING" , HFILL }
 }
 , # line 659 "../../asn1/t38/packet-t38-template.c" {
 & hf_t38_setup , {
 "Stream setup" , "t38.setup" , FT_STRING , BASE_NONE , NULL , 0x0 , "Stream setup, method and frame number" , HFILL }
 }
 , {
 & hf_t38_setup_frame , {
 "Stream frame" , "t38.setup-frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , "Frame that set up this stream" , HFILL }
 }
 , {
 & hf_t38_setup_method , {
 "Stream Method" , "t38.setup-method" , FT_STRING , BASE_NONE , NULL , 0x0 , "Method used to set up this stream" , HFILL }
 }
 , {
 & hf_t38_fragments , {
 "Message fragments" , "t38.fragments" , FT_NONE , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment , {
 "Message fragment" , "t38.fragment" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment_overlap , {
 "Message fragment overlap" , "t38.fragment.overlap" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment_overlap_conflicts , {
 "Message fragment overlapping with conflicting data" , "t38.fragment.overlap.conflicts" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment_multiple_tails , {
 "Message has multiple tail fragments" , "t38.fragment.multiple_tails" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment_too_long_fragment , {
 "Message fragment too long" , "t38.fragment.too_long_fragment" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment_error , {
 "Message defragmentation error" , "t38.fragment.error" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_t38_fragment_count , {
 "Message fragment count" , "t38.fragment.count" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_t38_reassembled_in , {
 "Reassembled in" , "t38.reassembled.in" , FT_FRAMENUM , BASE_NONE , NULL , 0x00 , NULL , HFILL }
 }
 , {
 & hf_t38_reassembled_length , {
 "Reassembled T38 length" , "t38.reassembled.length" , FT_UINT32 , BASE_DEC , NULL , 0x00 , NULL , HFILL }
 }
 , }
 ;
 static gint * ett [ ] = {
 & ett_t38 , # line 1 "../../asn1/t38/packet-t38-ettarr.c" & ett_t38_IFPPacket , & ett_t38_Type_of_msg , & ett_t38_Data_Field , & ett_t38_Data_Field_item , & ett_t38_UDPTLPacket , & ett_t38_T_error_recovery , & ett_t38_T_secondary_ifp_packets , & ett_t38_T_fec_info , & ett_t38_T_fec_data , # line 706 "../../asn1/t38/packet-t38-template.c" & ett_t38_setup , & ett_data_fragment , & ett_data_fragments }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_t38_malformed , {
 "t38.malformed" , PI_MALFORMED , PI_ERROR , "Malformed packet" , EXPFILL }
 }
 , }
 ;
 module_t * t38_module ;
 expert_module_t * expert_t38 ;
 proto_t38 = proto_register_protocol ( "T.38" , "T.38" , "t38" ) ;
 proto_register_field_array ( proto_t38 , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_t38 = expert_register_protocol ( proto_t38 ) ;
 expert_register_field_array ( expert_t38 , ei , array_length ( ei ) ) ;
 register_dissector ( "t38_udp" , dissect_t38_udp , proto_t38 ) ;
 register_init_routine ( t38_defragment_init ) ;
 register_cleanup_routine ( t38_defragment_cleanup ) ;
 t38_tap = register_tap ( "t38" ) ;
 t38_module = prefs_register_protocol ( proto_t38 , proto_reg_handoff_t38 ) ;
 prefs_register_bool_preference ( t38_module , "use_pre_corrigendum_asn1_specification" , "Use the Pre-Corrigendum ASN.1 specification" , "Whether the T.38 dissector should decode using the Pre-Corrigendum T.38 " "ASN.1 specification (1998)." , & use_pre_corrigendum_asn1_specification ) ;
 prefs_register_bool_preference ( t38_module , "dissect_possible_rtpv2_packets_as_rtp" , "Dissect possible RTP version 2 packets with RTP dissector" , "Whether a UDP packet that looks like RTP version 2 packet will " "be dissected as RTP packet or T.38 packet. If enabled there is a risk that T.38 UDPTL " "packets with sequence number higher than 32767 may be dissected as RTP." , & dissect_possible_rtpv2_packets_as_rtp ) ;
 prefs_register_uint_preference ( t38_module , "tcp.port" , "T.38 TCP Port" , "Set the TCP port for T.38 messages" , 10 , & global_t38_tcp_port ) ;
 prefs_register_uint_preference ( t38_module , "udp.port" , "T.38 UDP Port" , "Set the UDP port for T.38 messages" , 10 , & global_t38_udp_port ) ;
 prefs_register_bool_preference ( t38_module , "reassembly" , "Reassemble T.38 PDUs over TPKT over TCP" , "Whether the dissector should reassemble T.38 PDUs spanning multiple TCP segments " "when TPKT is used over TCP. " "To use this option, you must also enable \"Allow subdissectors to reassemble " "TCP streams\" in the TCP protocol settings." , & t38_tpkt_reassembly ) ;
 prefs_register_enum_preference ( t38_module , "tpkt_usage" , "TPKT used over TCP" , "Whether T.38 is used with TPKT for TCP" , ( gint * ) & t38_tpkt_usage , t38_tpkt_options , FALSE ) ;
 prefs_register_bool_preference ( t38_module , "show_setup_info" , "Show stream setup information" , "Where available, show which protocol and frame caused " "this T.38 stream to be created" , & global_t38_show_setup_info ) ;
 }
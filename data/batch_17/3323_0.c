void proto_register_rtp ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_rtp_version , {
 "Version" , "rtp.version" , FT_UINT8 , BASE_DEC , VALS ( rtp_version_vals ) , 0xC0 , NULL , HFILL }
 }
 , {
 & hf_rtp_padding , {
 "Padding" , "rtp.padding" , FT_BOOLEAN , 8 , NULL , 0x20 , NULL , HFILL }
 }
 , {
 & hf_rtp_extension , {
 "Extension" , "rtp.ext" , FT_BOOLEAN , 8 , NULL , 0x10 , NULL , HFILL }
 }
 , {
 & hf_rtp_csrc_count , {
 "Contributing source identifiers count" , "rtp.cc" , FT_UINT8 , BASE_DEC , NULL , 0x0F , NULL , HFILL }
 }
 , {
 & hf_rtp_marker , {
 "Marker" , "rtp.marker" , FT_BOOLEAN , 8 , NULL , 0x80 , NULL , HFILL }
 }
 , {
 & hf_rtp_payload_type , {
 "Payload type" , "rtp.p_type" , FT_UINT8 , BASE_DEC , NULL , 0x7F , NULL , HFILL }
 }
 , {
 & hf_rtp_seq_nr , {
 "Sequence number" , "rtp.seq" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_ext_seq_nr , {
 "Extended sequence number" , "rtp.extseq" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_timestamp , {
 "Timestamp" , "rtp.timestamp" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_ssrc , {
 "Synchronization Source identifier" , "rtp.ssrc" , FT_UINT32 , BASE_HEX_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_prof_define , {
 "Defined by profile" , "rtp.ext.profile" , FT_UINT16 , BASE_HEX_DEC , VALS ( rtp_ext_profile_vals ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_length , {
 "Extension length" , "rtp.ext.len" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_csrc_items , {
 "Contributing Source identifiers" , "rtp.csrc.items" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_csrc_item , {
 "CSRC item" , "rtp.csrc.item" , FT_UINT32 , BASE_HEX_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_exts , {
 "Header extensions" , "rtp.hdr_exts" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137s , {
 "ED137 extensions" , "rtp.ext.ed137s" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137 , {
 "ED137 extension" , "rtp.ext.ed137" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ptt_type , {
 "PTT Type" , "rtp.ext.ed137.ptt_type" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137_ptt_type ) , 0xE0000000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_squ , {
 "SQU" , "rtp.ext.ed137.squ" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137_squ ) , 0x10000000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ptt_id , {
 "PTT-id" , "rtp.ext.ed137.ptt_id" , FT_UINT32 , BASE_DEC , NULL , 0x0F000000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_sct , {
 "Simultaneous Call Transmissions" , "rtp.ext.ed137.sct" , FT_UINT32 , BASE_DEC , NULL , 0x00800000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_x , {
 "X" , "rtp.ext.ed137.x" , FT_UINT32 , BASE_DEC , NULL , 0x00400000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_x_nu , {
 "Not used" , "rtp.ext.ed137.x-nu" , FT_UINT32 , BASE_DEC , NULL , 0x003FFFFE , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_type , {
 "Feature type" , "rtp.ext.ed137.ft.type" , FT_UINT32 , BASE_HEX_DEC , VALS ( rtp_ext_ed137_ft_type ) , 0x003C0000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_len , {
 "Feature length" , "rtp.ext.ed137.ft.len" , FT_UINT32 , BASE_DEC , NULL , 0x0003C000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_value , {
 "Feature value" , "rtp.ext.ed137.ft.value" , FT_UINT32 , BASE_HEX_DEC , NULL , 0x00003FFE , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_vf , {
 "VF" , "rtp.ext.ed137.vf" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137_vf ) , 0x00000001 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_bss_qidx , {
 "BSS Quality Index" , "rtp.ext.ed137.ft.bss.qidx" , FT_UINT32 , BASE_DEC , NULL , 0x00003FC0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_bss_rssi_qidx , {
 "BSS Quality Index" , "rtp.ext.ed137.ft.bss.qidx" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137_ft_bss_rssi_qidx ) , 0x00003FC0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_bss_qidx_ml , {
 "BSS Quality Index Method" , "rtp.ext.ed137.ft.bss.qidx-ml" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137_ft_bss_qidx_ml ) , 0x00000038 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137_ft_bss_nu , {
 "Not used" , "rtp.ext.ed137.ft.bss-nu" , FT_UINT32 , BASE_DEC , NULL , 0x00000006 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a , {
 "ED137A extension" , "rtp.ext.ed137A" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_ptt_type , {
 "PTT Type" , "rtp.ext.ed137A.ptt_type" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137a_ptt_type ) , 0xE0000000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_squ , {
 "SQU" , "rtp.ext.ed137A.squ" , FT_UINT32 , BASE_DEC , VALS ( rtp_ext_ed137a_squ ) , 0x10000000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_ptt_id , {
 "PTT-id" , "rtp.ext.ed137A.ptt_id" , FT_UINT32 , BASE_DEC , NULL , 0x0FC00000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_pm , {
 "PTT Mute" , "rtp.ext.ed137A.pm" , FT_UINT32 , BASE_DEC , NULL , 0x00200000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_ptts , {
 "PTT Summation" , "rtp.ext.ed137A.ptts" , FT_UINT32 , BASE_DEC , NULL , 0x00100000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_sct , {
 "Simultaneous Call Transmissions" , "rtp.ext.ed137a.sct" , FT_UINT32 , BASE_DEC , NULL , 0x00080000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_reserved , {
 "Reserved" , "rtp.ext.ed137A.reserved" , FT_UINT32 , BASE_HEX_DEC , NULL , 0x00060000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_x , {
 "X" , "rtp.ext.ed137A.x" , FT_UINT32 , BASE_DEC , NULL , 0x00010000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_x_nu , {
 "Not used" , "rtp.ext.ed137A.x-nu" , FT_UINT32 , BASE_DEC , NULL , 0x0000FFFF , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_ft_type , {
 "Feature type" , "rtp.ext.ed137A.ft.type" , FT_UINT32 , BASE_HEX_DEC , VALS ( rtp_ext_ed137a_ft_type ) , 0x0000F000 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_ft_len , {
 "Feature length" , "rtp.ext.ed137A.ft.len" , FT_UINT32 , BASE_DEC , NULL , 0x00000F00 , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ed137a_ft_value , {
 "Feature value" , "rtp.ext.ed137A.ft.value" , FT_UINT32 , BASE_HEX_DEC , NULL , 0x000000FF , NULL , HFILL }
 }
 , {
 & hf_rtp_hdr_ext , {
 "Header extension" , "rtp.hdr_ext" , FT_UINT32 , BASE_HEX_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_data , {
 "Payload" , "rtp.payload" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_padding_data , {
 "Padding data" , "rtp.padding.data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_padding_count , {
 "Padding count" , "rtp.padding.count" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_setup , {
 "Stream setup" , "rtp.setup" , FT_STRING , BASE_NONE , NULL , 0x0 , "Stream setup, method and frame number" , HFILL }
 }
 , {
 & hf_rtp_setup_frame , {
 "Setup frame" , "rtp.setup-frame" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , "Frame that set up this stream" , HFILL }
 }
 , {
 & hf_rtp_setup_method , {
 "Setup Method" , "rtp.setup-method" , FT_STRING , BASE_NONE , NULL , 0x0 , "Method used to set up this stream" , HFILL }
 }
 , {
 & hf_rtp_rfc2198_follow , {
 "Follow" , "rtp.follow" , FT_BOOLEAN , 8 , TFS ( & tfs_set_notset ) , 0x80 , "Next header follows" , HFILL }
 }
 , {
 & hf_rtp_rfc2198_tm_off , {
 "Timestamp offset" , "rtp.timestamp-offset" , FT_UINT16 , BASE_DEC , NULL , 0xFFFC , NULL , HFILL }
 }
 , {
 & hf_rtp_rfc2198_bl_len , {
 "Block length" , "rtp.block-length" , FT_UINT16 , BASE_DEC , NULL , 0x03FF , NULL , HFILL }
 }
 , {
 & hf_rtp_ext_rfc5285_id , {
 "Identifier" , "rtp.ext.rfc5285.id" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "RFC 5285 Header Extension Identifier" , HFILL }
 }
 , {
 & hf_rtp_ext_rfc5285_length , {
 "Length" , "rtp.ext.rfc5285.len" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "RFC 5285 Header Extension length" , HFILL }
 }
 , {
 & hf_rtp_ext_rfc5285_appbits , {
 "Application Bits" , "rtp.ext.rfc5285.appbits" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "RFC 5285 2-bytes header application bits" , HFILL }
 }
 , {
 & hf_rtp_ext_rfc5285_data , {
 "Extension Data" , "rtp.ext.rfc5285.data" , FT_BYTES , BASE_NONE , NULL , 0x0 , "RFC 5285 Extension Data" , HFILL }
 }
 , {
 & hf_rtp_fragments , {
 "RTP Fragments" , "rtp.fragments" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_fragment , {
 "RTP Fragment data" , "rtp.fragment" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_fragment_overlap , {
 "Fragment overlap" , "rtp.fragment.overlap" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Fragment overlaps with other fragments" , HFILL }
 }
 , {
 & hf_rtp_fragment_overlap_conflict , {
 "Conflicting data in fragment overlap" , "rtp.fragment.overlap.conflict" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Overlapping fragments contained conflicting data" , HFILL }
 }
 , {
 & hf_rtp_fragment_multiple_tails , {
 "Multiple tail fragments found" , "rtp.fragment.multipletails" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Several tails were found when defragmenting the packet" , HFILL }
 }
 , {
 & hf_rtp_fragment_too_long_fragment , {
 "Fragment too long" , "rtp.fragment.toolongfragment" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Fragment contained data past end of packet" , HFILL }
 }
 , {
 & hf_rtp_fragment_error , {
 "Defragmentation error" , "rtp.fragment.error" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , "Defragmentation error due to illegal fragments" , HFILL }
 }
 , {
 & hf_rtp_fragment_count , {
 "Fragment count" , "rtp.fragment.count" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_rtp_reassembled_in , {
 "RTP fragment, reassembled in frame" , "rtp.reassembled_in" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , "This RTP packet is reassembled in this frame" , HFILL }
 }
 , {
 & hf_rtp_reassembled_length , {
 "Reassembled RTP length" , "rtp.reassembled.length" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "The total length of the reassembled payload" , HFILL }
 }
 , {
 & hf_srtp_encrypted_payload , {
 "SRTP Encrypted Payload" , "srtp.enc_payload" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_srtp_mki , {
 "SRTP MKI" , "srtp.mki" , FT_BYTES , BASE_NONE , NULL , 0x0 , "SRTP Master Key Index" , HFILL }
 }
 , {
 & hf_srtp_auth_tag , {
 "SRTP Auth Tag" , "srtp.auth_tag" , FT_BYTES , BASE_NONE , NULL , 0x0 , "SRTP Authentication Tag" , HFILL }
 }
 }
 ;
 static gint * ett [ ] = {
 & ett_rtp , & ett_csrc_list , & ett_hdr_ext , & ett_hdr_ext_rfc5285 , & ett_hdr_ext_ed137s , & ett_hdr_ext_ed137 , & ett_hdr_ext_ed137a , & ett_rtp_setup , & ett_rtp_rfc2198 , & ett_rtp_rfc2198_hdr , & ett_rtp_fragment , & ett_rtp_fragments }
 ;
 module_t * rtp_module ;
 proto_rtp = proto_register_protocol ( "Real-Time Transport Protocol" , "RTP" , "rtp" ) ;
 proto_register_field_array ( proto_rtp , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 new_register_dissector ( "rtp" , dissect_rtp , proto_rtp ) ;
 register_dissector ( "rtp.rfc2198" , dissect_rtp_rfc2198 , proto_rtp ) ;
 rtp_tap = register_tap ( "rtp" ) ;
 rtp_pt_dissector_table = register_dissector_table ( "rtp.pt" , "RTP payload type" , FT_UINT8 , BASE_DEC ) ;
 rtp_dyn_pt_dissector_table = register_dissector_table ( "rtp_dyn_payload_type" , "Dynamic RTP payload type" , FT_STRING , BASE_NONE ) ;
 rtp_hdr_ext_dissector_table = register_dissector_table ( "rtp.hdr_ext" , "RTP header extension" , FT_UINT32 , BASE_HEX ) ;
 rtp_hdr_ext_rfc5285_dissector_table = register_dissector_table ( "rtp.ext.rfc5285.id" , "RTP Generic header extension (RFC 5285)" , FT_UINT8 , BASE_DEC ) ;
 register_dissector ( "rtp.ext.ed137" , dissect_rtp_hdr_ext_ed137 , proto_rtp ) ;
 register_dissector ( "rtp.ext.ed137a" , dissect_rtp_hdr_ext_ed137a , proto_rtp ) ;
 rtp_module = prefs_register_protocol ( proto_rtp , proto_reg_handoff_rtp ) ;
 prefs_register_bool_preference ( rtp_module , "show_setup_info" , "Show stream setup information" , "Where available, show which protocol and frame caused " "this RTP stream to be created" , & global_rtp_show_setup_info ) ;
 prefs_register_bool_preference ( rtp_module , "heuristic_rtp" , "Try to decode RTP outside of conversations" , "If call control SIP/H323/RTSP/.. messages are missing in the trace, " "RTP isn't decoded without this" , & global_rtp_heur ) ;
 prefs_register_bool_preference ( rtp_module , "desegment_rtp_streams" , "Allow subdissector to reassemble RTP streams" , "Whether subdissector can request RTP streams to be reassembled" , & desegment_rtp ) ;
 prefs_register_enum_preference ( rtp_module , "version0_type" , "Treat RTP version 0 packets as" , "If an RTP version 0 packet is encountered, it can be treated as " "an invalid or ZRTP packet, a CLASSIC-STUN packet, or a T.38 packet" , & global_rtp_version0_type , rtp_version0_types , FALSE ) ;
 prefs_register_uint_preference ( rtp_module , "rfc2198_payload_type" , "Payload Type for RFC2198" , "Payload Type for RFC2198 Redundant Audio Data" , 10 , & rtp_rfc2198_pt ) ;
 register_init_routine ( rtp_fragment_init ) ;
 register_init_routine ( rtp_dyn_payloads_init ) ;
 }
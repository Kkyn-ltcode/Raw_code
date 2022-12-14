void proto_register_umts_mac ( void ) {
 module_t * mac_module ;
 static gint * ett [ ] = {
 & ett_mac , & ett_mac_fach , & ett_mac_rach , & ett_mac_dch , & ett_mac_pch , & ett_mac_edch , & ett_mac_hsdsch , & ett_mac_edch_type2 , & ett_mac_edch_type2_sdu }
 ;
 static hf_register_info hf [ ] = {
 {
 & hf_mac_rach_fdd_tctf , {
 "Target Channel Type Field" , "mac.tctf" , FT_UINT8 , BASE_HEX , VALS ( rach_fdd_tctf_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_mac_fach_fdd_tctf , {
 "Target Channel Type Field" , "mac.tctf" , FT_UINT8 , BASE_HEX , VALS ( fach_fdd_tctf_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_mac_ct , {
 "C/T" , "mac.ct" , FT_UINT8 , BASE_HEX , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mac_ueid_type , {
 "UEID Type" , "mac.ueid_type" , FT_UINT8 , BASE_DEC , VALS ( ueid_type_vals ) , 0 , NULL , HFILL }
 }
 , {
 & hf_mac_crnti , {
 "C-RNTI (UEID)" , "mac.ueid" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_mac_urnti , {
 "U-RNTI (UEID)" , "mac.ueid" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_mac_channel , {
 "Logical Channel Type" , "mac.logical_channel" , FT_UINT16 , BASE_DEC , VALS ( mac_logical_channel_vals ) , 0 , NULL , HFILL }
 }
 , # if 0 {
 & hf_mac_channel_str , {
 "Logical Channel" , "mac.logical_channel" , FT_STRING , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , # endif # if 0 {
 & hf_mac_channel_hsdsch , {
 "MACd-FlowID" , "mac.macd_flowid" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , # endif {
 & hf_mac_macdflowd_id , {
 "MACd-FlowID" , "mac.macd_flowid" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_mac_lch_id , {
 "Logical Channel ID" , "mac.logical_channel_id" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_mac_trch_id , {
 "Transport Channel ID" , "mac.transport_channel_id" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , # if 0 {
 & hf_mac_edch_type2_descriptors , {
 "MAC-is Descriptors" , "mac.edch.type2.descriptors" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , # endif # if 0 {
 & hf_mac_edch_type2_lchid , {
 "LCH-ID" , "mac.logical_channel_id" , FT_UINT8 , BASE_HEX , NULL , 0xf0 , NULL , HFILL }
 }
 , # endif # if 0 {
 & hf_mac_edch_type2_length , {
 "Length" , "mac.edch.type2.length" , FT_UINT16 , BASE_DEC , NULL , 0x0ffe , NULL , HFILL }
 }
 , # endif # if 0 {
 & hf_mac_edch_type2_flag , {
 "Flag" , "mac.edch.type2.lchid" , FT_UINT8 , BASE_HEX , NULL , 0x01 , "Indicates if another entry follows" , HFILL }
 }
 , # endif {
 & hf_mac_edch_type2_ss , {
 "SS" , "mac.edch.type2.ss" , FT_UINT8 , BASE_HEX , NULL , 0xc0 , "Segmentation Status" , HFILL }
 }
 , {
 & hf_mac_edch_type2_ss_interpretation , {
 "SS interpretation" , "mac.edch.type2.ss_interpretation" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_mac_edch_type2_tsn , {
 "TSN" , "mac.edch.type2.tsn" , FT_UINT16 , BASE_DEC , NULL , 0 , "Transmission Sequence Number" , HFILL }
 }
 , {
 & hf_mac_edch_type2_sdu , {
 "MAC-is SDU" , "mac.edch.type2.sdu" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_mac_edch_type2_sdu_data , {
 "Data" , "mac.edch.type2.sdu.data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , # if 0 {
 & hf_mac_edch_type2_subframe_header , {
 "Subframe header" , "mac.edch.type2.subframeheader" , FT_STRING , BASE_NONE , NULL , 0x0 , "EDCH Subframe header" , HFILL }
 }
 , # endif {
 & hf_mac_is_reasmin , {
 "Reassembled in frame" , "mac.is.reasmin" , FT_FRAMENUM , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_mac_is_fraglink , {
 "Frame" , "mac.is.fraglink" , FT_FRAMENUM , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_mac_per_frame_info_missing , {
 "mac.per_frame_info_missing" , PI_MALFORMED , PI_ERROR , "Cannot dissect MAC frame because per-frame info is missing" , EXPFILL }
 }
 , {
 & ei_mac_unknown_content , {
 "mac.unknown_content" , PI_MALFORMED , PI_ERROR , "Unknown RACH DCCH/DTCH Content" , EXPFILL }
 }
 , {
 & ei_mac_rach_tctf_unknown , {
 "mac.rach_tctf.unknown" , PI_MALFORMED , PI_ERROR , "Unknown RACH TCTF" , EXPFILL }
 }
 , {
 & ei_mac_cs_dtch_not_implemented , {
 "mac.cs_dtch.not_implemented" , PI_DEBUG , PI_ERROR , "CS DTCH Is not implemented" , EXPFILL }
 }
 , {
 & ei_mac_fach_content_type_unknown , {
 "mac.fach_content_type.unknown" , PI_UNDECODED , PI_WARN , " Unimplemented FACH Content type!" , EXPFILL }
 }
 , {
 & ei_mac_no_logical_channel , {
 "mac.no_logical_channel" , PI_PROTOCOL , PI_WARN , "Frame is missing logical channel" , EXPFILL }
 }
 , {
 & ei_mac_faked_logical_channel_id , {
 "mac.faked_logical_channel_id" , PI_PROTOCOL , PI_WARN , "This is a faked logical channel id!" , EXPFILL }
 }
 , {
 & ei_mac_macis_sdu_reassembled , {
 "mac.macis_sdu.reassembled" , PI_REASSEMBLE , PI_CHAT , "Reassembled MAC-is SDU" , EXPFILL }
 }
 , {
 & ei_mac_macis_sdu_first , {
 "mac.macis_sdu.first" , PI_REASSEMBLE , PI_CHAT , "This MAC-is SDU is the first segment of a MAC-d PDU or MAC-c PDU" , EXPFILL }
 }
 , {
 & ei_mac_macis_sdu_middle , {
 "mac.macis_sdu.middle" , PI_REASSEMBLE , PI_CHAT , "This MAC-is SDU is a middle segment of a MAC-d PDU or MAC-c PDU" , EXPFILL }
 }
 , {
 & ei_mac_macis_sdu_last , {
 "mac.macis_sdu.last" , PI_REASSEMBLE , PI_CHAT , "This MAC-is SDU is the last segment of a MAC-d PDU or MAC-c PDU" , EXPFILL }
 }
 , {
 & ei_mac_macis_sdu_complete , {
 "mac.macis_sdu.complete" , PI_REASSEMBLE , PI_CHAT , "This MAC-is SDU is a complete MAC-d PDU or MAC-c PDU" , EXPFILL }
 }
 , }
 ;
 expert_module_t * expert_umts_mac ;
 proto_umts_mac = proto_register_protocol ( "MAC" , "MAC" , "mac" ) ;
 proto_register_field_array ( proto_umts_mac , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_umts_mac = expert_register_protocol ( proto_umts_mac ) ;
 expert_register_field_array ( expert_umts_mac , ei , array_length ( ei ) ) ;
 register_dissector ( "mac.fdd.rach" , dissect_mac_fdd_rach , proto_umts_mac ) ;
 register_dissector ( "mac.fdd.fach" , dissect_mac_fdd_fach , proto_umts_mac ) ;
 register_dissector ( "mac.fdd.pch" , dissect_mac_fdd_pch , proto_umts_mac ) ;
 register_dissector ( "mac.fdd.dch" , dissect_mac_fdd_dch , proto_umts_mac ) ;
 register_dissector ( "mac.fdd.edch" , dissect_mac_fdd_edch , proto_umts_mac ) ;
 register_dissector ( "mac.fdd.edch.type2" , dissect_mac_fdd_edch_type2 , proto_umts_mac ) ;
 register_dissector ( "mac.fdd.hsdsch" , dissect_mac_fdd_hsdsch , proto_umts_mac ) ;
 register_init_routine ( mac_init ) ;
 register_cleanup_routine ( mac_cleanup ) ;
 mac_module = prefs_register_protocol ( proto_umts_mac , NULL ) ;
 prefs_register_enum_preference ( mac_module , "tsn_size" , "TSN size" , "TSN size in bits, either 6 or 14 bit" , & global_mac_tsn_size , tsn_size_enumvals , FALSE ) ;
 }
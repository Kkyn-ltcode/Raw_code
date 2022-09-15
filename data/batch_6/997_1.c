void proto_register_iax2 ( void ) {
 static hf_register_info hf [ ] = {
 {
 & hf_iax2_packet_type , {
 "Packet type" , "iax2.packet_type" , FT_UINT8 , BASE_DEC , VALS ( iax_packet_types ) , 0 , "Full/minivoice/minivideo/trunk packet" , HFILL }
 }
 , {
 & hf_iax2_callno , {
 "Call identifier" , "iax2.call" , FT_UINT32 , BASE_DEC , NULL , 0 , "This is the identifier Wireshark assigns to identify this call." " It does not correspond to any real field in the protocol" , HFILL }
 }
 , {
 & hf_iax2_scallno , {
 "Source call" , "iax2.src_call" , FT_UINT16 , BASE_DEC , NULL , 0x7FFF , "src_call holds the number of this call at the packet source pbx" , HFILL }
 }
 , {
 & hf_iax2_dcallno , {
 "Destination call" , "iax2.dst_call" , FT_UINT16 , BASE_DEC , NULL , 0x7FFF , "dst_call holds the number of this call at the packet destination" , HFILL }
 }
 , {
 & hf_iax2_retransmission , {
 "Retransmission" , "iax2.retransmission" , FT_BOOLEAN , 16 , NULL , 0x8000 , "retransmission is set if this packet is a retransmission of an earlier failed packet" , HFILL }
 }
 , {
 & hf_iax2_ts , {
 "Timestamp" , "iax2.timestamp" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "timestamp is the time, in ms after the start of this call, at which this packet was transmitted" , HFILL }
 }
 , {
 & hf_iax2_minits , {
 "Timestamp" , "iax2.timestamp" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "timestamp is the time, in ms after the start of this call, at which this packet was transmitted" , HFILL }
 }
 , {
 & hf_iax2_minividts , {
 "Timestamp" , "iax2.timestamp" , FT_UINT16 , BASE_DEC , NULL , 0x7FFF , "timestamp is the time, in ms after the start of this call, at which this packet was transmitted" , HFILL }
 }
 , {
 & hf_iax2_absts , {
 "Absolute Time" , "iax2.abstime" , FT_ABSOLUTE_TIME , ABSOLUTE_TIME_LOCAL , NULL , 0x0 , "The absolute time of this packet (calculated by adding the IAX timestamp to the start time of this call)" , HFILL }
 }
 , {
 & hf_iax2_lateness , {
 "Lateness" , "iax2.lateness" , FT_RELATIVE_TIME , BASE_NONE , NULL , 0x0 , "The lateness of this packet compared to its timestamp" , HFILL }
 }
 , {
 & hf_iax2_minividmarker , {
 "Marker" , "iax2.video.marker" , FT_UINT16 , BASE_DEC , NULL , 0x8000 , "RTP end-of-frame marker" , HFILL }
 }
 , {
 & hf_iax2_oseqno , {
 "Outbound seq.no." , "iax2.oseqno" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "oseqno is the sequence no of this packet. The first packet has oseqno==0," " and subsequent packets increment the oseqno by 1" , HFILL }
 }
 , {
 & hf_iax2_iseqno , {
 "Inbound seq.no." , "iax2.iseqno" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "iseqno is the sequence no of the last successfully received packet" , HFILL }
 }
 , {
 & hf_iax2_type , {
 "Type" , "iax2.type" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & iax_frame_types_ext , 0x0 , "For full IAX2 frames, type is the type of frame" , HFILL }
 }
 , {
 & hf_iax2_csub , {
 "Unknown subclass" , "iax2.subclass" , FT_UINT8 , BASE_DEC , NULL , 0x0 , "Subclass of unknown type of full IAX2 frame" , HFILL }
 }
 , {
 & hf_iax2_dtmf_csub , {
 "DTMF subclass (digit)" , "iax2.dtmf.subclass" , FT_STRINGZ , BASE_NONE , NULL , 0x0 , "DTMF subclass gives the DTMF digit" , HFILL }
 }
 , {
 & hf_iax2_cmd_csub , {
 "Control subclass" , "iax2.control.subclass" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & iax_cmd_subclasses_ext , 0x0 , "This gives the command number for a Control packet." , HFILL }
 }
 , {
 & hf_iax2_iax_csub , {
 "IAX subclass" , "iax2.iax.subclass" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & iax_iax_subclasses_ext , 0x0 , "IAX subclass gives the command number for IAX signaling packets" , HFILL }
 }
 , {
 & hf_iax2_voice_csub , {
 "Voice Subclass (compressed codec no)" , "iax2.voice.subclass" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_voice_codec , {
 "CODEC" , "iax2.voice.codec" , FT_UINT32 , BASE_HEX | BASE_EXT_STRING , & codec_types_ext , 0x0 , "CODEC gives the codec used to encode audio data" , HFILL }
 }
 , {
 & hf_iax2_video_csub , {
 "Video Subclass (compressed codec no)" , "iax2.video.subclass" , FT_UINT8 , BASE_DEC , NULL , 0xBF , NULL , HFILL }
 }
 , {
 & hf_iax2_marker , {
 "Marker" , "iax2.video.marker" , FT_BOOLEAN , 8 , NULL , 0x40 , "RTP end-of-frame marker" , HFILL }
 }
 , {
 & hf_iax2_video_codec , {
 "CODEC" , "iax2.video.codec" , FT_UINT32 , BASE_HEX | BASE_EXT_STRING , & codec_types_ext , 0 , "The codec used to encode video data" , HFILL }
 }
 , {
 & hf_iax2_modem_csub , {
 "Modem subclass" , "iax2.modem.subclass" , FT_UINT8 , BASE_DEC , VALS ( iax_modem_subclasses ) , 0x0 , "Modem subclass gives the type of modem" , HFILL }
 }
 , {
 & hf_iax2_text_csub , {
 "Text subclass" , "iax2.text.subclass" , FT_UINT8 , BASE_DEC , VALS ( iax_text_subclasses ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_text_text , {
 "Text" , "iax2.text.text" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_html_csub , {
 "HTML subclass" , "iax2.html.subclass" , FT_UINT8 , BASE_DEC , VALS ( iax_html_subclasses ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_html_url , {
 "HTML URL" , "iax2.html.url" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_trunk_ts , {
 "Timestamp" , "iax2.timestamp" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "timestamp is the time, in ms after the start of Command data this call," " at which this trunk packet was transmitted" , HFILL }
 }
 , {
 & hf_iax2_trunk_metacmd , {
 "Meta command" , "iax2.trunk.metacmd" , FT_UINT8 , BASE_DEC , NULL , 0x7F , "Meta command indicates whether or not the Meta Frame is a trunk." , HFILL }
 }
 , {
 & hf_iax2_trunk_cmddata , {
 "Command data" , "iax2.trunk.cmddata" , FT_UINT8 , BASE_HEX , NULL , 0x0 , "Flags for options that apply to a trunked call" , HFILL }
 }
 , {
 & hf_iax2_trunk_cmddata_ts , {
 "Trunk timestamps" , "iax2.trunk.cmddata.ts" , FT_BOOLEAN , 8 , NULL , IAX2_TRUNK_TS , "True: calls do each include their own timestamp" , HFILL }
 }
 , {
 & hf_iax2_trunk_call_len , {
 "Data length" , "iax2.trunk.call.len" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "Trunk call data length in octets" , HFILL }
 }
 , {
 & hf_iax2_trunk_call_scallno , {
 "Source call number" , "iax2.trunk.call.scallno" , FT_UINT16 , BASE_DEC , NULL , 0x7FFF , "Trunk call source call number" , HFILL }
 }
 , {
 & hf_iax2_trunk_call_ts , {
 "Timestamp" , "iax2.trunk.call.ts" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "timestamp is the time, in ms after the start of this call, at which this packet was transmitted" , HFILL }
 }
 , {
 & hf_iax2_trunk_call_data , {
 "Data" , "iax2.trunk.call.payload" , FT_BYTES , BASE_NONE , NULL , 0x0 , "Payload carried by this trunked packet." , HFILL }
 }
 , {
 & hf_iax2_trunk_ncalls , {
 "Number of calls" , "iax2.trunk.ncalls" , FT_UINT16 , BASE_DEC , NULL , 0x0 , "Number of calls in this trunk packet" , HFILL }
 }
 , {
 & hf_IAX_IE_APPARENTADDR_SINFAMILY , {
 "Family" , "iax2.iax.app_addr.sinfamily" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_IAX_IE_APPARENTADDR_SINPORT , {
 "Port" , "iax2.iax.app_addr.sinport" , FT_UINT16 , BASE_DEC , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_IAX_IE_APPARENTADDR_SINADDR , {
 "Address" , "iax2.iax.app_addr.sinaddr" , FT_IPv4 , BASE_NONE , NULL , 0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLED_NUMBER ] , {
 "Number/extension being called" , "iax2.iax.called_number" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLING_NUMBER ] , {
 "Calling number" , "iax2.iax.calling_number" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLING_ANI ] , {
 "Calling number ANI for billing" , "iax2.iax.calling_ani" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLING_NAME ] , {
 "Name of caller" , "iax2.iax.calling_name" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLED_CONTEXT ] , {
 "Context for number" , "iax2.iax.called_context" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_USERNAME ] , {
 "Username (peer or user) for authentication" , "iax2.iax.username" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_PASSWORD ] , {
 "Password for authentication" , "iax2.iax.password" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CAPABILITY ] , {
 "Actual codec capability" , "iax2.iax.capability" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_FORMAT ] , {
 "Desired codec format" , "iax2.iax.format" , FT_UINT32 , BASE_HEX | BASE_EXT_STRING , & codec_types_ext , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_LANGUAGE ] , {
 "Desired language" , "iax2.iax.language" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_VERSION ] , {
 "Protocol version" , "iax2.iax.version" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_ADSICPE ] , {
 "CPE ADSI capability" , "iax2.iax.cpe_adsi" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_DNID ] , {
 "Originally dialed DNID" , "iax2.iax.dnid" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_AUTHMETHODS ] , {
 "Authentication method(s)" , "iax2.iax.auth.methods" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CHALLENGE ] , {
 "Challenge data for MD5/RSA" , "iax2.iax.auth.challenge" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_MD5_RESULT ] , {
 "MD5 challenge result" , "iax2.iax.auth.md5" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RSA_RESULT ] , {
 "RSA challenge result" , "iax2.iax.auth.rsa" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_REFRESH ] , {
 "When to refresh registration" , "iax2.iax.refresh" , FT_INT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_DPSTATUS ] , {
 "Dialplan status" , "iax2.iax.dialplan_status" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLNO ] , {
 "Call number of peer" , "iax2.iax.call_no" , FT_UINT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CAUSE ] , {
 "Cause" , "iax2.iax.cause" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_IAX_UNKNOWN ] , {
 "Unknown IAX command" , "iax2.iax.iax_unknown" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_MSGCOUNT ] , {
 "How many messages waiting" , "iax2.iax.msg_count" , FT_INT16 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_AUTOANSWER ] , {
 "Request auto-answering" , "iax2.iax.autoanswer" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_MUSICONHOLD ] , {
 "Request musiconhold with QUELCH" , "iax2.iax.moh" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_TRANSFERID ] , {
 "Transfer Request Identifier" , "iax2.iax.transferid" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RDNIS ] , {
 "Referring DNIS" , "iax2.iax.rdnis" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_PROVISIONING ] , {
 "Provisioning info" , "iax2.iax.provisioning" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_AESPROVISIONING ] , {
 "AES Provisioning info" , "iax2.iax.aesprovisioning" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_DATETIME ] , {
 "Date/Time" , "iax2.iax.datetime.raw" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ie_datetime , {
 "Date/Time" , "iax2.iax.datetime" , FT_ABSOLUTE_TIME , ABSOLUTE_TIME_LOCAL , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_DEVICETYPE ] , {
 "Device type" , "iax2.iax.devicetype" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_SERVICEIDENT ] , {
 "Service identifier" , "iax2.iax.serviceident" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_FIRMWAREVER ] , {
 "Firmware version" , "iax2.iax.firmwarever" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_FWBLOCKDESC ] , {
 "Firmware block description" , "iax2.iax.fwblockdesc" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_FWBLOCKDATA ] , {
 "Firmware block of data" , "iax2.iax.fwblockdata" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_PROVVER ] , {
 "Provisioning version" , "iax2.iax.provver" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLINGPRES ] , {
 "Calling presentation" , "iax2.iax.callingpres" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLINGTON ] , {
 "Calling type of number" , "iax2.iax.callington" , FT_UINT8 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CALLINGTNS ] , {
 "Calling transit network select" , "iax2.iax.callingtns" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_SAMPLINGRATE ] , {
 "Supported sampling rates" , "iax2.iax.samplingrate" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CAUSECODE ] , {
 "Hangup cause" , "iax2.iax.causecode" , FT_UINT8 , BASE_HEX | BASE_EXT_STRING , & iax_causecodes_ext , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_ENCRYPTION ] , {
 "Encryption format" , "iax2.iax.encryption" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_ENCKEY ] , {
 "Encryption key" , "iax2.iax.enckey" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_CODEC_PREFS ] , {
 "Codec negotiation" , "iax2.iax.codecprefs" , FT_STRING , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RR_JITTER ] , {
 "Received jitter (as in RFC1889)" , "iax2.iax.rrjitter" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RR_LOSS ] , {
 "Received loss (high byte loss pct, low 24 bits loss count, as in rfc1889)" , "iax2.iax.rrloss" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RR_PKTS ] , {
 "Total frames received" , "iax2.iax.rrpkts" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RR_DELAY ] , {
 "Max playout delay in ms for received frames" , "iax2.iax.rrdelay" , FT_UINT16 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RR_DROPPED ] , {
 "Dropped frames (presumably by jitterbuffer)" , "iax2.iax.rrdropped" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_RR_OOO ] , {
 "Frame received out of order" , "iax2.iax.rrooo" , FT_UINT32 , BASE_HEX , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_ies [ IAX_IE_DATAFORMAT ] , {
 "Data call format" , "iax2.iax.dataformat" , FT_UINT32 , BASE_HEX , VALS ( iax_dataformats ) , 0x0 , NULL , HFILL }
 }
 , {
 & hf_IAX_IE_UNKNOWN_BYTE , {
 "Unknown" , "iax2.iax.unknownbyte" , FT_UINT8 , BASE_HEX , NULL , 0x0 , "Raw data for unknown IEs" , HFILL }
 }
 , {
 & hf_IAX_IE_UNKNOWN_I16 , {
 "Unknown" , "iax2.iax.unknownshort" , FT_UINT16 , BASE_HEX , NULL , 0x0 , "Raw data for unknown IEs" , HFILL }
 }
 , {
 & hf_IAX_IE_UNKNOWN_I32 , {
 "Unknown" , "iax2.iax.unknownlong" , FT_UINT32 , BASE_HEX , NULL , 0x0 , "Raw data for unknown IEs" , HFILL }
 }
 , {
 & hf_IAX_IE_UNKNOWN_BYTES , {
 "Unknown" , "iax2.iax.unknownstring" , FT_STRING , BASE_NONE , NULL , 0x0 , "Raw data for unknown IEs" , HFILL }
 }
 , {
 & hf_iax2_ie_id , {
 "IE id" , "iax2.ie_id" , FT_UINT8 , BASE_DEC | BASE_EXT_STRING , & iax_ies_type_ext , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_length , {
 "Length" , "iax2.length" , FT_UINT8 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_g723_1 , {
 "G.723.1 compression" , "iax2.cap.g723_1" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_G723_1 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_gsm , {
 "GSM compression" , "iax2.cap.gsm" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_GSM , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_ulaw , {
 "Raw mu-law data (G.711)" , "iax2.cap.ulaw" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_ULAW , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_alaw , {
 "Raw A-law data (G.711)" , "iax2.cap.alaw" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_ALAW , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_g726_aal2 , {
 "G.726 compression (AAL2 packing)" , "iax2.cap.g726_aal2" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_G726_AAL2 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_adpcm , {
 "ADPCM" , "iax2.cap.adpcm" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_ADPCM , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_slinear , {
 "Raw 16-bit Signed Linear (8000 Hz) PCM" , "iax2.cap.slinear" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_SLINEAR , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_lpc10 , {
 "LPC10, 180 samples/frame" , "iax2.cap.lpc10" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_LPC10 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_g729a , {
 "G.729a Audio" , "iax2.cap.g729a" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_G729A , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_speex , {
 "SPEEX Audio" , "iax2.cap.speex" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_SPEEX , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_ilbc , {
 "iLBC Free compressed Audio" , "iax2.cap.ilbc" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_ILBC , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_g726 , {
 "ADPCM (G.726, 32kbps, RFC3551 codeword packing)" , "iax2.cap.g726" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_G726 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_g722 , {
 "G.722 wideband audio" , "iax2.cap.g722" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_G722 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_siren7 , {
 "G.722.1 (also known as Siren7, 32kbps assumed)" , "iax2.cap.siren7" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_SIREN7 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_siren14 , {
 "G.722.1 Annex C (also known as Siren14, 48kbps assumed)" , "iax2.cap.siren14" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_SIREN14 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_slinear16 , {
 "Raw 16-bit Signed Linear (16000 Hz) PCM" , "iax2.cap.slinear16" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_SLINEAR16 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_jpeg , {
 "JPEG images" , "iax2.cap.jpeg" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_JPEG , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_png , {
 "PNG images" , "iax2.cap.png" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_PNG , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_h261 , {
 "H.261 video" , "iax2.cap.h261" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_H261 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_h263 , {
 "H.263 video" , "iax2.cap.h263" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_H263 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_h263_plus , {
 "H.263+ video" , "iax2.cap.h263_plus" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_H263_PLUS , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_h264 , {
 "H.264 video" , "iax2.cap.h264" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_H264 , NULL , HFILL }
 }
 , {
 & hf_iax2_cap_mpeg4 , {
 "MPEG4 video" , "iax2.cap.mpeg4" , FT_BOOLEAN , 32 , TFS ( & tfs_supported_not_supported ) , AST_FORMAT_MP4_VIDEO , NULL , HFILL }
 }
 , {
 & hf_iax2_fragment_unfinished , {
 "IAX2 fragment, unfinished" , "iax2.fragment_unfinished" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_payload_data , {
 "IAX2 payload" , "iax2.payload_data" , FT_BYTES , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_fragments , {
 "IAX2 Fragments" , "iax2.fragments" , FT_NONE , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_fragment , {
 "IAX2 Fragment data" , "iax2.fragment" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_fragment_overlap , {
 "Fragment overlap" , "iax2.fragment.overlap" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Fragment overlaps with other fragments" , HFILL }
 }
 , {
 & hf_iax2_fragment_overlap_conflict , {
 "Conflicting data in fragment overlap" , "iax2.fragment.overlap.conflict" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Overlapping fragments contained conflicting data" , HFILL }
 }
 , {
 & hf_iax2_fragment_multiple_tails , {
 "Multiple tail fragments found" , "iax2.fragment.multipletails" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Several tails were found when defragmenting the packet" , HFILL }
 }
 , {
 & hf_iax2_fragment_too_long_fragment , {
 "Fragment too long" , "iax2.fragment.toolongfragment" , FT_BOOLEAN , BASE_NONE , NULL , 0x0 , "Fragment contained data past end of packet" , HFILL }
 }
 , {
 & hf_iax2_fragment_error , {
 "Defragmentation error" , "iax2.fragment.error" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , "Defragmentation error due to illegal fragments" , HFILL }
 }
 , {
 & hf_iax2_fragment_count , {
 "Fragment count" , "iax2.fragment.count" , FT_UINT32 , BASE_DEC , NULL , 0x0 , NULL , HFILL }
 }
 , {
 & hf_iax2_reassembled_in , {
 "IAX2 fragment, reassembled in frame" , "iax2.reassembled_in" , FT_FRAMENUM , BASE_NONE , NULL , 0x0 , "This IAX2 packet is reassembled in this frame" , HFILL }
 }
 , {
 & hf_iax2_reassembled_length , {
 "Reassembled IAX2 length" , "iax2.reassembled.length" , FT_UINT32 , BASE_DEC , NULL , 0x0 , "The total length of the reassembled payload" , HFILL }
 }
 }
 ;
 static gint * ett [ ] = {
 & ett_iax2 , & ett_iax2_full_mini_subtree , & ett_iax2_type , & ett_iax2_ie , & ett_iax2_codecs , & ett_iax2_ies_apparent_addr , & ett_iax2_fragment , & ett_iax2_fragments , & ett_iax2_trunk_cmddata , & ett_iax2_trunk_call }
 ;
 static ei_register_info ei [ ] = {
 {
 & ei_iax_too_many_transfers , {
 "iax2.too_many_transfers" , PI_PROTOCOL , PI_WARN , "Too many transfers for iax_call" , EXPFILL }
 }
 , {
 & ei_iax_circuit_id_conflict , {
 "iax2.circuit_id_conflict" , PI_PROTOCOL , PI_WARN , "Circuit ID conflict" , EXPFILL }
 }
 , {
 & ei_iax_peer_address_unsupported , {
 "iax2.peer_address_unsupported" , PI_PROTOCOL , PI_WARN , "Peer address unsupported" , EXPFILL }
 }
 , {
 & ei_iax_invalid_len , {
 "iax2.invalid_len" , PI_PROTOCOL , PI_WARN , "Invalid length" , EXPFILL }
 }
 }
 ;
 expert_module_t * expert_iax ;
 memset ( hf_iax2_ies , 0xff , sizeof ( hf_iax2_ies ) ) ;
 proto_iax2 = proto_register_protocol ( "Inter-Asterisk eXchange v2" , "IAX2" , "iax2" ) ;
 proto_register_field_array ( proto_iax2 , hf , array_length ( hf ) ) ;
 proto_register_subtree_array ( ett , array_length ( ett ) ) ;
 expert_iax = expert_register_protocol ( proto_iax2 ) ;
 expert_register_field_array ( expert_iax , ei , array_length ( ei ) ) ;
 register_dissector ( "iax2" , dissect_iax2 , proto_iax2 ) ;
 iax2_codec_dissector_table = register_dissector_table ( "iax2.codec" , "IAX codec number" , FT_UINT32 , BASE_HEX ) ;
 iax2_dataformat_dissector_table = register_dissector_table ( "iax2.dataformat" , "IAX dataformat number" , FT_UINT32 , BASE_HEX ) ;
 register_init_routine ( & iax_init_protocol ) ;
 register_cleanup_routine ( & iax_cleanup_protocol ) ;
 iax2_tap = register_tap ( "IAX2" ) ;
 }
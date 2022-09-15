static int dissct_rsl_ipaccess_msg ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , int offset ) {
 guint8 msg_type ;
 guint32 local_addr = 0 ;
 guint16 local_port = 0 ;
 address src_addr ;
 msg_type = tvb_get_guint8 ( tvb , offset ) & 0x7f ;
 offset ++ ;
 while ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 guint8 tag ;
 unsigned int len , hlen ;
 const struct tlv_def * tdef ;
 proto_item * ti ;
 proto_tree * ie_tree ;
 tag = tvb_get_guint8 ( tvb , offset ) ;
 tdef = & rsl_att_tlvdef . def [ tag ] ;
 switch ( tdef -> type ) {
 case TLV_TYPE_FIXED : hlen = 1 ;
 len = tdef -> fixed_len ;
 break ;
 case TLV_TYPE_T : hlen = 1 ;
 len = 0 ;
 break ;
 case TLV_TYPE_TV : hlen = 1 ;
 len = 1 ;
 break ;
 case TLV_TYPE_TLV : hlen = 2 ;
 len = tvb_get_guint8 ( tvb , offset + 1 ) ;
 break ;
 case TLV_TYPE_TL16V : hlen = 3 ;
 len = tvb_get_guint8 ( tvb , offset + 1 ) << 8 | tvb_get_guint8 ( tvb , offset + 2 ) ;
 break ;
 case TLV_TYPE_UNKNOWN : default : DISSECTOR_ASSERT_NOT_REACHED ( ) ;
 break ;
 }
 ti = proto_tree_add_item ( tree , hf_rsl_ie_id , tvb , offset , 1 , ENC_BIG_ENDIAN ) ;
 ie_tree = proto_item_add_subtree ( ti , ett_ie_local_port ) ;
 offset += hlen ;
 switch ( tag ) {
 case RSL_IE_CH_NO : dissect_rsl_ie_ch_no ( tvb , pinfo , ie_tree , offset , FALSE ) ;
 break ;
 case RSL_IE_FRAME_NO : dissect_rsl_ie_frame_no ( tvb , pinfo , ie_tree , offset , FALSE ) ;
 break ;
 case RSL_IE_MS_POW : dissect_rsl_ie_ms_pow ( tvb , pinfo , ie_tree , offset , FALSE ) ;
 break ;
 case RSL_IE_IPAC_REMOTE_IP : proto_tree_add_item ( ie_tree , hf_rsl_remote_ip , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 break ;
 case RSL_IE_IPAC_REMOTE_PORT : proto_tree_add_item ( ie_tree , hf_rsl_remote_port , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 break ;
 case RSL_IE_IPAC_LOCAL_IP : proto_tree_add_item ( ie_tree , hf_rsl_local_ip , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 local_addr = tvb_get_ipv4 ( tvb , offset ) ;
 break ;
 case RSL_IE_IPAC_LOCAL_PORT : proto_tree_add_item ( ie_tree , hf_rsl_local_port , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 local_port = tvb_get_ntohs ( tvb , offset ) ;
 break ;
 case RSL_IE_IPAC_SPEECH_MODE : proto_tree_add_item ( ie_tree , hf_rsl_speech_mode_s , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_speech_mode_m , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 break ;
 case RSL_IE_IPAC_RTP_PAYLOAD : case RSL_IE_IPAC_RTP_PAYLOAD2 : proto_tree_add_item ( ie_tree , hf_rsl_rtp_payload , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 break ;
 case RSL_IE_IPAC_RTP_CSD_FMT : proto_tree_add_item ( ie_tree , hf_rsl_rtp_csd_fmt_d , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_rtp_csd_fmt_ir , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 break ;
 case RSL_IE_IPAC_CONN_ID : proto_tree_add_item ( ie_tree , hf_rsl_conn_id , tvb , offset , len , ENC_BIG_ENDIAN ) ;
 break ;
 case RSL_IE_IPAC_CONN_STAT : proto_tree_add_item ( ie_tree , hf_rsl_cstat_tx_pkts , tvb , offset , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_cstat_tx_octs , tvb , offset + 4 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_cstat_rx_pkts , tvb , offset + 8 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_cstat_rx_octs , tvb , offset + 12 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_cstat_lost_pkts , tvb , offset + 16 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_cstat_ia_jitter , tvb , offset + 20 , 4 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( ie_tree , hf_rsl_cstat_avg_tx_dly , tvb , offset + 24 , 4 , ENC_BIG_ENDIAN ) ;
 break ;
 }
 offset += len ;
 }
 switch ( msg_type ) {
 case RSL_MSG_TYPE_IPAC_CRCX_ACK : src_addr . type = AT_IPv4 ;
 src_addr . len = 4 ;
 src_addr . data = ( guint8 * ) & local_addr ;
 rtp_add_address ( pinfo , & src_addr , local_port , 0 , "GSM A-bis/IP" , pinfo -> fd -> num , 0 , NULL ) ;
 rtcp_add_address ( pinfo , & src_addr , local_port + 1 , 0 , "GSM A-bis/IP" , pinfo -> fd -> num ) ;
 break ;
 }
 return offset ;
 }
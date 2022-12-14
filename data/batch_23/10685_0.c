static void dtap_cc_setup ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo _U_ , guint32 offset , guint len ) {
 guint32 curr_offset ;
 guint32 consumed ;
 guint curr_len ;
 curr_offset = offset ;
 curr_len = len ;
 is_uplink = IS_UPLINK_TRUE ;
 ELEM_OPT_TV_SHORT ( 0xd0 , GSM_A_PDU_TYPE_DTAP , DE_REPEAT_IND , " BC repeat indicator" ) ;
 ELEM_OPT_TLV ( 0x04 , GSM_A_PDU_TYPE_DTAP , DE_BEARER_CAP , " 1" ) ;
 ELEM_OPT_TLV ( 0x04 , GSM_A_PDU_TYPE_DTAP , DE_BEARER_CAP , " 2" ) ;
 ELEM_OPT_TLV ( 0x1c , GSM_A_PDU_TYPE_DTAP , DE_FACILITY , NULL ) ;
 ELEM_OPT_TLV ( 0x1e , GSM_A_PDU_TYPE_DTAP , DE_PROG_IND , NULL ) ;
 ELEM_OPT_TV ( 0x34 , GSM_A_PDU_TYPE_DTAP , DE_SIGNAL , NULL ) ;
 ELEM_OPT_TLV ( 0x5c , GSM_A_PDU_TYPE_DTAP , DE_CLG_PARTY_BCD_NUM , NULL ) ;
 ELEM_OPT_TLV ( 0x5d , GSM_A_PDU_TYPE_DTAP , DE_CLG_PARTY_SUB_ADDR , NULL ) ;
 ELEM_OPT_TLV ( 0x5e , GSM_A_PDU_TYPE_DTAP , DE_CLD_PARTY_BCD_NUM , NULL ) ;
 ELEM_OPT_TLV ( 0x6d , GSM_A_PDU_TYPE_DTAP , DE_CLD_PARTY_SUB_ADDR , NULL ) ;
 ELEM_OPT_TLV ( 0x74 , GSM_A_PDU_TYPE_DTAP , DE_RED_PARTY_BCD_NUM , NULL ) ;
 ELEM_OPT_TLV ( 0x75 , GSM_A_PDU_TYPE_DTAP , DE_RED_PARTY_SUB_ADDR , NULL ) ;
 ELEM_OPT_TV_SHORT ( 0xd0 , GSM_A_PDU_TYPE_DTAP , DE_REPEAT_IND , " LLC repeat indicator" ) ;
 ELEM_OPT_TLV ( 0x7c , GSM_A_PDU_TYPE_DTAP , DE_LLC , " 1" ) ;
 ELEM_OPT_TLV ( 0x7c , GSM_A_PDU_TYPE_DTAP , DE_LLC , " 2" ) ;
 ELEM_OPT_TV_SHORT ( 0xd0 , GSM_A_PDU_TYPE_DTAP , DE_REPEAT_IND , " HLC repeat indicator" ) ;
 ELEM_OPT_TLV ( 0x7d , GSM_A_PDU_TYPE_DTAP , DE_HLC , " 1" ) ;
 ELEM_OPT_TLV ( 0x7d , GSM_A_PDU_TYPE_DTAP , DE_HLC , " 2" ) ;
 ELEM_OPT_TLV ( 0x7e , GSM_A_PDU_TYPE_DTAP , DE_USER_USER , NULL ) ;
 ELEM_OPT_TV_SHORT ( 0x80 , GSM_A_PDU_TYPE_COMMON , DE_PRIO , NULL ) ;
 ELEM_OPT_TLV ( 0x19 , GSM_A_PDU_TYPE_DTAP , DE_ALERT_PATTERN , NULL ) ;
 ELEM_OPT_TLV ( 0x2f , GSM_A_PDU_TYPE_DTAP , DE_NET_CC_CAP , NULL ) ;
 ELEM_OPT_TLV ( 0x3a , GSM_A_PDU_TYPE_DTAP , DE_CAUSE_NO_CLI , NULL ) ;
 ELEM_OPT_TLV ( 0x41 , GSM_A_PDU_TYPE_DTAP , DE_BEARER_CAP , NULL ) ;
 ELEM_OPT_TLV ( 0x7f , GSM_A_PDU_TYPE_DTAP , DE_SS_VER_IND , NULL ) ;
 ELEM_OPT_T ( 0xa1 , GSM_A_PDU_TYPE_DTAP , DE_CLIR_SUP , NULL ) ;
 ELEM_OPT_T ( 0xa2 , GSM_A_PDU_TYPE_DTAP , DE_CLIR_INV , NULL ) ;
 ELEM_OPT_TLV ( 0x15 , GSM_A_PDU_TYPE_DTAP , DE_CC_CAP , NULL ) ;
 ELEM_OPT_TLV ( 0x1d , GSM_A_PDU_TYPE_DTAP , DE_FACILITY , " $(CCBS)$ (advanced recall alignment)" ) ;
 ELEM_OPT_TLV ( 0x1b , GSM_A_PDU_TYPE_DTAP , DE_FACILITY , " (recall alignment Not essential) $(CCBS)$" ) ;
 ELEM_OPT_TLV ( 0x2d , GSM_A_PDU_TYPE_DTAP , DE_SI , NULL ) ;
 ELEM_OPT_TLV ( 0x40 , GSM_A_PDU_TYPE_DTAP , DE_SUP_CODEC_LIST , NULL ) ;
 ELEM_OPT_T ( 0xA3 , GSM_A_PDU_TYPE_DTAP , DE_REDIAL , NULL ) ;
 EXTRANEOUS_DATA_CHECK ( curr_len , 0 , pinfo , & ei_gsm_a_dtap_extraneous_data ) ;
 }
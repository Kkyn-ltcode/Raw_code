static void dtap_gcc_setup ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo _U_ , guint32 offset , guint len ) {
 guint32 curr_offset ;
 guint32 consumed ;
 guint curr_len ;
 curr_offset = offset ;
 curr_len = len ;
 ELEM_MAND_V ( GSM_A_PDU_TYPE_DTAP , DE_GCC_CALL_REF , NULL ) ;
 ELEM_OPT_TLV ( 0x7e , GSM_A_PDU_TYPE_DTAP , DE_USER_USER , NULL ) ;
 }
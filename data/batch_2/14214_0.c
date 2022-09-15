static void dissect_u3v_read_mem_cmd ( proto_tree * u3v_telegram_tree , tvbuff_t * tvb , packet_info * pinfo , gint startoffset , gint length , u3v_conv_info_t * u3v_conv_info , gencp_transaction_t * gencp_trans ) {
 guint64 addr = 0 ;
 const gchar * address_string = NULL ;
 gboolean is_custom_register = FALSE ;
 guint16 count = 0 ;
 gint offset = startoffset ;
 proto_item * item = NULL ;
 addr = tvb_get_letoh64 ( tvb , offset ) ;
 gencp_trans -> address = addr ;
 address_string = get_register_name_from_address ( addr , & is_custom_register , u3v_conv_info ) ;
 count = tvb_get_letohs ( tvb , offset + 10 ) ;
 gencp_trans -> count = count ;
 if ( 0xffffffff00000000 & addr ) {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , " (0x%016" G_GINT64_MODIFIER "X (%d) bytes) %s" , addr , count , address_string ) ;
 }
 else {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , " (0x%08X (%d) bytes)" , ( guint32 ) addr , count ) ;
 }
 item = proto_tree_add_item ( u3v_telegram_tree , hf_u3v_scd_readmem_cmd , tvb , offset , length , ENC_NA ) ;
 u3v_telegram_tree = proto_item_add_subtree ( item , ett_u3v_payload_cmd ) ;
 if ( is_known_bootstrap_register ( addr , u3v_conv_info ) ) {
 item = proto_tree_add_uint64 ( u3v_telegram_tree , hf_u3v_address , tvb , offset , 8 , addr ) ;
 proto_item_append_text ( item , " %s" , address_string ) ;
 }
 else {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_custom_memory_addr , tvb , offset , 8 , ENC_LITTLE_ENDIAN ) ;
 }
 offset += 8 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_reserved , tvb , offset , 2 , ENC_NA ) ;
 offset += 2 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_count , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 }
static void dissect_u3v_read_mem_ack ( proto_tree * u3v_telegram_tree , tvbuff_t * tvb , packet_info * pinfo , gint startoffset , gint length , u3v_conv_info_t * u3v_conv_info , gencp_transaction_t * gencp_trans ) {
 guint64 addr = 0 ;
 const gchar * address_string = NULL ;
 gboolean is_custom_register = FALSE ;
 gboolean have_address = ( 0 != gencp_trans -> cmd_frame ) ;
 proto_item * item = NULL ;
 guint offset = startoffset ;
 guint byte_count = ( length ) ;
 addr = gencp_trans -> address ;
 dissect_u3v_register_bases ( addr , tvb , startoffset , u3v_conv_info ) ;
 if ( have_address ) {
 address_string = get_register_name_from_address ( addr , & is_custom_register , u3v_conv_info ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "%s" , address_string ) ;
 }
 item = proto_tree_add_item ( u3v_telegram_tree , hf_u3v_scd_ack_readmem_ack , tvb , startoffset , length , ENC_NA ) ;
 u3v_telegram_tree = proto_item_add_subtree ( item , ett_u3v_payload_cmd ) ;
 if ( have_address ) {
 item = proto_tree_add_uint64 ( u3v_telegram_tree , hf_u3v_address , tvb , 0 , 0 , addr ) ;
 PROTO_ITEM_SET_GENERATED ( item ) ;
 if ( is_known_bootstrap_register ( addr , u3v_conv_info ) ) {
 dissect_u3v_register ( addr , u3v_telegram_tree , tvb , offset , byte_count , u3v_conv_info ) ;
 }
 else {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_custom_memory_data , tvb , startoffset , length , ENC_NA ) ;
 }
 }
 }
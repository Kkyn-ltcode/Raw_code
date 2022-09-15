static void dissect_u3v_event_cmd ( proto_tree * u3v_telegram_tree , tvbuff_t * tvb , packet_info * pinfo , gint startoffset , gint length ) {
 gint32 eventid ;
 gint offset = startoffset ;
 proto_item * item = NULL ;
 eventid = tvb_get_letohs ( tvb , offset + 2 ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "[ID: 0x%04X]" , eventid ) ;
 item = proto_tree_add_item ( u3v_telegram_tree , hf_u3v_scd_event_cmd , tvb , offset , length , ENC_NA ) ;
 u3v_telegram_tree = proto_item_add_subtree ( item , ett_u3v_payload_cmd ) ;
 offset += 2 ;
 if ( ( eventid >= 0x0000 ) && ( eventid <= 0x8000 ) ) {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_eventcmd_id , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 }
 else if ( ( eventid >= 0x8001 ) && ( eventid <= 0x8FFF ) ) {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_eventcmd_error_id , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 }
 else if ( ( eventid >= 0x9000 ) && ( eventid <= 0xFFFF ) ) {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_eventcmd_device_specific_id , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 }
 offset += 2 ;
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_eventcmd_timestamp , tvb , offset , 8 , ENC_LITTLE_ENDIAN ) ;
 offset += 8 ;
 if ( length > offset ) {
 proto_tree_add_item ( u3v_telegram_tree , hf_u3v_eventcmd_data , tvb , offset , length - 12 , ENC_NA ) ;
 }
 }
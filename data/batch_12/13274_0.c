static int dissect_t38_T_primary_ifp_packet ( tvbuff_t * tvb _U_ , int offset _U_ , asn1_ctx_t * actx _U_ , proto_tree * tree _U_ , int hf_index _U_ ) {
 # line 246 "../../asn1/t38/t38.cnf" primary_part = TRUE ;
 offset = dissect_per_open_type ( tvb , offset , actx , tree , hf_index , dissect_t38_IFPPacket ) ;
 # line 248 "../../asn1/t38/t38.cnf" if ( p_t38_packet_conv && ( ! actx -> pinfo -> flags . in_error_pkt ) && ( ( gint32 ) seq_number != p_t38_packet_conv_info -> last_seqnum ) && ! ( t38_info -> type_msg == 1 && t38_info -> Data_Field_field_type_value == 7 && t38_info -> frame_num_first_t4_data == 0 ) ) tap_queue_packet ( t38_tap , actx -> pinfo , t38_info ) ;
 if ( p_t38_conv ) p_t38_conv_info -> last_seqnum = ( gint32 ) seq_number ;
 return offset ;
 }
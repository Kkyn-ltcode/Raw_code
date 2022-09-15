static guint32 dissect_iax2_command ( tvbuff_t * tvb , guint32 offset , packet_info * pinfo , proto_tree * tree , iax_packet_data * iax_packet ) {
 guint8 csub = tvb_get_guint8 ( tvb , offset ) ;
 guint8 address_data [ MAX_ADDRESS ] ;
 proto_item * ti ;
 iax2_ie_data ie_data ;
 iax_call_data * iax_call ;
 ie_data . peer_address . type = AT_NONE ;
 ie_data . peer_address . len = 0 ;
 ie_data . peer_address . data = address_data ;
 ie_data . peer_ptype = PT_NONE ;
 ie_data . peer_port = 0 ;
 ie_data . peer_callno = 0 ;
 ie_data . dataformat = ( guint32 ) - 1 ;
 iax_call = iax_packet -> call_data ;
 ti = proto_tree_add_uint ( tree , hf_iax2_iax_csub , tvb , offset , 1 , csub ) ;
 offset ++ ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , " %s" , val_to_str_ext ( csub , & iax_iax_subclasses_ext , "unknown (0x%02x)" ) ) ;
 if ( offset >= tvb_reported_length ( tvb ) ) return offset ;
 offset = dissect_ies ( tvb , pinfo , offset , tree , ti , & ie_data ) ;
 if ( iax_call && ie_data . dataformat != ( guint32 ) - 1 && iax_call -> subdissector == NULL ) {
 iax_call -> subdissector = dissector_get_uint_handle ( iax2_dataformat_dissector_table , ie_data . dataformat ) ;
 iax_call -> dataformat = ( iax_dataformat_t ) ie_data . dataformat ;
 }
 if ( csub == IAX_COMMAND_TXREQ && iax_packet -> first_time ) {
 if ( ie_data . peer_address . type != AT_NONE && ie_data . peer_callno != 0 ) {
 guint tx_circuit = iax_circuit_lookup ( & ie_data . peer_address , ie_data . peer_ptype , ie_data . peer_port , ie_data . peer_callno ) ;
 iax2_new_circuit_for_call ( pinfo , NULL , tx_circuit , pinfo -> fd -> num , iax_call , iax_packet -> reversed ) ;
 }
 }
 return offset ;
 }
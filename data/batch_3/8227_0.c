static iax_call_data * iax_lookup_call_from_dest ( packet_info * pinfo , proto_item * item , guint src_circuit_id , guint dst_circuit_id , guint framenum , gboolean * reversed_p ) {
 circuit_t * dst_circuit ;
 iax_call_data * iax_call ;
 gboolean reversed = FALSE ;
 dst_circuit = find_circuit ( CT_IAX2 , dst_circuit_id , framenum ) ;
 if ( ! dst_circuit ) {
 # ifdef DEBUG_HASHING g_debug ( "++ destination circuit not found, must have missed NEW packet" ) ;
 # endif if ( reversed_p ) * reversed_p = FALSE ;
 return NULL ;
 }
 # ifdef DEBUG_HASHING g_debug ( "++ found destination circuit" ) ;
 # endif iax_call = ( iax_call_data * ) circuit_get_proto_data ( dst_circuit , proto_iax2 ) ;
 DISSECTOR_ASSERT ( iax_call ) ;
 if ( is_forward_circuit ( dst_circuit_id , iax_call ) ) {
 # ifdef DEBUG_HASHING g_debug ( "++ destination circuit matches forward_circuit_id of call, " "therefore packet is reversed" ) ;
 # endif reversed = TRUE ;
 if ( iax_call -> n_reverse_circuit_ids == 0 ) {
 # ifdef DEBUG_HASHING g_debug ( "++ reverse_circuit_id of call is zero, need to create a " "new reverse circuit for this call" ) ;
 # endif iax2_new_circuit_for_call ( pinfo , item , src_circuit_id , framenum , iax_call , TRUE ) ;
 # ifdef DEBUG_HASHING g_debug ( "++ done" ) ;
 # endif }
 else if ( ! is_reverse_circuit ( src_circuit_id , iax_call ) ) {
 expert_add_info_format ( pinfo , item , & ei_iax_circuit_id_conflict , "IAX Packet %u from circuit ids %u->%u conflicts with earlier call with circuit ids %u->%u" , framenum , src_circuit_id , dst_circuit_id , iax_call -> forward_circuit_ids [ 0 ] , iax_call -> reverse_circuit_ids [ 0 ] ) ;
 return NULL ;
 }
 }
 else if ( is_reverse_circuit ( dst_circuit_id , iax_call ) ) {
 # ifdef DEBUG_HASHING g_debug ( "++ destination circuit matches reverse_circuit_id of call, " "therefore packet is forward" ) ;
 # endif reversed = FALSE ;
 if ( ! is_forward_circuit ( src_circuit_id , iax_call ) ) {
 expert_add_info_format ( pinfo , item , & ei_iax_circuit_id_conflict , "IAX Packet %u from circuit ids %u->%u conflicts with earlier call with circuit ids %u->%u" , framenum , src_circuit_id , dst_circuit_id , iax_call -> forward_circuit_ids [ 0 ] , iax_call -> reverse_circuit_ids [ 0 ] ) ;
 if ( reversed_p ) * reversed_p = FALSE ;
 return NULL ;
 }
 }
 else {
 DISSECTOR_ASSERT_NOT_REACHED ( ) ;
 }
 if ( reversed_p ) * reversed_p = reversed ;
 return iax_call ;
 }
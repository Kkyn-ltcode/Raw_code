static void dissect_rsvp_common ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , gboolean e2ei ) {
 guint8 message_type ;
 int session_off , tempfilt_off ;
 rsvp_conversation_info * rsvph ;
 conversation_t * conversation ;
 struct rsvp_request_key request_key , * new_request_key ;
 struct rsvp_request_val * request_val ;
 col_clear ( pinfo -> cinfo , COL_INFO ) ;
 message_type = tvb_get_guint8 ( tvb , 1 ) ;
 rsvph = wmem_new0 ( wmem_packet_scope ( ) , rsvp_conversation_info ) ;
 set_address ( & rsvph -> source , pinfo -> src . type , pinfo -> src . len , pinfo -> src . data ) ;
 set_address ( & rsvph -> destination , pinfo -> dst . type , pinfo -> dst . len , pinfo -> dst . data ) ;
 col_add_str ( pinfo -> cinfo , COL_INFO , val_to_str_ext ( message_type , & message_type_vals_ext , "Unknown (%u). " ) ) ;
 if ( message_type == RSVP_MSG_BUNDLE ) {
 col_set_str ( pinfo -> cinfo , COL_INFO , rsvp_bundle_dissect ? "Component Messages Dissected" : "Component Messages Not Dissected" ) ;
 }
 else {
 find_rsvp_session_tempfilt ( tvb , 0 , & session_off , & tempfilt_off ) ;
 if ( session_off ) col_append_str ( pinfo -> cinfo , COL_INFO , summary_session ( tvb , session_off ) ) ;
 if ( tempfilt_off ) col_append_str ( pinfo -> cinfo , COL_INFO , summary_template ( tvb , tempfilt_off ) ) ;
 }
 dissect_rsvp_msg_tree ( tvb , pinfo , tree , TREE ( TT_RSVP ) , rsvph , e2ei ) ;
 if ( ( message_type == RSVP_MSG_ACK ) || ( message_type == RSVP_MSG_SREFRESH ) || ( message_type == RSVP_MSG_HELLO ) ) return ;
 conversation = find_or_create_conversation ( pinfo ) ;
 memset ( & request_key , 0 , sizeof ( request_key ) ) ;
 request_key . conversation = conversation -> index ;
 request_key . session_type = rsvph -> session_type ;
 switch ( request_key . session_type ) {
 case RSVP_SESSION_TYPE_IPV4 : set_address ( & request_key . u . session_ipv4 . destination , rsvph -> destination . type , rsvph -> destination . len , rsvph -> destination . data ) ;
 request_key . u . session_ipv4 . protocol = rsvph -> protocol ;
 request_key . u . session_ipv4 . udp_dest_port = rsvph -> udp_dest_port ;
 break ;
 case RSVP_SESSION_TYPE_IPV6 : break ;
 case RSVP_SESSION_TYPE_IPV4_LSP : set_address ( & request_key . u . session_ipv4_lsp . destination , rsvph -> destination . type , rsvph -> destination . len , rsvph -> destination . data ) ;
 request_key . u . session_ipv4_lsp . udp_dest_port = rsvph -> udp_dest_port ;
 request_key . u . session_ipv4_lsp . ext_tunnel_id = rsvph -> ext_tunnel_id ;
 break ;
 case RSVP_SESSION_TYPE_AGGREGATE_IPV4 : set_address ( & request_key . u . session_agg_ipv4 . destination , rsvph -> destination . type , rsvph -> destination . len , rsvph -> destination . data ) ;
 request_key . u . session_agg_ipv4 . dscp = rsvph -> dscp ;
 break ;
 case RSVP_SESSION_TYPE_IPV4_UNI : set_address ( & request_key . u . session_ipv4_uni . destination , rsvph -> destination . type , rsvph -> destination . len , rsvph -> destination . data ) ;
 request_key . u . session_ipv4_uni . udp_dest_port = rsvph -> udp_dest_port ;
 request_key . u . session_ipv4_uni . ext_tunnel_id = rsvph -> ext_tunnel_id ;
 break ;
 case RSVP_SESSION_TYPE_IPV4_E_NNI : set_address ( & request_key . u . session_ipv4_enni . destination , rsvph -> destination . type , rsvph -> destination . len , rsvph -> destination . data ) ;
 request_key . u . session_ipv4_enni . udp_dest_port = rsvph -> udp_dest_port ;
 request_key . u . session_ipv4_enni . ext_tunnel_id = rsvph -> ext_tunnel_id ;
 break ;
 default : proto_tree_add_expert ( tree , pinfo , & ei_rsvp_session_type , tvb , 0 , 0 ) ;
 break ;
 }
 copy_address_shallow ( & request_key . source_info . source , & rsvph -> source ) ;
 request_key . source_info . udp_source_port = rsvph -> udp_source_port ;
 request_val = ( struct rsvp_request_val * ) g_hash_table_lookup ( rsvp_request_hash , & request_key ) ;
 if ( ! request_val ) {
 new_request_key = ( struct rsvp_request_key * ) wmem_memdup ( wmem_file_scope ( ) , & request_key , sizeof ( struct rsvp_request_key ) ) ;
 switch ( request_key . session_type ) {
 case RSVP_SESSION_TYPE_IPV4 : copy_address_wmem ( wmem_file_scope ( ) , & new_request_key -> u . session_ipv4 . destination , & request_key . u . session_ipv4 . destination ) ;
 break ;
 case RSVP_SESSION_TYPE_IPV4_LSP : copy_address_wmem ( wmem_file_scope ( ) , & new_request_key -> u . session_ipv4_lsp . destination , & request_key . u . session_ipv4_lsp . destination ) ;
 break ;
 case RSVP_SESSION_TYPE_AGGREGATE_IPV4 : copy_address_wmem ( wmem_file_scope ( ) , & new_request_key -> u . session_agg_ipv4 . destination , & request_key . u . session_agg_ipv4 . destination ) ;
 break ;
 case RSVP_SESSION_TYPE_IPV4_UNI : copy_address_wmem ( wmem_file_scope ( ) , & new_request_key -> u . session_ipv4_uni . destination , & request_key . u . session_ipv4_uni . destination ) ;
 break ;
 case RSVP_SESSION_TYPE_IPV4_E_NNI : copy_address_wmem ( wmem_file_scope ( ) , & new_request_key -> u . session_ipv4_enni . destination , & request_key . u . session_ipv4_enni . destination ) ;
 break ;
 default : break ;
 }
 copy_address_wmem ( wmem_file_scope ( ) , & new_request_key -> source_info . source , & rsvph -> source ) ;
 request_val = wmem_new ( wmem_file_scope ( ) , struct rsvp_request_val ) ;
 request_val -> value = conversation -> index ;
 g_hash_table_insert ( rsvp_request_hash , new_request_key , request_val ) ;
 }
 tap_queue_packet ( rsvp_tap , pinfo , rsvph ) ;
 }
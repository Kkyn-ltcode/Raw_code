static int dissect_netbios ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data _U_ ) {
 proto_tree * netb_tree = NULL ;
 proto_item * ti ;
 guint16 hdr_len , command ;
 const char * command_name ;
 char name [ ( NETBIOS_NAME_LEN - 1 ) * 4 + 1 ] ;
 int name_type ;
 guint16 session_id ;
 gboolean save_fragmented ;
 int len ;
 fragment_head * fd_head ;
 tvbuff_t * next_tvb ;
 int offset = 0 ;
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "NetBIOS" ) ;
 if ( 0xefff != tvb_get_letohs ( tvb , 2 ) ) {
 ++ offset ;
 if ( 0xefff != tvb_get_letohs ( tvb , 3 ) ) {
 col_set_str ( pinfo -> cinfo , COL_INFO , "Bad packet, no 0xEFFF marker" ) ;
 return 3 ;
 }
 }
 hdr_len = tvb_get_letohs ( tvb , offset + NB_LENGTH ) ;
 command = tvb_get_guint8 ( tvb , offset + NB_COMMAND ) ;
 command = MIN ( command , sizeof ( dissect_netb ) / sizeof ( void * ) ) ;
 command_name = val_to_str_ext ( command , & cmd_vals_ext , "Unknown (0x%02x)" ) ;
 switch ( command ) {
 case NB_NAME_QUERY : name_type = get_netbios_name ( tvb , offset + 12 , name , ( NETBIOS_NAME_LEN - 1 ) * 4 + 1 ) ;
 col_add_fstr ( pinfo -> cinfo , COL_INFO , "%s for %s<%02x>" , command_name , name , name_type ) ;
 break ;
 case NB_NAME_RESP : case NB_ADD_NAME : case NB_ADD_GROUP : name_type = get_netbios_name ( tvb , offset + 28 , name , ( NETBIOS_NAME_LEN - 1 ) * 4 + 1 ) ;
 col_add_fstr ( pinfo -> cinfo , COL_INFO , "%s - %s<%02x>" , command_name , name , name_type ) ;
 break ;
 default : col_add_str ( pinfo -> cinfo , COL_INFO , command_name ) ;
 break ;
 }
 if ( tree ) {
 ti = proto_tree_add_item ( tree , proto_netbios , tvb , 0 , hdr_len , ENC_NA ) ;
 netb_tree = proto_item_add_subtree ( ti , ett_netb ) ;
 proto_tree_add_uint_format_value ( netb_tree , hf_netb_hdr_len , tvb , offset , 2 , hdr_len , "%d bytes" , hdr_len ) ;
 proto_tree_add_uint_format_value ( netb_tree , hf_netb_delimiter , tvb , offset + 2 , 2 , tvb_get_letohs ( tvb , offset + 2 ) , "EFFF (NetBIOS)" ) ;
 proto_tree_add_uint ( netb_tree , hf_netb_cmd , tvb , offset + NB_COMMAND , 1 , command ) ;
 }
 if ( command < sizeof ( dissect_netb ) / sizeof ( void * ) ) {
 session_id = ( dissect_netb [ command ] ) ( tvb , pinfo , offset , netb_tree ) ;
 offset += hdr_len ;
 save_fragmented = pinfo -> fragmented ;
 switch ( command ) {
 case NB_DATAGRAM : case NB_DATAGRAM_BCAST : next_tvb = tvb_new_subset_remaining ( tvb , offset ) ;
 dissect_netbios_payload ( next_tvb , pinfo , tree ) ;
 break ;
 case NB_DATA_FIRST_MIDDLE : case NB_DATA_ONLY_LAST : len = tvb_reported_length_remaining ( tvb , offset ) ;
 if ( netbios_defragment && tvb_bytes_exist ( tvb , offset , len ) ) {
 fd_head = fragment_add_seq_next ( & netbios_reassembly_table , tvb , offset , pinfo , session_id , NULL , len , command == NB_DATA_FIRST_MIDDLE ) ;
 if ( fd_head != NULL ) {
 if ( fd_head -> next != NULL ) {
 next_tvb = tvb_new_chain ( tvb , fd_head -> tvb_data ) ;
 add_new_data_source ( pinfo , next_tvb , "Reassembled NetBIOS" ) ;
 if ( tree ) {
 proto_item * frag_tree_item ;
 show_fragment_seq_tree ( fd_head , & netbios_frag_items , netb_tree , pinfo , next_tvb , & frag_tree_item ) ;
 }
 }
 else {
 next_tvb = tvb_new_subset_remaining ( tvb , offset ) ;
 }
 }
 else {
 next_tvb = NULL ;
 }
 }
 else {
 next_tvb = tvb_new_subset_remaining ( tvb , offset ) ;
 }
 if ( next_tvb != NULL ) dissect_netbios_payload ( next_tvb , pinfo , tree ) ;
 else {
 next_tvb = tvb_new_subset_remaining ( tvb , offset ) ;
 call_data_dissector ( next_tvb , pinfo , tree ) ;
 }
 break ;
 }
 pinfo -> fragmented = save_fragmented ;
 }
 return tvb_captured_length ( tvb ) ;
 }
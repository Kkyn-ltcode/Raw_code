static void init_t38_info_conv ( packet_info * pinfo ) {
 t38_info_current ++ ;
 if ( t38_info_current == MAX_T38_MESSAGES_IN_PACKET ) {
 t38_info_current = 0 ;
 }
 t38_info = & t38_info_arr [ t38_info_current ] ;
 t38_info -> seq_num = 0 ;
 t38_info -> type_msg = 0 ;
 t38_info -> data_value = 0 ;
 t38_info -> t30ind_value = 0 ;
 t38_info -> setup_frame_number = 0 ;
 t38_info -> Data_Field_field_type_value = 0 ;
 t38_info -> desc [ 0 ] = '\0' ;
 t38_info -> desc_comment [ 0 ] = '\0' ;
 t38_info -> time_first_t4_data = 0 ;
 t38_info -> frame_num_first_t4_data = 0 ;
 p_t38_packet_conv = NULL ;
 p_t38_conv = NULL ;
 p_t38_packet_conv = ( t38_conv * ) p_get_proto_data ( wmem_file_scope ( ) , pinfo , proto_t38 , 0 ) ;
 p_conv = find_conversation ( pinfo -> fd -> num , & pinfo -> net_dst , & pinfo -> net_src , pinfo -> ptype , pinfo -> destport , pinfo -> srcport , NO_ADDR_B | NO_PORT_B ) ;
 if ( ! p_conv ) {
 p_conv = conversation_new ( pinfo -> fd -> num , & pinfo -> net_src , & pinfo -> net_dst , pinfo -> ptype , pinfo -> srcport , pinfo -> destport , NO_ADDR_B | NO_PORT_B ) ;
 conversation_set_dissector ( p_conv , t38_udp_handle ) ;
 }
 if ( ! p_t38_packet_conv ) {
 p_t38_conv = ( t38_conv * ) conversation_get_proto_data ( p_conv , proto_t38 ) ;
 if ( ! p_t38_conv ) {
 p_t38_conv = wmem_new ( wmem_file_scope ( ) , t38_conv ) ;
 p_t38_conv -> setup_method [ 0 ] = '\0' ;
 p_t38_conv -> setup_frame_number = 0 ;
 p_t38_conv -> src_t38_info . reass_ID = 0 ;
 p_t38_conv -> src_t38_info . reass_start_seqnum = - 1 ;
 p_t38_conv -> src_t38_info . reass_data_type = 0 ;
 p_t38_conv -> src_t38_info . last_seqnum = - 1 ;
 p_t38_conv -> src_t38_info . packet_lost = 0 ;
 p_t38_conv -> src_t38_info . burst_lost = 0 ;
 p_t38_conv -> src_t38_info . time_first_t4_data = 0 ;
 p_t38_conv -> src_t38_info . additional_hdlc_data_field_counter = 0 ;
 p_t38_conv -> src_t38_info . seqnum_prev_data_field = - 1 ;
 p_t38_conv -> dst_t38_info . reass_ID = 0 ;
 p_t38_conv -> dst_t38_info . reass_start_seqnum = - 1 ;
 p_t38_conv -> dst_t38_info . reass_data_type = 0 ;
 p_t38_conv -> dst_t38_info . last_seqnum = - 1 ;
 p_t38_conv -> dst_t38_info . packet_lost = 0 ;
 p_t38_conv -> dst_t38_info . burst_lost = 0 ;
 p_t38_conv -> dst_t38_info . time_first_t4_data = 0 ;
 p_t38_conv -> dst_t38_info . additional_hdlc_data_field_counter = 0 ;
 p_t38_conv -> dst_t38_info . seqnum_prev_data_field = - 1 ;
 conversation_add_proto_data ( p_conv , proto_t38 , p_t38_conv ) ;
 }
 p_t38_packet_conv = wmem_new ( wmem_file_scope ( ) , t38_conv ) ;
 g_strlcpy ( p_t38_packet_conv -> setup_method , p_t38_conv -> setup_method , MAX_T38_SETUP_METHOD_SIZE ) ;
 p_t38_packet_conv -> setup_frame_number = p_t38_conv -> setup_frame_number ;
 memcpy ( & ( p_t38_packet_conv -> src_t38_info ) , & ( p_t38_conv -> src_t38_info ) , sizeof ( t38_conv_info ) ) ;
 memcpy ( & ( p_t38_packet_conv -> dst_t38_info ) , & ( p_t38_conv -> dst_t38_info ) , sizeof ( t38_conv_info ) ) ;
 p_add_proto_data ( wmem_file_scope ( ) , pinfo , proto_t38 , 0 , p_t38_packet_conv ) ;
 }
 if ( ADDRESSES_EQUAL ( & p_conv -> key_ptr -> addr1 , & pinfo -> net_src ) ) {
 p_t38_conv_info = & ( p_t38_conv -> src_t38_info ) ;
 p_t38_packet_conv_info = & ( p_t38_packet_conv -> src_t38_info ) ;
 }
 else {
 p_t38_conv_info = & ( p_t38_conv -> dst_t38_info ) ;
 p_t38_packet_conv_info = & ( p_t38_packet_conv -> dst_t38_info ) ;
 }
 t38_info -> setup_frame_number = p_t38_packet_conv -> setup_frame_number ;
 }
static int dissect_btatt ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree , void * data ) {
 proto_item * main_item ;
 proto_tree * main_tree ;
 proto_item * sub_item ;
 proto_tree * sub_tree ;
 int offset = 0 ;
 guint8 opcode ;
 guint8 request_opcode ;
 bluetooth_data_t * bluetooth_data ;
 btatt_data_t att_data ;
 request_data_t * request_data ;
 guint16 handle ;
 bluetooth_uuid_t uuid ;
 guint mtu ;
 memset ( & uuid , 0 , sizeof uuid ) ;
 bluetooth_data = ( bluetooth_data_t * ) data ;
 if ( tvb_reported_length_remaining ( tvb , 0 ) < 1 ) return 0 ;
 att_data . bluetooth_data = bluetooth_data ;
 main_item = proto_tree_add_item ( tree , proto_btatt , tvb , 0 , - 1 , ENC_NA ) ;
 main_tree = proto_item_add_subtree ( main_item , ett_btatt ) ;
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "ATT" ) ;
 switch ( pinfo -> p2p_dir ) {
 case P2P_DIR_SENT : col_set_str ( pinfo -> cinfo , COL_INFO , "Sent " ) ;
 break ;
 case P2P_DIR_RECV : col_set_str ( pinfo -> cinfo , COL_INFO , "Rcvd " ) ;
 break ;
 default : col_set_str ( pinfo -> cinfo , COL_INFO , "UnknownDirection " ) ;
 break ;
 }
 mtu = get_mtu ( pinfo , bluetooth_data ) ;
 if ( tvb_reported_length ( tvb ) > mtu ) expert_add_info ( pinfo , main_item , & ei_btatt_mtu_exceeded ) ;
 proto_tree_add_bitmask_with_flags ( main_tree , tvb , offset , hf_btatt_opcode , ett_btatt_opcode , hfx_btatt_opcode , ENC_NA , BMT_NO_APPEND ) ;
 opcode = tvb_get_guint8 ( tvb , 0 ) ;
 att_data . opcode = opcode ;
 offset ++ ;
 request_data = get_request ( tvb , offset , pinfo , opcode , bluetooth_data ) ;
 col_append_str ( pinfo -> cinfo , COL_INFO , val_to_str_const ( opcode , opcode_vals , "<unknown>" ) ) ;
 switch ( opcode ) {
 case 0x01 : {
 guint8 error_code ;
 bluetooth_uuid_t service_uuid ;
 const value_string * error_vals = error_code_vals ;
 gint hfx_btatt_error_code = hf_btatt_error_code ;
 proto_tree_add_bitmask_with_flags ( main_tree , tvb , offset , hf_btatt_req_opcode_in_error , ett_btatt_opcode , hfx_btatt_opcode , ENC_NA , BMT_NO_APPEND ) ;
 request_opcode = tvb_get_guint8 ( tvb , offset ) ;
 offset += 1 ;
 offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle_in_error , tvb , offset , bluetooth_data , NULL , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 error_code = tvb_get_guint8 ( tvb , offset ) ;
 if ( error_code >= 0x80 && error_code <= 0x9F ) {
 service_uuid = get_service_uuid_from_handle ( pinfo , handle , bluetooth_data ) ;
 switch ( service_uuid . bt_uuid ) {
 case GATT_SERVICE_AUTOMATION_IO : error_vals = error_code_aios_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_aios ;
 break ;
 case GATT_SERVICE_ALERT_NOTIFICATION_SERVICE : error_vals = error_code_ans_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_ans ;
 break ;
 case GATT_SERVICE_BOND_MANAGEMENT : error_vals = error_code_bms_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_bms ;
 break ;
 case GATT_SERVICE_CONTINUOUS_GLUCOSE_MONITORING : error_vals = error_code_cgms_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_cgms ;
 break ;
 case GATT_SERVICE_CYCLING_POWER : error_vals = error_code_cps_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_cps ;
 break ;
 case GATT_SERVICE_CYCLING_SPEED_AND_CADENCE : error_vals = error_code_cscs_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_cscs ;
 break ;
 case GATT_SERVICE_CURRENT_TIME_SERVICE : error_vals = error_code_cts_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_cts ;
 break ;
 case GATT_SERVICE_ENVIRONMENTAL_SENSING : error_vals = error_code_ess_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_ess ;
 break ;
 case GATT_SERVICE_GLUCOSE : error_vals = error_code_gls_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_gls ;
 break ;
 case GATT_SERVICE_HTTP_PROXY : error_vals = error_code_hps_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_hps ;
 break ;
 case GATT_SERVICE_HEART_RATE : error_vals = error_code_hrs_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_hrs ;
 break ;
 case GATT_SERVICE_HEALTH_THERMOMETER : error_vals = error_code_hts_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_hts ;
 break ;
 case GATT_SERVICE_INDOOR_POSITIONING : error_vals = error_code_ips_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_ips ;
 break ;
 case GATT_SERVICE_OBJECT_TRANSFER : error_vals = error_code_ots_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_ots ;
 break ;
 case GATT_SERVICE_RUNNING_SPEED_AND_CADENCE : error_vals = error_code_rscs_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_rscs ;
 break ;
 case GATT_SERVICE_USER_DATA : error_vals = error_code_uds_vals ;
 hfx_btatt_error_code = hf_btatt_error_code_uds ;
 break ;
 default : error_vals = error_code_vals ;
 hfx_btatt_error_code = hf_btatt_error_code ;
 }
 }
 col_append_fstr ( pinfo -> cinfo , COL_INFO , " - %s" , val_to_str_const ( error_code , error_vals , "<unknown>" ) ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 proto_tree_add_item ( main_tree , hfx_btatt_error_code , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 if ( request_data && ( request_opcode == 0x08 || request_opcode == 0x10 ) ) {
 sub_item = proto_tree_add_uint ( main_tree , hf_btatt_uuid16 , tvb , 0 , 0 , request_data -> parameters . read_by_type . uuid . bt_uuid ) ;
 PROTO_ITEM_SET_GENERATED ( sub_item ) ;
 }
 }
 break ;
 case 0x02 : col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Client Rx MTU: %u" , tvb_get_letohs ( tvb , offset ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_client_rx_mtu , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . mtu . mtu = tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 break ;
 case 0x03 : col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Server Rx MTU: %u" , tvb_get_letohs ( tvb , offset ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_server_rx_mtu , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 if ( ! pinfo -> fd -> flags . visited && request_data && bluetooth_data ) {
 guint new_mtu ;
 new_mtu = tvb_get_guint16 ( tvb , offset , ENC_LITTLE_ENDIAN ) ;
 if ( new_mtu > request_data -> parameters . mtu . mtu ) new_mtu = request_data -> parameters . mtu . mtu ;
 save_mtu ( pinfo , bluetooth_data , new_mtu ) ;
 }
 offset += 2 ;
 break ;
 case 0x04 : col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Handles: 0x%04x..0x%04x" , tvb_get_letohs ( tvb , offset ) , tvb_get_letohs ( tvb , offset + 2 ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_starting_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( main_tree , hf_btatt_ending_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . find_information . starting_handle = tvb_get_guint16 ( tvb , offset - 4 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . find_information . ending_handle = tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 break ;
 case 0x05 : {
 guint8 format ;
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_uuid_format , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 format = tvb_get_guint8 ( tvb , offset ) ;
 offset += 1 ;
 if ( format == 1 ) {
 while ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_information_data , tvb , offset , 4 , ENC_NA ) ;
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_list ) ;
 offset = dissect_handle ( sub_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , NULL , HANDLE_TVB ) ;
 handle = tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( sub_tree , hf_btatt_uuid16 , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 uuid = get_uuid ( tvb , offset , 2 ) ;
 offset += 2 ;
 proto_item_append_text ( sub_item , ", Handle: 0x%04x, UUID: %s" , handle , print_uuid ( & uuid ) ) ;
 save_handle ( pinfo , uuid , handle , ATTRIBUTE_TYPE_OTHER , bluetooth_data ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 }
 }
 else if ( format == 2 ) {
 while ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_information_data , tvb , offset , 4 , ENC_NA ) ;
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_list ) ;
 offset = dissect_handle ( sub_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , NULL , HANDLE_TVB ) ;
 handle = tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( sub_tree , hf_btatt_uuid128 , tvb , offset , 16 , ENC_NA ) ;
 uuid = get_uuid ( tvb , offset , 16 ) ;
 offset += 16 ;
 proto_item_append_text ( sub_item , ", Handle: 0x%04x, UUID: %s" , handle , print_uuid ( & uuid ) ) ;
 save_handle ( pinfo , uuid , handle , ATTRIBUTE_TYPE_OTHER , bluetooth_data ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 }
 }
 else {
 expert_add_info ( pinfo , sub_item , & ei_btatt_uuid_format_unknown ) ;
 }
 }
 break ;
 case 0x06 : col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s, Handles: 0x%04x..0x%04x" , val_to_str_ext_const ( tvb_get_letohs ( tvb , offset + 4 ) , & bluetooth_uuid_vals_ext , "<unknown>" ) , tvb_get_letohs ( tvb , offset ) , tvb_get_letohs ( tvb , offset + 2 ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_starting_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( main_tree , hf_btatt_ending_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( main_tree , hf_btatt_uuid16 , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 uuid = get_uuid ( tvb , offset - 2 , 2 ) ;
 offset += 2 ;
 dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , tvb_captured_length_remaining ( tvb , offset ) , 0 , uuid , & att_data ) ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_by_type . starting_handle = tvb_get_guint16 ( tvb , offset - 6 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . read_by_type . ending_handle = tvb_get_guint16 ( tvb , offset - 4 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . read_by_type . uuid = uuid ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 offset = tvb_reported_length ( tvb ) ;
 break ;
 case 0x07 : while ( tvb_reported_length_remaining ( tvb , offset ) > 0 ) {
 sub_item = proto_tree_add_none_format ( main_tree , hf_btatt_handles_info , tvb , offset , 4 , "Handles Info, Handle: 0x%04x, Group End Handle: 0x%04x" , tvb_get_letohs ( tvb , offset ) , tvb_get_letohs ( tvb , offset + 2 ) ) ;
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_list ) ;
 offset = dissect_handle ( sub_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , NULL , HANDLE_TVB ) ;
 proto_tree_add_item ( sub_tree , hf_btatt_group_end_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( request_data ) save_handle ( pinfo , request_data -> parameters . read_by_type . uuid , tvb_get_guint16 ( tvb , offset - 4 , ENC_LITTLE_ENDIAN ) , ATTRIBUTE_TYPE_OTHER , bluetooth_data ) ;
 }
 break ;
 case 0x08 : case 0x10 : col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s, Handles: 0x%04x..0x%04x" , val_to_str_ext_const ( tvb_get_letohs ( tvb , offset + 4 ) , & bluetooth_uuid_vals_ext , "<unknown>" ) , tvb_get_letohs ( tvb , offset ) , tvb_get_letohs ( tvb , offset + 2 ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_starting_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 proto_tree_add_item ( main_tree , hf_btatt_ending_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( tvb_reported_length_remaining ( tvb , offset ) == 2 ) {
 proto_tree_add_item ( main_tree , hf_btatt_uuid16 , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_by_type . starting_handle = tvb_get_guint16 ( tvb , offset - 6 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . read_by_type . ending_handle = tvb_get_guint16 ( tvb , offset - 4 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . read_by_type . uuid = get_uuid ( tvb , offset - 2 , 2 ) ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 }
 else if ( tvb_reported_length_remaining ( tvb , offset ) == 16 ) {
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_uuid128 , tvb , offset , 16 , ENC_NA ) ;
 proto_item_append_text ( sub_item , " (%s)" , val_to_str_ext_const ( tvb_get_letohs ( tvb , offset ) , & bluetooth_uuid_vals_ext , "<unknown>" ) ) ;
 offset += 16 ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_by_type . starting_handle = tvb_get_guint16 ( tvb , offset - 20 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . read_by_type . ending_handle = tvb_get_guint16 ( tvb , offset - 18 , ENC_LITTLE_ENDIAN ) ;
 request_parameters . read_by_type . uuid = get_uuid ( tvb , offset - 16 , 16 ) ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 }
 else {
 sub_item = proto_tree_add_item ( tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 expert_add_info ( pinfo , sub_item , & ei_btatt_bad_data ) ;
 offset = tvb_captured_length ( tvb ) ;
 }
 break ;
 case 0x09 : {
 guint8 length = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( main_tree , hf_btatt_length , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 if ( length > 0 ) {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Attribute List Length: %u" , tvb_reported_length_remaining ( tvb , offset ) / length ) ;
 while ( tvb_reported_length_remaining ( tvb , offset ) >= length ) {
 sub_item = proto_tree_add_none_format ( main_tree , hf_btatt_attribute_data , tvb , offset , length , "Attribute Data, Handle: 0x%04x" , tvb_get_letohs ( tvb , offset ) ) ;
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_list ) ;
 if ( request_data ) {
 save_handle ( pinfo , request_data -> parameters . read_by_type . uuid , tvb_get_guint16 ( tvb , offset , ENC_LITTLE_ENDIAN ) , ATTRIBUTE_TYPE_OTHER , bluetooth_data ) ;
 }
 offset = dissect_handle ( sub_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , NULL , HANDLE_TVB ) ;
 if ( request_data ) {
 offset = dissect_attribute_value ( sub_tree , sub_item , pinfo , tvb , offset , length - 2 , tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) , request_data -> parameters . read_by_type . uuid , & att_data ) ;
 }
 else {
 proto_tree_add_item ( sub_tree , hf_btatt_value , tvb , offset , length - 2 , ENC_NA ) ;
 offset += length - 2 ;
 }
 }
 }
 if ( request_data ) {
 sub_item = proto_tree_add_uint ( main_tree , hf_btatt_uuid16 , tvb , 0 , 0 , request_data -> parameters . read_by_type . uuid . bt_uuid ) ;
 PROTO_ITEM_SET_GENERATED ( sub_item ) ;
 }
 }
 break ;
 case 0x0a : offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_write . handle = handle ;
 request_parameters . read_write . offset = 0 ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 offset = dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , tvb_captured_length_remaining ( tvb , offset ) , handle , uuid , & att_data ) ;
 break ;
 case 0x0b : if ( request_data ) {
 dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , request_data -> parameters . read_write . handle ) ;
 col_append_info_by_handle ( pinfo , request_data -> parameters . read_write . handle , bluetooth_data ) ;
 }
 if ( is_long_attribute_value ( uuid ) && tvb_captured_length ( tvb ) >= mtu ) {
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 if ( ! pinfo -> fd -> flags . visited && request_data && bluetooth_data ) save_value_fragment ( pinfo , tvb , offset , request_data -> parameters . read_write . handle , 0 , bluetooth_data ) ;
 offset = tvb_captured_length ( tvb ) ;
 expert_add_info ( pinfo , sub_item , & ei_btatt_mtu_full ) ;
 }
 else {
 if ( request_data ) handle = request_data -> parameters . read_write . handle ;
 else handle = 0 ;
 offset = dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , tvb_captured_length_remaining ( tvb , offset ) , handle , uuid , & att_data ) ;
 }
 break ;
 case 0x0c : offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Offset: %u" , tvb_get_letohs ( tvb , offset ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_offset , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , 0 , handle , uuid , & att_data ) ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_write . handle = handle ;
 request_parameters . read_write . offset = tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 break ;
 case 0x0d : if ( request_data ) {
 dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , request_data -> parameters . read_write . handle ) ;
 col_append_info_by_handle ( pinfo , request_data -> parameters . read_write . handle , bluetooth_data ) ;
 if ( request_data -> parameters . read_write . offset == 0 && ! is_long_attribute_value ( uuid ) ) {
 offset = dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , tvb_captured_length_remaining ( tvb , offset ) , request_data -> parameters . read_write . handle , uuid , & att_data ) ;
 }
 else {
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) save_value_fragment ( pinfo , tvb , offset , request_data -> parameters . read_write . handle , request_data -> parameters . read_write . offset , bluetooth_data ) ;
 if ( tvb_captured_length ( tvb ) < mtu ) {
 tvbuff_t * next_tvb ;
 guint reassembled_length ;
 guint8 * reassembled_data ;
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 offset = tvb_captured_length ( tvb ) ;
 reassembled_data = get_value ( pinfo , request_data -> parameters . read_write . handle , bluetooth_data , & reassembled_length ) ;
 if ( reassembled_data ) {
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_value ) ;
 next_tvb = tvb_new_child_real_data ( tvb , reassembled_data , reassembled_length , reassembled_length ) ;
 add_new_data_source ( pinfo , next_tvb , "Reassembled ATT" ) ;
 dissect_attribute_value ( sub_tree , NULL , pinfo , next_tvb , 0 , tvb_captured_length ( next_tvb ) , request_data -> parameters . read_write . handle , uuid , & att_data ) ;
 }
 }
 else {
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 offset = tvb_captured_length ( tvb ) ;
 expert_add_info ( pinfo , sub_item , & ei_btatt_mtu_full ) ;
 }
 }
 }
 else {
 proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 offset = tvb_captured_length ( tvb ) ;
 }
 break ;
 case 0x0e : if ( tvb_reported_length_remaining ( tvb , offset ) < 4 ) {
 expert_add_info ( pinfo , main_item , & ei_btatt_handle_too_few ) ;
 break ;
 }
 col_append_str ( pinfo -> cinfo , COL_INFO , ", Handles: " ) ;
 while ( tvb_reported_length_remaining ( tvb , offset ) >= 2 ) {
 offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , "0x%04x " , handle ) ;
 dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , 0 , handle , uuid , & att_data ) ;
 }
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_multiple . number_of_handles = ( tvb_captured_length ( tvb ) - 1 ) / 2 ;
 request_parameters . read_multiple . handle = ( guint16 * ) tvb_memdup ( wmem_file_scope ( ) , tvb , 1 , request_parameters . read_multiple . number_of_handles * 2 ) ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 break ;
 case 0x0f : if ( request_data ) {
 guint i_handle ;
 for ( i_handle = 0 ;
 i_handle < request_data -> parameters . read_multiple . number_of_handles ;
 i_handle += 1 ) {
 dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , request_data -> parameters . read_multiple . handle [ i_handle ] ) ;
 offset = dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , tvb_captured_length_remaining ( tvb , offset ) , request_data -> parameters . read_multiple . handle [ i_handle ] , uuid , & att_data ) ;
 }
 }
 else {
 proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 offset = tvb_reported_length ( tvb ) ;
 }
 break ;
 case 0x11 : {
 guint8 length = tvb_get_guint8 ( tvb , offset ) ;
 proto_tree_add_item ( main_tree , hf_btatt_length , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 if ( length > 0 ) {
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Attribute List Length: %u" , tvb_reported_length_remaining ( tvb , offset ) / length ) ;
 while ( tvb_reported_length_remaining ( tvb , offset ) >= length ) {
 sub_item = proto_tree_add_none_format ( main_tree , hf_btatt_attribute_data , tvb , offset , length , "Attribute Data, Handle: 0x%04x, Group End Handle: 0x%04x" , tvb_get_letohs ( tvb , offset ) , tvb_get_letohs ( tvb , offset + 2 ) ) ;
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_list ) ;
 offset = dissect_handle ( sub_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , NULL , HANDLE_TVB ) ;
 handle = tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) ;
 proto_tree_add_item ( sub_tree , hf_btatt_group_end_handle , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( request_data ) {
 offset = dissect_attribute_value ( sub_tree , sub_item , pinfo , tvb , offset , length - 4 , handle , request_data -> parameters . read_by_type . uuid , & att_data ) ;
 }
 else {
 proto_tree_add_item ( sub_tree , hf_btatt_value , tvb , offset , length - 4 , ENC_NA ) ;
 offset += length - 4 ;
 }
 }
 }
 if ( request_data ) {
 sub_item = proto_tree_add_uint ( main_tree , hf_btatt_uuid16 , tvb , 0 , 0 , request_data -> parameters . read_by_type . uuid . bt_uuid ) ;
 PROTO_ITEM_SET_GENERATED ( sub_item ) ;
 }
 }
 break ;
 case 0x12 : case 0x1d : case 0x52 : case 0x1b : offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 offset = dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , tvb_captured_length_remaining ( tvb , offset ) , tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) , uuid , & att_data ) ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data && ( opcode == 0x12 || opcode == 0x1d ) ) {
 union request_parameters_union request_parameters ;
 request_parameters . read_write . handle = handle ;
 request_parameters . read_write . offset = 0 ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 break ;
 case 0x13 : if ( request_data ) {
 dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , request_data -> parameters . read_write . handle ) ;
 dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , 0 , request_data -> parameters . read_write . handle , uuid , & att_data ) ;
 col_append_info_by_handle ( pinfo , request_data -> parameters . read_write . handle , bluetooth_data ) ;
 }
 break ;
 case 0x16 : case 0x17 : offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 col_append_fstr ( pinfo -> cinfo , COL_INFO , ", Offset: %u" , tvb_get_letohs ( tvb , offset ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_offset , tvb , offset , 2 , ENC_LITTLE_ENDIAN ) ;
 offset += 2 ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data && opcode == 0x16 ) {
 union request_parameters_union request_parameters ;
 request_parameters . data = NULL ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 if ( ! pinfo -> fd -> flags . visited && request_data && bluetooth_data && opcode == 0x16 ) save_value_fragment ( pinfo , tvb , offset , tvb_get_guint16 ( tvb , offset - 4 , ENC_LITTLE_ENDIAN ) , tvb_get_guint16 ( tvb , offset - 2 , ENC_LITTLE_ENDIAN ) , bluetooth_data ) ;
 if ( request_data && tvb_captured_length ( tvb ) < mtu ) {
 tvbuff_t * next_tvb ;
 guint reassembled_length ;
 guint8 * reassembled_data ;
 sub_item = proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 reassembled_data = get_value ( pinfo , request_data -> parameters . read_write . handle , bluetooth_data , & reassembled_length ) ;
 if ( reassembled_data ) {
 sub_tree = proto_item_add_subtree ( sub_item , ett_btatt_value ) ;
 next_tvb = tvb_new_child_real_data ( tvb , reassembled_data , reassembled_length , reassembled_length ) ;
 add_new_data_source ( pinfo , next_tvb , "Reassembled ATT" ) ;
 dissect_attribute_value ( sub_tree , NULL , pinfo , next_tvb , 0 , tvb_captured_length ( next_tvb ) , request_data -> parameters . read_write . handle , uuid , & att_data ) ;
 }
 }
 else {
 proto_tree_add_item ( main_tree , hf_btatt_value , tvb , offset , - 1 , ENC_NA ) ;
 }
 offset = tvb_reported_length ( tvb ) ;
 break ;
 case 0x18 : col_append_fstr ( pinfo -> cinfo , COL_INFO , ", %s" , val_to_str_const ( tvb_get_guint8 ( tvb , offset ) , flags_vals , "<unknown>" ) ) ;
 proto_tree_add_item ( main_tree , hf_btatt_flags , tvb , offset , 1 , ENC_LITTLE_ENDIAN ) ;
 offset ++ ;
 if ( ! pinfo -> fd -> flags . visited && bluetooth_data ) {
 union request_parameters_union request_parameters ;
 request_parameters . data = NULL ;
 save_request ( pinfo , opcode , request_parameters , bluetooth_data ) ;
 }
 break ;
 case 0x19 : break ;
 case 0x1E : if ( request_data ) {
 dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , request_data -> parameters . read_write . handle ) ;
 col_append_info_by_handle ( pinfo , request_data -> parameters . read_write . handle , bluetooth_data ) ;
 dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , 0 , request_data -> parameters . read_write . handle , uuid , & att_data ) ;
 }
 break ;
 case 0xd2 : {
 guint8 length ;
 offset = dissect_handle ( main_tree , pinfo , hf_btatt_handle , tvb , offset , bluetooth_data , & uuid , HANDLE_TVB ) ;
 handle = tvb_get_letohs ( tvb , offset - 2 ) ;
 col_append_info_by_handle ( pinfo , handle , bluetooth_data ) ;
 length = tvb_reported_length_remaining ( tvb , offset ) ;
 dissect_attribute_value ( main_tree , NULL , pinfo , tvb , offset , ( length > 12 ) ? length - 12 : 0 , handle , uuid , & att_data ) ;
 if ( length > 12 ) {
 offset += length - 12 ;
 }
 proto_tree_add_item ( main_tree , hf_btatt_sign_counter , tvb , offset , 4 , ENC_LITTLE_ENDIAN ) ;
 offset += 4 ;
 proto_tree_add_item ( main_tree , hf_btatt_signature , tvb , offset , 8 , ENC_NA ) ;
 offset += 8 ;
 break ;
 }
 default : break ;
 }
 if ( request_data ) {
 if ( request_data -> request_in_frame > 0 && request_data -> request_in_frame != pinfo -> num ) {
 sub_item = proto_tree_add_uint ( main_tree , hf_request_in_frame , tvb , 0 , 0 , request_data -> request_in_frame ) ;
 PROTO_ITEM_SET_GENERATED ( sub_item ) ;
 }
 if ( ! pinfo -> fd -> flags . visited && request_data -> response_in_frame == 0 && pinfo -> num > request_data -> request_in_frame ) request_data -> response_in_frame = pinfo -> num ;
 if ( request_data -> response_in_frame > 0 && request_data -> response_in_frame != pinfo -> num ) {
 sub_item = proto_tree_add_uint ( main_tree , hf_response_in_frame , tvb , 0 , 0 , request_data -> response_in_frame ) ;
 PROTO_ITEM_SET_GENERATED ( sub_item ) ;
 }
 }
 return offset ;
 }
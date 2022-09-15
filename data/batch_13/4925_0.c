static int dissect_btgatt_microbit_client_requirements ( tvbuff_t * tvb , packet_info * pinfo _U_ , proto_tree * tree , void * data ) {
 btatt_data_t * att_data = ( btatt_data_t * ) data ;
 if ( bluetooth_gatt_has_no_parameter ( att_data -> opcode ) ) return - 1 ;
 proto_tree_add_item ( tree , hf_gatt_microbit_client_requirements , tvb , 0 , tvb_captured_length ( tvb ) , ENC_NA ) ;
 return tvb_captured_length ( tvb ) ;
 }
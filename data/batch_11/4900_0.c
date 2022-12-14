static void save_request ( packet_info * pinfo , guint8 opcode , union request_parameters_union parameters , bluetooth_data_t * bluetooth_data ) {
 wmem_tree_key_t key [ 5 ] ;
 guint32 frame_number , curr_layer_num ;
 request_data_t * request_data ;
 frame_number = pinfo -> num ;
 curr_layer_num = pinfo -> curr_layer_num ;
 key [ 0 ] . length = 1 ;
 key [ 0 ] . key = & bluetooth_data -> interface_id ;
 key [ 1 ] . length = 1 ;
 key [ 1 ] . key = & bluetooth_data -> adapter_id ;
 key [ 2 ] . length = 1 ;
 key [ 2 ] . key = & curr_layer_num ;
 key [ 3 ] . length = 1 ;
 key [ 3 ] . key = & frame_number ;
 key [ 4 ] . length = 0 ;
 key [ 4 ] . key = NULL ;
 request_data = wmem_new ( wmem_file_scope ( ) , request_data_t ) ;
 request_data -> opcode = opcode ;
 request_data -> request_in_frame = frame_number ;
 request_data -> response_in_frame = 0 ;
 request_data -> parameters = parameters ;
 wmem_tree_insert32_array ( requests , key , request_data ) ;
 }
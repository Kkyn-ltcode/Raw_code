server_info * create_sim_server ( address_node * addr , double server_offset , script_info_fifo * script ) {
 # ifndef SIM return NULL ;
 # else server_info * my_info ;
 my_info = emalloc_zero ( sizeof ( * my_info ) ) ;
 my_info -> server_time = server_offset ;
 my_info -> addr = get_next_address ( addr ) ;
 my_info -> script = script ;
 UNLINK_FIFO ( my_info -> curr_script , * my_info -> script , link ) ;
 return my_info ;
 # endif }
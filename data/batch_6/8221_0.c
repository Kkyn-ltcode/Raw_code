static iax_call_data * iax_new_call ( packet_info * pinfo , guint32 scallno ) {
 iax_call_data * call ;
 guint circuit_id ;
 static const nstime_t millisecond = {
 0 , 1000000 }
 ;
 # ifdef DEBUG_HASHING g_debug ( "+ new_circuit: Handling NEW packet, frame %u" , pinfo -> fd -> num ) ;
 # endif circuit_id = iax_circuit_lookup ( & pinfo -> src , pinfo -> ptype , pinfo -> srcport , scallno ) ;
 call = wmem_new ( wmem_file_scope ( ) , iax_call_data ) ;
 call -> dataformat = AST_DATAFORMAT_NULL ;
 call -> src_codec = 0 ;
 call -> dst_codec = 0 ;
 call -> n_forward_circuit_ids = 0 ;
 call -> n_reverse_circuit_ids = 0 ;
 call -> subdissector = NULL ;
 call -> start_time = pinfo -> fd -> abs_ts ;
 nstime_delta ( & call -> start_time , & call -> start_time , & millisecond ) ;
 init_dir_data ( & call -> dirdata [ 0 ] ) ;
 init_dir_data ( & call -> dirdata [ 1 ] ) ;
 iax2_new_circuit_for_call ( pinfo , NULL , circuit_id , pinfo -> fd -> num , call , FALSE ) ;
 return call ;
 }
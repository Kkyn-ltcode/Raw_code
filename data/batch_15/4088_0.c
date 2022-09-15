static void _slurm_rpc_dump_nodes ( slurm_msg_t * msg ) {
 DEF_TIMERS ;
 char * dump ;
 int dump_size ;
 slurm_msg_t response_msg ;
 node_info_request_msg_t * node_req_msg = ( node_info_request_msg_t * ) msg -> data ;
 slurmctld_lock_t node_write_lock = {
 READ_LOCK , NO_LOCK , WRITE_LOCK , READ_LOCK , NO_LOCK }
 ;
 uid_t uid = g_slurm_auth_get_uid ( msg -> auth_cred , slurmctld_config . auth_info ) ;
 START_TIMER ;
 debug3 ( "Processing RPC: REQUEST_NODE_INFO from uid=%d" , uid ) ;
 if ( ( slurmctld_conf . private_data & PRIVATE_DATA_NODES ) && ( ! validate_operator ( uid ) ) ) {
 error ( "Security violation, REQUEST_NODE_INFO RPC from uid=%d" , uid ) ;
 slurm_send_rc_msg ( msg , ESLURM_ACCESS_DENIED ) ;
 return ;
 }
 lock_slurmctld ( node_write_lock ) ;
 select_g_select_nodeinfo_set_all ( ) ;
 if ( ( node_req_msg -> last_update - 1 ) >= last_node_update ) {
 unlock_slurmctld ( node_write_lock ) ;
 debug3 ( "_slurm_rpc_dump_nodes, no change" ) ;
 slurm_send_rc_msg ( msg , SLURM_NO_CHANGE_IN_DATA ) ;
 }
 else {
 pack_all_node ( & dump , & dump_size , node_req_msg -> show_flags , uid , msg -> protocol_version ) ;
 unlock_slurmctld ( node_write_lock ) ;
 END_TIMER2 ( "_slurm_rpc_dump_nodes" ) ;
 # if 0 info ( "_slurm_rpc_dump_nodes, size=%d %s" , dump_size , TIME_STR ) ;
 # endif slurm_msg_t_init ( & response_msg ) ;
 response_msg . flags = msg -> flags ;
 response_msg . protocol_version = msg -> protocol_version ;
 response_msg . address = msg -> address ;
 response_msg . conn = msg -> conn ;
 response_msg . msg_type = RESPONSE_NODE_INFO ;
 response_msg . data = dump ;
 response_msg . data_size = dump_size ;
 slurm_send_node_msg ( msg -> conn_fd , & response_msg ) ;
 xfree ( dump ) ;
 }
 }
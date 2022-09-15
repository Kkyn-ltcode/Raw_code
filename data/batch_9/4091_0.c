static void _slurm_rpc_update_node ( slurm_msg_t * msg ) {
 int error_code = SLURM_SUCCESS ;
 DEF_TIMERS ;
 update_node_msg_t * update_node_msg_ptr = ( update_node_msg_t * ) msg -> data ;
 slurmctld_lock_t node_write_lock = {
 NO_LOCK , WRITE_LOCK , WRITE_LOCK , NO_LOCK , READ_LOCK }
 ;
 uid_t uid = g_slurm_auth_get_uid ( msg -> auth_cred , slurmctld_config . auth_info ) ;
 START_TIMER ;
 debug2 ( "Processing RPC: REQUEST_UPDATE_NODE from uid=%d" , uid ) ;
 if ( ! validate_super_user ( uid ) ) {
 error_code = ESLURM_USER_ID_MISSING ;
 error ( "Security violation, UPDATE_NODE RPC from uid=%d" , uid ) ;
 }
 if ( error_code == SLURM_SUCCESS ) {
 lock_slurmctld ( node_write_lock ) ;
 error_code = update_node ( update_node_msg_ptr ) ;
 unlock_slurmctld ( node_write_lock ) ;
 END_TIMER2 ( "_slurm_rpc_update_node" ) ;
 }
 if ( error_code ) {
 info ( "_slurm_rpc_update_node for %s: %s" , update_node_msg_ptr -> node_names , slurm_strerror ( error_code ) ) ;
 slurm_send_rc_msg ( msg , error_code ) ;
 }
 else {
 debug2 ( "_slurm_rpc_update_node complete for %s %s" , update_node_msg_ptr -> node_names , TIME_STR ) ;
 slurm_send_rc_msg ( msg , SLURM_SUCCESS ) ;
 }
 schedule_node_save ( ) ;
 queue_job_scheduler ( ) ;
 trigger_reconfig ( ) ;
 }
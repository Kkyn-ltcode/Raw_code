extern bool validate_operator ( uid_t uid ) {
 # ifndef NDEBUG if ( drop_priv ) return false ;
 # endif if ( ( uid == 0 ) || ( uid == slurmctld_conf . slurm_user_id ) || assoc_mgr_get_admin_level ( acct_db_conn , uid ) >= SLURMDB_ADMIN_OPERATOR ) return true ;
 else return false ;
 }
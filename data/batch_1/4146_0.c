extern bool validate_slurm_user ( uid_t uid ) {
 # ifndef NDEBUG if ( drop_priv ) return false ;
 # endif if ( ( uid == 0 ) || ( uid == slurmctld_conf . slurm_user_id ) ) return true ;
 else return false ;
 }
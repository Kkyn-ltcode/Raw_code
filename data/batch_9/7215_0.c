int main ( int argc , char * * argv ) {
 char * analyze_script_file_name = NULL ;
 char * deletion_script_file_name = NULL ;
 bool live_check = false ;
 parseCommandLine ( argc , argv ) ;
 get_restricted_token ( os_info . progname ) ;
 adjust_data_dir ( & old_cluster ) ;
 adjust_data_dir ( & new_cluster ) ;
 setup ( argv [ 0 ] , & live_check ) ;
 output_check_banner ( live_check ) ;
 check_cluster_versions ( ) ;
 get_sock_dir ( & old_cluster , live_check ) ;
 get_sock_dir ( & new_cluster , false ) ;
 check_cluster_compatibility ( live_check ) ;
 check_and_dump_old_cluster ( live_check ) ;
 start_postmaster ( & new_cluster , true ) ;
 check_new_cluster ( ) ;
 report_clusters_compatible ( ) ;
 pg_log ( PG_REPORT , "\nPerforming Upgrade\n" ) ;
 pg_log ( PG_REPORT , "------------------\n" ) ;
 prepare_new_cluster ( ) ;
 stop_postmaster ( false ) ;
 copy_clog_xlog_xid ( ) ;
 start_postmaster ( & new_cluster , true ) ;
 prepare_new_databases ( ) ;
 create_new_objects ( ) ;
 stop_postmaster ( false ) ;
 if ( user_opts . transfer_mode == TRANSFER_MODE_LINK ) disable_old_cluster ( ) ;
 transfer_all_new_tablespaces ( & old_cluster . dbarr , & new_cluster . dbarr , old_cluster . pgdata , new_cluster . pgdata ) ;
 prep_status ( "Setting next OID for new cluster" ) ;
 exec_prog ( UTILITY_LOG_FILE , NULL , true , "\"%s/pg_resetxlog\" -o %u \"%s\"" , new_cluster . bindir , old_cluster . controldata . chkpnt_nxtoid , new_cluster . pgdata ) ;
 check_ok ( ) ;
 prep_status ( "Sync data directory to disk" ) ;
 exec_prog ( UTILITY_LOG_FILE , NULL , true , "\"%s/initdb\" --sync-only \"%s\"" , new_cluster . bindir , new_cluster . pgdata ) ;
 check_ok ( ) ;
 create_script_for_cluster_analyze ( & analyze_script_file_name ) ;
 create_script_for_old_cluster_deletion ( & deletion_script_file_name ) ;
 issue_warnings ( ) ;
 pg_log ( PG_REPORT , "\nUpgrade Complete\n" ) ;
 pg_log ( PG_REPORT , "----------------\n" ) ;
 output_completion_banner ( analyze_script_file_name , deletion_script_file_name ) ;
 pg_free ( analyze_script_file_name ) ;
 pg_free ( deletion_script_file_name ) ;
 cleanup ( ) ;
 return 0 ;
 }
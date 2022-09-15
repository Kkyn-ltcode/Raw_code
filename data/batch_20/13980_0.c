static void set_effective_user ( struct passwd * user_info_arg ) {
 # if ! defined ( __WIN__ ) DBUG_ASSERT ( user_info_arg != 0 ) ;
 if ( setregid ( ( gid_t ) - 1 , user_info_arg -> pw_gid ) == - 1 ) {
 sql_perror ( "setregid" ) ;
 unireg_abort ( 1 ) ;
 }
 if ( setreuid ( ( uid_t ) - 1 , user_info_arg -> pw_uid ) == - 1 ) {
 sql_perror ( "setreuid" ) ;
 unireg_abort ( 1 ) ;
 }
 allow_coredumps ( ) ;
 # endif }
static void set_user ( const char * user , struct passwd * user_info_arg ) {
 # if ! defined ( __WIN__ ) DBUG_ASSERT ( user_info_arg != 0 ) ;
 # ifdef HAVE_INITGROUPS calling_initgroups = 1 ;
 initgroups ( ( char * ) user , user_info_arg -> pw_gid ) ;
 calling_initgroups = 0 ;
 # endif if ( setgid ( user_info_arg -> pw_gid ) == - 1 ) {
 sql_perror ( "setgid" ) ;
 unireg_abort ( 1 ) ;
 }
 if ( setuid ( user_info_arg -> pw_uid ) == - 1 ) {
 sql_perror ( "setuid" ) ;
 unireg_abort ( 1 ) ;
 }
 allow_coredumps ( ) ;
 # endif }
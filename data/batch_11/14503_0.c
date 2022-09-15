static void usage ( int version ) {
 # if defined ( USE_LIBEDIT_INTERFACE ) const char * readline = "" ;
 # else const char * readline = "readline" ;
 # endif # ifdef HAVE_READLINE printf ( "%s Ver %s Distrib %s, for %s (%s) using %s %s\n" , my_progname , VER , MYSQL_SERVER_VERSION , SYSTEM_TYPE , MACHINE_TYPE , readline , rl_library_version ) ;
 # else printf ( "%s Ver %s Distrib %s, for %s (%s)\n" , my_progname , VER , MYSQL_SERVER_VERSION , SYSTEM_TYPE , MACHINE_TYPE ) ;
 # endif if ( version ) return ;
 puts ( ORACLE_WELCOME_COPYRIGHT_NOTICE ( "2000" ) ) ;
 printf ( "Usage: %s [OPTIONS] [database]\n" , my_progname ) ;
 print_defaults ( "my" , load_default_groups ) ;
 puts ( "" ) ;
 my_print_help ( my_long_options ) ;
 my_print_variables ( my_long_options ) ;
 }
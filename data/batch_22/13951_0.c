static void usage ( void ) {
 DBUG_ENTER ( "usage" ) ;
 if ( ! ( default_charset_info = get_charset_by_csname ( default_character_set_name , MY_CS_PRIMARY , MYF ( MY_WME ) ) ) ) exit ( 1 ) ;
 if ( ! default_collation_name ) default_collation_name = ( char * ) default_charset_info -> name ;
 print_version ( ) ;
 puts ( ORACLE_WELCOME_COPYRIGHT_NOTICE ( "2000" ) ) ;
 puts ( "Starts the MariaDB database server.\n" ) ;
 printf ( "Usage: %s [OPTIONS]\n" , my_progname ) ;
 if ( ! opt_verbose ) puts ( "\nFor more help options (several pages), use mysqld --verbose --help." ) ;
 else {
 # ifdef __WIN__ puts ( "NT and Win32 specific options:\n\ --install Install the default service (NT).\n\ --install-manual Install the default service started manually (NT).\n\ --install service_name Install an optional service (NT).\n\ --install-manual service_name Install an optional service started manually (NT).\n\ --remove Remove the default service from the service list (NT).\n\ --remove service_name Remove the service_name from the service list (NT).\n\ --enable-named-pipe Only to be used for the default server (NT).\n\ --standalone Dummy option to start as a standalone server (NT).\ " ) ;
 puts ( "" ) ;
 # endif print_defaults ( MYSQL_CONFIG_NAME , load_default_groups ) ;
 puts ( "" ) ;
 set_ports ( ) ;
 print_help ( ) ;
 if ( ! plugins_are_initialized ) {
 puts ( "\n\ Plugins have parameters that are not reflected in this list\n\ because execution stopped before plugins were initialized." ) ;
 }
 puts ( "\n\ To see what values a running MySQL server is using, type\n\ 'mysqladmin variables' instead of 'mysqld --verbose --help'." ) ;
 }
 DBUG_VOID_RETURN ;
 }
static void get_options ( register int * argc , register char * * * argv ) {
 int ho_error ;
 if ( load_defaults ( "my" , load_default_groups , argc , argv ) ) exit ( 1 ) ;
 default_argv = * argv ;
 if ( isatty ( fileno ( stdout ) ) ) check_param . testflag |= T_WRITE_LOOP ;
 if ( ( ho_error = handle_options ( argc , argv , my_long_options , get_one_option ) ) ) exit ( ho_error ) ;
 if ( ( check_param . testflag & T_UPDATE_STATE ) && ( check_param . testflag & T_REP_ANY ) ) check_param . testflag |= T_CALC_CHECKSUM ;
 if ( * argc == 0 ) {
 usage ( ) ;
 exit ( - 1 ) ;
 }
 if ( ( check_param . testflag & T_UNPACK ) && ( check_param . testflag & ( T_QUICK | T_SORT_RECORDS ) ) ) {
 ( void ) fprintf ( stderr , "%s: --unpack can't be used with --quick or --sort-records\n" , my_progname_short ) ;
 exit ( 1 ) ;
 }
 if ( ( check_param . testflag & T_READONLY ) && ( check_param . testflag & ( T_REP_ANY | T_STATISTICS | T_AUTO_INC | T_SORT_RECORDS | T_SORT_INDEX | T_FORCE_CREATE ) ) ) {
 ( void ) fprintf ( stderr , "%s: Can't use --readonly when repairing or sorting\n" , my_progname_short ) ;
 exit ( 1 ) ;
 }
 if ( init_tmpdir ( & myisamchk_tmpdir , opt_tmpdir ) ) exit ( 1 ) ;
 check_param . tmpdir = & myisamchk_tmpdir ;
 check_param . key_cache_block_size = opt_key_cache_block_size ;
 if ( set_collation_name ) if ( ! ( set_collation = get_charset_by_name ( set_collation_name , MYF ( MY_WME ) ) ) ) exit ( 1 ) ;
 myisam_block_size = ( uint ) 1 << my_bit_log2 ( opt_myisam_block_size ) ;
 return ;
 }
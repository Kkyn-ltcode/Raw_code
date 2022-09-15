void save_and_apply_config_tree ( void ) {
 config_tree * ptree ;
 # ifndef SAVECONFIG config_tree * punlinked ;
 # endif ptree = emalloc ( sizeof ( * ptree ) ) ;
 memcpy ( ptree , & cfgt , sizeof ( * ptree ) ) ;
 memset ( & cfgt , 0 , sizeof ( cfgt ) ) ;
 LINK_TAIL_SLIST ( cfg_tree_history , ptree , link , config_tree ) ;
 # ifdef SAVECONFIG if ( HAVE_OPT ( SAVECONFIGQUIT ) ) {
 FILE * dumpfile ;
 int err ;
 int dumpfailed ;
 dumpfile = fopen ( OPT_ARG ( SAVECONFIGQUIT ) , "w" ) ;
 if ( NULL == dumpfile ) {
 err = errno ;
 fprintf ( stderr , "can not create save file %s, error %d %s\n" , OPT_ARG ( SAVECONFIGQUIT ) , err , strerror ( err ) ) ;
 exit ( err ) ;
 }
 dumpfailed = dump_all_config_trees ( dumpfile , 0 ) ;
 if ( dumpfailed ) fprintf ( stderr , "--saveconfigquit %s error %d\n" , OPT_ARG ( SAVECONFIGQUIT ) , dumpfailed ) ;
 else fprintf ( stderr , "configuration saved to %s\n" , OPT_ARG ( SAVECONFIGQUIT ) ) ;
 exit ( dumpfailed ) ;
 }
 # endif # ifndef SIM config_ntpd ( ptree ) ;
 # else config_ntpdsim ( ptree ) ;
 # endif # ifndef SAVECONFIG UNLINK_SLIST ( punlinked , cfg_tree_history , ptree , link , config_tree ) ;
 NTP_INSIST ( punlinked == ptree ) ;
 free_config_tree ( ptree ) ;
 # endif }
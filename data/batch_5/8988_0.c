static void config_qos ( config_tree * ptree ) {
 attr_val * my_qc ;
 char * s ;
 # ifdef HAVE_IPTOS_SUPPORT unsigned int qtos = 0 ;
 # endif my_qc = HEAD_PFIFO ( ptree -> qos ) ;
 for ( ;
 my_qc != NULL ;
 my_qc = my_qc -> link ) {
 s = my_qc -> value . s ;
 # ifdef HAVE_IPTOS_SUPPORT if ( ! strcmp ( s , "lowdelay" ) ) qtos = CONF_QOS_LOWDELAY ;
 else if ( ! strcmp ( s , "throughput" ) ) qtos = CONF_QOS_THROUGHPUT ;
 else if ( ! strcmp ( s , "reliability" ) ) qtos = CONF_QOS_RELIABILITY ;
 else if ( ! strcmp ( s , "mincost" ) ) qtos = CONF_QOS_MINCOST ;
 # ifdef IPTOS_PREC_INTERNETCONTROL else if ( ! strcmp ( s , "routine" ) || ! strcmp ( s , "cs0" ) ) qtos = CONF_QOS_CS0 ;
 else if ( ! strcmp ( s , "priority" ) || ! strcmp ( s , "cs1" ) ) qtos = CONF_QOS_CS1 ;
 else if ( ! strcmp ( s , "immediate" ) || ! strcmp ( s , "cs2" ) ) qtos = CONF_QOS_CS2 ;
 else if ( ! strcmp ( s , "flash" ) || ! strcmp ( s , "cs3" ) ) qtos = CONF_QOS_CS3 ;
 if ( ! strcmp ( s , "flashoverride" ) || ! strcmp ( s , "cs4" ) ) qtos = CONF_QOS_CS4 ;
 else if ( ! strcmp ( s , "critical" ) || ! strcmp ( s , "cs5" ) ) qtos = CONF_QOS_CS5 ;
 else if ( ! strcmp ( s , "internetcontrol" ) || ! strcmp ( s , "cs6" ) ) qtos = CONF_QOS_CS6 ;
 else if ( ! strcmp ( s , "netcontrol" ) || ! strcmp ( s , "cs7" ) ) qtos = CONF_QOS_CS7 ;
 # endif if ( qtos == 0 ) msyslog ( LOG_ERR , "parse error, qos %s not accepted\n" , s ) ;
 else qos = qtos ;
 # endif }
 }
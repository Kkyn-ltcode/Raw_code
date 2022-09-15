void config_nic_rules ( config_tree * ptree ) {
 nic_rule_node * curr_node ;
 sockaddr_u addr ;
 nic_rule_match match_type ;
 nic_rule_action action ;
 char * if_name ;
 char * pchSlash ;
 int prefixlen ;
 int addrbits ;
 curr_node = HEAD_PFIFO ( ptree -> nic_rules ) ;
 if ( curr_node != NULL && ( HAVE_OPT ( NOVIRTUALIPS ) || HAVE_OPT ( INTERFACE ) ) ) {
 msyslog ( LOG_ERR , "interfaceic rules are not allowed with --interface (-I) or --novirtualips (-L)%s" , ( input_from_file ) ? ", exiting" : "" ) ;
 if ( input_from_file ) exit ( 1 ) ;
 else return ;
 }
 for ( ;
 curr_node != NULL ;
 curr_node = curr_node -> link ) {
 prefixlen = - 1 ;
 if_name = curr_node -> if_name ;
 if ( if_name != NULL ) if_name = estrdup ( if_name ) ;
 switch ( curr_node -> match_class ) {
 default : match_type = MATCH_ALL ;
 NTP_INSIST ( 0 ) ;
 break ;
 case 0 : NTP_INSIST ( if_name != NULL ) ;
 pchSlash = strchr ( if_name , '/' ) ;
 if ( pchSlash != NULL ) * pchSlash = '\0' ;
 if ( is_ip_address ( if_name , AF_UNSPEC , & addr ) ) {
 match_type = MATCH_IFADDR ;
 if ( pchSlash != NULL ) {
 sscanf ( pchSlash + 1 , "%d" , & prefixlen ) ;
 addrbits = 8 * SIZEOF_INADDR ( AF ( & addr ) ) ;
 prefixlen = max ( - 1 , prefixlen ) ;
 prefixlen = min ( prefixlen , addrbits ) ;
 }
 }
 else {
 match_type = MATCH_IFNAME ;
 if ( pchSlash != NULL ) * pchSlash = '/' ;
 }
 break ;
 case T_All : match_type = MATCH_ALL ;
 break ;
 case T_Ipv4 : match_type = MATCH_IPV4 ;
 break ;
 case T_Ipv6 : match_type = MATCH_IPV6 ;
 break ;
 case T_Wildcard : match_type = MATCH_WILDCARD ;
 break ;
 }
 switch ( curr_node -> action ) {
 default : action = ACTION_LISTEN ;
 NTP_INSIST ( 0 ) ;
 break ;
 case T_Listen : action = ACTION_LISTEN ;
 break ;
 case T_Ignore : action = ACTION_IGNORE ;
 break ;
 case T_Drop : action = ACTION_DROP ;
 break ;
 }
 add_nic_rule ( match_type , if_name , prefixlen , action ) ;
 timer_interfacetimeout ( current_time + 2 ) ;
 if ( if_name != NULL ) free ( if_name ) ;
 }
 }
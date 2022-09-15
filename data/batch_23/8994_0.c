static void config_fudge ( config_tree * ptree ) {
 addr_opts_node * curr_fudge ;
 attr_val * curr_opt ;
 sockaddr_u addr_sock ;
 address_node * addr_node ;
 struct refclockstat clock_stat ;
 int err_flag ;
 curr_fudge = HEAD_PFIFO ( ptree -> fudge ) ;
 for ( ;
 curr_fudge != NULL ;
 curr_fudge = curr_fudge -> link ) {
 err_flag = 0 ;
 addr_node = curr_fudge -> addr ;
 ZERO_SOCK ( & addr_sock ) ;
 if ( getnetnum ( addr_node -> address , & addr_sock , 1 , t_REF ) != 1 ) {
 err_flag = 1 ;
 msyslog ( LOG_ERR , "unrecognized fudge reference clock address %s, line ignored" , stoa ( & addr_sock ) ) ;
 }
 if ( ! ISREFCLOCKADR ( & addr_sock ) ) {
 err_flag = 1 ;
 msyslog ( LOG_ERR , "inappropriate address %s for the fudge command, line ignored" , stoa ( & addr_sock ) ) ;
 }
 memset ( & clock_stat , 0 , sizeof ( clock_stat ) ) ;
 curr_opt = HEAD_PFIFO ( curr_fudge -> options ) ;
 for ( ;
 curr_opt != NULL ;
 curr_opt = curr_opt -> link ) {
 switch ( curr_opt -> attr ) {
 case T_Time1 : clock_stat . haveflags |= CLK_HAVETIME1 ;
 clock_stat . fudgetime1 = curr_opt -> value . d ;
 break ;
 case T_Time2 : clock_stat . haveflags |= CLK_HAVETIME2 ;
 clock_stat . fudgetime2 = curr_opt -> value . d ;
 break ;
 case T_Stratum : clock_stat . haveflags |= CLK_HAVEVAL1 ;
 clock_stat . fudgeval1 = curr_opt -> value . i ;
 break ;
 case T_Refid : clock_stat . haveflags |= CLK_HAVEVAL2 ;
 clock_stat . fudgeval2 = 0 ;
 memcpy ( & clock_stat . fudgeval2 , curr_opt -> value . s , min ( strlen ( curr_opt -> value . s ) , 4 ) ) ;
 break ;
 case T_Flag1 : clock_stat . haveflags |= CLK_HAVEFLAG1 ;
 if ( curr_opt -> value . i ) clock_stat . flags |= CLK_FLAG1 ;
 else clock_stat . flags &= ~ CLK_FLAG1 ;
 break ;
 case T_Flag2 : clock_stat . haveflags |= CLK_HAVEFLAG2 ;
 if ( curr_opt -> value . i ) clock_stat . flags |= CLK_FLAG2 ;
 else clock_stat . flags &= ~ CLK_FLAG2 ;
 break ;
 case T_Flag3 : clock_stat . haveflags |= CLK_HAVEFLAG3 ;
 if ( curr_opt -> value . i ) clock_stat . flags |= CLK_FLAG3 ;
 else clock_stat . flags &= ~ CLK_FLAG3 ;
 break ;
 case T_Flag4 : clock_stat . haveflags |= CLK_HAVEFLAG4 ;
 if ( curr_opt -> value . i ) clock_stat . flags |= CLK_FLAG4 ;
 else clock_stat . flags &= ~ CLK_FLAG4 ;
 break ;
 default : msyslog ( LOG_ERR , "Unexpected fudge flag %s (%d) for %s\n" , token_name ( curr_opt -> attr ) , curr_opt -> attr , stoa ( & addr_sock ) ) ;
 exit ( curr_opt -> attr ? curr_opt -> attr : 1 ) ;
 }
 }
 # ifdef REFCLOCK if ( ! err_flag ) refclock_control ( & addr_sock , & clock_stat , NULL ) ;
 # endif }
 }
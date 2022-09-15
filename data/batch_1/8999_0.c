static void config_tos ( config_tree * ptree ) {
 attr_val * tos ;
 int item ;
 item = - 1 ;
 tos = HEAD_PFIFO ( ptree -> orphan_cmds ) ;
 for ( ;
 tos != NULL ;
 tos = tos -> link ) {
 switch ( tos -> attr ) {
 default : NTP_INSIST ( 0 ) ;
 break ;
 case T_Ceiling : item = PROTO_CEILING ;
 break ;
 case T_Floor : item = PROTO_FLOOR ;
 break ;
 case T_Cohort : item = PROTO_COHORT ;
 break ;
 case T_Orphan : item = PROTO_ORPHAN ;
 break ;
 case T_Orphanwait : item = PROTO_ORPHWAIT ;
 break ;
 case T_Mindist : item = PROTO_MINDISP ;
 break ;
 case T_Maxdist : item = PROTO_MAXDIST ;
 break ;
 case T_Minclock : item = PROTO_MINCLOCK ;
 break ;
 case T_Maxclock : item = PROTO_MAXCLOCK ;
 break ;
 case T_Minsane : item = PROTO_MINSANE ;
 break ;
 case T_Beacon : item = PROTO_BEACON ;
 break ;
 }
 proto_config ( item , 0 , tos -> value . d , NULL ) ;
 }
 }
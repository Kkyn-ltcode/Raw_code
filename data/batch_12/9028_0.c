script_info * create_sim_script_info ( double duration , attr_val_fifo * script_queue ) {
 # ifndef SIM return NULL ;
 # else script_info * my_info ;
 attr_val * my_attr_val ;
 my_info = emalloc_zero ( sizeof ( * my_info ) ) ;
 my_info -> duration = duration ;
 my_info -> prop_delay = NET_DLY ;
 my_info -> proc_delay = PROC_DLY ;
 for ( my_attr_val = HEAD_PFIFO ( script_queue ) ;
 my_attr_val != NULL ;
 my_attr_val = my_attr_val -> link ) {
 switch ( my_attr_val -> attr ) {
 case T_Freq_Offset : my_info -> freq_offset = my_attr_val -> value . d ;
 break ;
 case T_Wander : my_info -> wander = my_attr_val -> value . d ;
 break ;
 case T_Jitter : my_info -> jitter = my_attr_val -> value . d ;
 break ;
 case T_Prop_Delay : my_info -> prop_delay = my_attr_val -> value . d ;
 break ;
 case T_Proc_Delay : my_info -> proc_delay = my_attr_val -> value . d ;
 break ;
 default : msyslog ( LOG_ERR , "Unknown script token %d" , my_attr_val -> attr ) ;
 }
 }
 return my_info ;
 # endif }
static void config_other_modes ( config_tree * ptree ) {
 sockaddr_u addr_sock ;
 address_node * addr_node ;
 if ( ptree -> broadcastclient ) proto_config ( PROTO_BROADCLIENT , ptree -> broadcastclient , 0. , NULL ) ;
 addr_node = HEAD_PFIFO ( ptree -> manycastserver ) ;
 while ( addr_node != NULL ) {
 ZERO_SOCK ( & addr_sock ) ;
 AF ( & addr_sock ) = addr_node -> type ;
 if ( 1 == getnetnum ( addr_node -> address , & addr_sock , 1 , t_UNK ) ) {
 proto_config ( PROTO_MULTICAST_ADD , 0 , 0. , & addr_sock ) ;
 sys_manycastserver = 1 ;
 }
 addr_node = addr_node -> link ;
 }
 addr_node = HEAD_PFIFO ( ptree -> multicastclient ) ;
 if ( addr_node != NULL ) {
 do {
 ZERO_SOCK ( & addr_sock ) ;
 AF ( & addr_sock ) = addr_node -> type ;
 if ( 1 == getnetnum ( addr_node -> address , & addr_sock , 1 , t_UNK ) ) {
 proto_config ( PROTO_MULTICAST_ADD , 0 , 0. , & addr_sock ) ;
 }
 addr_node = addr_node -> link ;
 }
 while ( addr_node != NULL ) ;
 proto_config ( PROTO_MULTICAST_ADD , 1 , 0. , NULL ) ;
 }
 }
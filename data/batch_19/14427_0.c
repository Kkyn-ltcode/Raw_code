static void dissect_llmnr_udp ( tvbuff_t * tvb , packet_info * pinfo , proto_tree * tree ) {
 col_set_str ( pinfo -> cinfo , COL_PROTOCOL , "LLMNR" ) ;
 dissect_dns_common ( tvb , pinfo , tree , FALSE , FALSE , TRUE ) ;
 }
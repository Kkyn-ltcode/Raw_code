static void add_rr_to_tree ( proto_tree * rr_tree , tvbuff_t * tvb , int offset , const guchar * name , int namelen , int type , packet_info * pinfo , gboolean is_mdns ) {
 proto_item * ttl_item ;
 gchar * * srv_rr_info ;
 if ( type == T_SRV ) {
 srv_rr_info = g_strsplit ( name , "." , 3 ) ;
 proto_tree_add_string ( rr_tree , hf_dns_srv_service , tvb , offset , namelen , srv_rr_info [ 0 ] ) ;
 if ( srv_rr_info [ 1 ] ) {
 proto_tree_add_string ( rr_tree , hf_dns_srv_proto , tvb , offset , namelen , srv_rr_info [ 1 ] ) ;
 if ( srv_rr_info [ 2 ] ) {
 proto_tree_add_string ( rr_tree , hf_dns_srv_name , tvb , offset , namelen , srv_rr_info [ 2 ] ) ;
 }
 }
 g_strfreev ( srv_rr_info ) ;
 }
 else {
 proto_tree_add_string ( rr_tree , hf_dns_rr_name , tvb , offset , namelen , name ) ;
 }
 offset += namelen ;
 proto_tree_add_item ( rr_tree , hf_dns_rr_type , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 offset += 2 ;
 if ( is_mdns ) {
 proto_tree_add_item ( rr_tree , hf_dns_rr_class_mdns , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 proto_tree_add_item ( rr_tree , hf_dns_rr_cache_flush , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 }
 else {
 proto_tree_add_item ( rr_tree , hf_dns_rr_class , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 }
 offset += 2 ;
 ttl_item = proto_tree_add_item ( rr_tree , hf_dns_rr_ttl , tvb , offset , 4 , ENC_BIG_ENDIAN | ENC_TIME_TIMESPEC ) ;
 if ( tvb_get_ntohl ( tvb , offset ) & 0x80000000 ) {
 expert_add_info ( pinfo , ttl_item , & ei_ttl_negative ) ;
 }
 offset += 4 ;
 proto_tree_add_item ( rr_tree , hf_dns_rr_len , tvb , offset , 2 , ENC_BIG_ENDIAN ) ;
 }
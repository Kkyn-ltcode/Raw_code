static void nlm_register_unmatched_msg ( packet_info * pinfo , tvbuff_t * tvb , int offset ) {
 nlm_msg_res_unmatched_data * umd ;
 nlm_msg_res_unmatched_data * old_umd ;
 umd = ( nlm_msg_res_unmatched_data * ) g_malloc ( sizeof ( nlm_msg_res_unmatched_data ) ) ;
 umd -> req_frame = pinfo -> fd -> num ;
 umd -> ns = pinfo -> fd -> abs_ts ;
 umd -> cookie_len = tvb_get_ntohl ( tvb , offset ) ;
 umd -> cookie = ( const guint8 * ) tvb_memdup ( NULL , tvb , offset + 4 , umd -> cookie_len ) ;
 old_umd = ( nlm_msg_res_unmatched_data * ) g_hash_table_lookup ( nlm_msg_res_unmatched , ( gconstpointer ) umd ) ;
 if ( old_umd ) {
 g_hash_table_remove ( nlm_msg_res_unmatched , ( gconstpointer ) old_umd ) ;
 }
 g_hash_table_insert ( nlm_msg_res_unmatched , ( gpointer ) umd , ( gpointer ) umd ) ;
 }
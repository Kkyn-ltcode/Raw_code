static void nlm_register_unmatched_res ( packet_info * pinfo , tvbuff_t * tvb , int offset ) {
 nlm_msg_res_unmatched_data umd ;
 nlm_msg_res_unmatched_data * old_umd ;
 umd . cookie_len = tvb_get_ntohl ( tvb , offset ) ;
 umd . cookie = tvb_get_ptr ( tvb , offset + 4 , - 1 ) ;
 old_umd = ( nlm_msg_res_unmatched_data * ) g_hash_table_lookup ( nlm_msg_res_unmatched , ( gconstpointer ) & umd ) ;
 if ( old_umd ) {
 nlm_msg_res_matched_data * md_req , * md_rep ;
 md_req = ( nlm_msg_res_matched_data * ) g_malloc ( sizeof ( nlm_msg_res_matched_data ) ) ;
 md_req -> req_frame = old_umd -> req_frame ;
 md_req -> rep_frame = pinfo -> fd -> num ;
 md_req -> ns = old_umd -> ns ;
 md_rep = ( nlm_msg_res_matched_data * ) g_memdup ( md_req , sizeof ( nlm_msg_res_matched_data ) ) ;
 g_hash_table_insert ( nlm_msg_res_matched , GINT_TO_POINTER ( md_req -> req_frame ) , ( gpointer ) md_req ) ;
 g_hash_table_insert ( nlm_msg_res_matched , GINT_TO_POINTER ( md_rep -> rep_frame ) , ( gpointer ) md_rep ) ;
 g_hash_table_remove ( nlm_msg_res_unmatched , ( gconstpointer ) old_umd ) ;
 }
 }
static void nlm_msg_res_unmatched_value_destroy ( gpointer value ) {
 nlm_msg_res_unmatched_data * umd = ( nlm_msg_res_unmatched_data * ) value ;
 wmem_free ( NULL , ( gpointer ) umd -> cookie ) ;
 g_free ( umd ) ;
 }
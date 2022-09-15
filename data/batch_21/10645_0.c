static guint16 de_conn_num ( tvbuff_t * tvb , proto_tree * tree , packet_info * pinfo , guint32 offset , guint len , gchar * add_string , int string_len ) {
 const gchar * extr_addr ;
 de_bcd_num ( tvb , tree , pinfo , offset , len , hf_gsm_a_dtap_conn_num , & extr_addr ) ;
 if ( extr_addr && add_string ) g_snprintf ( add_string , string_len , " - (%s)" , extr_addr ) ;
 return ( len ) ;
 }
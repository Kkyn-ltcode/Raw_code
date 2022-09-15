static void h245_setup_channels ( packet_info * pinfo , channel_info_t * upcoming_channel_lcl ) {
 rtp_dyn_payload_t * rtp_dyn_payload = NULL ;
 struct srtp_info * dummy_srtp_info = NULL ;
 if ( ! upcoming_channel_lcl ) return ;
 if ( ! strcmp ( upcoming_channel_lcl -> data_type_str , "t38fax" ) ) {
 if ( upcoming_channel_lcl -> media_addr . addr . type != AT_NONE && upcoming_channel_lcl -> media_addr . port != 0 ) {
 t38_add_address ( pinfo , & upcoming_channel_lcl -> media_addr . addr , upcoming_channel_lcl -> media_addr . port , 0 , "H245" , pinfo -> fd -> num ) ;
 }
 return ;
 }
 if ( upcoming_channel_lcl -> rfc2198 > 0 ) {
 rtp_dyn_payload = rtp_dyn_payload_new ( ) ;
 rtp_dyn_payload_insert ( rtp_dyn_payload , upcoming_channel_lcl -> rfc2198 , "red" , 8000 ) ;
 }
 if ( upcoming_channel_lcl -> srtp_flag ) {
 dummy_srtp_info = wmem_new0 ( wmem_file_scope ( ) , struct srtp_info ) ;
 }
 if ( upcoming_channel_lcl -> media_addr . addr . type != AT_NONE && upcoming_channel_lcl -> media_addr . port != 0 ) {
 srtp_add_address ( pinfo , & upcoming_channel_lcl -> media_addr . addr , upcoming_channel_lcl -> media_addr . port , 0 , "H245" , pinfo -> fd -> num , upcoming_channel_lcl -> is_video , rtp_dyn_payload , dummy_srtp_info ) ;
 }
 if ( upcoming_channel_lcl -> media_control_addr . addr . type != AT_NONE && upcoming_channel_lcl -> media_control_addr . port != 0 && rtcp_handle ) {
 srtcp_add_address ( pinfo , & upcoming_channel_lcl -> media_control_addr . addr , upcoming_channel_lcl -> media_control_addr . port , 0 , "H245" , pinfo -> fd -> num , dummy_srtp_info ) ;
 }
 }
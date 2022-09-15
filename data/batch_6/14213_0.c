static const gchar * get_register_name_from_address ( guint64 addr , gboolean * is_custom_register , u3v_conv_info_t * u3v_conv_info ) {
 const gchar * address_string = NULL ;
 guint32 offset_address ;
 if ( is_custom_register != NULL ) {
 * is_custom_register = FALSE ;
 }
 if ( addr < 0x10000 ) {
 offset_address = ( guint32 ) addr ;
 address_string = try_val_to_str ( offset_address , bootstrap_register_names_abrm ) ;
 }
 if ( u3v_conv_info && u3v_conv_info -> sbrm_addr != 0 && ( addr >= u3v_conv_info -> sbrm_addr ) ) {
 offset_address = ( guint32 ) ( addr - u3v_conv_info -> sbrm_addr ) ;
 address_string = try_val_to_str ( offset_address , bootstrap_register_names_sbrm ) ;
 }
 if ( u3v_conv_info && u3v_conv_info -> sirm_addr != 0 && ( addr >= u3v_conv_info -> sirm_addr ) ) {
 offset_address = ( guint32 ) ( addr - u3v_conv_info -> sirm_addr ) ;
 address_string = try_val_to_str ( offset_address , bootstrap_register_names_sirm ) ;
 }
 if ( u3v_conv_info && u3v_conv_info -> eirm_addr != 0 && ( addr >= u3v_conv_info -> eirm_addr ) ) {
 offset_address = ( guint32 ) ( addr - u3v_conv_info -> eirm_addr ) ;
 address_string = try_val_to_str ( offset_address , bootstrap_register_names_eirm ) ;
 }
 if ( ! address_string ) {
 address_string = wmem_strdup_printf ( wmem_packet_scope ( ) , "[Addr:0x%016" G_GINT64_MODIFIER "X]" , addr ) ;
 if ( is_custom_register != NULL ) {
 * is_custom_register = TRUE ;
 }
 }
 return address_string ;
 }
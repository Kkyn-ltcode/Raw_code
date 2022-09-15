void iax2_calls_init_tap ( void ) {
 GString * error_string ;
 if ( have_iax2_tap_listener == FALSE ) {
 error_string = register_tap_listener ( "IAX2" , & ( the_tapinfo_struct . iax2_dummy ) , NULL , TL_REQUIRES_PROTO_TREE , voip_calls_dlg_reset , iax2_calls_packet , voip_calls_dlg_draw ) ;
 if ( error_string != NULL ) {
 simple_dialog ( ESD_TYPE_ERROR , ESD_BTN_OK , "%s" , error_string -> str ) ;
 g_string_free ( error_string , TRUE ) ;
 exit ( 1 ) ;
 }
 have_iax2_tap_listener = TRUE ;
 }
 }
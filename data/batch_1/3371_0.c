void sip_calls_init_tap ( void ) {
 GString * error_string ;
 if ( have_SIP_tap_listener == FALSE ) {
 error_string = register_tap_listener ( "sip" , & ( the_tapinfo_struct . sip_dummy ) , NULL , 0 , voip_calls_dlg_reset , SIPcalls_packet , voip_calls_dlg_draw ) ;
 if ( error_string != NULL ) {
 simple_dialog ( ESD_TYPE_ERROR , ESD_BTN_OK , "%s" , error_string -> str ) ;
 g_string_free ( error_string , TRUE ) ;
 exit ( 1 ) ;
 }
 have_SIP_tap_listener = TRUE ;
 }
 }
void actrace_calls_init_tap ( void ) {
 GString * error_string ;
 if ( have_actrace_tap_listener == FALSE ) {
 error_string = register_tap_listener ( "actrace" , & ( the_tapinfo_struct . actrace_dummy ) , NULL , 0 , voip_calls_dlg_reset , ACTRACEcalls_packet , voip_calls_dlg_draw ) ;
 if ( error_string != NULL ) {
 simple_dialog ( ESD_TYPE_ERROR , ESD_BTN_OK , "%s" , error_string -> str ) ;
 g_string_free ( error_string , TRUE ) ;
 exit ( 1 ) ;
 }
 have_actrace_tap_listener = TRUE ;
 }
 }
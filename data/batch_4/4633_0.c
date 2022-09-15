static void pk_register_default ( void ) {
 gcry_err_code_t err = 0 ;
 int i ;
 for ( i = 0 ;
 ( ! err ) && pubkey_table [ i ] . pubkey ;
 i ++ ) {
 # define pubkey_use_dummy ( func ) \ if ( ! pubkey_table [ i ] . pubkey -> func ) \ pubkey_table [ i ] . pubkey -> func = dummy_ ## func ;
 pubkey_use_dummy ( generate ) ;
 pubkey_use_dummy ( check_secret_key ) ;
 pubkey_use_dummy ( encrypt ) ;
 pubkey_use_dummy ( decrypt ) ;
 pubkey_use_dummy ( sign ) ;
 pubkey_use_dummy ( verify ) ;
 pubkey_use_dummy ( get_nbits ) ;
 # undef pubkey_use_dummy err = _gcry_module_add ( & pubkeys_registered , pubkey_table [ i ] . algorithm , ( void * ) pubkey_table [ i ] . pubkey , ( void * ) pubkey_table [ i ] . extraspec , NULL ) ;
 }
 if ( err ) BUG ( ) ;
 }
static ossl_inline void lh_ ## type ## _doall ( LHASH_OF ( type ) * lh , void ( * doall ) ( type * ) ) {
 OPENSSL_LH_doall ( ( OPENSSL_LHASH * ) lh , ( OPENSSL_LH_DOALL_FUNC ) doall ) ;
 }
 LHASH_OF ( type ) # define IMPLEMENT_LHASH_DOALL_ARG_CONST ( type , argtype ) int_implement_lhash_doall ( type , argtype , const type ) # define IMPLEMENT_LHASH_DOALL_ARG ( type , argtype ) int_implement_lhash_doall ( type , argtype , type ) # define int_implement_lhash_doall ( type , argtype , cbargtype ) static ossl_inline void lh_ ## type ## _doall_ ## argtype ( LHASH_OF ( type ) * lh , void ( * fn ) ( cbargtype * , argtype * ) , argtype * arg ) {
 OPENSSL_LH_doall_arg ( ( OPENSSL_LHASH * ) lh , ( OPENSSL_LH_DOALL_FUNCARG ) fn , ( void * ) arg ) ;
 }
 LHASH_OF ( type ) DEFINE_LHASH_OF ( OPENSSL_STRING )
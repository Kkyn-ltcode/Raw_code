static gcry_err_code_t sexp_to_enc ( gcry_sexp_t sexp , gcry_mpi_t * * retarray , gcry_module_t * retalgo , int * ret_modern , int * flags , struct pk_encoding_ctx * ctx ) {
 gcry_err_code_t err = 0 ;
 gcry_sexp_t list = NULL , l2 = NULL ;
 gcry_pk_spec_t * pubkey = NULL ;
 gcry_module_t module = NULL ;
 char * name = NULL ;
 size_t n ;
 int parsed_flags = 0 ;
 const char * elems ;
 gcry_mpi_t * array = NULL ;
 * ret_modern = 0 ;
 list = gcry_sexp_find_token ( sexp , "enc-val" , 0 ) ;
 if ( ! list ) {
 err = GPG_ERR_INV_OBJ ;
 goto leave ;
 }
 l2 = gcry_sexp_nth ( list , 1 ) ;
 if ( ! l2 ) {
 err = GPG_ERR_NO_OBJ ;
 goto leave ;
 }
 name = _gcry_sexp_nth_string ( l2 , 0 ) ;
 if ( ! name ) {
 err = GPG_ERR_INV_OBJ ;
 goto leave ;
 }
 if ( ! strcmp ( name , "flags" ) ) {
 const char * s ;
 int i ;
 * ret_modern = 1 ;
 for ( i = gcry_sexp_length ( l2 ) - 1 ;
 i > 0 ;
 i -- ) {
 s = gcry_sexp_nth_data ( l2 , i , & n ) ;
 if ( ! s ) ;
 else if ( n == 3 && ! memcmp ( s , "raw" , 3 ) && ctx -> encoding == PUBKEY_ENC_UNKNOWN ) ctx -> encoding = PUBKEY_ENC_RAW ;
 else if ( n == 5 && ! memcmp ( s , "pkcs1" , 5 ) && ctx -> encoding == PUBKEY_ENC_UNKNOWN ) ctx -> encoding = PUBKEY_ENC_PKCS1 ;
 else if ( n == 4 && ! memcmp ( s , "oaep" , 4 ) && ctx -> encoding == PUBKEY_ENC_UNKNOWN ) ctx -> encoding = PUBKEY_ENC_OAEP ;
 else if ( n == 3 && ! memcmp ( s , "pss" , 3 ) && ctx -> encoding == PUBKEY_ENC_UNKNOWN ) {
 err = GPG_ERR_CONFLICT ;
 goto leave ;
 }
 else if ( n == 11 && ! memcmp ( s , "no-blinding" , 11 ) ) parsed_flags |= PUBKEY_FLAG_NO_BLINDING ;
 else {
 err = GPG_ERR_INV_FLAG ;
 goto leave ;
 }
 }
 gcry_sexp_release ( l2 ) ;
 if ( ctx -> encoding == PUBKEY_ENC_OAEP ) {
 l2 = gcry_sexp_find_token ( list , "hash-algo" , 0 ) ;
 if ( l2 ) {
 s = gcry_sexp_nth_data ( l2 , 1 , & n ) ;
 if ( ! s ) err = GPG_ERR_NO_OBJ ;
 else {
 ctx -> hash_algo = get_hash_algo ( s , n ) ;
 if ( ! ctx -> hash_algo ) err = GPG_ERR_DIGEST_ALGO ;
 }
 gcry_sexp_release ( l2 ) ;
 if ( err ) goto leave ;
 }
 l2 = gcry_sexp_find_token ( list , "label" , 0 ) ;
 if ( l2 ) {
 s = gcry_sexp_nth_data ( l2 , 1 , & n ) ;
 if ( ! s ) err = GPG_ERR_NO_OBJ ;
 else if ( n > 0 ) {
 ctx -> label = gcry_malloc ( n ) ;
 if ( ! ctx -> label ) err = gpg_err_code_from_syserror ( ) ;
 else {
 memcpy ( ctx -> label , s , n ) ;
 ctx -> labellen = n ;
 }
 }
 gcry_sexp_release ( l2 ) ;
 if ( err ) goto leave ;
 }
 }
 for ( i = 2 ;
 ( l2 = gcry_sexp_nth ( list , i ) ) != NULL ;
 i ++ ) {
 s = gcry_sexp_nth_data ( l2 , 0 , & n ) ;
 if ( ! ( n == 9 && ! memcmp ( s , "hash-algo" , 9 ) ) && ! ( n == 5 && ! memcmp ( s , "label" , 5 ) ) && ! ( n == 15 && ! memcmp ( s , "random-override" , 15 ) ) ) break ;
 gcry_sexp_release ( l2 ) ;
 }
 if ( ! l2 ) {
 err = GPG_ERR_NO_OBJ ;
 goto leave ;
 }
 gcry_free ( name ) ;
 name = _gcry_sexp_nth_string ( l2 , 0 ) ;
 if ( ! name ) {
 err = GPG_ERR_INV_OBJ ;
 goto leave ;
 }
 gcry_sexp_release ( list ) ;
 list = l2 ;
 l2 = NULL ;
 }
 ath_mutex_lock ( & pubkeys_registered_lock ) ;
 module = gcry_pk_lookup_name ( name ) ;
 ath_mutex_unlock ( & pubkeys_registered_lock ) ;
 if ( ! module ) {
 err = GPG_ERR_PUBKEY_ALGO ;
 goto leave ;
 }
 pubkey = ( gcry_pk_spec_t * ) module -> spec ;
 elems = pubkey -> elements_enc ;
 array = gcry_calloc ( strlen ( elems ) + 1 , sizeof ( * array ) ) ;
 if ( ! array ) {
 err = gpg_err_code_from_syserror ( ) ;
 goto leave ;
 }
 err = sexp_elements_extract ( list , elems , array , NULL , 0 ) ;
 leave : gcry_sexp_release ( list ) ;
 gcry_sexp_release ( l2 ) ;
 gcry_free ( name ) ;
 if ( err ) {
 ath_mutex_lock ( & pubkeys_registered_lock ) ;
 _gcry_module_release ( module ) ;
 ath_mutex_unlock ( & pubkeys_registered_lock ) ;
 gcry_free ( array ) ;
 gcry_free ( ctx -> label ) ;
 ctx -> label = NULL ;
 }
 else {
 * retarray = array ;
 * retalgo = module ;
 * flags = parsed_flags ;
 }
 return err ;
 }
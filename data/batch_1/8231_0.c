static guint iax_circuit_hash ( gconstpointer v ) {
 const iax_circuit_key * key = ( const iax_circuit_key * ) v ;
 guint hash_val ;
 hash_val = 0 ;
 ADD_ADDRESS_TO_HASH ( hash_val , & key -> addr ) ;
 hash_val += ( guint ) ( key -> ptype ) ;
 hash_val += ( guint ) ( key -> port ) ;
 hash_val += ( guint ) ( key -> callno ) ;
 # ifdef DEBUG_HASHING g_debug ( "+++ Hashing key: %s, result %#x" , key_to_str ( key ) , hash_val ) ;
 # endif return ( guint ) hash_val ;
 }
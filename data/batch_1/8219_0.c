static gint iax_circuit_equal ( gconstpointer v , gconstpointer w ) {
 const iax_circuit_key * v1 = ( const iax_circuit_key * ) v ;
 const iax_circuit_key * v2 = ( const iax_circuit_key * ) w ;
 gint result ;
 result = ( ADDRESSES_EQUAL ( & ( v1 -> addr ) , & ( v2 -> addr ) ) && v1 -> ptype == v2 -> ptype && v1 -> port == v2 -> port && v1 -> callno == v2 -> callno ) ;
 # ifdef DEBUG_HASHING g_debug ( "+++ Comparing for equality: %s, %s: %u" , key_to_str ( v1 ) , key_to_str ( v2 ) , result ) ;
 # endif return result ;
 }
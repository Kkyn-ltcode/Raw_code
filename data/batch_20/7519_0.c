void free_pointer_array ( POINTER_ARRAY * pa ) {
 if ( pa -> typelib . count ) {
 pa -> typelib . count = 0 ;
 my_free ( pa -> typelib . type_names ) ;
 pa -> typelib . type_names = 0 ;
 my_free ( pa -> str ) ;
 }
 }
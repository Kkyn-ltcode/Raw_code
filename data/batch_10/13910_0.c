THD * first_global_thread ( ) {
 if ( threads . is_empty ( ) ) return NULL ;
 return threads . head ( ) ;
 }
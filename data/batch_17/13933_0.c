THD * next_global_thread ( THD * thd ) {
 if ( threads . is_last ( thd ) ) return NULL ;
 struct ilink * next = thd -> next ;
 return static_cast < THD * > ( next ) ;
 }
static char * search_make_new ( const struct search_state * const state , int n , const char * const base_name ) {
 const int base_len = strlen ( base_name ) ;
 const char need_to_append_dot = base_name [ base_len - 1 ] == '.' ? 0 : 1 ;
 struct search_domain * dom ;
 for ( dom = state -> head ;
 dom ;
 dom = dom -> next ) {
 if ( ! n -- ) {
 const u8 * const postfix = ( ( u8 * ) dom ) + sizeof ( struct search_domain ) ;
 const int postfix_len = dom -> len ;
 char * const newname = ( char * ) malloc ( base_len + need_to_append_dot + postfix_len + 1 ) ;
 if ( ! newname ) return NULL ;
 memcpy ( newname , base_name , base_len ) ;
 if ( need_to_append_dot ) newname [ base_len ] = '.' ;
 memcpy ( newname + base_len + need_to_append_dot , postfix , postfix_len ) ;
 newname [ base_len + need_to_append_dot + postfix_len ] = 0 ;
 return newname ;
 }
 }
 abort ( ) ;
 return NULL ;
 }
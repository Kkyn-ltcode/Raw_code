clump_t * clump_splay_walk_bwd ( clump_splay_walker * sw ) {
 clump_t * cp = sw -> cp ;
 int from = sw -> from ;
 if ( cp == NULL ) return NULL ;
 while ( 1 ) {
 if ( from == SPLAY_FROM_ABOVE ) {
 if ( cp -> right ) {
 cp = cp -> right ;
 from = SPLAY_FROM_ABOVE ;
 continue ;
 }
 from = SPLAY_FROM_RIGHT ;
 if ( cp == sw -> end ) cp = NULL ;
 break ;
 }
 if ( from == SPLAY_FROM_RIGHT ) {
 if ( cp -> left ) {
 cp = cp -> left ;
 from = SPLAY_FROM_ABOVE ;
 continue ;
 }
 from = SPLAY_FROM_LEFT ;
 }
 if ( from == SPLAY_FROM_LEFT ) {
 clump_t * old = cp ;
 cp = cp -> parent ;
 from = ( cp == NULL || cp -> left != old ? SPLAY_FROM_RIGHT : SPLAY_FROM_LEFT ) ;
 if ( from == SPLAY_FROM_RIGHT ) {
 if ( cp == sw -> end ) cp = NULL ;
 break ;
 }
 }
 }
 sw -> cp = cp ;
 sw -> from = from ;
 return cp ;
 }
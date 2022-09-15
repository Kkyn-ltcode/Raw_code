static void dtls1_clear_queues ( SSL * s ) {
 pitem * item = NULL ;
 hm_fragment * frag = NULL ;
 while ( ( item = pqueue_pop ( s -> d1 -> buffered_messages ) ) != NULL ) {
 frag = ( hm_fragment * ) item -> data ;
 dtls1_hm_fragment_free ( frag ) ;
 pitem_free ( item ) ;
 }
 while ( ( item = pqueue_pop ( s -> d1 -> sent_messages ) ) != NULL ) {
 frag = ( hm_fragment * ) item -> data ;
 dtls1_hm_fragment_free ( frag ) ;
 pitem_free ( item ) ;
 }
 }
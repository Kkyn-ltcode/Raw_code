static void show_commit ( struct commit * commit , void * data ) {
 struct rev_list_info * info = data ;
 struct rev_info * revs = info -> revs ;
 if ( info -> flags & REV_LIST_QUIET ) {
 finish_commit ( commit , data ) ;
 return ;
 }
 graph_show_commit ( revs -> graph ) ;
 if ( revs -> count ) {
 if ( commit -> object . flags & PATCHSAME ) revs -> count_same ++ ;
 else if ( commit -> object . flags & SYMMETRIC_LEFT ) revs -> count_left ++ ;
 else revs -> count_right ++ ;
 finish_commit ( commit , data ) ;
 return ;
 }
 if ( info -> show_timestamp ) printf ( "%lu " , commit -> date ) ;
 if ( info -> header_prefix ) fputs ( info -> header_prefix , stdout ) ;
 if ( ! revs -> graph ) fputs ( get_revision_mark ( revs , commit ) , stdout ) ;
 if ( revs -> abbrev_commit && revs -> abbrev ) fputs ( find_unique_abbrev ( commit -> object . oid . hash , revs -> abbrev ) , stdout ) ;
 else fputs ( oid_to_hex ( & commit -> object . oid ) , stdout ) ;
 if ( revs -> print_parents ) {
 struct commit_list * parents = commit -> parents ;
 while ( parents ) {
 printf ( " %s" , oid_to_hex ( & parents -> item -> object . oid ) ) ;
 parents = parents -> next ;
 }
 }
 if ( revs -> children . name ) {
 struct commit_list * children ;
 children = lookup_decoration ( & revs -> children , & commit -> object ) ;
 while ( children ) {
 printf ( " %s" , oid_to_hex ( & children -> item -> object . oid ) ) ;
 children = children -> next ;
 }
 }
 show_decorations ( revs , commit ) ;
 if ( revs -> commit_format == CMIT_FMT_ONELINE ) putchar ( ' ' ) ;
 else putchar ( '\n' ) ;
 if ( revs -> verbose_header && get_cached_commit_buffer ( commit , NULL ) ) {
 struct strbuf buf = STRBUF_INIT ;
 struct pretty_print_context ctx = {
 0 }
 ;
 ctx . abbrev = revs -> abbrev ;
 ctx . date_mode = revs -> date_mode ;
 ctx . date_mode_explicit = revs -> date_mode_explicit ;
 ctx . fmt = revs -> commit_format ;
 ctx . output_encoding = get_log_output_encoding ( ) ;
 pretty_print_commit ( & ctx , commit , & buf ) ;
 if ( revs -> graph ) {
 if ( buf . len ) {
 if ( revs -> commit_format != CMIT_FMT_ONELINE ) graph_show_oneline ( revs -> graph ) ;
 graph_show_commit_msg ( revs -> graph , & buf ) ;
 if ( buf . len && buf . buf [ buf . len - 1 ] == '\n' ) graph_show_padding ( revs -> graph ) ;
 putchar ( '\n' ) ;
 }
 else {
 if ( graph_show_remainder ( revs -> graph ) ) putchar ( '\n' ) ;
 if ( revs -> commit_format == CMIT_FMT_ONELINE ) putchar ( '\n' ) ;
 }
 }
 else {
 if ( revs -> commit_format != CMIT_FMT_USERFORMAT || buf . len ) {
 fwrite ( buf . buf , 1 , buf . len , stdout ) ;
 putchar ( info -> hdr_termination ) ;
 }
 }
 strbuf_release ( & buf ) ;
 }
 else {
 if ( graph_show_remainder ( revs -> graph ) ) putchar ( '\n' ) ;
 }
 maybe_flush_or_die ( stdout , "stdout" ) ;
 finish_commit ( commit , data ) ;
 }
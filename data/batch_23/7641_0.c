static int sort_key_write ( MI_SORT_PARAM * sort_param , const void * a ) {
 uint diff_pos [ 2 ] ;
 char llbuff [ 22 ] , llbuff2 [ 22 ] ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 MI_CHECK * param = sort_info -> param ;
 int cmp ;
 if ( sort_info -> key_block -> inited ) {
 cmp = ha_key_cmp ( sort_param -> seg , sort_info -> key_block -> lastkey , ( uchar * ) a , USE_WHOLE_KEY , SEARCH_FIND | SEARCH_UPDATE , diff_pos ) ;
 if ( param -> stats_method == MI_STATS_METHOD_NULLS_NOT_EQUAL ) ha_key_cmp ( sort_param -> seg , sort_info -> key_block -> lastkey , ( uchar * ) a , USE_WHOLE_KEY , SEARCH_FIND | SEARCH_NULL_ARE_NOT_EQUAL , diff_pos ) ;
 else if ( param -> stats_method == MI_STATS_METHOD_IGNORE_NULLS ) {
 diff_pos [ 0 ] = mi_collect_stats_nonulls_next ( sort_param -> seg , sort_param -> notnull , sort_info -> key_block -> lastkey , ( uchar * ) a ) ;
 }
 sort_param -> unique [ diff_pos [ 0 ] - 1 ] ++ ;
 }
 else {
 cmp = - 1 ;
 if ( param -> stats_method == MI_STATS_METHOD_IGNORE_NULLS ) mi_collect_stats_nonulls_first ( sort_param -> seg , sort_param -> notnull , ( uchar * ) a ) ;
 }
 if ( ( sort_param -> keyinfo -> flag & HA_NOSAME ) && cmp == 0 ) {
 sort_info -> dupp ++ ;
 sort_info -> info -> lastpos = get_record_for_key ( sort_info -> info , sort_param -> keyinfo , ( uchar * ) a ) ;
 mi_check_print_warning ( param , "Duplicate key for record at %10s against record at %10s" , llstr ( sort_info -> info -> lastpos , llbuff ) , llstr ( get_record_for_key ( sort_info -> info , sort_param -> keyinfo , sort_info -> key_block -> lastkey ) , llbuff2 ) ) ;
 param -> testflag |= T_RETRY_WITHOUT_QUICK ;
 if ( sort_info -> param -> testflag & T_VERBOSE ) _mi_print_key ( stdout , sort_param -> seg , ( uchar * ) a , USE_WHOLE_KEY ) ;
 return ( sort_delete_record ( sort_param ) ) ;
 }
 # ifndef DBUG_OFF if ( cmp > 0 ) {
 mi_check_print_error ( param , "Internal error: Keys are not in order from sort" ) ;
 return ( 1 ) ;
 }
 # endif return ( sort_insert_key ( sort_param , sort_info -> key_block , ( uchar * ) a , HA_OFFSET_ERROR ) ) ;
 }
static int sort_insert_key ( MI_SORT_PARAM * sort_param , register SORT_KEY_BLOCKS * key_block , uchar * key , my_off_t prev_block ) {
 uint a_length , t_length , nod_flag ;
 my_off_t filepos , key_file_length ;
 uchar * anc_buff , * lastkey ;
 MI_KEY_PARAM s_temp ;
 MI_INFO * info ;
 MI_KEYDEF * keyinfo = sort_param -> keyinfo ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 MI_CHECK * param = sort_info -> param ;
 DBUG_ENTER ( "sort_insert_key" ) ;
 anc_buff = key_block -> buff ;
 info = sort_info -> info ;
 lastkey = key_block -> lastkey ;
 nod_flag = ( key_block == sort_info -> key_block ? 0 : info -> s -> base . key_reflength ) ;
 if ( ! key_block -> inited ) {
 key_block -> inited = 1 ;
 if ( key_block == sort_info -> key_block_end ) {
 mi_check_print_error ( param , "To many key-block-levels;
 Try increasing sort_key_blocks" ) ;
 DBUG_RETURN ( 1 ) ;
 }
 a_length = 2 + nod_flag ;
 key_block -> end_pos = anc_buff + 2 ;
 lastkey = 0 ;
 }
 else a_length = mi_getint ( anc_buff ) ;
 if ( nod_flag ) _mi_kpointer ( info , key_block -> end_pos , prev_block ) ;
 t_length = ( * keyinfo -> pack_key ) ( keyinfo , nod_flag , ( uchar * ) 0 , lastkey , lastkey , key , & s_temp ) ;
 ( * keyinfo -> store_key ) ( keyinfo , key_block -> end_pos + nod_flag , & s_temp ) ;
 a_length += t_length ;
 mi_putint ( anc_buff , a_length , nod_flag ) ;
 key_block -> end_pos += t_length ;
 if ( a_length <= keyinfo -> block_length ) {
 ( void ) _mi_move_key ( keyinfo , key_block -> lastkey , key ) ;
 key_block -> last_length = a_length - t_length ;
 DBUG_RETURN ( 0 ) ;
 }
 mi_putint ( anc_buff , key_block -> last_length , nod_flag ) ;
 bzero ( ( uchar * ) anc_buff + key_block -> last_length , keyinfo -> block_length - key_block -> last_length ) ;
 key_file_length = info -> state -> key_file_length ;
 if ( ( filepos = _mi_new ( info , keyinfo , DFLT_INIT_HITS ) ) == HA_OFFSET_ERROR ) DBUG_RETURN ( 1 ) ;
 if ( key_file_length == info -> state -> key_file_length ) {
 if ( _mi_write_keypage ( info , keyinfo , filepos , DFLT_INIT_HITS , anc_buff ) ) DBUG_RETURN ( 1 ) ;
 }
 else if ( mysql_file_pwrite ( info -> s -> kfile , ( uchar * ) anc_buff , ( uint ) keyinfo -> block_length , filepos , param -> myf_rw ) ) DBUG_RETURN ( 1 ) ;
 DBUG_DUMP ( "buff" , ( uchar * ) anc_buff , mi_getint ( anc_buff ) ) ;
 if ( sort_insert_key ( sort_param , key_block + 1 , key_block -> lastkey , filepos ) ) DBUG_RETURN ( 1 ) ;
 key_block -> inited = 0 ;
 DBUG_RETURN ( sort_insert_key ( sort_param , key_block , key , prev_block ) ) ;
 }
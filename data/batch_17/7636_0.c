int flush_pending_blocks ( MI_SORT_PARAM * sort_param ) {
 uint nod_flag , length ;
 my_off_t filepos , key_file_length ;
 SORT_KEY_BLOCKS * key_block ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 myf myf_rw = sort_info -> param -> myf_rw ;
 MI_INFO * info = sort_info -> info ;
 MI_KEYDEF * keyinfo = sort_param -> keyinfo ;
 DBUG_ENTER ( "flush_pending_blocks" ) ;
 filepos = HA_OFFSET_ERROR ;
 nod_flag = 0 ;
 for ( key_block = sort_info -> key_block ;
 key_block -> inited ;
 key_block ++ ) {
 key_block -> inited = 0 ;
 length = mi_getint ( key_block -> buff ) ;
 if ( nod_flag ) _mi_kpointer ( info , key_block -> end_pos , filepos ) ;
 key_file_length = info -> state -> key_file_length ;
 bzero ( ( uchar * ) key_block -> buff + length , keyinfo -> block_length - length ) ;
 if ( ( filepos = _mi_new ( info , keyinfo , DFLT_INIT_HITS ) ) == HA_OFFSET_ERROR ) DBUG_RETURN ( 1 ) ;
 if ( key_file_length == info -> state -> key_file_length ) {
 if ( _mi_write_keypage ( info , keyinfo , filepos , DFLT_INIT_HITS , key_block -> buff ) ) DBUG_RETURN ( 1 ) ;
 }
 else if ( mysql_file_pwrite ( info -> s -> kfile , ( uchar * ) key_block -> buff , ( uint ) keyinfo -> block_length , filepos , myf_rw ) ) DBUG_RETURN ( 1 ) ;
 DBUG_DUMP ( "buff" , ( uchar * ) key_block -> buff , length ) ;
 nod_flag = 1 ;
 }
 info -> s -> state . key_root [ sort_param -> key ] = filepos ;
 DBUG_RETURN ( 0 ) ;
 }
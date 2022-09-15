static int chk_index ( MI_CHECK * param , MI_INFO * info , MI_KEYDEF * keyinfo , my_off_t page , uchar * buff , ha_rows * keys , ha_checksum * key_checksum , uint level ) {
 int flag ;
 uint used_length , comp_flag , nod_flag , key_length = 0 ;
 uchar key [ HA_MAX_POSSIBLE_KEY_BUFF ] , * temp_buff , * keypos , * old_keypos , * endpos ;
 my_off_t next_page , record ;
 char llbuff [ 22 ] ;
 uint diff_pos [ 2 ] ;
 DBUG_ENTER ( "chk_index" ) ;
 DBUG_DUMP ( "buff" , ( uchar * ) buff , mi_getint ( buff ) ) ;
 if ( keyinfo -> flag & HA_SPATIAL ) DBUG_RETURN ( 0 ) ;
 if ( ! ( temp_buff = ( uchar * ) my_alloca ( ( uint ) keyinfo -> block_length ) ) ) {
 mi_check_print_error ( param , "Not enough memory for keyblock" ) ;
 DBUG_RETURN ( - 1 ) ;
 }
 if ( keyinfo -> flag & HA_NOSAME ) comp_flag = SEARCH_FIND | SEARCH_UPDATE ;
 else comp_flag = SEARCH_SAME ;
 nod_flag = mi_test_if_nod ( buff ) ;
 used_length = mi_getint ( buff ) ;
 keypos = buff + 2 + nod_flag ;
 endpos = buff + used_length ;
 param -> keydata += used_length ;
 param -> totaldata += keyinfo -> block_length ;
 param -> key_blocks ++ ;
 if ( level > param -> max_level ) param -> max_level = level ;
 if ( used_length > keyinfo -> block_length ) {
 mi_check_print_error ( param , "Wrong pageinfo at page: %s" , llstr ( page , llbuff ) ) ;
 goto err ;
 }
 for ( ;
 ;
 ) {
 if ( * killed_ptr ( param ) ) goto err ;
 memcpy ( ( char * ) info -> lastkey , ( char * ) key , key_length ) ;
 info -> lastkey_length = key_length ;
 if ( nod_flag ) {
 next_page = _mi_kpos ( nod_flag , keypos ) ;
 if ( chk_index_down ( param , info , keyinfo , next_page , temp_buff , keys , key_checksum , level + 1 ) ) goto err ;
 }
 old_keypos = keypos ;
 if ( keypos >= endpos || ( key_length = ( * keyinfo -> get_key ) ( keyinfo , nod_flag , & keypos , key ) ) == 0 ) break ;
 if ( keypos > endpos ) {
 mi_check_print_error ( param , "Wrong key block length at page: %s" , llstr ( page , llbuff ) ) ;
 goto err ;
 }
 if ( ( * keys ) ++ && ( flag = ha_key_cmp ( keyinfo -> seg , info -> lastkey , key , key_length , comp_flag , diff_pos ) ) >= 0 ) {
 DBUG_DUMP ( "old" , ( uchar * ) info -> lastkey , info -> lastkey_length ) ;
 DBUG_DUMP ( "new" , ( uchar * ) key , key_length ) ;
 DBUG_DUMP ( "new_in_page" , ( uchar * ) old_keypos , ( uint ) ( keypos - old_keypos ) ) ;
 if ( comp_flag & SEARCH_FIND && flag == 0 ) mi_check_print_error ( param , "Found duplicated key at page %s" , llstr ( page , llbuff ) ) ;
 else mi_check_print_error ( param , "Key in wrong position at page %s" , llstr ( page , llbuff ) ) ;
 goto err ;
 }
 if ( param -> testflag & T_STATISTICS ) {
 if ( * keys != 1L ) {
 if ( param -> stats_method == MI_STATS_METHOD_NULLS_NOT_EQUAL ) ha_key_cmp ( keyinfo -> seg , info -> lastkey , key , USE_WHOLE_KEY , SEARCH_FIND | SEARCH_NULL_ARE_NOT_EQUAL , diff_pos ) ;
 else if ( param -> stats_method == MI_STATS_METHOD_IGNORE_NULLS ) {
 diff_pos [ 0 ] = mi_collect_stats_nonulls_next ( keyinfo -> seg , param -> notnull_count , info -> lastkey , key ) ;
 }
 param -> unique_count [ diff_pos [ 0 ] - 1 ] ++ ;
 }
 else {
 if ( param -> stats_method == MI_STATS_METHOD_IGNORE_NULLS ) mi_collect_stats_nonulls_first ( keyinfo -> seg , param -> notnull_count , key ) ;
 }
 }
 ( * key_checksum ) += mi_byte_checksum ( ( uchar * ) key , key_length - info -> s -> rec_reflength ) ;
 record = _mi_dpos ( info , 0 , key + key_length ) ;
 if ( keyinfo -> flag & HA_FULLTEXT ) {
 uint off ;
 int subkeys ;
 get_key_full_length_rdonly ( off , key ) ;
 subkeys = ft_sintXkorr ( key + off ) ;
 if ( subkeys < 0 ) {
 ha_rows tmp_keys = 0 ;
 if ( chk_index_down ( param , info , & info -> s -> ft2_keyinfo , record , temp_buff , & tmp_keys , key_checksum , 1 ) ) goto err ;
 if ( tmp_keys + subkeys ) {
 mi_check_print_error ( param , "Number of words in the 2nd level tree " "does not match the number in the header. " "Parent word in on the page %s, offset %u" , llstr ( page , llbuff ) , ( uint ) ( old_keypos - buff ) ) ;
 goto err ;
 }
 ( * keys ) += tmp_keys - 1 ;
 continue ;
 }
 }
 if ( record >= info -> state -> data_file_length ) {
 # ifndef DBUG_OFF char llbuff2 [ 22 ] , llbuff3 [ 22 ] ;
 # endif mi_check_print_error ( param , "Found key at page %s that points to record outside datafile" , llstr ( page , llbuff ) ) ;
 DBUG_PRINT ( "test" , ( "page: %s record: %s filelength: %s" , llstr ( page , llbuff ) , llstr ( record , llbuff2 ) , llstr ( info -> state -> data_file_length , llbuff3 ) ) ) ;
 DBUG_DUMP ( "key" , ( uchar * ) key , key_length ) ;
 DBUG_DUMP ( "new_in_page" , ( uchar * ) old_keypos , ( uint ) ( keypos - old_keypos ) ) ;
 goto err ;
 }
 param -> record_checksum += ( ha_checksum ) record ;
 }
 if ( keypos != endpos ) {
 mi_check_print_error ( param , "Keyblock size at page %s is not correct. Block length: %d key length: %d" , llstr ( page , llbuff ) , used_length , ( keypos - buff ) ) ;
 goto err ;
 }
 my_afree ( ( uchar * ) temp_buff ) ;
 DBUG_RETURN ( 0 ) ;
 err : my_afree ( ( uchar * ) temp_buff ) ;
 DBUG_RETURN ( 1 ) ;
 }
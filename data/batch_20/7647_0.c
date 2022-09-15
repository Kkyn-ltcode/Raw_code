int chk_key ( MI_CHECK * param , register MI_INFO * info ) {
 uint key , found_keys = 0 , full_text_keys = 0 , result = 0 ;
 ha_rows keys ;
 ha_checksum old_record_checksum , init_checksum ;
 my_off_t all_keydata , all_totaldata , key_totlength , length ;
 ulong * rec_per_key_part ;
 MYISAM_SHARE * share = info -> s ;
 MI_KEYDEF * keyinfo ;
 char buff [ 22 ] , buff2 [ 22 ] ;
 DBUG_ENTER ( "chk_key" ) ;
 if ( ! ( param -> testflag & T_SILENT ) ) puts ( "- check key delete-chain" ) ;
 param -> key_file_blocks = info -> s -> base . keystart ;
 for ( key = 0 ;
 key < info -> s -> state . header . max_block_size_index ;
 key ++ ) if ( check_k_link ( param , info , key ) ) {
 if ( param -> testflag & T_VERBOSE ) puts ( "" ) ;
 mi_check_print_error ( param , "key delete-link-chain corrupted" ) ;
 DBUG_RETURN ( - 1 ) ;
 }
 if ( ! ( param -> testflag & T_SILENT ) ) puts ( "- check index reference" ) ;
 all_keydata = all_totaldata = key_totlength = 0 ;
 old_record_checksum = 0 ;
 init_checksum = param -> record_checksum ;
 if ( ! ( share -> options & ( HA_OPTION_PACK_RECORD | HA_OPTION_COMPRESS_RECORD ) ) ) old_record_checksum = calc_checksum ( info -> state -> records + info -> state -> del - 1 ) * share -> base . pack_reclength ;
 rec_per_key_part = param -> rec_per_key_part ;
 for ( key = 0 , keyinfo = & share -> keyinfo [ 0 ] ;
 key < share -> base . keys ;
 rec_per_key_part += keyinfo -> keysegs , key ++ , keyinfo ++ ) {
 param -> key_crc [ key ] = 0 ;
 if ( ! mi_is_key_active ( share -> state . key_map , key ) ) {
 memcpy ( ( char * ) rec_per_key_part , ( char * ) ( share -> state . rec_per_key_part + ( uint ) ( rec_per_key_part - param -> rec_per_key_part ) ) , keyinfo -> keysegs * sizeof ( * rec_per_key_part ) ) ;
 continue ;
 }
 found_keys ++ ;
 param -> record_checksum = init_checksum ;
 bzero ( ( char * ) & param -> unique_count , sizeof ( param -> unique_count ) ) ;
 bzero ( ( char * ) & param -> notnull_count , sizeof ( param -> notnull_count ) ) ;
 if ( ( ! ( param -> testflag & T_SILENT ) ) ) printf ( "- check data record references index: %d\n" , key + 1 ) ;
 if ( keyinfo -> flag & ( HA_FULLTEXT | HA_SPATIAL ) ) full_text_keys ++ ;
 if ( share -> state . key_root [ key ] == HA_OFFSET_ERROR && ( info -> state -> records == 0 || keyinfo -> flag & HA_FULLTEXT ) ) goto do_stat ;
 if ( ! _mi_fetch_keypage ( info , keyinfo , share -> state . key_root [ key ] , DFLT_INIT_HITS , info -> buff , 0 ) ) {
 mi_check_print_error ( param , "Can't read indexpage from filepos: %s" , llstr ( share -> state . key_root [ key ] , buff ) ) ;
 if ( ! ( param -> testflag & T_INFO ) ) DBUG_RETURN ( - 1 ) ;
 result = - 1 ;
 continue ;
 }
 param -> key_file_blocks += keyinfo -> block_length ;
 keys = 0 ;
 param -> keydata = param -> totaldata = 0 ;
 param -> key_blocks = 0 ;
 param -> max_level = 0 ;
 if ( chk_index ( param , info , keyinfo , share -> state . key_root [ key ] , info -> buff , & keys , param -> key_crc + key , 1 ) ) DBUG_RETURN ( - 1 ) ;
 if ( ! ( keyinfo -> flag & ( HA_FULLTEXT | HA_SPATIAL ) ) ) {
 if ( keys != info -> state -> records ) {
 mi_check_print_error ( param , "Found %s keys of %s" , llstr ( keys , buff ) , llstr ( info -> state -> records , buff2 ) ) ;
 if ( ! ( param -> testflag & T_INFO ) ) DBUG_RETURN ( - 1 ) ;
 result = - 1 ;
 continue ;
 }
 if ( found_keys - full_text_keys == 1 && ( ( share -> options & ( HA_OPTION_PACK_RECORD | HA_OPTION_COMPRESS_RECORD ) ) || ( param -> testflag & T_DONT_CHECK_CHECKSUM ) ) ) old_record_checksum = param -> record_checksum ;
 else if ( old_record_checksum != param -> record_checksum ) {
 if ( key ) mi_check_print_error ( param , "Key %u doesn't point at same records that key 1" , key + 1 ) ;
 else mi_check_print_error ( param , "Key 1 doesn't point at all records" ) ;
 if ( ! ( param -> testflag & T_INFO ) ) DBUG_RETURN ( - 1 ) ;
 result = - 1 ;
 continue ;
 }
 }
 if ( ( uint ) share -> base . auto_key - 1 == key ) {
 ulonglong auto_increment ;
 info -> lastinx = key ;
 _mi_read_key_record ( info , 0L , info -> rec_buff ) ;
 auto_increment = retrieve_auto_increment ( info , info -> rec_buff ) ;
 if ( auto_increment > info -> s -> state . auto_increment ) {
 mi_check_print_warning ( param , "Auto-increment value: %s is smaller " "than max used value: %s" , llstr ( info -> s -> state . auto_increment , buff2 ) , llstr ( auto_increment , buff ) ) ;
 }
 if ( param -> testflag & T_AUTO_INC ) {
 set_if_bigger ( info -> s -> state . auto_increment , auto_increment ) ;
 set_if_bigger ( info -> s -> state . auto_increment , param -> auto_increment_value ) ;
 }
 mi_extra ( info , HA_EXTRA_KEYREAD , 0 ) ;
 bzero ( info -> lastkey , keyinfo -> seg -> length ) ;
 if ( ! mi_rkey ( info , info -> rec_buff , key , ( const uchar * ) info -> lastkey , ( key_part_map ) 1 , HA_READ_KEY_EXACT ) ) {
 uint save = param -> warning_printed ;
 mi_check_print_warning ( param , "Found row where the auto_increment " "column has the value 0" ) ;
 param -> warning_printed = save ;
 }
 mi_extra ( info , HA_EXTRA_NO_KEYREAD , 0 ) ;
 }
 length = ( my_off_t ) isam_key_length ( info , keyinfo ) * keys + param -> key_blocks * 2 ;
 if ( param -> testflag & T_INFO && param -> totaldata != 0L && keys != 0L ) printf ( "Key: %2d: Keyblocks used: %3d%% Packed: %4d%% Max levels: %2d\n" , key + 1 , ( int ) ( my_off_t2double ( param -> keydata ) * 100.0 / my_off_t2double ( param -> totaldata ) ) , ( int ) ( ( my_off_t2double ( length ) - my_off_t2double ( param -> keydata ) ) * 100.0 / my_off_t2double ( length ) ) , param -> max_level ) ;
 all_keydata += param -> keydata ;
 all_totaldata += param -> totaldata ;
 key_totlength += length ;
 do_stat : if ( param -> testflag & T_STATISTICS ) update_key_parts ( keyinfo , rec_per_key_part , param -> unique_count , param -> stats_method == MI_STATS_METHOD_IGNORE_NULLS ? param -> notnull_count : NULL , ( ulonglong ) info -> state -> records ) ;
 }
 if ( param -> testflag & T_INFO ) {
 if ( all_totaldata != 0L && found_keys > 0 ) printf ( "Total: Keyblocks used: %3d%% Packed: %4d%%\n\n" , ( int ) ( my_off_t2double ( all_keydata ) * 100.0 / my_off_t2double ( all_totaldata ) ) , ( int ) ( ( my_off_t2double ( key_totlength ) - my_off_t2double ( all_keydata ) ) * 100.0 / my_off_t2double ( key_totlength ) ) ) ;
 else if ( all_totaldata != 0L && mi_is_any_key_active ( share -> state . key_map ) ) puts ( "" ) ;
 }
 if ( param -> key_file_blocks != info -> state -> key_file_length && param -> keys_in_use != ~ ( ulonglong ) 0 ) mi_check_print_warning ( param , "Some data are unreferenced in keyfile" ) ;
 if ( found_keys != full_text_keys ) param -> record_checksum = old_record_checksum - init_checksum ;
 else param -> record_checksum = 0 ;
 DBUG_RETURN ( result ) ;
 }
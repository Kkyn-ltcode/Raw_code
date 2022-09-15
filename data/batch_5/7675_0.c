static int mi_sort_records ( MI_CHECK * param , register MI_INFO * info , char * name , uint sort_key , my_bool write_info , my_bool update_index ) {
 int got_error ;
 uint key ;
 MI_KEYDEF * keyinfo ;
 File new_file ;
 uchar * temp_buff ;
 ha_rows old_record_count ;
 MYISAM_SHARE * share = info -> s ;
 char llbuff [ 22 ] , llbuff2 [ 22 ] ;
 SORT_INFO sort_info ;
 MI_SORT_PARAM sort_param ;
 DBUG_ENTER ( "sort_records" ) ;
 bzero ( ( char * ) & sort_info , sizeof ( sort_info ) ) ;
 bzero ( ( char * ) & sort_param , sizeof ( sort_param ) ) ;
 sort_param . sort_info = & sort_info ;
 sort_info . param = param ;
 keyinfo = & share -> keyinfo [ sort_key ] ;
 got_error = 1 ;
 temp_buff = 0 ;
 new_file = - 1 ;
 if ( ! mi_is_key_active ( share -> state . key_map , sort_key ) ) {
 mi_check_print_warning ( param , "Can't sort table '%s' on key %d;
 No such key" , name , sort_key + 1 ) ;
 param -> error_printed = 0 ;
 DBUG_RETURN ( 0 ) ;
 }
 if ( keyinfo -> flag & HA_FULLTEXT ) {
 mi_check_print_warning ( param , "Can't sort table '%s' on FULLTEXT key %d" , name , sort_key + 1 ) ;
 param -> error_printed = 0 ;
 DBUG_RETURN ( 0 ) ;
 }
 if ( share -> data_file_type == COMPRESSED_RECORD ) {
 mi_check_print_warning ( param , "Can't sort read-only table '%s'" , name ) ;
 param -> error_printed = 0 ;
 DBUG_RETURN ( 0 ) ;
 }
 if ( ! ( param -> testflag & T_SILENT ) ) {
 printf ( "- Sorting records for MyISAM-table '%s'\n" , name ) ;
 if ( write_info ) printf ( "Data records: %9s Deleted: %9s\n" , llstr ( info -> state -> records , llbuff ) , llstr ( info -> state -> del , llbuff2 ) ) ;
 }
 if ( share -> state . key_root [ sort_key ] == HA_OFFSET_ERROR ) DBUG_RETURN ( 0 ) ;
 init_key_cache ( dflt_key_cache , opt_key_cache_block_size , ( size_t ) param -> use_buffers , 0 , 0 ) ;
 if ( init_io_cache ( & info -> rec_cache , - 1 , ( uint ) param -> write_buffer_length , WRITE_CACHE , share -> pack . header_length , 1 , MYF ( MY_WME | MY_WAIT_IF_FULL ) ) ) goto err ;
 info -> opt_flag |= WRITE_CACHE_USED ;
 if ( ! ( temp_buff = ( uchar * ) my_alloca ( ( uint ) keyinfo -> block_length ) ) ) {
 mi_check_print_error ( param , "Not enough memory for key block" ) ;
 goto err ;
 }
 if ( ! mi_alloc_rec_buff ( info , - 1 , & sort_param . record ) ) {
 mi_check_print_error ( param , "Not enough memory for record" ) ;
 goto err ;
 }
 fn_format ( param -> temp_filename , name , "" , MI_NAME_DEXT , 2 + 4 + 32 ) ;
 new_file = my_create ( fn_format ( param -> temp_filename , param -> temp_filename , "" , DATA_TMP_EXT , 2 + 4 ) , 0 , param -> tmpfile_createflag , MYF ( 0 ) ) ;
 if ( new_file < 0 ) {
 mi_check_print_error ( param , "Can't create new tempfile: '%s'" , param -> temp_filename ) ;
 goto err ;
 }
 if ( share -> pack . header_length ) if ( filecopy ( param , new_file , info -> dfile , 0L , share -> pack . header_length , "datafile-header" ) ) goto err ;
 info -> rec_cache . file = new_file ;
 lock_memory ( param ) ;
 for ( key = 0 ;
 key < share -> base . keys ;
 key ++ ) share -> keyinfo [ key ] . flag |= HA_SORT_ALLOWS_SAME ;
 if ( my_pread ( share -> kfile , ( uchar * ) temp_buff , ( uint ) keyinfo -> block_length , share -> state . key_root [ sort_key ] , MYF ( MY_NABP + MY_WME ) ) ) {
 mi_check_print_error ( param , "Can't read indexpage from filepos: %s" , ( ulong ) share -> state . key_root [ sort_key ] ) ;
 goto err ;
 }
 sort_info . info = info ;
 sort_info . new_data_file_type = share -> data_file_type ;
 sort_param . fix_datafile = 1 ;
 sort_param . master = 1 ;
 sort_param . filepos = share -> pack . header_length ;
 old_record_count = info -> state -> records ;
 info -> state -> records = 0 ;
 if ( sort_info . new_data_file_type != COMPRESSED_RECORD ) info -> state -> checksum = 0 ;
 if ( sort_record_index ( & sort_param , info , keyinfo , share -> state . key_root [ sort_key ] , temp_buff , sort_key , new_file , update_index ) || write_data_suffix ( & sort_info , 1 ) || flush_io_cache ( & info -> rec_cache ) ) goto err ;
 if ( info -> state -> records != old_record_count ) {
 mi_check_print_error ( param , "found %s of %s records" , llstr ( info -> state -> records , llbuff ) , llstr ( old_record_count , llbuff2 ) ) ;
 goto err ;
 }
 ( void ) my_close ( info -> dfile , MYF ( MY_WME ) ) ;
 param -> out_flag |= O_NEW_DATA ;
 info -> dfile = new_file ;
 info -> state -> del = 0 ;
 info -> state -> empty = 0 ;
 share -> state . dellink = HA_OFFSET_ERROR ;
 info -> state -> data_file_length = sort_param . filepos ;
 share -> state . split = info -> state -> records ;
 share -> state . version = ( ulong ) time ( ( time_t * ) 0 ) ;
 info -> update = ( short ) ( HA_STATE_CHANGED | HA_STATE_ROW_CHANGED ) ;
 if ( param -> testflag & T_WRITE_LOOP ) {
 ( void ) fputs ( " \r" , stdout ) ;
 ( void ) fflush ( stdout ) ;
 }
 got_error = 0 ;
 err : if ( got_error && new_file >= 0 ) {
 ( void ) end_io_cache ( & info -> rec_cache ) ;
 ( void ) my_close ( new_file , MYF ( MY_WME ) ) ;
 ( void ) my_delete ( param -> temp_filename , MYF ( MY_WME ) ) ;
 }
 if ( temp_buff ) {
 my_afree ( ( uchar * ) temp_buff ) ;
 }
 my_free ( mi_get_rec_buff_ptr ( info , sort_param . record ) ) ;
 info -> opt_flag &= ~ ( READ_CACHE_USED | WRITE_CACHE_USED ) ;
 ( void ) end_io_cache ( & info -> rec_cache ) ;
 my_free ( sort_info . buff ) ;
 sort_info . buff = 0 ;
 share -> state . sortkey = sort_key ;
 DBUG_RETURN ( flush_blocks ( param , share -> key_cache , share -> kfile ) | got_error ) ;
 }
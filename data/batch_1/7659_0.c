static int sort_get_next_record ( MI_SORT_PARAM * sort_param ) {
 int searching ;
 int parallel_flag ;
 uint found_record , b_type , left_length ;
 my_off_t pos ;
 uchar * UNINIT_VAR ( to ) ;
 MI_BLOCK_INFO block_info ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 MI_CHECK * param = sort_info -> param ;
 MI_INFO * info = sort_info -> info ;
 MYISAM_SHARE * share = info -> s ;
 char llbuff [ 22 ] , llbuff2 [ 22 ] ;
 DBUG_ENTER ( "sort_get_next_record" ) ;
 if ( * killed_ptr ( param ) ) DBUG_RETURN ( 1 ) ;
 switch ( share -> data_file_type ) {
 case STATIC_RECORD : for ( ;
 ;
 ) {
 if ( my_b_read ( & sort_param -> read_cache , sort_param -> record , share -> base . pack_reclength ) ) {
 if ( sort_param -> read_cache . error ) param -> out_flag |= O_DATA_LOST ;
 param -> retry_repair = 1 ;
 param -> testflag |= T_RETRY_WITHOUT_QUICK ;
 DBUG_RETURN ( - 1 ) ;
 }
 sort_param -> start_recpos = sort_param -> pos ;
 if ( ! sort_param -> fix_datafile ) {
 sort_param -> filepos = sort_param -> pos ;
 if ( sort_param -> master ) share -> state . split ++ ;
 }
 sort_param -> max_pos = ( sort_param -> pos += share -> base . pack_reclength ) ;
 if ( * sort_param -> record ) {
 if ( sort_param -> calc_checksum ) param -> glob_crc += ( info -> checksum = mi_static_checksum ( info , sort_param -> record ) ) ;
 DBUG_RETURN ( 0 ) ;
 }
 if ( ! sort_param -> fix_datafile && sort_param -> master ) {
 info -> state -> del ++ ;
 info -> state -> empty += share -> base . pack_reclength ;
 }
 }
 case DYNAMIC_RECORD : LINT_INIT ( to ) ;
 pos = sort_param -> pos ;
 searching = ( sort_param -> fix_datafile && ( param -> testflag & T_EXTEND ) ) ;
 parallel_flag = ( sort_param -> read_cache . file < 0 ) ? READING_NEXT : 0 ;
 for ( ;
 ;
 ) {
 found_record = block_info . second_read = 0 ;
 left_length = 1 ;
 if ( searching ) {
 pos = MY_ALIGN ( pos , MI_DYN_ALIGN_SIZE ) ;
 param -> testflag |= T_RETRY_WITHOUT_QUICK ;
 sort_param -> start_recpos = pos ;
 }
 do {
 if ( pos > sort_param -> max_pos ) sort_param -> max_pos = pos ;
 if ( pos & ( MI_DYN_ALIGN_SIZE - 1 ) ) {
 if ( ( param -> testflag & T_VERBOSE ) || searching == 0 ) mi_check_print_info ( param , "Wrong aligned block at %s" , llstr ( pos , llbuff ) ) ;
 if ( searching ) goto try_next ;
 }
 if ( found_record && pos == param -> search_after_block ) mi_check_print_info ( param , "Block: %s used by record at %s" , llstr ( param -> search_after_block , llbuff ) , llstr ( sort_param -> start_recpos , llbuff2 ) ) ;
 if ( _mi_read_cache ( & sort_param -> read_cache , ( uchar * ) block_info . header , pos , MI_BLOCK_INFO_HEADER_LENGTH , ( ! found_record ? READING_NEXT : 0 ) | parallel_flag | READING_HEADER ) ) {
 if ( found_record ) {
 mi_check_print_info ( param , "Can't read whole record at %s (errno: %d)" , llstr ( sort_param -> start_recpos , llbuff ) , errno ) ;
 goto try_next ;
 }
 DBUG_RETURN ( - 1 ) ;
 }
 if ( searching && ! sort_param -> fix_datafile ) {
 param -> error_printed = 1 ;
 param -> retry_repair = 1 ;
 param -> testflag |= T_RETRY_WITHOUT_QUICK ;
 DBUG_RETURN ( 1 ) ;
 }
 b_type = _mi_get_block_info ( & block_info , - 1 , pos ) ;
 if ( ( b_type & ( BLOCK_ERROR | BLOCK_FATAL_ERROR ) ) || ( ( b_type & BLOCK_FIRST ) && ( block_info . rec_len < ( uint ) share -> base . min_pack_length || block_info . rec_len > ( uint ) share -> base . max_pack_length ) ) ) {
 uint i ;
 if ( param -> testflag & T_VERBOSE || searching == 0 ) mi_check_print_info ( param , "Wrong bytesec: %3d-%3d-%3d at %10s;
 Skipped" , block_info . header [ 0 ] , block_info . header [ 1 ] , block_info . header [ 2 ] , llstr ( pos , llbuff ) ) ;
 if ( found_record ) goto try_next ;
 block_info . second_read = 0 ;
 searching = 1 ;
 for ( i = MI_DYN_ALIGN_SIZE ;
 i < MI_BLOCK_INFO_HEADER_LENGTH ;
 i += MI_DYN_ALIGN_SIZE ) if ( block_info . header [ i ] >= 1 && block_info . header [ i ] <= MI_MAX_DYN_HEADER_BYTE ) break ;
 pos += ( ulong ) i ;
 sort_param -> start_recpos = pos ;
 continue ;
 }
 if ( b_type & BLOCK_DELETED ) {
 my_bool error = 0 ;
 if ( block_info . block_len + ( uint ) ( block_info . filepos - pos ) < share -> base . min_block_length ) {
 if ( ! searching ) mi_check_print_info ( param , "Deleted block with impossible length %u at %s" , block_info . block_len , llstr ( pos , llbuff ) ) ;
 error = 1 ;
 }
 else {
 if ( ( block_info . next_filepos != HA_OFFSET_ERROR && block_info . next_filepos >= info -> state -> data_file_length ) || ( block_info . prev_filepos != HA_OFFSET_ERROR && block_info . prev_filepos >= info -> state -> data_file_length ) ) {
 if ( ! searching ) mi_check_print_info ( param , "Delete link points outside datafile at %s" , llstr ( pos , llbuff ) ) ;
 error = 1 ;
 }
 }
 if ( error ) {
 if ( found_record ) goto try_next ;
 searching = 1 ;
 pos += MI_DYN_ALIGN_SIZE ;
 sort_param -> start_recpos = pos ;
 block_info . second_read = 0 ;
 continue ;
 }
 }
 else {
 if ( block_info . block_len + ( uint ) ( block_info . filepos - pos ) < share -> base . min_block_length || block_info . block_len > ( uint ) share -> base . max_pack_length + MI_SPLIT_LENGTH ) {
 if ( ! searching ) mi_check_print_info ( param , "Found block with impossible length %u at %s;
 Skipped" , block_info . block_len + ( uint ) ( block_info . filepos - pos ) , llstr ( pos , llbuff ) ) ;
 if ( found_record ) goto try_next ;
 searching = 1 ;
 pos += MI_DYN_ALIGN_SIZE ;
 sort_param -> start_recpos = pos ;
 block_info . second_read = 0 ;
 continue ;
 }
 }
 if ( b_type & ( BLOCK_DELETED | BLOCK_SYNC_ERROR ) ) {
 if ( ! sort_param -> fix_datafile && sort_param -> master && ( b_type & BLOCK_DELETED ) ) {
 info -> state -> empty += block_info . block_len ;
 info -> state -> del ++ ;
 share -> state . split ++ ;
 }
 if ( found_record ) goto try_next ;
 if ( searching ) {
 pos += MI_DYN_ALIGN_SIZE ;
 sort_param -> start_recpos = pos ;
 }
 else pos = block_info . filepos + block_info . block_len ;
 block_info . second_read = 0 ;
 continue ;
 }
 if ( ! sort_param -> fix_datafile && sort_param -> master ) share -> state . split ++ ;
 if ( ! found_record ++ ) {
 sort_param -> find_length = left_length = block_info . rec_len ;
 sort_param -> start_recpos = pos ;
 if ( ! sort_param -> fix_datafile ) sort_param -> filepos = sort_param -> start_recpos ;
 if ( sort_param -> fix_datafile && ( param -> testflag & T_EXTEND ) ) sort_param -> pos = block_info . filepos + 1 ;
 else sort_param -> pos = block_info . filepos + block_info . block_len ;
 if ( share -> base . blobs ) {
 if ( ! ( to = mi_alloc_rec_buff ( info , block_info . rec_len , & ( sort_param -> rec_buff ) ) ) ) {
 if ( param -> max_record_length >= block_info . rec_len ) {
 mi_check_print_error ( param , "Not enough memory for blob at %s (need %lu)" , llstr ( sort_param -> start_recpos , llbuff ) , ( ulong ) block_info . rec_len ) ;
 DBUG_RETURN ( 1 ) ;
 }
 else {
 mi_check_print_info ( param , "Not enough memory for blob at %s (need %lu);
 Row skipped" , llstr ( sort_param -> start_recpos , llbuff ) , ( ulong ) block_info . rec_len ) ;
 goto try_next ;
 }
 }
 }
 else to = sort_param -> rec_buff ;
 }
 if ( left_length < block_info . data_len || ! block_info . data_len ) {
 mi_check_print_info ( param , "Found block with too small length at %s;
 Skipped" , llstr ( sort_param -> start_recpos , llbuff ) ) ;
 goto try_next ;
 }
 if ( block_info . filepos + block_info . data_len > sort_param -> read_cache . end_of_file ) {
 mi_check_print_info ( param , "Found block that points outside data file at %s" , llstr ( sort_param -> start_recpos , llbuff ) ) ;
 goto try_next ;
 }
 {
 uint header_len = ( uint ) ( block_info . filepos - pos ) ;
 uint prefetch_len = ( MI_BLOCK_INFO_HEADER_LENGTH - header_len ) ;
 if ( prefetch_len > block_info . data_len ) prefetch_len = block_info . data_len ;
 if ( prefetch_len ) {
 memcpy ( to , block_info . header + header_len , prefetch_len ) ;
 block_info . filepos += prefetch_len ;
 block_info . data_len -= prefetch_len ;
 left_length -= prefetch_len ;
 to += prefetch_len ;
 }
 }
 if ( block_info . data_len && _mi_read_cache ( & sort_param -> read_cache , to , block_info . filepos , block_info . data_len , ( found_record == 1 ? READING_NEXT : 0 ) | parallel_flag ) ) {
 mi_check_print_info ( param , "Read error for block at: %s (error: %d);
 Skipped" , llstr ( block_info . filepos , llbuff ) , my_errno ) ;
 goto try_next ;
 }
 left_length -= block_info . data_len ;
 to += block_info . data_len ;
 pos = block_info . next_filepos ;
 if ( pos == HA_OFFSET_ERROR && left_length ) {
 mi_check_print_info ( param , "Wrong block with wrong total length starting at %s" , llstr ( sort_param -> start_recpos , llbuff ) ) ;
 goto try_next ;
 }
 if ( pos + MI_BLOCK_INFO_HEADER_LENGTH > sort_param -> read_cache . end_of_file ) {
 mi_check_print_info ( param , "Found link that points at %s (outside data file) at %s" , llstr ( pos , llbuff2 ) , llstr ( sort_param -> start_recpos , llbuff ) ) ;
 goto try_next ;
 }
 }
 while ( left_length ) ;
 if ( _mi_rec_unpack ( info , sort_param -> record , sort_param -> rec_buff , sort_param -> find_length ) != MY_FILE_ERROR ) {
 if ( sort_param -> read_cache . error < 0 ) DBUG_RETURN ( 1 ) ;
 if ( sort_param -> calc_checksum ) info -> checksum = mi_checksum ( info , sort_param -> record ) ;
 if ( ( param -> testflag & ( T_EXTEND | T_REP ) ) || searching ) {
 if ( _mi_rec_check ( info , sort_param -> record , sort_param -> rec_buff , sort_param -> find_length , ( param -> testflag & T_QUICK ) && sort_param -> calc_checksum && test ( info -> s -> calc_checksum ) ) ) {
 mi_check_print_info ( param , "Found wrong packed record at %s" , llstr ( sort_param -> start_recpos , llbuff ) ) ;
 goto try_next ;
 }
 }
 if ( sort_param -> calc_checksum ) param -> glob_crc += info -> checksum ;
 DBUG_RETURN ( 0 ) ;
 }
 if ( ! searching ) mi_check_print_info ( param , "Key %d - Found wrong stored record at %s" , sort_param -> key + 1 , llstr ( sort_param -> start_recpos , llbuff ) ) ;
 try_next : pos = ( sort_param -> start_recpos += MI_DYN_ALIGN_SIZE ) ;
 searching = 1 ;
 }
 case COMPRESSED_RECORD : for ( searching = 0 ;
 ;
 searching = 1 , sort_param -> pos ++ ) {
 if ( _mi_read_cache ( & sort_param -> read_cache , ( uchar * ) block_info . header , sort_param -> pos , share -> pack . ref_length , READING_NEXT ) ) DBUG_RETURN ( - 1 ) ;
 if ( searching && ! sort_param -> fix_datafile ) {
 param -> error_printed = 1 ;
 param -> retry_repair = 1 ;
 param -> testflag |= T_RETRY_WITHOUT_QUICK ;
 DBUG_RETURN ( 1 ) ;
 }
 sort_param -> start_recpos = sort_param -> pos ;
 if ( _mi_pack_get_block_info ( info , & sort_param -> bit_buff , & block_info , & sort_param -> rec_buff , - 1 , sort_param -> pos ) ) DBUG_RETURN ( - 1 ) ;
 if ( ! block_info . rec_len && sort_param -> pos + MEMMAP_EXTRA_MARGIN == sort_param -> read_cache . end_of_file ) DBUG_RETURN ( - 1 ) ;
 if ( block_info . rec_len < ( uint ) share -> min_pack_length || block_info . rec_len > ( uint ) share -> max_pack_length ) {
 if ( ! searching ) mi_check_print_info ( param , "Found block with wrong recordlength: %d at %s\n" , block_info . rec_len , llstr ( sort_param -> pos , llbuff ) ) ;
 continue ;
 }
 if ( _mi_read_cache ( & sort_param -> read_cache , ( uchar * ) sort_param -> rec_buff , block_info . filepos , block_info . rec_len , READING_NEXT ) ) {
 if ( ! searching ) mi_check_print_info ( param , "Couldn't read whole record from %s" , llstr ( sort_param -> pos , llbuff ) ) ;
 continue ;
 }
 if ( _mi_pack_rec_unpack ( info , & sort_param -> bit_buff , sort_param -> record , sort_param -> rec_buff , block_info . rec_len ) ) {
 if ( ! searching ) mi_check_print_info ( param , "Found wrong record at %s" , llstr ( sort_param -> pos , llbuff ) ) ;
 continue ;
 }
 if ( ! sort_param -> fix_datafile ) {
 sort_param -> filepos = sort_param -> pos ;
 if ( sort_param -> master ) share -> state . split ++ ;
 }
 sort_param -> max_pos = ( sort_param -> pos = block_info . filepos + block_info . rec_len ) ;
 info -> packed_length = block_info . rec_len ;
 if ( sort_param -> calc_checksum ) param -> glob_crc += ( info -> checksum = mi_checksum ( info , sort_param -> record ) ) ;
 DBUG_RETURN ( 0 ) ;
 }
 case BLOCK_RECORD : assert ( 0 ) ;
 }
 DBUG_RETURN ( 1 ) ;
 }
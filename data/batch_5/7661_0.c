int sort_write_record ( MI_SORT_PARAM * sort_param ) {
 int flag ;
 uint length ;
 ulong block_length , reclength ;
 uchar * from ;
 uchar block_buff [ 8 ] ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 MI_CHECK * param = sort_info -> param ;
 MI_INFO * info = sort_info -> info ;
 MYISAM_SHARE * share = info -> s ;
 DBUG_ENTER ( "sort_write_record" ) ;
 if ( sort_param -> fix_datafile ) {
 switch ( sort_info -> new_data_file_type ) {
 case STATIC_RECORD : if ( my_b_write ( & info -> rec_cache , sort_param -> record , share -> base . pack_reclength ) ) {
 mi_check_print_error ( param , "%d when writing to datafile" , my_errno ) ;
 DBUG_RETURN ( 1 ) ;
 }
 sort_param -> filepos += share -> base . pack_reclength ;
 info -> s -> state . split ++ ;
 break ;
 case DYNAMIC_RECORD : if ( ! info -> blobs ) from = sort_param -> rec_buff ;
 else {
 reclength = info -> s -> base . pack_reclength + _my_calc_total_blob_length ( info , sort_param -> record ) + ALIGN_SIZE ( MI_MAX_DYN_BLOCK_HEADER ) + MI_SPLIT_LENGTH + MI_DYN_DELETE_BLOCK_HEADER ;
 if ( sort_info -> buff_length < reclength ) {
 if ( ! ( sort_info -> buff = my_realloc ( sort_info -> buff , ( uint ) reclength , MYF ( MY_FREE_ON_ERROR | MY_ALLOW_ZERO_PTR ) ) ) ) DBUG_RETURN ( 1 ) ;
 sort_info -> buff_length = reclength ;
 }
 from = sort_info -> buff + ALIGN_SIZE ( MI_MAX_DYN_BLOCK_HEADER ) ;
 }
 info -> checksum = mi_checksum ( info , sort_param -> record ) ;
 reclength = _mi_rec_pack ( info , from , sort_param -> record ) ;
 flag = 0 ;
 do {
 block_length = reclength + 3 + test ( reclength >= ( 65520 - 3 ) ) ;
 if ( block_length < share -> base . min_block_length ) block_length = share -> base . min_block_length ;
 info -> update |= HA_STATE_WRITE_AT_END ;
 block_length = MY_ALIGN ( block_length , MI_DYN_ALIGN_SIZE ) ;
 if ( block_length > MI_MAX_BLOCK_LENGTH ) block_length = MI_MAX_BLOCK_LENGTH ;
 if ( _mi_write_part_record ( info , 0L , block_length , sort_param -> filepos + block_length , & from , & reclength , & flag ) ) {
 mi_check_print_error ( param , "%d when writing to datafile" , my_errno ) ;
 DBUG_RETURN ( 1 ) ;
 }
 sort_param -> filepos += block_length ;
 info -> s -> state . split ++ ;
 }
 while ( reclength ) ;
 break ;
 case COMPRESSED_RECORD : reclength = info -> packed_length ;
 length = save_pack_length ( ( uint ) share -> pack . version , block_buff , reclength ) ;
 if ( info -> s -> base . blobs ) length += save_pack_length ( ( uint ) share -> pack . version , block_buff + length , info -> blob_length ) ;
 if ( my_b_write ( & info -> rec_cache , block_buff , length ) || my_b_write ( & info -> rec_cache , ( uchar * ) sort_param -> rec_buff , reclength ) ) {
 mi_check_print_error ( param , "%d when writing to datafile" , my_errno ) ;
 DBUG_RETURN ( 1 ) ;
 }
 sort_param -> filepos += reclength + length ;
 info -> s -> state . split ++ ;
 break ;
 case BLOCK_RECORD : assert ( 0 ) ;
 }
 }
 if ( sort_param -> master ) {
 info -> state -> records ++ ;
 if ( ( param -> testflag & T_WRITE_LOOP ) && ( info -> state -> records % WRITE_COUNT ) == 0 ) {
 char llbuff [ 22 ] ;
 printf ( "%s\r" , llstr ( info -> state -> records , llbuff ) ) ;
 ( void ) fflush ( stdout ) ;
 }
 }
 DBUG_RETURN ( 0 ) ;
 }
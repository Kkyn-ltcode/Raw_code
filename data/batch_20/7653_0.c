int chk_del ( MI_CHECK * param , register MI_INFO * info , uint test_flag ) {
 reg2 ha_rows i ;
 uint delete_link_length ;
 my_off_t empty , next_link , old_link = 0 ;
 char buff [ 22 ] , buff2 [ 22 ] ;
 DBUG_ENTER ( "chk_del" ) ;
 param -> record_checksum = 0 ;
 delete_link_length = ( ( info -> s -> options & HA_OPTION_PACK_RECORD ) ? 20 : info -> s -> rec_reflength + 1 ) ;
 if ( ! ( test_flag & T_SILENT ) ) puts ( "- check record delete-chain" ) ;
 next_link = info -> s -> state . dellink ;
 if ( info -> state -> del == 0 ) {
 if ( test_flag & T_VERBOSE ) {
 puts ( "No recordlinks" ) ;
 }
 }
 else {
 if ( test_flag & T_VERBOSE ) printf ( "Recordlinks: " ) ;
 empty = 0 ;
 for ( i = info -> state -> del ;
 i > 0L && next_link != HA_OFFSET_ERROR ;
 i -- ) {
 if ( * killed_ptr ( param ) ) DBUG_RETURN ( 1 ) ;
 if ( test_flag & T_VERBOSE ) printf ( " %9s" , llstr ( next_link , buff ) ) ;
 if ( next_link >= info -> state -> data_file_length ) goto wrong ;
 if ( mysql_file_pread ( info -> dfile , ( uchar * ) buff , delete_link_length , next_link , MYF ( MY_NABP ) ) ) {
 if ( test_flag & T_VERBOSE ) puts ( "" ) ;
 mi_check_print_error ( param , "Can't read delete-link at filepos: %s" , llstr ( next_link , buff ) ) ;
 DBUG_RETURN ( 1 ) ;
 }
 if ( * buff != '\0' ) {
 if ( test_flag & T_VERBOSE ) puts ( "" ) ;
 mi_check_print_error ( param , "Record at pos: %s is not remove-marked" , llstr ( next_link , buff ) ) ;
 goto wrong ;
 }
 if ( info -> s -> options & HA_OPTION_PACK_RECORD ) {
 my_off_t prev_link = mi_sizekorr ( buff + 12 ) ;
 if ( empty && prev_link != old_link ) {
 if ( test_flag & T_VERBOSE ) puts ( "" ) ;
 mi_check_print_error ( param , "Deleted block at %s doesn't point back at previous delete link" , llstr ( next_link , buff2 ) ) ;
 goto wrong ;
 }
 old_link = next_link ;
 next_link = mi_sizekorr ( buff + 4 ) ;
 empty += mi_uint3korr ( buff + 1 ) ;
 }
 else {
 param -> record_checksum += ( ha_checksum ) next_link ;
 next_link = _mi_rec_pos ( info -> s , ( uchar * ) buff + 1 ) ;
 empty += info -> s -> base . pack_reclength ;
 }
 }
 if ( test_flag & T_VERBOSE ) puts ( "\n" ) ;
 if ( empty != info -> state -> empty ) {
 mi_check_print_warning ( param , "Found %s deleted space in delete link chain. Should be %s" , llstr ( empty , buff2 ) , llstr ( info -> state -> empty , buff ) ) ;
 }
 if ( next_link != HA_OFFSET_ERROR ) {
 mi_check_print_error ( param , "Found more than the expected %s deleted rows in delete link chain" , llstr ( info -> state -> del , buff ) ) ;
 goto wrong ;
 }
 if ( i != 0 ) {
 mi_check_print_error ( param , "Found %s deleted rows in delete link chain. Should be %s" , llstr ( info -> state -> del - i , buff2 ) , llstr ( info -> state -> del , buff ) ) ;
 goto wrong ;
 }
 }
 DBUG_RETURN ( 0 ) ;
 wrong : param -> testflag |= T_RETRY_WITHOUT_QUICK ;
 if ( test_flag & T_VERBOSE ) puts ( "" ) ;
 mi_check_print_error ( param , "record delete-link-chain corrupted" ) ;
 DBUG_RETURN ( 1 ) ;
 }
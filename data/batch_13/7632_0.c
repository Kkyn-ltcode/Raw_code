static int sort_delete_record ( MI_SORT_PARAM * sort_param ) {
 uint i ;
 int old_file , error ;
 uchar * key ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 MI_CHECK * param = sort_info -> param ;
 MI_INFO * info = sort_info -> info ;
 DBUG_ENTER ( "sort_delete_record" ) ;
 if ( ( param -> testflag & ( T_FORCE_UNIQUENESS | T_QUICK ) ) == T_QUICK ) {
 mi_check_print_error ( param , "Quick-recover aborted;
 Run recovery without switch -q or with switch -qq" ) ;
 DBUG_RETURN ( 1 ) ;
 }
 if ( info -> s -> options & HA_OPTION_COMPRESS_RECORD ) {
 mi_check_print_error ( param , "Recover aborted;
 Can't run standard recovery on compressed tables with errors in data-file. Use switch 'myisamchk --safe-recover' to fix it\n" , stderr ) ;
 ;
 DBUG_RETURN ( 1 ) ;
 }
 old_file = info -> dfile ;
 info -> dfile = info -> rec_cache . file ;
 if ( sort_info -> current_key ) {
 key = info -> lastkey + info -> s -> base . max_key_length ;
 if ( ( error = ( * info -> s -> read_rnd ) ( info , sort_param -> record , info -> lastpos , 0 ) ) && error != HA_ERR_RECORD_DELETED ) {
 mi_check_print_error ( param , "Can't read record to be removed" ) ;
 info -> dfile = old_file ;
 DBUG_RETURN ( 1 ) ;
 }
 for ( i = 0 ;
 i < sort_info -> current_key ;
 i ++ ) {
 uint key_length = _mi_make_key ( info , i , key , sort_param -> record , info -> lastpos ) ;
 if ( _mi_ck_delete ( info , i , key , key_length ) ) {
 mi_check_print_error ( param , "Can't delete key %d from record to be removed" , i + 1 ) ;
 info -> dfile = old_file ;
 DBUG_RETURN ( 1 ) ;
 }
 }
 if ( sort_param -> calc_checksum ) param -> glob_crc -= ( * info -> s -> calc_checksum ) ( info , sort_param -> record ) ;
 }
 error = flush_io_cache ( & info -> rec_cache ) || ( * info -> s -> delete_record ) ( info ) ;
 info -> dfile = old_file ;
 info -> state -> records -- ;
 DBUG_RETURN ( error ) ;
 }
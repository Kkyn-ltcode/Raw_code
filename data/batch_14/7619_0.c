int update_state_info ( MI_CHECK * param , MI_INFO * info , uint update ) {
 MYISAM_SHARE * share = info -> s ;
 if ( update & UPDATE_OPEN_COUNT ) {
 share -> state . open_count = 0 ;
 share -> global_changed = 0 ;
 }
 if ( update & UPDATE_STAT ) {
 uint i , key_parts = mi_uint2korr ( share -> state . header . key_parts ) ;
 share -> state . rec_per_key_rows = info -> state -> records ;
 share -> state . changed &= ~ STATE_NOT_ANALYZED ;
 if ( info -> state -> records ) {
 for ( i = 0 ;
 i < key_parts ;
 i ++ ) {
 if ( ! ( share -> state . rec_per_key_part [ i ] = param -> rec_per_key_part [ i ] ) ) share -> state . changed |= STATE_NOT_ANALYZED ;
 }
 }
 }
 if ( update & ( UPDATE_STAT | UPDATE_SORT | UPDATE_TIME | UPDATE_AUTO_INC ) ) {
 if ( update & UPDATE_TIME ) {
 share -> state . check_time = ( long ) time ( ( time_t * ) 0 ) ;
 if ( ! share -> state . create_time ) share -> state . create_time = share -> state . check_time ;
 }
 if ( info -> lock_type == F_WRLCK ) share -> state . state = * info -> state ;
 if ( mi_state_info_write ( share -> kfile , & share -> state , 1 + 2 ) ) goto err ;
 share -> changed = 0 ;
 }
 {
 int error ;
 uint r_locks = share -> r_locks , w_locks = share -> w_locks ;
 share -> r_locks = share -> w_locks = share -> tot_locks = 0 ;
 error = _mi_writeinfo ( info , WRITEINFO_NO_UNLOCK ) ;
 share -> r_locks = r_locks ;
 share -> w_locks = w_locks ;
 share -> tot_locks = r_locks + w_locks ;
 if ( ! error ) return 0 ;
 }
 err : mi_check_print_error ( param , "%d when updating keyfile" , my_errno ) ;
 return 1 ;
 }
void update_auto_increment_key ( MI_CHECK * param , MI_INFO * info , my_bool repair_only ) {
 uchar * record = 0 ;
 DBUG_ENTER ( "update_auto_increment_key" ) ;
 if ( ! info -> s -> base . auto_key || ! mi_is_key_active ( info -> s -> state . key_map , info -> s -> base . auto_key - 1 ) ) {
 if ( ! ( param -> testflag & T_VERY_SILENT ) ) mi_check_print_info ( param , "Table: %s doesn't have an auto increment key\n" , param -> isam_file_name ) ;
 DBUG_VOID_RETURN ;
 }
 if ( ! ( param -> testflag & T_SILENT ) && ! ( param -> testflag & T_REP ) ) printf ( "Updating MyISAM file: %s\n" , param -> isam_file_name ) ;
 if ( ! mi_alloc_rec_buff ( info , - 1 , & record ) ) {
 mi_check_print_error ( param , "Not enough memory for extra record" ) ;
 DBUG_VOID_RETURN ;
 }
 mi_extra ( info , HA_EXTRA_KEYREAD , 0 ) ;
 if ( mi_rlast ( info , record , info -> s -> base . auto_key - 1 ) ) {
 if ( my_errno != HA_ERR_END_OF_FILE ) {
 mi_extra ( info , HA_EXTRA_NO_KEYREAD , 0 ) ;
 my_free ( mi_get_rec_buff_ptr ( info , record ) ) ;
 mi_check_print_error ( param , "%d when reading last record" , my_errno ) ;
 DBUG_VOID_RETURN ;
 }
 if ( ! repair_only ) info -> s -> state . auto_increment = param -> auto_increment_value ;
 }
 else {
 ulonglong auto_increment = retrieve_auto_increment ( info , record ) ;
 set_if_bigger ( info -> s -> state . auto_increment , auto_increment ) ;
 if ( ! repair_only ) set_if_bigger ( info -> s -> state . auto_increment , param -> auto_increment_value ) ;
 }
 mi_extra ( info , HA_EXTRA_NO_KEYREAD , 0 ) ;
 my_free ( mi_get_rec_buff_ptr ( info , record ) ) ;
 update_state_info ( param , info , UPDATE_AUTO_INC ) ;
 DBUG_VOID_RETURN ;
 }
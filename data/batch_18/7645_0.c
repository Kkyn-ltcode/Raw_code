static void set_data_file_type ( SORT_INFO * sort_info , MYISAM_SHARE * share ) {
 if ( ( sort_info -> new_data_file_type = share -> data_file_type ) == COMPRESSED_RECORD && sort_info -> param -> testflag & T_UNPACK ) {
 MYISAM_SHARE tmp ;
 if ( share -> options & HA_OPTION_PACK_RECORD ) sort_info -> new_data_file_type = DYNAMIC_RECORD ;
 else sort_info -> new_data_file_type = STATIC_RECORD ;
 memcpy ( ( char * ) & tmp , share , sizeof ( * share ) ) ;
 tmp . options = ~ HA_OPTION_COMPRESS_RECORD ;
 mi_setup_functions ( & tmp ) ;
 share -> delete_record = tmp . delete_record ;
 }
 }
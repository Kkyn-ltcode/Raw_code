int recreate_table ( MI_CHECK * param , MI_INFO * * org_info , char * filename ) {
 int error ;
 MI_INFO info ;
 MYISAM_SHARE share ;
 MI_KEYDEF * keyinfo , * key , * key_end ;
 HA_KEYSEG * keysegs , * keyseg ;
 MI_COLUMNDEF * recdef , * rec , * end ;
 MI_UNIQUEDEF * uniquedef , * u_ptr , * u_end ;
 MI_STATUS_INFO status_info ;
 uint unpack , key_parts ;
 ha_rows max_records ;
 ulonglong file_length , tmp_length ;
 MI_CREATE_INFO create_info ;
 DBUG_ENTER ( "recreate_table" ) ;
 error = 1 ;
 info = * * org_info ;
 status_info = ( * org_info ) -> state [ 0 ] ;
 info . state = & status_info ;
 share = * ( * org_info ) -> s ;
 unpack = ( share . options & HA_OPTION_COMPRESS_RECORD ) && ( param -> testflag & T_UNPACK ) ;
 if ( ! ( keyinfo = ( MI_KEYDEF * ) my_alloca ( sizeof ( MI_KEYDEF ) * share . base . keys ) ) ) DBUG_RETURN ( 0 ) ;
 memcpy ( ( uchar * ) keyinfo , ( uchar * ) share . keyinfo , ( size_t ) ( sizeof ( MI_KEYDEF ) * share . base . keys ) ) ;
 key_parts = share . base . all_key_parts ;
 if ( ! ( keysegs = ( HA_KEYSEG * ) my_alloca ( sizeof ( HA_KEYSEG ) * ( key_parts + share . base . keys ) ) ) ) {
 my_afree ( ( uchar * ) keyinfo ) ;
 DBUG_RETURN ( 1 ) ;
 }
 if ( ! ( recdef = ( MI_COLUMNDEF * ) my_alloca ( sizeof ( MI_COLUMNDEF ) * ( share . base . fields + 1 ) ) ) ) {
 my_afree ( ( uchar * ) keyinfo ) ;
 my_afree ( ( uchar * ) keysegs ) ;
 DBUG_RETURN ( 1 ) ;
 }
 if ( ! ( uniquedef = ( MI_UNIQUEDEF * ) my_alloca ( sizeof ( MI_UNIQUEDEF ) * ( share . state . header . uniques + 1 ) ) ) ) {
 my_afree ( ( uchar * ) recdef ) ;
 my_afree ( ( uchar * ) keyinfo ) ;
 my_afree ( ( uchar * ) keysegs ) ;
 DBUG_RETURN ( 1 ) ;
 }
 memcpy ( ( uchar * ) recdef , ( uchar * ) share . rec , ( size_t ) ( sizeof ( MI_COLUMNDEF ) * ( share . base . fields + 1 ) ) ) ;
 for ( rec = recdef , end = recdef + share . base . fields ;
 rec != end ;
 rec ++ ) {
 if ( unpack && ! ( share . options & HA_OPTION_PACK_RECORD ) && rec -> type != FIELD_BLOB && rec -> type != FIELD_VARCHAR && rec -> type != FIELD_CHECK ) rec -> type = ( int ) FIELD_NORMAL ;
 }
 memcpy ( ( uchar * ) keysegs , ( uchar * ) share . keyparts , ( size_t ) ( sizeof ( HA_KEYSEG ) * ( key_parts + share . base . keys + share . state . header . uniques ) ) ) ;
 keyseg = keysegs ;
 for ( key = keyinfo , key_end = keyinfo + share . base . keys ;
 key != key_end ;
 key ++ ) {
 key -> seg = keyseg ;
 for ( ;
 keyseg -> type ;
 keyseg ++ ) {
 if ( param -> language ) keyseg -> language = param -> language ;
 }
 keyseg ++ ;
 }
 memcpy ( ( uchar * ) uniquedef , ( uchar * ) share . uniqueinfo , ( size_t ) ( sizeof ( MI_UNIQUEDEF ) * ( share . state . header . uniques ) ) ) ;
 for ( u_ptr = uniquedef , u_end = uniquedef + share . state . header . uniques ;
 u_ptr != u_end ;
 u_ptr ++ ) {
 u_ptr -> seg = keyseg ;
 keyseg += u_ptr -> keysegs + 1 ;
 }
 unpack = ( share . options & HA_OPTION_COMPRESS_RECORD ) && ( param -> testflag & T_UNPACK ) ;
 share . options &= ~ HA_OPTION_TEMP_COMPRESS_RECORD ;
 file_length = ( ulonglong ) mysql_file_seek ( info . dfile , 0L , MY_SEEK_END , MYF ( 0 ) ) ;
 tmp_length = file_length + file_length / 10 ;
 set_if_bigger ( file_length , param -> max_data_file_length ) ;
 set_if_bigger ( file_length , tmp_length ) ;
 set_if_bigger ( file_length , ( ulonglong ) share . base . max_data_file_length ) ;
 if ( share . options & HA_OPTION_COMPRESS_RECORD ) share . base . records = max_records = info . state -> records ;
 else if ( ! ( share . options & HA_OPTION_PACK_RECORD ) ) max_records = ( ha_rows ) ( file_length / share . base . pack_reclength ) ;
 else max_records = 0 ;
 ( void ) mi_close ( * org_info ) ;
 bzero ( ( char * ) & create_info , sizeof ( create_info ) ) ;
 create_info . max_rows = max_records ;
 create_info . reloc_rows = share . base . reloc ;
 create_info . old_options = ( share . options | ( unpack ? HA_OPTION_TEMP_COMPRESS_RECORD : 0 ) ) ;
 create_info . data_file_length = file_length ;
 create_info . auto_increment = share . state . auto_increment ;
 create_info . language = ( param -> language ? param -> language : share . state . header . language ) ;
 create_info . key_file_length = status_info . key_file_length ;
 create_info . with_auto_increment = TRUE ;
 if ( mi_create ( filename , share . base . keys - share . state . header . uniques , keyinfo , share . base . fields , recdef , share . state . header . uniques , uniquedef , & create_info , HA_DONT_TOUCH_DATA ) ) {
 mi_check_print_error ( param , "Got error %d when trying to recreate indexfile" , my_errno ) ;
 goto end ;
 }
 * org_info = mi_open ( filename , O_RDWR , ( param -> testflag & T_WAIT_FOREVER ) ? HA_OPEN_WAIT_IF_LOCKED : ( param -> testflag & T_DESCRIPT ) ? HA_OPEN_IGNORE_IF_LOCKED : HA_OPEN_ABORT_IF_LOCKED ) ;
 if ( ! * org_info ) {
 mi_check_print_error ( param , "Got error %d when trying to open re-created indexfile" , my_errno ) ;
 goto end ;
 }
 ( * org_info ) -> s -> options &= ~ HA_OPTION_READ_ONLY_DATA ;
 ( void ) _mi_readinfo ( * org_info , F_WRLCK , 0 ) ;
 ( * org_info ) -> state -> records = info . state -> records ;
 if ( share . state . create_time ) ( * org_info ) -> s -> state . create_time = share . state . create_time ;
 ( * org_info ) -> s -> state . unique = ( * org_info ) -> this_unique = share . state . unique ;
 ( * org_info ) -> state -> checksum = info . state -> checksum ;
 ( * org_info ) -> state -> del = info . state -> del ;
 ( * org_info ) -> s -> state . dellink = share . state . dellink ;
 ( * org_info ) -> state -> empty = info . state -> empty ;
 ( * org_info ) -> state -> data_file_length = info . state -> data_file_length ;
 if ( update_state_info ( param , * org_info , UPDATE_TIME | UPDATE_STAT | UPDATE_OPEN_COUNT ) ) goto end ;
 error = 0 ;
 end : my_afree ( ( uchar * ) uniquedef ) ;
 my_afree ( ( uchar * ) keyinfo ) ;
 my_afree ( ( uchar * ) recdef ) ;
 my_afree ( ( uchar * ) keysegs ) ;
 DBUG_RETURN ( error ) ;
 }
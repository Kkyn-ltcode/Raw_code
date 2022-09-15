static int sort_ft_key_write ( MI_SORT_PARAM * sort_param , const void * a ) {
 uint a_len , val_off , val_len , error ;
 uchar * p ;
 SORT_INFO * sort_info = sort_param -> sort_info ;
 SORT_FT_BUF * ft_buf = sort_info -> ft_buf ;
 SORT_KEY_BLOCKS * key_block = sort_info -> key_block ;
 val_len = HA_FT_WLEN + sort_info -> info -> s -> rec_reflength ;
 get_key_full_length_rdonly ( a_len , ( uchar * ) a ) ;
 if ( ! ft_buf ) {
 if ( ( sort_info -> info -> s -> base . key_reflength <= sort_info -> info -> s -> rec_reflength ) && ( sort_info -> info -> s -> options & ( HA_OPTION_PACK_RECORD | HA_OPTION_COMPRESS_RECORD ) ) ) ft_buf = ( SORT_FT_BUF * ) my_malloc ( sort_param -> keyinfo -> block_length + sizeof ( SORT_FT_BUF ) , MYF ( MY_WME ) ) ;
 if ( ! ft_buf ) {
 sort_param -> key_write = sort_key_write ;
 return sort_key_write ( sort_param , a ) ;
 }
 sort_info -> ft_buf = ft_buf ;
 goto word_init_ft_buf ;
 }
 get_key_full_length_rdonly ( val_off , ft_buf -> lastkey ) ;
 if ( ha_compare_text ( sort_param -> seg -> charset , ( ( uchar * ) a ) + 1 , a_len - 1 , ft_buf -> lastkey + 1 , val_off - 1 , 0 , 0 ) == 0 ) {
 if ( ! ft_buf -> buf ) {
 ft_buf -> count ++ ;
 return sort_insert_key ( sort_param , key_block , ( ( uchar * ) a ) + a_len , HA_OFFSET_ERROR ) ;
 }
 memcpy ( ft_buf -> buf , ( char * ) a + a_len , val_len ) ;
 ft_buf -> buf += val_len ;
 if ( ft_buf -> buf < ft_buf -> end ) return 0 ;
 p = ft_buf -> lastkey + val_off ;
 while ( key_block -> inited ) key_block ++ ;
 sort_info -> key_block = key_block ;
 sort_param -> keyinfo = & sort_info -> info -> s -> ft2_keyinfo ;
 ft_buf -> count = ( uint ) ( ft_buf -> buf - p ) / val_len ;
 for ( error = 0 ;
 ! error && p < ft_buf -> buf ;
 p += val_len ) error = sort_insert_key ( sort_param , key_block , p , HA_OFFSET_ERROR ) ;
 ft_buf -> buf = 0 ;
 return error ;
 }
 if ( ( error = sort_ft_buf_flush ( sort_param ) ) ) return error ;
 word_init_ft_buf : a_len += val_len ;
 memcpy ( ft_buf -> lastkey , a , a_len ) ;
 ft_buf -> buf = ft_buf -> lastkey + a_len ;
 ft_buf -> end = ft_buf -> lastkey + ( sort_param -> keyinfo -> block_length - 32 ) ;
 return 0 ;
 }
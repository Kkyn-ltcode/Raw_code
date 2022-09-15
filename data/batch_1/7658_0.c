static int writekeys ( MI_SORT_PARAM * sort_param ) {
 register uint i ;
 uchar * key ;
 MI_INFO * info = sort_param -> sort_info -> info ;
 uchar * buff = sort_param -> record ;
 my_off_t filepos = sort_param -> filepos ;
 DBUG_ENTER ( "writekeys" ) ;
 key = info -> lastkey + info -> s -> base . max_key_length ;
 for ( i = 0 ;
 i < info -> s -> base . keys ;
 i ++ ) {
 if ( mi_is_key_active ( info -> s -> state . key_map , i ) ) {
 if ( info -> s -> keyinfo [ i ] . flag & HA_FULLTEXT ) {
 if ( _mi_ft_add ( info , i , key , buff , filepos ) ) goto err ;
 }
 # ifdef HAVE_SPATIAL else if ( info -> s -> keyinfo [ i ] . flag & HA_SPATIAL ) {
 uint key_length = _mi_make_key ( info , i , key , buff , filepos ) ;
 if ( rtree_insert ( info , i , key , key_length ) ) goto err ;
 }
 # endif else {
 uint key_length = _mi_make_key ( info , i , key , buff , filepos ) ;
 if ( _mi_ck_write ( info , i , key , key_length ) ) goto err ;
 }
 }
 }
 DBUG_RETURN ( 0 ) ;
 err : if ( my_errno == HA_ERR_FOUND_DUPP_KEY ) {
 info -> errkey = ( int ) i ;
 while ( i -- > 0 ) {
 if ( mi_is_key_active ( info -> s -> state . key_map , i ) ) {
 if ( info -> s -> keyinfo [ i ] . flag & HA_FULLTEXT ) {
 if ( _mi_ft_del ( info , i , key , buff , filepos ) ) break ;
 }
 else {
 uint key_length = _mi_make_key ( info , i , key , buff , filepos ) ;
 if ( _mi_ck_delete ( info , i , key , key_length ) ) break ;
 }
 }
 }
 }
 if ( sort_param -> calc_checksum ) sort_param -> sort_info -> param -> glob_crc -= info -> checksum ;
 DBUG_PRINT ( "error" , ( "errno: %d" , my_errno ) ) ;
 DBUG_RETURN ( - 1 ) ;
 }
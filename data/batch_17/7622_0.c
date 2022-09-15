int movepoint ( register MI_INFO * info , uchar * record , my_off_t oldpos , my_off_t newpos , uint prot_key ) {
 register uint i ;
 uchar * key ;
 uint key_length ;
 DBUG_ENTER ( "movepoint" ) ;
 key = info -> lastkey + info -> s -> base . max_key_length ;
 for ( i = 0 ;
 i < info -> s -> base . keys ;
 i ++ ) {
 if ( i != prot_key && mi_is_key_active ( info -> s -> state . key_map , i ) ) {
 key_length = _mi_make_key ( info , i , key , record , oldpos ) ;
 if ( info -> s -> keyinfo [ i ] . flag & HA_NOSAME ) {
 uint nod_flag ;
 MI_KEYDEF * keyinfo ;
 keyinfo = info -> s -> keyinfo + i ;
 if ( _mi_search ( info , keyinfo , key , USE_WHOLE_KEY , ( uint ) ( SEARCH_SAME | SEARCH_SAVE_BUFF ) , info -> s -> state . key_root [ i ] ) ) DBUG_RETURN ( - 1 ) ;
 nod_flag = mi_test_if_nod ( info -> buff ) ;
 _mi_dpointer ( info , info -> int_keypos - nod_flag - info -> s -> rec_reflength , newpos ) ;
 if ( _mi_write_keypage ( info , keyinfo , info -> last_keypage , DFLT_INIT_HITS , info -> buff ) ) DBUG_RETURN ( - 1 ) ;
 }
 else {
 if ( _mi_ck_delete ( info , i , key , key_length ) ) DBUG_RETURN ( - 1 ) ;
 key_length = _mi_make_key ( info , i , key , record , newpos ) ;
 if ( _mi_ck_write ( info , i , key , key_length ) ) DBUG_RETURN ( - 1 ) ;
 }
 }
 }
 DBUG_RETURN ( 0 ) ;
 }
static my_off_t get_record_for_key ( MI_INFO * info , MI_KEYDEF * keyinfo , uchar * key ) {
 return _mi_dpos ( info , 0 , key + _mi_keylength ( keyinfo , key ) ) ;
 }
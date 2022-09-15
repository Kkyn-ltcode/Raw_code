static my_bool mi_too_big_key_for_sort ( MI_KEYDEF * key , ha_rows rows ) {
 uint key_maxlength = key -> maxlength ;
 if ( key -> flag & HA_FULLTEXT ) {
 uint ft_max_word_len_for_sort = FT_MAX_WORD_LEN_FOR_SORT * key -> seg -> charset -> mbmaxlen ;
 key_maxlength += ft_max_word_len_for_sort - HA_FT_MAXBYTELEN ;
 }
 return ( key -> flag & HA_SPATIAL ) || ( key -> flag & ( HA_BINARY_PACK_KEY | HA_VAR_LENGTH_KEY | HA_FULLTEXT ) && ( ( ulonglong ) rows * key_maxlength > myisam_max_temp_length ) ) ;
 }
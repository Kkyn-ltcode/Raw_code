int test_if_almost_full ( MI_INFO * info ) {
 if ( info -> s -> options & HA_OPTION_COMPRESS_RECORD ) return 0 ;
 return mysql_file_seek ( info -> s -> kfile , 0L , MY_SEEK_END , MYF ( MY_THREADSAFE ) ) / 10 * 9 > ( my_off_t ) info -> s -> base . max_key_file_length || mysql_file_seek ( info -> dfile , 0L , MY_SEEK_END , MYF ( 0 ) ) / 10 * 9 > ( my_off_t ) info -> s -> base . max_data_file_length ;
 }
void ufile_flush_translit ( UFILE * f ) {
 # if ! UCONFIG_NO_TRANSLITERATION if ( ( ! f ) || ( ! f -> fTranslit ) ) return ;
 # endif u_file_write_flush ( NULL , 0 , f , FALSE , TRUE ) ;
 }
void ufile_close_translit ( UFILE * f ) {
 # if ! UCONFIG_NO_TRANSLITERATION if ( ( ! f ) || ( ! f -> fTranslit ) ) return ;
 # endif ufile_flush_translit ( f ) ;
 # if ! UCONFIG_NO_TRANSLITERATION if ( f -> fTranslit -> translit ) utrans_close ( f -> fTranslit -> translit ) ;
 if ( f -> fTranslit -> buffer ) {
 uprv_free ( f -> fTranslit -> buffer ) ;
 }
 uprv_free ( f -> fTranslit ) ;
 f -> fTranslit = NULL ;
 # endif }
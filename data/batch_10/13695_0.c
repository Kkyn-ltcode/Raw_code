static gboolean is_all_button_text ( const char * button_text ) {
 g_assert ( button_text != NULL ) ;
 return ! strcmp ( button_text , SKIP_ALL ) || ! strcmp ( button_text , REPLACE_ALL ) || ! strcmp ( button_text , DELETE_ALL ) || ! strcmp ( button_text , MERGE_ALL ) ;
 }
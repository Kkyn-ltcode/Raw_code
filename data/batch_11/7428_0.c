void free_replace_regex ( ) {
 if ( glob_replace_regex ) {
 delete_dynamic ( & glob_replace_regex -> regex_arr ) ;
 my_free ( glob_replace_regex -> even_buf ) ;
 my_free ( glob_replace_regex -> odd_buf ) ;
 my_free ( glob_replace_regex ) ;
 glob_replace_regex = 0 ;
 }
 }
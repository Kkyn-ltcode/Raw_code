static char * my_case_str ( const char * str , size_t str_len , const char * token , uint token_len ) {
 my_match_t match ;
 uint status = my_charset_latin1 . coll -> instr ( & my_charset_latin1 , str , str_len , token , token_len , & match , 1 ) ;
 return status ? ( char * ) str + match . end : NULL ;
 }
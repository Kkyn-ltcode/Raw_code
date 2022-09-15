static int replace ( DYNAMIC_STRING * ds_str , const char * search_str , ulong search_len , const char * replace_str , ulong replace_len ) {
 DYNAMIC_STRING ds_tmp ;
 const char * start = strstr ( ds_str -> str , search_str ) ;
 if ( ! start ) return 1 ;
 init_dynamic_string ( & ds_tmp , "" , ds_str -> length + replace_len , 256 ) ;
 dynstr_append_mem ( & ds_tmp , ds_str -> str , start - ds_str -> str ) ;
 dynstr_append_mem ( & ds_tmp , replace_str , replace_len ) ;
 dynstr_append ( & ds_tmp , start + search_len ) ;
 dynstr_set ( ds_str , ds_tmp . str ) ;
 dynstr_free ( & ds_tmp ) ;
 return 0 ;
 }
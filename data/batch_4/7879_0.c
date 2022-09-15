static void print_comment ( FILE * sql_file , my_bool is_error , const char * format , ... ) {
 static char comment_buff [ COMMENT_LENGTH ] ;
 va_list args ;
 if ( ! is_error && ! opt_comments ) return ;
 va_start ( args , format ) ;
 my_vsnprintf ( comment_buff , COMMENT_LENGTH , format , args ) ;
 va_end ( args ) ;
 if ( ! opt_xml ) {
 fputs ( comment_buff , sql_file ) ;
 check_io ( sql_file ) ;
 return ;
 }
 print_xml_comment ( sql_file , strlen ( comment_buff ) , comment_buff ) ;
 }
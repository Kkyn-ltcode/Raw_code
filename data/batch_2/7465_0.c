void do_sync_with_master ( struct st_command * command ) {
 long offset = 0 ;
 char * p = command -> first_argument ;
 const char * offset_start = p ;
 if ( * offset_start ) {
 for ( ;
 my_isdigit ( charset_info , * p ) ;
 p ++ ) offset = offset * 10 + * p - '0' ;
 if ( * p && ! my_isspace ( charset_info , * p ) ) die ( "Invalid integer argument \"%s\"" , offset_start ) ;
 command -> last_argument = p ;
 }
 do_sync_with_master2 ( command , offset ) ;
 return ;
 }
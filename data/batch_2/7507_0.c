void do_get_file_name ( struct st_command * command , char * dest , uint dest_max_len ) {
 char * p = command -> first_argument , * name ;
 if ( ! * p ) die ( "Missing file name argument" ) ;
 name = p ;
 while ( * p && ! my_isspace ( charset_info , * p ) ) p ++ ;
 if ( * p ) * p ++ = 0 ;
 command -> last_argument = p ;
 strmake ( dest , name , dest_max_len - 1 ) ;
 }
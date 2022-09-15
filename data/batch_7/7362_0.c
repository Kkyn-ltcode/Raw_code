int match_re ( my_regex_t * re , char * str ) {
 while ( my_isspace ( charset_info , * str ) ) str ++ ;
 if ( str [ 0 ] == '/' && str [ 1 ] == '*' ) {
 char * comm_end = strstr ( str , "*/" ) ;
 if ( ! comm_end ) die ( "Statement is unterminated comment" ) ;
 str = comm_end + 2 ;
 }
 int err = my_regexec ( re , str , ( size_t ) 0 , NULL , 0 ) ;
 if ( err == 0 ) return 1 ;
 else if ( err == REG_NOMATCH ) return 0 ;
 {
 char erbuf [ 100 ] ;
 int len = my_regerror ( err , re , erbuf , sizeof ( erbuf ) ) ;
 die ( "error %s, %d/%d `%s'\n" , re_eprint ( err ) , ( int ) len , ( int ) sizeof ( erbuf ) , erbuf ) ;
 }
 return 0 ;
 }
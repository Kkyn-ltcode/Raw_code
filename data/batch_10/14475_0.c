static const char * construct_prompt ( ) {
 processed_prompt . free ( ) ;
 time_t lclock = time ( NULL ) ;
 struct tm * t = localtime ( & lclock ) ;
 for ( char * c = current_prompt ;
 * c ;
 c ++ ) {
 if ( * c != PROMPT_CHAR ) processed_prompt . append ( * c ) ;
 else {
 switch ( * ++ c ) {
 case '\0' : c -- ;
 break ;
 case 'c' : add_int_to_prompt ( ++ prompt_counter ) ;
 break ;
 case 'v' : if ( connected ) processed_prompt . append ( mysql_get_server_info ( & mysql ) ) ;
 else processed_prompt . append ( "not_connected" ) ;
 break ;
 case 'd' : processed_prompt . append ( current_db ? current_db : "(none)" ) ;
 break ;
 case 'N' : if ( connected ) processed_prompt . append ( mysql_get_server_name ( & mysql ) ) ;
 else processed_prompt . append ( "unknown" ) ;
 break ;
 case 'h' : {
 const char * prompt ;
 prompt = connected ? mysql_get_host_info ( & mysql ) : "not_connected" ;
 if ( strstr ( prompt , "Localhost" ) ) processed_prompt . append ( "localhost" ) ;
 else {
 const char * end = strcend ( prompt , ' ' ) ;
 processed_prompt . append ( prompt , ( uint ) ( end - prompt ) ) ;
 }
 break ;
 }
 case 'p' : {
 # ifndef EMBEDDED_LIBRARY if ( ! connected ) {
 processed_prompt . append ( "not_connected" ) ;
 break ;
 }
 const char * host_info = mysql_get_host_info ( & mysql ) ;
 if ( strstr ( host_info , "memory" ) ) {
 processed_prompt . append ( mysql . host ) ;
 }
 else if ( strstr ( host_info , "TCP/IP" ) || ! mysql . unix_socket ) add_int_to_prompt ( mysql . port ) ;
 else {
 char * pos = strrchr ( mysql . unix_socket , '/' ) ;
 processed_prompt . append ( pos ? pos + 1 : mysql . unix_socket ) ;
 }
 # endif }
 break ;
 case 'U' : if ( ! full_username ) init_username ( ) ;
 processed_prompt . append ( full_username ? full_username : ( current_user ? current_user : "(unknown)" ) ) ;
 break ;
 case 'u' : if ( ! full_username ) init_username ( ) ;
 processed_prompt . append ( part_username ? part_username : ( current_user ? current_user : "(unknown)" ) ) ;
 break ;
 case PROMPT_CHAR : processed_prompt . append ( PROMPT_CHAR ) ;
 break ;
 case 'n' : processed_prompt . append ( '\n' ) ;
 break ;
 case ' ' : case '_' : processed_prompt . append ( ' ' ) ;
 break ;
 case 'R' : if ( t -> tm_hour < 10 ) processed_prompt . append ( '0' ) ;
 add_int_to_prompt ( t -> tm_hour ) ;
 break ;
 case 'r' : int getHour ;
 getHour = t -> tm_hour % 12 ;
 if ( getHour == 0 ) getHour = 12 ;
 if ( getHour < 10 ) processed_prompt . append ( '0' ) ;
 add_int_to_prompt ( getHour ) ;
 break ;
 case 'm' : if ( t -> tm_min < 10 ) processed_prompt . append ( '0' ) ;
 add_int_to_prompt ( t -> tm_min ) ;
 break ;
 case 'y' : int getYear ;
 getYear = t -> tm_year % 100 ;
 if ( getYear < 10 ) processed_prompt . append ( '0' ) ;
 add_int_to_prompt ( getYear ) ;
 break ;
 case 'Y' : add_int_to_prompt ( t -> tm_year + 1900 ) ;
 break ;
 case 'D' : char * dateTime ;
 dateTime = ctime ( & lclock ) ;
 processed_prompt . append ( strtok ( dateTime , "\n" ) ) ;
 break ;
 case 's' : if ( t -> tm_sec < 10 ) processed_prompt . append ( '0' ) ;
 add_int_to_prompt ( t -> tm_sec ) ;
 break ;
 case 'w' : processed_prompt . append ( day_names [ t -> tm_wday ] ) ;
 break ;
 case 'P' : processed_prompt . append ( t -> tm_hour < 12 ? "am" : "pm" ) ;
 break ;
 case 'o' : add_int_to_prompt ( t -> tm_mon + 1 ) ;
 break ;
 case 'O' : processed_prompt . append ( month_names [ t -> tm_mon ] ) ;
 break ;
 case '\'' : processed_prompt . append ( "'" ) ;
 break ;
 case '"' : processed_prompt . append ( '"' ) ;
 break ;
 case 'S' : processed_prompt . append ( ';
' ) ;
 break ;
 case 't' : processed_prompt . append ( '\t' ) ;
 break ;
 case 'l' : processed_prompt . append ( delimiter_str ) ;
 break ;
 default : processed_prompt . append ( c ) ;
 }
 }
 }
 processed_prompt . append ( '\0' ) ;
 return processed_prompt . ptr ( ) ;
 }
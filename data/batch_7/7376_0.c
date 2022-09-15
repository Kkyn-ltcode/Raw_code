void check_command_args ( struct st_command * command , const char * arguments , const struct command_arg * args , int num_args , const char delimiter_arg ) {
 int i ;
 const char * ptr = arguments ;
 const char * start ;
 DBUG_ENTER ( "check_command_args" ) ;
 DBUG_PRINT ( "enter" , ( "num_args: %d" , num_args ) ) ;
 for ( i = 0 ;
 i < num_args ;
 i ++ ) {
 const struct command_arg * arg = & args [ i ] ;
 char delimiter ;
 switch ( arg -> type ) {
 case ARG_STRING : while ( * ptr && * ptr == ' ' ) ptr ++ ;
 start = ptr ;
 delimiter = delimiter_arg ;
 if ( * ptr && strchr ( "'`\"" , * ptr ) ) {
 delimiter = * ptr ;
 start = ++ ptr ;
 }
 while ( * ptr && * ptr != delimiter ) ptr ++ ;
 if ( ptr > start ) {
 init_dynamic_string ( arg -> ds , 0 , ptr - start , 32 ) ;
 do_eval ( arg -> ds , start , ptr , FALSE ) ;
 }
 else {
 init_dynamic_string ( arg -> ds , "" , 0 , 0 ) ;
 }
 while ( * ptr && * ptr != delimiter_arg ) ptr ++ ;
 command -> last_argument = ( char * ) ptr ;
 if ( * ptr && * ptr == delimiter_arg ) ptr ++ ;
 DBUG_PRINT ( "info" , ( "val: %s" , arg -> ds -> str ) ) ;
 break ;
 case ARG_REST : start = ptr ;
 init_dynamic_string ( arg -> ds , 0 , command -> query_len , 256 ) ;
 do_eval ( arg -> ds , start , command -> end , FALSE ) ;
 command -> last_argument = command -> end ;
 DBUG_PRINT ( "info" , ( "val: %s" , arg -> ds -> str ) ) ;
 break ;
 default : DBUG_ASSERT ( "Unknown argument type" ) ;
 break ;
 }
 if ( arg -> ds -> length == 0 && arg -> required ) die ( "Missing required argument '%s' to command '%.*s'" , arg -> argname , command -> first_word_len , command -> query ) ;
 }
 ptr = command -> last_argument ;
 while ( ptr <= command -> end && * ptr != '#' ) {
 if ( * ptr && * ptr != ' ' ) die ( "Extra argument '%s' passed to '%.*s'" , ptr , command -> first_word_len , command -> query ) ;
 ptr ++ ;
 }
 DBUG_VOID_RETURN ;
 }
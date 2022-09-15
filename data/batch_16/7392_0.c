void read_embedded_server_arguments ( const char * name ) {
 char argument [ 1024 ] , buff [ FN_REFLEN ] , * str = 0 ;
 FILE * file ;
 if ( ! test_if_hard_path ( name ) ) {
 strxmov ( buff , opt_basedir , name , NullS ) ;
 name = buff ;
 }
 fn_format ( buff , name , "" , "" , MY_UNPACK_FILENAME ) ;
 if ( ! embedded_server_arg_count ) {
 embedded_server_arg_count = 1 ;
 embedded_server_args [ 0 ] = ( char * ) "" ;
 }
 if ( ! ( file = my_fopen ( buff , O_RDONLY | FILE_BINARY , MYF ( MY_WME ) ) ) ) die ( "Failed to open file '%s'" , buff ) ;
 while ( embedded_server_arg_count < MAX_EMBEDDED_SERVER_ARGS && ( str = fgets ( argument , sizeof ( argument ) , file ) ) ) {
 * ( strend ( str ) - 1 ) = 0 ;
 if ( ! ( embedded_server_args [ embedded_server_arg_count ] = ( char * ) my_strdup ( str , MYF ( MY_WME ) ) ) ) {
 my_fclose ( file , MYF ( 0 ) ) ;
 die ( "Out of memory" ) ;
 }
 embedded_server_arg_count ++ ;
 }
 my_fclose ( file , MYF ( 0 ) ) ;
 if ( str ) die ( "Too many arguments in option file: %s" , name ) ;
 return ;
 }
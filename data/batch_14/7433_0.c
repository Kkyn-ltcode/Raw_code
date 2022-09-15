void do_write_file_command ( struct st_command * command , my_bool append ) {
 static DYNAMIC_STRING ds_content ;
 static DYNAMIC_STRING ds_filename ;
 static DYNAMIC_STRING ds_delimiter ;
 const struct command_arg write_file_args [ ] = {
 {
 "filename" , ARG_STRING , TRUE , & ds_filename , "File to write to" }
 , {
 "delimiter" , ARG_STRING , FALSE , & ds_delimiter , "Delimiter to read until" }
 }
 ;
 DBUG_ENTER ( "do_write_file" ) ;
 check_command_args ( command , command -> first_argument , write_file_args , sizeof ( write_file_args ) / sizeof ( struct command_arg ) , ' ' ) ;
 if ( ! append && access ( ds_filename . str , F_OK ) == 0 ) {
 die ( "File already exist: '%s'" , ds_filename . str ) ;
 }
 ds_content = command -> content ;
 if ( ! ds_content . str ) {
 if ( ds_delimiter . length == 0 ) dynstr_set ( & ds_delimiter , "EOF" ) ;
 init_dynamic_string ( & ds_content , "" , 1024 , 1024 ) ;
 read_until_delimiter ( & ds_content , & ds_delimiter ) ;
 command -> content = ds_content ;
 }
 if ( cur_block -> ok ) {
 DBUG_PRINT ( "info" , ( "Writing to file: %s" , ds_filename . str ) ) ;
 str_to_file2 ( ds_filename . str , ds_content . str , ds_content . length , append ) ;
 }
 dynstr_free ( & ds_filename ) ;
 dynstr_free ( & ds_delimiter ) ;
 DBUG_VOID_RETURN ;
 }
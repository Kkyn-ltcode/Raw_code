void do_source ( struct st_command * command ) {
 static DYNAMIC_STRING ds_filename ;
 const struct command_arg source_args [ ] = {
 {
 "filename" , ARG_STRING , TRUE , & ds_filename , "File to source" }
 }
 ;
 DBUG_ENTER ( "do_source" ) ;
 check_command_args ( command , command -> first_argument , source_args , sizeof ( source_args ) / sizeof ( struct command_arg ) , ' ' ) ;
 if ( parser . current_line < ( parser . read_lines - 1 ) ) ;
 else {
 DBUG_PRINT ( "info" , ( "sourcing file: %s" , ds_filename . str ) ) ;
 open_file ( ds_filename . str ) ;
 }
 dynstr_free ( & ds_filename ) ;
 DBUG_VOID_RETURN ;
 }
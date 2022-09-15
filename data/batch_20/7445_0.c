static void do_result_format_version ( struct st_command * command ) {
 long version ;
 static DYNAMIC_STRING ds_version ;
 const struct command_arg result_format_args [ ] = {
 {
 "version" , ARG_STRING , TRUE , & ds_version , "Version to use" }
 }
 ;
 DBUG_ENTER ( "do_result_format_version" ) ;
 check_command_args ( command , command -> first_argument , result_format_args , sizeof ( result_format_args ) / sizeof ( struct command_arg ) , ',' ) ;
 if ( ! str2int ( ds_version . str , 10 , ( long ) 0 , ( long ) INT_MAX , & version ) ) die ( "Invalid version number: '%s'" , ds_version . str ) ;
 set_result_format_version ( version ) ;
 dynstr_append ( & ds_res , "result_format: " ) ;
 dynstr_append_mem ( & ds_res , ds_version . str , ds_version . length ) ;
 dynstr_append ( & ds_res , "\n" ) ;
 dynstr_free ( & ds_version ) ;
 }
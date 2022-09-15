void select_connection ( struct st_command * command ) {
 DBUG_ENTER ( "select_connection" ) ;
 static DYNAMIC_STRING ds_connection ;
 const struct command_arg connection_args [ ] = {
 {
 "connection_name" , ARG_STRING , TRUE , & ds_connection , "Name of the connection that we switch to." }
 }
 ;
 check_command_args ( command , command -> first_argument , connection_args , sizeof ( connection_args ) / sizeof ( struct command_arg ) , ' ' ) ;
 DBUG_PRINT ( "info" , ( "changing connection: %s" , ds_connection . str ) ) ;
 select_connection_name ( ds_connection . str ) ;
 dynstr_free ( & ds_connection ) ;
 DBUG_VOID_RETURN ;
 }
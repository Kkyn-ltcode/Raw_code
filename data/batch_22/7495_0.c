int do_echo ( struct st_command * command ) {
 DYNAMIC_STRING ds_echo ;
 DBUG_ENTER ( "do_echo" ) ;
 init_dynamic_string ( & ds_echo , "" , command -> query_len , 256 ) ;
 do_eval ( & ds_echo , command -> first_argument , command -> end , FALSE ) ;
 dynstr_append_mem ( & ds_res , ds_echo . str , ds_echo . length ) ;
 dynstr_append_mem ( & ds_res , "\n" , 1 ) ;
 dynstr_free ( & ds_echo ) ;
 command -> last_argument = command -> end ;
 DBUG_RETURN ( 0 ) ;
 }
void do_let ( struct st_command * command ) {
 char * p = command -> first_argument ;
 char * var_name , * var_name_end ;
 DYNAMIC_STRING let_rhs_expr ;
 DBUG_ENTER ( "do_let" ) ;
 init_dynamic_string ( & let_rhs_expr , "" , 512 , 2048 ) ;
 if ( ! * p ) die ( "Missing arguments to let" ) ;
 var_name = p ;
 while ( * p && ( * p != '=' ) && ! my_isspace ( charset_info , * p ) ) p ++ ;
 var_name_end = p ;
 if ( var_name == var_name_end || ( var_name + 1 == var_name_end && * var_name == '$' ) ) die ( "Missing variable name in let" ) ;
 while ( my_isspace ( charset_info , * p ) ) p ++ ;
 if ( * p ++ != '=' ) die ( "Missing assignment operator in let" ) ;
 while ( * p && my_isspace ( charset_info , * p ) ) p ++ ;
 do_eval ( & let_rhs_expr , p , command -> end , FALSE ) ;
 command -> last_argument = command -> end ;
 var_set ( var_name , var_name_end , let_rhs_expr . str , ( let_rhs_expr . str + let_rhs_expr . length ) ) ;
 dynstr_free ( & let_rhs_expr ) ;
 revert_properties ( ) ;
 DBUG_VOID_RETURN ;
 }
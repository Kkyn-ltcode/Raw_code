void var_set_errno ( int sql_errno ) {
 var_set_int ( "$mysql_errno" , sql_errno ) ;
 var_set_string ( "$mysql_errname" , get_errname_from_code ( sql_errno ) ) ;
 }
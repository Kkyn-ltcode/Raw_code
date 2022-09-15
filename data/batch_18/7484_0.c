void var_set ( const char * var_name , const char * var_name_end , const char * var_val , const char * var_val_end ) {
 int digit , env_var = 0 ;
 VAR * v ;
 DBUG_ENTER ( "var_set" ) ;
 DBUG_PRINT ( "enter" , ( "var_name: '%.*s' = '%.*s' (length: %d)" , ( int ) ( var_name_end - var_name ) , var_name , ( int ) ( var_val_end - var_val ) , var_val , ( int ) ( var_val_end - var_val ) ) ) ;
 if ( * var_name != '$' ) env_var = 1 ;
 else var_name ++ ;
 digit = * var_name - '0' ;
 if ( ! ( digit < 10 && digit >= 0 ) ) {
 v = var_obtain ( var_name , ( uint ) ( var_name_end - var_name ) ) ;
 }
 else v = var_reg + digit ;
 eval_expr ( v , var_val , ( const char * * ) & var_val_end ) ;
 if ( env_var ) {
 if ( v -> int_dirty ) {
 sprintf ( v -> str_val , "%d" , v -> int_val ) ;
 v -> int_dirty = false ;
 v -> str_val_len = strlen ( v -> str_val ) ;
 }
 DBUG_ASSERT ( v -> name [ v -> name_len ] == 0 ) ;
 setenv ( v -> name , v -> str_val , 1 ) ;
 }
 DBUG_VOID_RETURN ;
 }
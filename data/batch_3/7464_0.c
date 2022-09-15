VAR * var_get ( const char * var_name , const char * * var_name_end , my_bool raw , my_bool ignore_not_existing ) {
 int digit ;
 VAR * v ;
 DBUG_ENTER ( "var_get" ) ;
 DBUG_PRINT ( "enter" , ( "var_name: %s" , var_name ) ) ;
 if ( * var_name != '$' ) goto err ;
 digit = * ++ var_name - '0' ;
 if ( digit < 0 || digit >= 10 ) {
 const char * save_var_name = var_name , * end ;
 uint length ;
 end = ( var_name_end ) ? * var_name_end : 0 ;
 while ( my_isvar ( charset_info , * var_name ) && var_name != end ) var_name ++ ;
 if ( var_name == save_var_name ) {
 if ( ignore_not_existing ) DBUG_RETURN ( 0 ) ;
 die ( "Empty variable" ) ;
 }
 length = ( uint ) ( var_name - save_var_name ) ;
 if ( length >= MAX_VAR_NAME_LENGTH ) die ( "Too long variable name: %s" , save_var_name ) ;
 if ( ! ( v = ( VAR * ) my_hash_search ( & var_hash , ( const uchar * ) save_var_name , length ) ) ) {
 char buff [ MAX_VAR_NAME_LENGTH + 1 ] ;
 strmake ( buff , save_var_name , length ) ;
 v = var_from_env ( buff , "" ) ;
 }
 var_name -- ;
 }
 else v = var_reg + digit ;
 if ( ! raw && v -> int_dirty ) {
 sprintf ( v -> str_val , "%d" , v -> int_val ) ;
 v -> int_dirty = false ;
 v -> str_val_len = strlen ( v -> str_val ) ;
 }
 if ( var_name_end ) * var_name_end = var_name ;
 DBUG_RETURN ( v ) ;
 err : if ( var_name_end ) * var_name_end = 0 ;
 die ( "Unsupported variable name: %s" , var_name ) ;
 DBUG_RETURN ( 0 ) ;
 }
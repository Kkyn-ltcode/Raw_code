VAR * var_from_env ( const char * name , const char * def_val ) {
 const char * tmp ;
 VAR * v ;
 if ( ! ( tmp = getenv ( name ) ) ) tmp = def_val ;
 v = var_init ( 0 , name , strlen ( name ) , tmp , strlen ( tmp ) ) ;
 my_hash_insert ( & var_hash , ( uchar * ) v ) ;
 return v ;
 }
static void var_free ( void * v ) {
 VAR * var = ( VAR * ) v ;
 my_free ( var -> str_val ) ;
 if ( var -> alloced ) my_free ( var ) ;
 }
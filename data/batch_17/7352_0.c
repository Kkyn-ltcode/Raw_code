VAR * var_obtain ( const char * name , int len ) {
 VAR * v ;
 if ( ( v = ( VAR * ) my_hash_search ( & var_hash , ( const uchar * ) name , len ) ) ) return v ;
 v = var_init ( 0 , name , len , "" , 0 ) ;
 my_hash_insert ( & var_hash , ( uchar * ) v ) ;
 return v ;
 }
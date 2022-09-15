static int show_default_keycache ( THD * thd , SHOW_VAR * var , char * buff ) {
 struct st_data {
 KEY_CACHE_STATISTICS stats ;
 SHOW_VAR var [ 8 ] ;
 }
 * data ;
 SHOW_VAR * v ;
 data = ( st_data * ) buff ;
 v = data -> var ;
 var -> type = SHOW_ARRAY ;
 var -> value = ( char * ) v ;
 get_key_cache_statistics ( dflt_key_cache , 0 , & data -> stats ) ;
 # define set_one_keycache_var ( X , Y ) v -> name = X ;
 v -> type = SHOW_LONGLONG ;
 v -> value = ( char * ) & data -> stats . Y ;
 v ++ ;
 set_one_keycache_var ( "blocks_not_flushed" , blocks_changed ) ;
 set_one_keycache_var ( "blocks_unused" , blocks_unused ) ;
 set_one_keycache_var ( "blocks_used" , blocks_used ) ;
 set_one_keycache_var ( "blocks_warm" , blocks_warm ) ;
 set_one_keycache_var ( "read_requests" , read_requests ) ;
 set_one_keycache_var ( "reads" , reads ) ;
 set_one_keycache_var ( "write_requests" , write_requests ) ;
 set_one_keycache_var ( "writes" , writes ) ;
 v -> name = 0 ;
 DBUG_ASSERT ( ( char * ) ( v + 1 ) <= buff + SHOW_VAR_FUNC_BUFF_SIZE ) ;
 # undef set_one_keycache_var return 0 ;
 }
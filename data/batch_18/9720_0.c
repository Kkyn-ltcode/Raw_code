static void State_free ( void * ptr ) {
 JSON_Generator_State * state = ptr ;
 if ( state -> indent ) ruby_xfree ( state -> indent ) ;
 if ( state -> space ) ruby_xfree ( state -> space ) ;
 if ( state -> space_before ) ruby_xfree ( state -> space_before ) ;
 if ( state -> object_nl ) ruby_xfree ( state -> object_nl ) ;
 if ( state -> array_nl ) ruby_xfree ( state -> array_nl ) ;
 if ( state -> array_delim ) fbuffer_free ( state -> array_delim ) ;
 if ( state -> object_delim ) fbuffer_free ( state -> object_delim ) ;
 if ( state -> object_delim2 ) fbuffer_free ( state -> object_delim2 ) ;
 ruby_xfree ( state ) ;
 }
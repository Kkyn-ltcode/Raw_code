static size_t State_memsize ( const void * ptr ) {
 const JSON_Generator_State * state = ptr ;
 size_t size = sizeof ( * state ) ;
 if ( state -> indent ) size += state -> indent_len + 1 ;
 if ( state -> space ) size += state -> space_len + 1 ;
 if ( state -> space_before ) size += state -> space_before_len + 1 ;
 if ( state -> object_nl ) size += state -> object_nl_len + 1 ;
 if ( state -> array_nl ) size += state -> array_nl_len + 1 ;
 if ( state -> array_delim ) size += FBUFFER_CAPA ( state -> array_delim ) ;
 if ( state -> object_delim ) size += FBUFFER_CAPA ( state -> object_delim ) ;
 if ( state -> object_delim2 ) size += FBUFFER_CAPA ( state -> object_delim2 ) ;
 return size ;
 }
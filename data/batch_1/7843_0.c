static char * alloc_query_str ( ulong size ) {
 char * query ;
 if ( ! ( query = ( char * ) my_malloc ( size , MYF ( MY_WME ) ) ) ) die ( EX_MYSQLERR , "Couldn't allocate a query string." ) ;
 return query ;
 }
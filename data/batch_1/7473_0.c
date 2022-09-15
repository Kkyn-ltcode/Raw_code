static int setenv ( const char * name , const char * value , int overwrite ) {
 size_t buflen = strlen ( name ) + strlen ( value ) + 2 ;
 char * envvar = ( char * ) malloc ( buflen ) ;
 if ( ! envvar ) return ENOMEM ;
 strcpy ( envvar , name ) ;
 strcat ( envvar , "=" ) ;
 strcat ( envvar , value ) ;
 putenv ( envvar ) ;
 return 0 ;
 }
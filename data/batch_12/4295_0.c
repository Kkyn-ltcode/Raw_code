static const char * lookup_name ( struct cpio * cpio , struct name_cache * * name_cache_variable , int ( * lookup_fn ) ( struct cpio * , const char * * , id_t ) , id_t id ) {
 char asnum [ 16 ] ;
 struct name_cache * cache ;
 const char * name ;
 int slot ;
 if ( * name_cache_variable == NULL ) {
 * name_cache_variable = malloc ( sizeof ( struct name_cache ) ) ;
 if ( * name_cache_variable == NULL ) lafe_errc ( 1 , ENOMEM , "No more memory" ) ;
 memset ( * name_cache_variable , 0 , sizeof ( struct name_cache ) ) ;
 ( * name_cache_variable ) -> size = name_cache_size ;
 }
 cache = * name_cache_variable ;
 cache -> probes ++ ;
 slot = id % cache -> size ;
 if ( cache -> cache [ slot ] . name != NULL ) {
 if ( cache -> cache [ slot ] . id == id ) {
 cache -> hits ++ ;
 return ( cache -> cache [ slot ] . name ) ;
 }
 free ( cache -> cache [ slot ] . name ) ;
 cache -> cache [ slot ] . name = NULL ;
 }
 if ( lookup_fn ( cpio , & name , id ) == 0 ) {
 if ( name == NULL || name [ 0 ] == '\0' ) {
 snprintf ( asnum , sizeof ( asnum ) , "%u" , ( unsigned ) id ) ;
 name = asnum ;
 }
 cache -> cache [ slot ] . name = strdup ( name ) ;
 if ( cache -> cache [ slot ] . name != NULL ) {
 cache -> cache [ slot ] . id = id ;
 return ( cache -> cache [ slot ] . name ) ;
 }
 }
 return ( NULL ) ;
 }
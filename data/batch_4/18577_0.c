xmlHashTablePtr xmlHashCreate ( int size ) {
 xmlHashTablePtr table ;
 if ( size <= 0 ) size = 256 ;
 table = xmlMalloc ( sizeof ( xmlHashTable ) ) ;
 if ( table ) {
 table -> dict = NULL ;
 table -> size = size ;
 table -> nbElems = 0 ;
 table -> table = xmlMalloc ( size * sizeof ( xmlHashEntry ) ) ;
 if ( table -> table ) {
 memset ( table -> table , 0 , size * sizeof ( xmlHashEntry ) ) ;
 # ifdef HASH_RANDOMIZATION table -> random_seed = __xmlRandom ( ) ;
 # endif return ( table ) ;
 }
 xmlFree ( table ) ;
 }
 return ( NULL ) ;
 }
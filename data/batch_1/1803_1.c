static const DataHeader * pointerTOCLookupFn ( const UDataMemory * pData , const char * name , int32_t * pLength , UErrorCode * pErrorCode ) {
 if ( pData -> toc != NULL ) {
 const PointerTOC * toc = ( PointerTOC * ) pData -> toc ;
 int32_t number , count = ( int32_t ) toc -> count ;
 # if defined ( UDATA_DEBUG_DUMP ) for ( number = 0 ;
 number < count ;
 ++ number ) {
 fprintf ( stderr , "\tx%d: %s\n" , number , toc -> entry [ number ] . entryName ) ;
 }
 # endif number = pointerTOCPrefixBinarySearch ( name , toc -> entry , count ) ;
 if ( number >= 0 ) {
 # ifdef UDATA_DEBUG fprintf ( stderr , "%s: Found.\n" , toc -> entry [ number ] . entryName ) ;
 # endif * pLength = - 1 ;
 return UDataMemory_normalizeDataPointer ( toc -> entry [ number ] . pHeader ) ;
 }
 else {
 # ifdef UDATA_DEBUG fprintf ( stderr , "%s: Not found.\n" , name ) ;
 # endif return NULL ;
 }
 }
 else {
 return pData -> pHeader ;
 }
 }
static const DataHeader * U_CALLCONV offsetTOCLookupFn ( const UDataMemory * pData , const char * tocEntryName , int32_t * pLength , UErrorCode * pErrorCode ) {
 ( void ) pErrorCode ;
 const UDataOffsetTOC * toc = ( UDataOffsetTOC * ) pData -> toc ;
 if ( toc != NULL ) {
 const char * base = ( const char * ) toc ;
 int32_t number , count = ( int32_t ) toc -> count ;
 # if defined ( UDATA_DEBUG_DUMP ) for ( number = 0 ;
 number < count ;
 ++ number ) {
 fprintf ( stderr , "\tx%d: %s\n" , number , & base [ toc -> entry [ number ] . nameOffset ] ) ;
 }
 # endif number = offsetTOCPrefixBinarySearch ( tocEntryName , base , toc -> entry , count ) ;
 if ( number >= 0 ) {
 const UDataOffsetTOCEntry * entry = toc -> entry + number ;
 # ifdef UDATA_DEBUG fprintf ( stderr , "%s: Found.\n" , tocEntryName ) ;
 # endif if ( ( number + 1 ) < count ) {
 * pLength = ( int32_t ) ( entry [ 1 ] . dataOffset - entry -> dataOffset ) ;
 }
 else {
 * pLength = - 1 ;
 }
 return ( const DataHeader * ) ( base + entry -> dataOffset ) ;
 }
 else {
 # ifdef UDATA_DEBUG fprintf ( stderr , "%s: Not found.\n" , tocEntryName ) ;
 # endif return NULL ;
 }
 }
 else {
 # ifdef UDATA_DEBUG fprintf ( stderr , "returning header\n" ) ;
 # endif return pData -> pHeader ;
 }
 }
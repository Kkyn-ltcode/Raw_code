static uint32_t U_CALLCONV offsetTOCEntryCount ( const UDataMemory * pData ) {
 int32_t retVal = 0 ;
 const UDataOffsetTOC * toc = ( UDataOffsetTOC * ) pData -> toc ;
 if ( toc != NULL ) {
 retVal = toc -> count ;
 }
 return retVal ;
 }
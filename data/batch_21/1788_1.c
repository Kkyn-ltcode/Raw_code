static void _LMBCSOpenWorker ( UConverter * _this , UConverterLoadArgs * pArgs , UErrorCode * err , ulmbcs_byte_t OptGroup ) {
 UConverterDataLMBCS * extraInfo = _this -> extraInfo = ( UConverterDataLMBCS * ) uprv_malloc ( sizeof ( UConverterDataLMBCS ) ) ;
 if ( extraInfo != NULL ) {
 UConverterNamePieces stackPieces ;
 UConverterLoadArgs stackArgs = {
 ( int32_t ) sizeof ( UConverterLoadArgs ) }
 ;
 ulmbcs_byte_t i ;
 uprv_memset ( extraInfo , 0 , sizeof ( UConverterDataLMBCS ) ) ;
 stackArgs . onlyTestIsLoadable = pArgs -> onlyTestIsLoadable ;
 for ( i = 0 ;
 i <= ULMBCS_GRP_LAST && U_SUCCESS ( * err ) ;
 i ++ ) {
 if ( OptGroupByteToCPName [ i ] != NULL ) {
 extraInfo -> OptGrpConverter [ i ] = ucnv_loadSharedData ( OptGroupByteToCPName [ i ] , & stackPieces , & stackArgs , err ) ;
 }
 }
 if ( U_FAILURE ( * err ) || pArgs -> onlyTestIsLoadable ) {
 _LMBCSClose ( _this ) ;
 return ;
 }
 extraInfo -> OptGroup = OptGroup ;
 extraInfo -> localeConverterIndex = FindLMBCSLocale ( pArgs -> locale ) ;
 }
 else {
 * err = U_MEMORY_ALLOCATION_ERROR ;
 }
 }
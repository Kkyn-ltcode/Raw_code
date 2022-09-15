char * FLTGetExpressionForValuesRanges ( layerObj * lp , const char * item , const char * value , int forcecharcter ) {
 int bIscharacter , bSqlLayer = MS_FALSE ;
 char * pszExpression = NULL , * pszEscapedStr = NULL , * pszTmpExpression = NULL ;
 char * * paszElements = NULL , * * papszRangeElements = NULL ;
 int numelements , i , nrangeelements ;
 if ( lp && item && value ) {
 if ( strstr ( value , "/" ) == NULL ) {
 paszElements = msStringSplit ( value , ',' , & numelements ) ;
 if ( paszElements && numelements > 0 ) {
 if ( forcecharcter ) bIscharacter = MS_TRUE ;
 bIscharacter = ! FLTIsNumeric ( paszElements [ 0 ] ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "(" ) ;
 for ( i = 0 ;
 i < numelements ;
 i ++ ) {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "(" ) ;
 if ( bSqlLayer ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 else {
 if ( bIscharacter ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , "\"" ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "[" ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "]" ) ;
 if ( bIscharacter ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , "\"" ) ;
 }
 if ( bIscharacter ) {
 if ( bSqlLayer ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , " = '" ) ;
 else pszTmpExpression = msStringConcatenate ( pszTmpExpression , " = \"" ) ;
 }
 else pszTmpExpression = msStringConcatenate ( pszTmpExpression , " = " ) ;
 pszEscapedStr = msLayerEscapeSQLParam ( lp , paszElements [ i ] ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , pszEscapedStr ) ;
 if ( bIscharacter ) {
 if ( bSqlLayer ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , "'" ) ;
 else pszTmpExpression = msStringConcatenate ( pszTmpExpression , "\"" ) ;
 }
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , ")" ) ;
 msFree ( pszEscapedStr ) ;
 pszEscapedStr = NULL ;
 if ( pszExpression != NULL ) pszExpression = msStringConcatenate ( pszExpression , " OR " ) ;
 pszExpression = msStringConcatenate ( pszExpression , pszTmpExpression ) ;
 msFree ( pszTmpExpression ) ;
 pszTmpExpression = NULL ;
 }
 pszExpression = msStringConcatenate ( pszExpression , ")" ) ;
 }
 msFreeCharArray ( paszElements , numelements ) ;
 }
 else {
 paszElements = msStringSplit ( value , ',' , & numelements ) ;
 if ( paszElements && numelements > 0 ) {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "(" ) ;
 for ( i = 0 ;
 i < numelements ;
 i ++ ) {
 papszRangeElements = msStringSplit ( paszElements [ i ] , '/' , & nrangeelements ) ;
 if ( papszRangeElements && nrangeelements > 0 ) {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "(" ) ;
 if ( nrangeelements == 2 || nrangeelements == 3 ) {
 if ( bSqlLayer ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 else {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "[" ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "]" ) ;
 }
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , " >= " ) ;
 pszEscapedStr = msLayerEscapeSQLParam ( lp , papszRangeElements [ 0 ] ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , pszEscapedStr ) ;
 msFree ( pszEscapedStr ) ;
 pszEscapedStr = NULL ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , " AND " ) ;
 if ( bSqlLayer ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 else {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "[" ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "]" ) ;
 }
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , " <= " ) ;
 pszEscapedStr = msLayerEscapeSQLParam ( lp , papszRangeElements [ 1 ] ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , pszEscapedStr ) ;
 msFree ( pszEscapedStr ) ;
 pszEscapedStr = NULL ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , ")" ) ;
 }
 else if ( nrangeelements == 1 ) {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "(" ) ;
 if ( bSqlLayer ) pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 else {
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "[" ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , item ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , "]" ) ;
 }
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , " = " ) ;
 pszEscapedStr = msLayerEscapeSQLParam ( lp , papszRangeElements [ 0 ] ) ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , pszEscapedStr ) ;
 msFree ( pszEscapedStr ) ;
 pszEscapedStr = NULL ;
 pszTmpExpression = msStringConcatenate ( pszTmpExpression , ")" ) ;
 }
 if ( pszExpression != NULL ) pszExpression = msStringConcatenate ( pszExpression , " OR " ) ;
 pszExpression = msStringConcatenate ( pszExpression , pszTmpExpression ) ;
 msFree ( pszTmpExpression ) ;
 pszTmpExpression = NULL ;
 }
 msFreeCharArray ( papszRangeElements , nrangeelements ) ;
 }
 pszExpression = msStringConcatenate ( pszExpression , ")" ) ;
 }
 msFreeCharArray ( paszElements , numelements ) ;
 }
 }
 msFree ( pszTmpExpression ) ;
 return pszExpression ;
 }
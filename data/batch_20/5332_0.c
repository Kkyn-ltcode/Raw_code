static char * get_icu_value_internal ( const char * loc_name , char * tag_name , int * result , int fromParseLocale ) {
 char * tag_value = NULL ;
 int32_t tag_value_len = 512 ;
 int singletonPos = 0 ;
 char * mod_loc_name = NULL ;
 int grOffset = 0 ;
 int32_t buflen = 512 ;
 UErrorCode status = U_ZERO_ERROR ;
 if ( strcmp ( tag_name , LOC_CANONICALIZE_TAG ) != 0 ) {
 grOffset = findOffset ( LOC_GRANDFATHERED , loc_name ) ;
 if ( grOffset >= 0 ) {
 if ( strcmp ( tag_name , LOC_LANG_TAG ) == 0 ) {
 return estrdup ( loc_name ) ;
 }
 else {
 return NULL ;
 }
 }
 if ( fromParseLocale == 1 ) {
 if ( strcmp ( tag_name , LOC_LANG_TAG ) == 0 ) {
 if ( strlen ( loc_name ) > 1 && ( isIDPrefix ( loc_name ) == 1 ) ) {
 return estrdup ( loc_name ) ;
 }
 }
 singletonPos = getSingletonPos ( loc_name ) ;
 if ( singletonPos == 0 ) {
 return NULL ;
 }
 else if ( singletonPos > 0 ) {
 mod_loc_name = estrndup ( loc_name , singletonPos - 1 ) ;
 }
 }
 }
 if ( mod_loc_name == NULL ) {
 mod_loc_name = estrdup ( loc_name ) ;
 }
 do {
 tag_value = erealloc ( tag_value , buflen ) ;
 tag_value_len = buflen ;
 if ( strcmp ( tag_name , LOC_SCRIPT_TAG ) == 0 ) {
 buflen = uloc_getScript ( mod_loc_name , tag_value , tag_value_len , & status ) ;
 }
 if ( strcmp ( tag_name , LOC_LANG_TAG ) == 0 ) {
 buflen = uloc_getLanguage ( mod_loc_name , tag_value , tag_value_len , & status ) ;
 }
 if ( strcmp ( tag_name , LOC_REGION_TAG ) == 0 ) {
 buflen = uloc_getCountry ( mod_loc_name , tag_value , tag_value_len , & status ) ;
 }
 if ( strcmp ( tag_name , LOC_VARIANT_TAG ) == 0 ) {
 buflen = uloc_getVariant ( mod_loc_name , tag_value , tag_value_len , & status ) ;
 }
 if ( strcmp ( tag_name , LOC_CANONICALIZE_TAG ) == 0 ) {
 buflen = uloc_canonicalize ( mod_loc_name , tag_value , tag_value_len , & status ) ;
 }
 if ( U_FAILURE ( status ) ) {
 if ( status == U_BUFFER_OVERFLOW_ERROR ) {
 status = U_ZERO_ERROR ;
 buflen ++ ;
 continue ;
 }
 * result = 0 ;
 if ( tag_value ) {
 efree ( tag_value ) ;
 }
 if ( mod_loc_name ) {
 efree ( mod_loc_name ) ;
 }
 return NULL ;
 }
 }
 while ( buflen > tag_value_len ) ;
 if ( buflen == 0 ) {
 * result = - 1 ;
 if ( tag_value ) {
 efree ( tag_value ) ;
 }
 if ( mod_loc_name ) {
 efree ( mod_loc_name ) ;
 }
 return NULL ;
 }
 else {
 * result = 1 ;
 }
 if ( mod_loc_name ) {
 efree ( mod_loc_name ) ;
 }
 return tag_value ;
 }
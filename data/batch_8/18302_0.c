static UBool hasCESU8Data ( const UConverter * cnv ) {
 # if UCONFIG_ONLY_HTML_CONVERSION return FALSE ;
 # else return ( UBool ) ( cnv -> sharedData == & _CESU8Data ) ;
 # endif }
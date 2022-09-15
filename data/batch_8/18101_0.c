inline UChar * toUCharPtr ( char16_t * p ) {
 # ifdef U_ALIASING_BARRIER U_ALIASING_BARRIER ( p ) ;
 # endif return reinterpret_cast < UChar * > ( p ) ;
 }
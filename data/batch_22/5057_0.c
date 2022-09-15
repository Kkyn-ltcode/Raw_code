static int pattern_char_isalpha ( char c , bool is_multibyte , pg_locale_t locale , bool locale_is_c ) {
 if ( locale_is_c ) return ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ) ;
 else if ( is_multibyte && IS_HIGHBIT_SET ( c ) ) return true ;
 # ifdef HAVE_LOCALE_T else if ( locale ) return isalpha_l ( ( unsigned char ) c , locale ) ;
 # endif else return isalpha ( ( unsigned char ) c ) ;
 }
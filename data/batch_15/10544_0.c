static char * StripTags ( char * psz_subtitle ) {
 char * psz_text_start ;
 char * psz_text ;
 psz_text = psz_text_start = malloc ( strlen ( psz_subtitle ) + 1 ) ;
 if ( ! psz_text_start ) return NULL ;
 while ( * psz_subtitle ) {
 if ( * psz_subtitle == '<' ) {
 if ( strncasecmp ( psz_subtitle , "<br/>" , 5 ) == 0 ) * psz_text ++ = '\n' ;
 psz_subtitle += strcspn ( psz_subtitle , ">" ) ;
 }
 else if ( * psz_subtitle == '&' ) {
 if ( ! strncasecmp ( psz_subtitle , "&lt;
" , 4 ) ) {
 * psz_text ++ = '<' ;
 psz_subtitle += strcspn ( psz_subtitle , ";
" ) ;
 }
 else if ( ! strncasecmp ( psz_subtitle , "&gt;
" , 4 ) ) {
 * psz_text ++ = '>' ;
 psz_subtitle += strcspn ( psz_subtitle , ";
" ) ;
 }
 else if ( ! strncasecmp ( psz_subtitle , "&amp;
" , 5 ) ) {
 * psz_text ++ = '&' ;
 psz_subtitle += strcspn ( psz_subtitle , ";
" ) ;
 }
 else if ( ! strncasecmp ( psz_subtitle , "&quot;
" , 6 ) ) {
 * psz_text ++ = '\"' ;
 psz_subtitle += strcspn ( psz_subtitle , ";
" ) ;
 }
 else {
 * psz_text ++ = '&' ;
 }
 }
 else {
 * psz_text ++ = * psz_subtitle ;
 }
 if ( * psz_subtitle == '\0' ) break ;
 psz_subtitle ++ ;
 }
 * psz_text = '\0' ;
 char * psz = realloc ( psz_text_start , strlen ( psz_text_start ) + 1 ) ;
 if ( psz ) psz_text_start = psz ;
 return psz_text_start ;
 }
int get_file_params_count_resume ( char * * params , int paramcount ) {
 int pos , best ;
 if ( * params [ 0 ] == '"' ) {
 for ( pos = 0 ;
 pos < paramcount - 2 ;
 pos ++ ) {
 if ( params [ pos ] [ strlen ( params [ pos ] ) - 1 ] == '"' && get_params_match_resume ( params , pos + 1 ) ) return pos + 1 ;
 }
 }
 best = paramcount - 2 ;
 for ( pos = paramcount - 2 ;
 pos > 0 ;
 pos -- ) {
 if ( get_params_match_resume ( params , pos ) ) best = pos ;
 }
 return best ;
 }
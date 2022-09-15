static void full_to_model_counts ( vp9_coeff_count_model * model_count , vp9_coeff_count * full_count ) {
 int i , j , k , l ;
 for ( i = 0 ;
 i < PLANE_TYPES ;
 ++ i ) for ( j = 0 ;
 j < REF_TYPES ;
 ++ j ) for ( k = 0 ;
 k < COEF_BANDS ;
 ++ k ) for ( l = 0 ;
 l < BAND_COEFF_CONTEXTS ( k ) ;
 ++ l ) full_to_model_count ( model_count [ i ] [ j ] [ k ] [ l ] , full_count [ i ] [ j ] [ k ] [ l ] ) ;
 }
float * build_input_gamma_table ( struct curveType * TRC ) {
 float * gamma_table ;
 if ( ! TRC ) return NULL ;
 gamma_table = malloc ( sizeof ( float ) * 256 ) ;
 if ( gamma_table ) {
 if ( TRC -> type == PARAMETRIC_CURVE_TYPE ) {
 compute_curve_gamma_table_type_parametric ( gamma_table , TRC -> parameter , TRC -> count ) ;
 }
 else {
 if ( TRC -> count == 0 ) {
 compute_curve_gamma_table_type0 ( gamma_table ) ;
 }
 else if ( TRC -> count == 1 ) {
 compute_curve_gamma_table_type1 ( gamma_table , TRC -> data [ 0 ] ) ;
 }
 else {
 compute_curve_gamma_table_type2 ( gamma_table , TRC -> data , TRC -> count ) ;
 }
 }
 }
 validate_gamma_table ( gamma_table ) ;
 return gamma_table ;
 }
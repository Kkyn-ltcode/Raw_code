static float * anti_sparseness ( AMRWBContext * ctx , float * fixed_vector , float * buf ) {
 int ir_filter_nr ;
 if ( ctx -> fr_cur_mode > MODE_8k85 ) return fixed_vector ;
 if ( ctx -> pitch_gain [ 0 ] < 0.6 ) {
 ir_filter_nr = 0 ;
 }
 else if ( ctx -> pitch_gain [ 0 ] < 0.9 ) {
 ir_filter_nr = 1 ;
 }
 else ir_filter_nr = 2 ;
 if ( ctx -> fixed_gain [ 0 ] > 3.0 * ctx -> fixed_gain [ 1 ] ) {
 if ( ir_filter_nr < 2 ) ir_filter_nr ++ ;
 }
 else {
 int i , count = 0 ;
 for ( i = 0 ;
 i < 6 ;
 i ++ ) if ( ctx -> pitch_gain [ i ] < 0.6 ) count ++ ;
 if ( count > 2 ) ir_filter_nr = 0 ;
 if ( ir_filter_nr > ctx -> prev_ir_filter_nr + 1 ) ir_filter_nr -- ;
 }
 ctx -> prev_ir_filter_nr = ir_filter_nr ;
 ir_filter_nr += ( ctx -> fr_cur_mode == MODE_8k85 ) ;
 if ( ir_filter_nr < 2 ) {
 int i ;
 const float * coef = ir_filters_lookup [ ir_filter_nr ] ;
 memset ( buf , 0 , sizeof ( float ) * AMRWB_SFR_SIZE ) ;
 for ( i = 0 ;
 i < AMRWB_SFR_SIZE ;
 i ++ ) if ( fixed_vector [ i ] ) ff_celp_circ_addf ( buf , buf , coef , i , fixed_vector [ i ] , AMRWB_SFR_SIZE ) ;
 fixed_vector = buf ;
 }
 return fixed_vector ;
 }
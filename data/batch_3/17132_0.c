static int decode_coefs ( VP9_COMMON * cm , const MACROBLOCKD * xd , PLANE_TYPE type , tran_low_t * dqcoeff , TX_SIZE tx_size , const int16_t * dq , int ctx , const int16_t * scan , const int16_t * nb , vp9_reader * r ) {
 const int max_eob = 16 << ( tx_size << 1 ) ;
 const FRAME_CONTEXT * const fc = & cm -> fc ;
 FRAME_COUNTS * const counts = & cm -> counts ;
 const int ref = is_inter_block ( & xd -> mi [ 0 ] . src_mi -> mbmi ) ;
 int band , c = 0 ;
 const vp9_prob ( * coef_probs ) [ COEFF_CONTEXTS ] [ UNCONSTRAINED_NODES ] = fc -> coef_probs [ tx_size ] [ type ] [ ref ] ;
 const vp9_prob * prob ;
 unsigned int ( * coef_counts ) [ COEFF_CONTEXTS ] [ UNCONSTRAINED_NODES + 1 ] = counts -> coef [ tx_size ] [ type ] [ ref ] ;
 unsigned int ( * eob_branch_count ) [ COEFF_CONTEXTS ] = counts -> eob_branch [ tx_size ] [ type ] [ ref ] ;
 uint8_t token_cache [ 32 * 32 ] ;
 const uint8_t * band_translate = get_band_translate ( tx_size ) ;
 const int dq_shift = ( tx_size == TX_32X32 ) ;
 int v , token ;
 int16_t dqv = dq [ 0 ] ;
 const uint8_t * cat1_prob ;
 const uint8_t * cat2_prob ;
 const uint8_t * cat3_prob ;
 const uint8_t * cat4_prob ;
 const uint8_t * cat5_prob ;
 const uint8_t * cat6_prob ;
 # if CONFIG_VP9_HIGHBITDEPTH if ( cm -> use_highbitdepth ) {
 if ( cm -> bit_depth == VPX_BITS_10 ) {
 cat1_prob = vp9_cat1_prob_high10 ;
 cat2_prob = vp9_cat2_prob_high10 ;
 cat3_prob = vp9_cat3_prob_high10 ;
 cat4_prob = vp9_cat4_prob_high10 ;
 cat5_prob = vp9_cat5_prob_high10 ;
 cat6_prob = vp9_cat6_prob_high10 ;
 }
 else {
 cat1_prob = vp9_cat1_prob_high12 ;
 cat2_prob = vp9_cat2_prob_high12 ;
 cat3_prob = vp9_cat3_prob_high12 ;
 cat4_prob = vp9_cat4_prob_high12 ;
 cat5_prob = vp9_cat5_prob_high12 ;
 cat6_prob = vp9_cat6_prob_high12 ;
 }
 }
 else {
 cat1_prob = vp9_cat1_prob ;
 cat2_prob = vp9_cat2_prob ;
 cat3_prob = vp9_cat3_prob ;
 cat4_prob = vp9_cat4_prob ;
 cat5_prob = vp9_cat5_prob ;
 cat6_prob = vp9_cat6_prob ;
 }
 # else cat1_prob = vp9_cat1_prob ;
 cat2_prob = vp9_cat2_prob ;
 cat3_prob = vp9_cat3_prob ;
 cat4_prob = vp9_cat4_prob ;
 cat5_prob = vp9_cat5_prob ;
 cat6_prob = vp9_cat6_prob ;
 # endif while ( c < max_eob ) {
 int val = - 1 ;
 band = * band_translate ++ ;
 prob = coef_probs [ band ] [ ctx ] ;
 if ( ! cm -> frame_parallel_decoding_mode ) ++ eob_branch_count [ band ] [ ctx ] ;
 if ( ! vp9_read ( r , prob [ EOB_CONTEXT_NODE ] ) ) {
 INCREMENT_COUNT ( EOB_MODEL_TOKEN ) ;
 break ;
 }
 while ( ! vp9_read ( r , prob [ ZERO_CONTEXT_NODE ] ) ) {
 INCREMENT_COUNT ( ZERO_TOKEN ) ;
 dqv = dq [ 1 ] ;
 token_cache [ scan [ c ] ] = 0 ;
 ++ c ;
 if ( c >= max_eob ) return c ;
 ctx = get_coef_context ( nb , token_cache , c ) ;
 band = * band_translate ++ ;
 prob = coef_probs [ band ] [ ctx ] ;
 }
 if ( ! vp9_read ( r , prob [ ONE_CONTEXT_NODE ] ) ) {
 INCREMENT_COUNT ( ONE_TOKEN ) ;
 token = ONE_TOKEN ;
 val = 1 ;
 }
 else {
 INCREMENT_COUNT ( TWO_TOKEN ) ;
 token = vp9_read_tree ( r , coeff_subtree_high , vp9_pareto8_full [ prob [ PIVOT_NODE ] - 1 ] ) ;
 switch ( token ) {
 case TWO_TOKEN : case THREE_TOKEN : case FOUR_TOKEN : val = token ;
 break ;
 case CATEGORY1_TOKEN : val = CAT1_MIN_VAL + read_coeff ( cat1_prob , 1 , r ) ;
 break ;
 case CATEGORY2_TOKEN : val = CAT2_MIN_VAL + read_coeff ( cat2_prob , 2 , r ) ;
 break ;
 case CATEGORY3_TOKEN : val = CAT3_MIN_VAL + read_coeff ( cat3_prob , 3 , r ) ;
 break ;
 case CATEGORY4_TOKEN : val = CAT4_MIN_VAL + read_coeff ( cat4_prob , 4 , r ) ;
 break ;
 case CATEGORY5_TOKEN : val = CAT5_MIN_VAL + read_coeff ( cat5_prob , 5 , r ) ;
 break ;
 case CATEGORY6_TOKEN : # if CONFIG_VP9_HIGHBITDEPTH switch ( cm -> bit_depth ) {
 case VPX_BITS_8 : val = CAT6_MIN_VAL + read_coeff ( cat6_prob , 14 , r ) ;
 break ;
 case VPX_BITS_10 : val = CAT6_MIN_VAL + read_coeff ( cat6_prob , 16 , r ) ;
 break ;
 case VPX_BITS_12 : val = CAT6_MIN_VAL + read_coeff ( cat6_prob , 18 , r ) ;
 break ;
 default : assert ( 0 ) ;
 return - 1 ;
 }
 # else val = CAT6_MIN_VAL + read_coeff ( cat6_prob , 14 , r ) ;
 # endif break ;
 }
 }
 v = ( val * dqv ) >> dq_shift ;
 dqcoeff [ scan [ c ] ] = vp9_read_bit ( r ) ? - v : v ;
 token_cache [ scan [ c ] ] = vp9_pt_energy_class [ token ] ;
 ++ c ;
 ctx = get_coef_context ( nb , token_cache , c ) ;
 dqv = dq [ 1 ] ;
 }
 return c ;
 }
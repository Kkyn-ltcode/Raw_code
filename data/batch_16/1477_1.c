static int decode_coefs ( VP9_COMMON * cm , const MACROBLOCKD * xd , PLANE_TYPE type , int16_t * dqcoeff , TX_SIZE tx_size , const int16_t * dq , int ctx , const int16_t * scan , const int16_t * nb , vp9_reader * r ) {
 const int max_eob = 16 << ( tx_size << 1 ) ;
 const FRAME_CONTEXT * const fc = & cm -> fc ;
 FRAME_COUNTS * const counts = & cm -> counts ;
 const int ref = is_inter_block ( & xd -> mi [ 0 ] -> mbmi ) ;
 int band , c = 0 ;
 const vp9_prob ( * coef_probs ) [ COEFF_CONTEXTS ] [ UNCONSTRAINED_NODES ] = fc -> coef_probs [ tx_size ] [ type ] [ ref ] ;
 const vp9_prob * prob ;
 unsigned int ( * coef_counts ) [ COEFF_CONTEXTS ] [ UNCONSTRAINED_NODES + 1 ] = counts -> coef [ tx_size ] [ type ] [ ref ] ;
 unsigned int ( * eob_branch_count ) [ COEFF_CONTEXTS ] = counts -> eob_branch [ tx_size ] [ type ] [ ref ] ;
 uint8_t token_cache [ 32 * 32 ] ;
 const uint8_t * band_translate = get_band_translate ( tx_size ) ;
 const int dq_shift = ( tx_size == TX_32X32 ) ;
 int v ;
 int16_t dqv = dq [ 0 ] ;
 while ( c < max_eob ) {
 int val ;
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
 WRITE_COEF_CONTINUE ( 1 , ONE_TOKEN ) ;
 }
 INCREMENT_COUNT ( TWO_TOKEN ) ;
 prob = vp9_pareto8_full [ prob [ PIVOT_NODE ] - 1 ] ;
 if ( ! vp9_read ( r , prob [ LOW_VAL_CONTEXT_NODE ] ) ) {
 if ( ! vp9_read ( r , prob [ TWO_CONTEXT_NODE ] ) ) {
 WRITE_COEF_CONTINUE ( 2 , TWO_TOKEN ) ;
 }
 if ( ! vp9_read ( r , prob [ THREE_CONTEXT_NODE ] ) ) {
 WRITE_COEF_CONTINUE ( 3 , THREE_TOKEN ) ;
 }
 WRITE_COEF_CONTINUE ( 4 , FOUR_TOKEN ) ;
 }
 if ( ! vp9_read ( r , prob [ HIGH_LOW_CONTEXT_NODE ] ) ) {
 if ( ! vp9_read ( r , prob [ CAT_ONE_CONTEXT_NODE ] ) ) {
 val = CAT1_MIN_VAL ;
 ADJUST_COEF ( vp9_cat1_prob [ 0 ] , 0 ) ;
 WRITE_COEF_CONTINUE ( val , CATEGORY1_TOKEN ) ;
 }
 val = CAT2_MIN_VAL ;
 ADJUST_COEF ( vp9_cat2_prob [ 0 ] , 1 ) ;
 ADJUST_COEF ( vp9_cat2_prob [ 1 ] , 0 ) ;
 WRITE_COEF_CONTINUE ( val , CATEGORY2_TOKEN ) ;
 }
 if ( ! vp9_read ( r , prob [ CAT_THREEFOUR_CONTEXT_NODE ] ) ) {
 if ( ! vp9_read ( r , prob [ CAT_THREE_CONTEXT_NODE ] ) ) {
 val = CAT3_MIN_VAL ;
 ADJUST_COEF ( vp9_cat3_prob [ 0 ] , 2 ) ;
 ADJUST_COEF ( vp9_cat3_prob [ 1 ] , 1 ) ;
 ADJUST_COEF ( vp9_cat3_prob [ 2 ] , 0 ) ;
 WRITE_COEF_CONTINUE ( val , CATEGORY3_TOKEN ) ;
 }
 val = CAT4_MIN_VAL ;
 ADJUST_COEF ( vp9_cat4_prob [ 0 ] , 3 ) ;
 ADJUST_COEF ( vp9_cat4_prob [ 1 ] , 2 ) ;
 ADJUST_COEF ( vp9_cat4_prob [ 2 ] , 1 ) ;
 ADJUST_COEF ( vp9_cat4_prob [ 3 ] , 0 ) ;
 WRITE_COEF_CONTINUE ( val , CATEGORY4_TOKEN ) ;
 }
 if ( ! vp9_read ( r , prob [ CAT_FIVE_CONTEXT_NODE ] ) ) {
 val = CAT5_MIN_VAL ;
 ADJUST_COEF ( vp9_cat5_prob [ 0 ] , 4 ) ;
 ADJUST_COEF ( vp9_cat5_prob [ 1 ] , 3 ) ;
 ADJUST_COEF ( vp9_cat5_prob [ 2 ] , 2 ) ;
 ADJUST_COEF ( vp9_cat5_prob [ 3 ] , 1 ) ;
 ADJUST_COEF ( vp9_cat5_prob [ 4 ] , 0 ) ;
 WRITE_COEF_CONTINUE ( val , CATEGORY5_TOKEN ) ;
 }
 val = 0 ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 0 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 1 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 2 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 3 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 4 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 5 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 6 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 7 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 8 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 9 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 10 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 11 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 12 ] ) ;
 val = ( val << 1 ) | vp9_read ( r , vp9_cat6_prob [ 13 ] ) ;
 val += CAT6_MIN_VAL ;
 WRITE_COEF_CONTINUE ( val , CATEGORY6_TOKEN ) ;
 }
 return c ;
 }
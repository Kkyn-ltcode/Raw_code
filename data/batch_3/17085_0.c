static void update_rd_ref_frame_probs ( VP8_COMP * cpi ) {
 VP8_COMMON * cm = & cpi -> common ;
 const int * const rfct = cpi -> mb . count_mb_ref_frame_usage ;
 const int rf_intra = rfct [ INTRA_FRAME ] ;
 const int rf_inter = rfct [ LAST_FRAME ] + rfct [ GOLDEN_FRAME ] + rfct [ ALTREF_FRAME ] ;
 if ( cm -> frame_type == KEY_FRAME ) {
 cpi -> prob_intra_coded = 255 ;
 cpi -> prob_last_coded = 128 ;
 cpi -> prob_gf_coded = 128 ;
 }
 else if ( ! ( rf_intra + rf_inter ) ) {
 cpi -> prob_intra_coded = 63 ;
 cpi -> prob_last_coded = 128 ;
 cpi -> prob_gf_coded = 128 ;
 }
 if ( cpi -> oxcf . number_of_layers == 1 ) {
 if ( cpi -> common . refresh_alt_ref_frame ) {
 cpi -> prob_intra_coded += 40 ;
 if ( cpi -> prob_intra_coded > 255 ) cpi -> prob_intra_coded = 255 ;
 cpi -> prob_last_coded = 200 ;
 cpi -> prob_gf_coded = 1 ;
 }
 else if ( cpi -> frames_since_golden == 0 ) {
 cpi -> prob_last_coded = 214 ;
 }
 else if ( cpi -> frames_since_golden == 1 ) {
 cpi -> prob_last_coded = 192 ;
 cpi -> prob_gf_coded = 220 ;
 }
 else if ( cpi -> source_alt_ref_active ) {
 cpi -> prob_gf_coded -= 20 ;
 if ( cpi -> prob_gf_coded < 10 ) cpi -> prob_gf_coded = 10 ;
 }
 if ( ! cpi -> source_alt_ref_active ) cpi -> prob_gf_coded = 255 ;
 }
 }
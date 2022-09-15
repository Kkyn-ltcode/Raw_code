void vp9_rc_update_rate_correction_factors ( VP9_COMP * cpi , int damp_var ) {
 const VP9_COMMON * const cm = & cpi -> common ;
 int correction_factor = 100 ;
 double rate_correction_factor = get_rate_correction_factor ( cpi ) ;
 double adjustment_limit ;
 int projected_size_based_on_q = 0 ;
 if ( cpi -> rc . is_src_frame_alt_ref ) return ;
 vp9_clear_system_state ( ) ;
 projected_size_based_on_q = estimate_bits_at_q ( cm -> frame_type , cm -> base_qindex , cm -> MBs , rate_correction_factor , cm -> bit_depth ) ;
 if ( projected_size_based_on_q > 0 ) correction_factor = ( 100 * cpi -> rc . projected_frame_size ) / projected_size_based_on_q ;
 switch ( damp_var ) {
 case 0 : adjustment_limit = 0.75 ;
 break ;
 case 1 : adjustment_limit = 0.375 ;
 break ;
 case 2 : default : adjustment_limit = 0.25 ;
 break ;
 }
 if ( correction_factor > 102 ) {
 correction_factor = ( int ) ( 100 + ( ( correction_factor - 100 ) * adjustment_limit ) ) ;
 rate_correction_factor = ( rate_correction_factor * correction_factor ) / 100 ;
 if ( rate_correction_factor > MAX_BPB_FACTOR ) rate_correction_factor = MAX_BPB_FACTOR ;
 }
 else if ( correction_factor < 99 ) {
 correction_factor = ( int ) ( 100 - ( ( 100 - correction_factor ) * adjustment_limit ) ) ;
 rate_correction_factor = ( rate_correction_factor * correction_factor ) / 100 ;
 if ( rate_correction_factor < MIN_BPB_FACTOR ) rate_correction_factor = MIN_BPB_FACTOR ;
 }
 set_rate_correction_factor ( cpi , rate_correction_factor ) ;
 }
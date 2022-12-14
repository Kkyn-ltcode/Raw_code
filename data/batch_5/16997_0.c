void vp9_set_contexts ( const MACROBLOCKD * xd , struct macroblockd_plane * pd , BLOCK_SIZE plane_bsize , TX_SIZE tx_size , int has_eob , int aoff , int loff ) {
 ENTROPY_CONTEXT * const a = pd -> above_context + aoff ;
 ENTROPY_CONTEXT * const l = pd -> left_context + loff ;
 const int tx_size_in_blocks = 1 << tx_size ;
 if ( has_eob && xd -> mb_to_right_edge < 0 ) {
 int i ;
 const int blocks_wide = num_4x4_blocks_wide_lookup [ plane_bsize ] + ( xd -> mb_to_right_edge >> ( 5 + pd -> subsampling_x ) ) ;
 int above_contexts = tx_size_in_blocks ;
 if ( above_contexts + aoff > blocks_wide ) above_contexts = blocks_wide - aoff ;
 for ( i = 0 ;
 i < above_contexts ;
 ++ i ) a [ i ] = has_eob ;
 for ( i = above_contexts ;
 i < tx_size_in_blocks ;
 ++ i ) a [ i ] = 0 ;
 }
 else {
 vpx_memset ( a , has_eob , sizeof ( ENTROPY_CONTEXT ) * tx_size_in_blocks ) ;
 }
 if ( has_eob && xd -> mb_to_bottom_edge < 0 ) {
 int i ;
 const int blocks_high = num_4x4_blocks_high_lookup [ plane_bsize ] + ( xd -> mb_to_bottom_edge >> ( 5 + pd -> subsampling_y ) ) ;
 int left_contexts = tx_size_in_blocks ;
 if ( left_contexts + loff > blocks_high ) left_contexts = blocks_high - loff ;
 for ( i = 0 ;
 i < left_contexts ;
 ++ i ) l [ i ] = has_eob ;
 for ( i = left_contexts ;
 i < tx_size_in_blocks ;
 ++ i ) l [ i ] = 0 ;
 }
 else {
 vpx_memset ( l , has_eob , sizeof ( ENTROPY_CONTEXT ) * tx_size_in_blocks ) ;
 }
 }
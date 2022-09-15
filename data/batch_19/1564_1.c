static void duplicate_mode_info_in_sb ( VP9_COMMON * cm , MACROBLOCKD * xd , int mi_row , int mi_col , BLOCK_SIZE bsize ) {
 const int block_width = num_8x8_blocks_wide_lookup [ bsize ] ;
 const int block_height = num_8x8_blocks_high_lookup [ bsize ] ;
 int i , j ;
 for ( j = 0 ;
 j < block_height ;
 ++ j ) for ( i = 0 ;
 i < block_width ;
 ++ i ) {
 if ( mi_row + j < cm -> mi_rows && mi_col + i < cm -> mi_cols ) xd -> mi [ j * xd -> mi_stride + i ] = xd -> mi [ 0 ] ;
 }
 }
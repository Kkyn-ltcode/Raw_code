void vp9_build_inter_predictors_sb ( MACROBLOCKD * xd , int mi_row , int mi_col , BLOCK_SIZE bsize ) {
 build_inter_predictors_for_planes ( xd , bsize , mi_row , mi_col , 0 , MAX_MB_PLANE - 1 ) ;
 }
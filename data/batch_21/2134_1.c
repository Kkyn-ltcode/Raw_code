static void sbr_qmf_analysis ( AVFloatDSPContext * dsp , FFTContext * mdct , SBRDSPContext * sbrdsp , const float * in , float * x , float z [ 320 ] , float W [ 2 ] [ 32 ] [ 32 ] [ 2 ] , int buf_idx ) {
 int i ;
 memcpy ( x , x + 1024 , ( 320 - 32 ) * sizeof ( x [ 0 ] ) ) ;
 memcpy ( x + 288 , in , 1024 * sizeof ( x [ 0 ] ) ) ;
 for ( i = 0 ;
 i < 32 ;
 i ++ ) {
 dsp -> vector_fmul_reverse ( z , sbr_qmf_window_ds , x , 320 ) ;
 sbrdsp -> sum64x5 ( z ) ;
 sbrdsp -> qmf_pre_shuffle ( z ) ;
 mdct -> imdct_half ( mdct , z , z + 64 ) ;
 sbrdsp -> qmf_post_shuffle ( W [ buf_idx ] [ i ] , z ) ;
 x += 32 ;
 }
 }
static void scale_and_extend_source ( YV12_BUFFER_CONFIG * sd , VP8_COMP * cpi ) {
 VP8_COMMON * cm = & cpi -> common ;
 if ( cm -> horiz_scale != 0 || cm -> vert_scale != 0 ) {
 # if CONFIG_SPATIAL_RESAMPLING int UNINITIALIZED_IS_SAFE ( hr ) , UNINITIALIZED_IS_SAFE ( hs ) ;
 int UNINITIALIZED_IS_SAFE ( vr ) , UNINITIALIZED_IS_SAFE ( vs ) ;
 int tmp_height ;
 if ( cm -> vert_scale == 3 ) tmp_height = 9 ;
 else tmp_height = 11 ;
 Scale2Ratio ( cm -> horiz_scale , & hr , & hs ) ;
 Scale2Ratio ( cm -> vert_scale , & vr , & vs ) ;
 vpx_scale_frame ( sd , & cpi -> scaled_source , cm -> temp_scale_frame . y_buffer , tmp_height , hs , hr , vs , vr , 0 ) ;
 vp8_yv12_extend_frame_borders ( & cpi -> scaled_source ) ;
 cpi -> Source = & cpi -> scaled_source ;
 # endif }
 else cpi -> Source = sd ;
 }
static void qcms_transform_module_clut_only ( struct qcms_modular_transform * transform , float * src , float * dest , size_t length ) {
 size_t i ;
 int xy_len = 1 ;
 int x_len = transform -> grid_size ;
 int len = x_len * x_len ;
 float * r_table = transform -> r_clut ;
 float * g_table = transform -> g_clut ;
 float * b_table = transform -> b_clut ;
 for ( i = 0 ;
 i < length ;
 i ++ ) {
 float linear_r = * src ++ ;
 float linear_g = * src ++ ;
 float linear_b = * src ++ ;
 int x = floor ( linear_r * ( transform -> grid_size - 1 ) ) ;
 int y = floor ( linear_g * ( transform -> grid_size - 1 ) ) ;
 int z = floor ( linear_b * ( transform -> grid_size - 1 ) ) ;
 int x_n = ceil ( linear_r * ( transform -> grid_size - 1 ) ) ;
 int y_n = ceil ( linear_g * ( transform -> grid_size - 1 ) ) ;
 int z_n = ceil ( linear_b * ( transform -> grid_size - 1 ) ) ;
 float x_d = linear_r * ( transform -> grid_size - 1 ) - x ;
 float y_d = linear_g * ( transform -> grid_size - 1 ) - y ;
 float z_d = linear_b * ( transform -> grid_size - 1 ) - z ;
 float r_x1 = lerp ( CLU ( r_table , x , y , z ) , CLU ( r_table , x_n , y , z ) , x_d ) ;
 float r_x2 = lerp ( CLU ( r_table , x , y_n , z ) , CLU ( r_table , x_n , y_n , z ) , x_d ) ;
 float r_y1 = lerp ( r_x1 , r_x2 , y_d ) ;
 float r_x3 = lerp ( CLU ( r_table , x , y , z_n ) , CLU ( r_table , x_n , y , z_n ) , x_d ) ;
 float r_x4 = lerp ( CLU ( r_table , x , y_n , z_n ) , CLU ( r_table , x_n , y_n , z_n ) , x_d ) ;
 float r_y2 = lerp ( r_x3 , r_x4 , y_d ) ;
 float clut_r = lerp ( r_y1 , r_y2 , z_d ) ;
 float g_x1 = lerp ( CLU ( g_table , x , y , z ) , CLU ( g_table , x_n , y , z ) , x_d ) ;
 float g_x2 = lerp ( CLU ( g_table , x , y_n , z ) , CLU ( g_table , x_n , y_n , z ) , x_d ) ;
 float g_y1 = lerp ( g_x1 , g_x2 , y_d ) ;
 float g_x3 = lerp ( CLU ( g_table , x , y , z_n ) , CLU ( g_table , x_n , y , z_n ) , x_d ) ;
 float g_x4 = lerp ( CLU ( g_table , x , y_n , z_n ) , CLU ( g_table , x_n , y_n , z_n ) , x_d ) ;
 float g_y2 = lerp ( g_x3 , g_x4 , y_d ) ;
 float clut_g = lerp ( g_y1 , g_y2 , z_d ) ;
 float b_x1 = lerp ( CLU ( b_table , x , y , z ) , CLU ( b_table , x_n , y , z ) , x_d ) ;
 float b_x2 = lerp ( CLU ( b_table , x , y_n , z ) , CLU ( b_table , x_n , y_n , z ) , x_d ) ;
 float b_y1 = lerp ( b_x1 , b_x2 , y_d ) ;
 float b_x3 = lerp ( CLU ( b_table , x , y , z_n ) , CLU ( b_table , x_n , y , z_n ) , x_d ) ;
 float b_x4 = lerp ( CLU ( b_table , x , y_n , z_n ) , CLU ( b_table , x_n , y_n , z_n ) , x_d ) ;
 float b_y2 = lerp ( b_x3 , b_x4 , y_d ) ;
 float clut_b = lerp ( b_y1 , b_y2 , z_d ) ;
 * dest ++ = clamp_float ( clut_r ) ;
 * dest ++ = clamp_float ( clut_g ) ;
 * dest ++ = clamp_float ( clut_b ) ;
 }
 }
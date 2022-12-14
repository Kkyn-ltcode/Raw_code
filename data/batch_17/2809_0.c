static void apply_loop_filter ( Vp3DecodeContext * s , int plane , int ystart , int yend ) {
 int x , y ;
 int * bounding_values = s -> bounding_values_array + 127 ;
 int width = s -> fragment_width [ ! ! plane ] ;
 int height = s -> fragment_height [ ! ! plane ] ;
 int fragment = s -> fragment_start [ plane ] + ystart * width ;
 int stride = s -> current_frame . f -> linesize [ plane ] ;
 uint8_t * plane_data = s -> current_frame . f -> data [ plane ] ;
 if ( ! s -> flipped_image ) stride = - stride ;
 plane_data += s -> data_offset [ plane ] + 8 * ystart * stride ;
 for ( y = ystart ;
 y < yend ;
 y ++ ) {
 for ( x = 0 ;
 x < width ;
 x ++ ) {
 if ( s -> all_fragments [ fragment ] . coding_method != MODE_COPY ) {
 if ( x > 0 ) {
 s -> vp3dsp . h_loop_filter ( plane_data + 8 * x , stride , bounding_values ) ;
 }
 if ( y > 0 ) {
 s -> vp3dsp . v_loop_filter ( plane_data + 8 * x , stride , bounding_values ) ;
 }
 if ( ( x < width - 1 ) && ( s -> all_fragments [ fragment + 1 ] . coding_method == MODE_COPY ) ) {
 s -> vp3dsp . h_loop_filter ( plane_data + 8 * x + 8 , stride , bounding_values ) ;
 }
 if ( ( y < height - 1 ) && ( s -> all_fragments [ fragment + width ] . coding_method == MODE_COPY ) ) {
 s -> vp3dsp . v_loop_filter ( plane_data + 8 * x + 8 * stride , stride , bounding_values ) ;
 }
 }
 fragment ++ ;
 }
 plane_data += 8 * stride ;
 }
 }
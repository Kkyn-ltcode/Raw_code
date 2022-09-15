int vp8_calc_ss_err ( YV12_BUFFER_CONFIG * source , YV12_BUFFER_CONFIG * dest ) {
 int i , j ;
 int Total = 0 ;
 unsigned char * src = source -> y_buffer ;
 unsigned char * dst = dest -> y_buffer ;
 for ( i = 0 ;
 i < source -> y_height ;
 i += 16 ) {
 for ( j = 0 ;
 j < source -> y_width ;
 j += 16 ) {
 unsigned int sse ;
 Total += vp8_mse16x16 ( src + j , source -> y_stride , dst + j , dest -> y_stride , & sse ) ;
 }
 src += 16 * source -> y_stride ;
 dst += 16 * dest -> y_stride ;
 }
 return Total ;
 }
static void libopenjpeg_copyto8 ( AVFrame * picture , opj_image_t * image ) {
 int * comp_data ;
 uint8_t * img_ptr ;
 int index , x , y ;
 for ( index = 0 ;
 index < image -> numcomps ;
 index ++ ) {
 comp_data = image -> comps [ index ] . data ;
 for ( y = 0 ;
 y < image -> comps [ index ] . h ;
 y ++ ) {
 img_ptr = picture -> data [ index ] + y * picture -> linesize [ index ] ;
 for ( x = 0 ;
 x < image -> comps [ index ] . w ;
 x ++ ) {
 * img_ptr = ( uint8_t ) * comp_data ;
 img_ptr ++ ;
 comp_data ++ ;
 }
 }
 }
 }
static void write_image_file ( const vpx_image_t * img , const int planes [ 3 ] , FILE * file ) {
 int i , y ;
 # if CONFIG_VP9 && CONFIG_VP9_HIGHBITDEPTH const int bytes_per_sample = ( ( img -> fmt & VPX_IMG_FMT_HIGHBITDEPTH ) ? 2 : 1 ) ;
 # else const int bytes_per_sample = 1 ;
 # endif for ( i = 0 ;
 i < 3 ;
 ++ i ) {
 const int plane = planes [ i ] ;
 const unsigned char * buf = img -> planes [ plane ] ;
 const int stride = img -> stride [ plane ] ;
 const int w = vpx_img_plane_width ( img , plane ) ;
 const int h = vpx_img_plane_height ( img , plane ) ;
 for ( y = 0 ;
 y < h ;
 ++ y ) {
 fwrite ( buf , bytes_per_sample , w , file ) ;
 buf += stride ;
 }
 }
 }
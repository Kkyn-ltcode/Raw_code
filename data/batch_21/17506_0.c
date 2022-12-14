unsigned int vp9_sad ## m ## x ## n ## _c ( const uint8_t * src , int src_stride , const uint8_t * ref , int ref_stride ) {
 return sad ( src , src_stride , ref , ref_stride , m , n ) ;
 \ }
 unsigned int vp9_sad ## m ## x ## n ## _avg_c ( const uint8_t * src , int src_stride , const uint8_t * ref , int ref_stride , const uint8_t * second_pred ) {
 uint8_t comp_pred [ m * n ] ;
 vp9_comp_avg_pred ( comp_pred , second_pred , m , n , ref , ref_stride ) ;
 return sad ( src , src_stride , comp_pred , m , m , n ) ;
 \ }
 # define sadMxNxK ( m , n , k ) void vp9_sad ## m ## x ## n ## x ## k ## _c ( const uint8_t * src , int src_stride , const uint8_t * ref , int ref_stride , unsigned int * sads ) {
 int i ;
 for ( i = 0 ;
 i < k ;
 ++ i ) sads [ i ] = vp9_sad ## m ## x ## n ## _c ( src , src_stride , & ref [ i ] , ref_stride ) ;
 \ }
 # define sadMxNx4D ( m , n ) void vp9_sad ## m ## x ## n ## x4d_c ( const uint8_t * src , int src_stride , const uint8_t * const refs [ ] , int ref_stride , unsigned int * sads ) {
 int i ;
 for ( i = 0 ;
 i < 4 ;
 ++ i ) sads [ i ] = vp9_sad ## m ## x ## n ## _c ( src , src_stride , refs [ i ] , ref_stride ) ;
 \ }
 sadMxN ( 64 , 64 )
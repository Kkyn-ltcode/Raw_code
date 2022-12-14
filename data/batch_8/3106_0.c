static int loco_decode_plane ( LOCOContext * l , uint8_t * data , int width , int height , int stride , const uint8_t * buf , int buf_size , int step ) {
 RICEContext rc ;
 int val ;
 int i , j ;
 init_get_bits ( & rc . gb , buf , buf_size * 8 ) ;
 rc . save = 0 ;
 rc . run = 0 ;
 rc . run2 = 0 ;
 rc . lossy = l -> lossy ;
 rc . sum = 8 ;
 rc . count = 1 ;
 val = loco_get_rice ( & rc ) ;
 data [ 0 ] = 128 + val ;
 for ( i = 1 ;
 i < width ;
 i ++ ) {
 val = loco_get_rice ( & rc ) ;
 data [ i * step ] = data [ i * step - step ] + val ;
 }
 data += stride ;
 for ( j = 1 ;
 j < height ;
 j ++ ) {
 val = loco_get_rice ( & rc ) ;
 data [ 0 ] = data [ - stride ] + val ;
 for ( i = 1 ;
 i < width ;
 i ++ ) {
 val = loco_get_rice ( & rc ) ;
 data [ i * step ] = loco_predict ( & data [ i * step ] , stride , step ) + val ;
 }
 data += stride ;
 }
 return ( get_bits_count ( & rc . gb ) + 7 ) >> 3 ;
 }
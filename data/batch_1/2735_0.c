static inline int decode_mb ( ASV1Context * a , int16_t block [ 6 ] [ 64 ] ) {
 int i ;
 a -> dsp . clear_blocks ( block [ 0 ] ) ;
 if ( a -> avctx -> codec_id == AV_CODEC_ID_ASV1 ) {
 for ( i = 0 ;
 i < 6 ;
 i ++ ) {
 if ( asv1_decode_block ( a , block [ i ] ) < 0 ) return - 1 ;
 }
 }
 else {
 for ( i = 0 ;
 i < 6 ;
 i ++ ) {
 if ( asv2_decode_block ( a , block [ i ] ) < 0 ) return - 1 ;
 }
 }
 return 0 ;
 }
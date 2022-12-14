static void tgq_idct_put_mb_dconly ( TgqContext * s , AVFrame * frame , int mb_x , int mb_y , const int8_t * dc ) {
 int linesize = frame -> linesize [ 0 ] ;
 uint8_t * dest_y = frame -> data [ 0 ] + ( mb_y * 16 * linesize ) + mb_x * 16 ;
 uint8_t * dest_cb = frame -> data [ 1 ] + ( mb_y * 8 * frame -> linesize [ 1 ] ) + mb_x * 8 ;
 uint8_t * dest_cr = frame -> data [ 2 ] + ( mb_y * 8 * frame -> linesize [ 2 ] ) + mb_x * 8 ;
 tgq_dconly ( s , dest_y , linesize , dc [ 0 ] ) ;
 tgq_dconly ( s , dest_y + 8 , linesize , dc [ 1 ] ) ;
 tgq_dconly ( s , dest_y + 8 * linesize , linesize , dc [ 2 ] ) ;
 tgq_dconly ( s , dest_y + 8 * linesize + 8 , linesize , dc [ 3 ] ) ;
 if ( ! ( s -> avctx -> flags & CODEC_FLAG_GRAY ) ) {
 tgq_dconly ( s , dest_cb , frame -> linesize [ 1 ] , dc [ 4 ] ) ;
 tgq_dconly ( s , dest_cr , frame -> linesize [ 2 ] , dc [ 5 ] ) ;
 }
 }
void vp8_sixtap_predict8x8_neon ( unsigned char * src_ptr , int src_pixels_per_line , int xoffset , int yoffset , unsigned char * dst_ptr , int dst_pitch ) {
 unsigned char * src , * tmpp ;
 unsigned char tmp [ 64 ] ;
 int i ;
 uint8x8_t d0u8 , d1u8 , d2u8 , d3u8 , d4u8 , d5u8 , d6u8 , d7u8 , d8u8 , d9u8 ;
 uint8x8_t d18u8 , d19u8 , d20u8 , d21u8 , d22u8 , d23u8 , d24u8 , d25u8 ;
 uint8x8_t d26u8 , d27u8 , d28u8 , d29u8 , d30u8 , d31u8 ;
 int8x8_t dtmps8 , d0s8 , d1s8 , d2s8 , d3s8 , d4s8 , d5s8 ;
 uint16x8_t q3u16 , q4u16 , q5u16 , q6u16 , q7u16 ;
 uint16x8_t q8u16 , q9u16 , q10u16 , q11u16 , q12u16 ;
 int16x8_t q3s16 , q4s16 , q5s16 , q6s16 , q7s16 ;
 int16x8_t q8s16 , q9s16 , q10s16 , q11s16 , q12s16 ;
 uint8x16_t q3u8 , q4u8 , q5u8 , q6u8 , q7u8 , q9u8 , q10u8 , q11u8 , q12u8 ;
 if ( xoffset == 0 ) {
 dtmps8 = vld1_s8 ( vp8_sub_pel_filters [ yoffset ] ) ;
 d0s8 = vdup_lane_s8 ( dtmps8 , 0 ) ;
 d1s8 = vdup_lane_s8 ( dtmps8 , 1 ) ;
 d2s8 = vdup_lane_s8 ( dtmps8 , 2 ) ;
 d3s8 = vdup_lane_s8 ( dtmps8 , 3 ) ;
 d4s8 = vdup_lane_s8 ( dtmps8 , 4 ) ;
 d5s8 = vdup_lane_s8 ( dtmps8 , 5 ) ;
 d0u8 = vreinterpret_u8_s8 ( vabs_s8 ( d0s8 ) ) ;
 d1u8 = vreinterpret_u8_s8 ( vabs_s8 ( d1s8 ) ) ;
 d2u8 = vreinterpret_u8_s8 ( vabs_s8 ( d2s8 ) ) ;
 d3u8 = vreinterpret_u8_s8 ( vabs_s8 ( d3s8 ) ) ;
 d4u8 = vreinterpret_u8_s8 ( vabs_s8 ( d4s8 ) ) ;
 d5u8 = vreinterpret_u8_s8 ( vabs_s8 ( d5s8 ) ) ;
 src = src_ptr - src_pixels_per_line * 2 ;
 d18u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d19u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d20u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d21u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d22u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d23u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d24u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d25u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d26u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d27u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d28u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d29u8 = vld1_u8 ( src ) ;
 src += src_pixels_per_line ;
 d30u8 = vld1_u8 ( src ) ;
 for ( i = 2 ;
 i > 0 ;
 i -- ) {
 q3u16 = vmull_u8 ( d18u8 , d0u8 ) ;
 q4u16 = vmull_u8 ( d19u8 , d0u8 ) ;
 q5u16 = vmull_u8 ( d20u8 , d0u8 ) ;
 q6u16 = vmull_u8 ( d21u8 , d0u8 ) ;
 q3u16 = vmlsl_u8 ( q3u16 , d19u8 , d1u8 ) ;
 q4u16 = vmlsl_u8 ( q4u16 , d20u8 , d1u8 ) ;
 q5u16 = vmlsl_u8 ( q5u16 , d21u8 , d1u8 ) ;
 q6u16 = vmlsl_u8 ( q6u16 , d22u8 , d1u8 ) ;
 q3u16 = vmlsl_u8 ( q3u16 , d22u8 , d4u8 ) ;
 q4u16 = vmlsl_u8 ( q4u16 , d23u8 , d4u8 ) ;
 q5u16 = vmlsl_u8 ( q5u16 , d24u8 , d4u8 ) ;
 q6u16 = vmlsl_u8 ( q6u16 , d25u8 , d4u8 ) ;
 q3u16 = vmlal_u8 ( q3u16 , d20u8 , d2u8 ) ;
 q4u16 = vmlal_u8 ( q4u16 , d21u8 , d2u8 ) ;
 q5u16 = vmlal_u8 ( q5u16 , d22u8 , d2u8 ) ;
 q6u16 = vmlal_u8 ( q6u16 , d23u8 , d2u8 ) ;
 q3u16 = vmlal_u8 ( q3u16 , d23u8 , d5u8 ) ;
 q4u16 = vmlal_u8 ( q4u16 , d24u8 , d5u8 ) ;
 q5u16 = vmlal_u8 ( q5u16 , d25u8 , d5u8 ) ;
 q6u16 = vmlal_u8 ( q6u16 , d26u8 , d5u8 ) ;
 q7u16 = vmull_u8 ( d21u8 , d3u8 ) ;
 q8u16 = vmull_u8 ( d22u8 , d3u8 ) ;
 q9u16 = vmull_u8 ( d23u8 , d3u8 ) ;
 q10u16 = vmull_u8 ( d24u8 , d3u8 ) ;
 q3s16 = vreinterpretq_s16_u16 ( q3u16 ) ;
 q4s16 = vreinterpretq_s16_u16 ( q4u16 ) ;
 q5s16 = vreinterpretq_s16_u16 ( q5u16 ) ;
 q6s16 = vreinterpretq_s16_u16 ( q6u16 ) ;
 q7s16 = vreinterpretq_s16_u16 ( q7u16 ) ;
 q8s16 = vreinterpretq_s16_u16 ( q8u16 ) ;
 q9s16 = vreinterpretq_s16_u16 ( q9u16 ) ;
 q10s16 = vreinterpretq_s16_u16 ( q10u16 ) ;
 q7s16 = vqaddq_s16 ( q7s16 , q3s16 ) ;
 q8s16 = vqaddq_s16 ( q8s16 , q4s16 ) ;
 q9s16 = vqaddq_s16 ( q9s16 , q5s16 ) ;
 q10s16 = vqaddq_s16 ( q10s16 , q6s16 ) ;
 d6u8 = vqrshrun_n_s16 ( q7s16 , 7 ) ;
 d7u8 = vqrshrun_n_s16 ( q8s16 , 7 ) ;
 d8u8 = vqrshrun_n_s16 ( q9s16 , 7 ) ;
 d9u8 = vqrshrun_n_s16 ( q10s16 , 7 ) ;
 d18u8 = d22u8 ;
 d19u8 = d23u8 ;
 d20u8 = d24u8 ;
 d21u8 = d25u8 ;
 d22u8 = d26u8 ;
 d23u8 = d27u8 ;
 d24u8 = d28u8 ;
 d25u8 = d29u8 ;
 d26u8 = d30u8 ;
 vst1_u8 ( dst_ptr , d6u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d7u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d8u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d9u8 ) ;
 dst_ptr += dst_pitch ;
 }
 return ;
 }
 dtmps8 = vld1_s8 ( vp8_sub_pel_filters [ xoffset ] ) ;
 d0s8 = vdup_lane_s8 ( dtmps8 , 0 ) ;
 d1s8 = vdup_lane_s8 ( dtmps8 , 1 ) ;
 d2s8 = vdup_lane_s8 ( dtmps8 , 2 ) ;
 d3s8 = vdup_lane_s8 ( dtmps8 , 3 ) ;
 d4s8 = vdup_lane_s8 ( dtmps8 , 4 ) ;
 d5s8 = vdup_lane_s8 ( dtmps8 , 5 ) ;
 d0u8 = vreinterpret_u8_s8 ( vabs_s8 ( d0s8 ) ) ;
 d1u8 = vreinterpret_u8_s8 ( vabs_s8 ( d1s8 ) ) ;
 d2u8 = vreinterpret_u8_s8 ( vabs_s8 ( d2s8 ) ) ;
 d3u8 = vreinterpret_u8_s8 ( vabs_s8 ( d3s8 ) ) ;
 d4u8 = vreinterpret_u8_s8 ( vabs_s8 ( d4s8 ) ) ;
 d5u8 = vreinterpret_u8_s8 ( vabs_s8 ( d5s8 ) ) ;
 if ( yoffset == 0 ) src = src_ptr - 2 ;
 else src = src_ptr - 2 - ( src_pixels_per_line * 2 ) ;
 tmpp = tmp ;
 for ( i = 2 ;
 i > 0 ;
 i -- ) {
 q3u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q4u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q5u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q6u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 __builtin_prefetch ( src ) ;
 __builtin_prefetch ( src + src_pixels_per_line ) ;
 __builtin_prefetch ( src + src_pixels_per_line * 2 ) ;
 q7u16 = vmull_u8 ( vget_low_u8 ( q3u8 ) , d0u8 ) ;
 q8u16 = vmull_u8 ( vget_low_u8 ( q4u8 ) , d0u8 ) ;
 q9u16 = vmull_u8 ( vget_low_u8 ( q5u8 ) , d0u8 ) ;
 q10u16 = vmull_u8 ( vget_low_u8 ( q6u8 ) , d0u8 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 1 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 1 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 1 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 1 ) ;
 q7u16 = vmlsl_u8 ( q7u16 , d28u8 , d1u8 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , d29u8 , d1u8 ) ;
 q9u16 = vmlsl_u8 ( q9u16 , d30u8 , d1u8 ) ;
 q10u16 = vmlsl_u8 ( q10u16 , d31u8 , d1u8 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 4 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 4 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 4 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 4 ) ;
 q7u16 = vmlsl_u8 ( q7u16 , d28u8 , d4u8 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , d29u8 , d4u8 ) ;
 q9u16 = vmlsl_u8 ( q9u16 , d30u8 , d4u8 ) ;
 q10u16 = vmlsl_u8 ( q10u16 , d31u8 , d4u8 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 2 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 2 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 2 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 2 ) ;
 q7u16 = vmlal_u8 ( q7u16 , d28u8 , d2u8 ) ;
 q8u16 = vmlal_u8 ( q8u16 , d29u8 , d2u8 ) ;
 q9u16 = vmlal_u8 ( q9u16 , d30u8 , d2u8 ) ;
 q10u16 = vmlal_u8 ( q10u16 , d31u8 , d2u8 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 5 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 5 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 5 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 5 ) ;
 q7u16 = vmlal_u8 ( q7u16 , d28u8 , d5u8 ) ;
 q8u16 = vmlal_u8 ( q8u16 , d29u8 , d5u8 ) ;
 q9u16 = vmlal_u8 ( q9u16 , d30u8 , d5u8 ) ;
 q10u16 = vmlal_u8 ( q10u16 , d31u8 , d5u8 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 3 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 3 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 3 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 3 ) ;
 q3u16 = vmull_u8 ( d28u8 , d3u8 ) ;
 q4u16 = vmull_u8 ( d29u8 , d3u8 ) ;
 q5u16 = vmull_u8 ( d30u8 , d3u8 ) ;
 q6u16 = vmull_u8 ( d31u8 , d3u8 ) ;
 q3s16 = vreinterpretq_s16_u16 ( q3u16 ) ;
 q4s16 = vreinterpretq_s16_u16 ( q4u16 ) ;
 q5s16 = vreinterpretq_s16_u16 ( q5u16 ) ;
 q6s16 = vreinterpretq_s16_u16 ( q6u16 ) ;
 q7s16 = vreinterpretq_s16_u16 ( q7u16 ) ;
 q8s16 = vreinterpretq_s16_u16 ( q8u16 ) ;
 q9s16 = vreinterpretq_s16_u16 ( q9u16 ) ;
 q10s16 = vreinterpretq_s16_u16 ( q10u16 ) ;
 q7s16 = vqaddq_s16 ( q7s16 , q3s16 ) ;
 q8s16 = vqaddq_s16 ( q8s16 , q4s16 ) ;
 q9s16 = vqaddq_s16 ( q9s16 , q5s16 ) ;
 q10s16 = vqaddq_s16 ( q10s16 , q6s16 ) ;
 d22u8 = vqrshrun_n_s16 ( q7s16 , 7 ) ;
 d23u8 = vqrshrun_n_s16 ( q8s16 , 7 ) ;
 d24u8 = vqrshrun_n_s16 ( q9s16 , 7 ) ;
 d25u8 = vqrshrun_n_s16 ( q10s16 , 7 ) ;
 if ( yoffset == 0 ) {
 vst1_u8 ( dst_ptr , d22u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d23u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d24u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d25u8 ) ;
 dst_ptr += dst_pitch ;
 }
 else {
 vst1_u8 ( tmpp , d22u8 ) ;
 tmpp += 8 ;
 vst1_u8 ( tmpp , d23u8 ) ;
 tmpp += 8 ;
 vst1_u8 ( tmpp , d24u8 ) ;
 tmpp += 8 ;
 vst1_u8 ( tmpp , d25u8 ) ;
 tmpp += 8 ;
 }
 }
 if ( yoffset == 0 ) return ;
 q3u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q4u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q5u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q6u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q7u8 = vld1q_u8 ( src ) ;
 q8u16 = vmull_u8 ( vget_low_u8 ( q3u8 ) , d0u8 ) ;
 q9u16 = vmull_u8 ( vget_low_u8 ( q4u8 ) , d0u8 ) ;
 q10u16 = vmull_u8 ( vget_low_u8 ( q5u8 ) , d0u8 ) ;
 q11u16 = vmull_u8 ( vget_low_u8 ( q6u8 ) , d0u8 ) ;
 q12u16 = vmull_u8 ( vget_low_u8 ( q7u8 ) , d0u8 ) ;
 d27u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 1 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 1 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 1 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 1 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q7u8 ) , vget_high_u8 ( q7u8 ) , 1 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , d27u8 , d1u8 ) ;
 q9u16 = vmlsl_u8 ( q9u16 , d28u8 , d1u8 ) ;
 q10u16 = vmlsl_u8 ( q10u16 , d29u8 , d1u8 ) ;
 q11u16 = vmlsl_u8 ( q11u16 , d30u8 , d1u8 ) ;
 q12u16 = vmlsl_u8 ( q12u16 , d31u8 , d1u8 ) ;
 d27u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 4 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 4 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 4 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 4 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q7u8 ) , vget_high_u8 ( q7u8 ) , 4 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , d27u8 , d4u8 ) ;
 q9u16 = vmlsl_u8 ( q9u16 , d28u8 , d4u8 ) ;
 q10u16 = vmlsl_u8 ( q10u16 , d29u8 , d4u8 ) ;
 q11u16 = vmlsl_u8 ( q11u16 , d30u8 , d4u8 ) ;
 q12u16 = vmlsl_u8 ( q12u16 , d31u8 , d4u8 ) ;
 d27u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 2 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 2 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 2 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 2 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q7u8 ) , vget_high_u8 ( q7u8 ) , 2 ) ;
 q8u16 = vmlal_u8 ( q8u16 , d27u8 , d2u8 ) ;
 q9u16 = vmlal_u8 ( q9u16 , d28u8 , d2u8 ) ;
 q10u16 = vmlal_u8 ( q10u16 , d29u8 , d2u8 ) ;
 q11u16 = vmlal_u8 ( q11u16 , d30u8 , d2u8 ) ;
 q12u16 = vmlal_u8 ( q12u16 , d31u8 , d2u8 ) ;
 d27u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 5 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 5 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 5 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 5 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q7u8 ) , vget_high_u8 ( q7u8 ) , 5 ) ;
 q8u16 = vmlal_u8 ( q8u16 , d27u8 , d5u8 ) ;
 q9u16 = vmlal_u8 ( q9u16 , d28u8 , d5u8 ) ;
 q10u16 = vmlal_u8 ( q10u16 , d29u8 , d5u8 ) ;
 q11u16 = vmlal_u8 ( q11u16 , d30u8 , d5u8 ) ;
 q12u16 = vmlal_u8 ( q12u16 , d31u8 , d5u8 ) ;
 d27u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 3 ) ;
 d28u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 3 ) ;
 d29u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 3 ) ;
 d30u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 3 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q7u8 ) , vget_high_u8 ( q7u8 ) , 3 ) ;
 q3u16 = vmull_u8 ( d27u8 , d3u8 ) ;
 q4u16 = vmull_u8 ( d28u8 , d3u8 ) ;
 q5u16 = vmull_u8 ( d29u8 , d3u8 ) ;
 q6u16 = vmull_u8 ( d30u8 , d3u8 ) ;
 q7u16 = vmull_u8 ( d31u8 , d3u8 ) ;
 q3s16 = vreinterpretq_s16_u16 ( q3u16 ) ;
 q4s16 = vreinterpretq_s16_u16 ( q4u16 ) ;
 q5s16 = vreinterpretq_s16_u16 ( q5u16 ) ;
 q6s16 = vreinterpretq_s16_u16 ( q6u16 ) ;
 q7s16 = vreinterpretq_s16_u16 ( q7u16 ) ;
 q8s16 = vreinterpretq_s16_u16 ( q8u16 ) ;
 q9s16 = vreinterpretq_s16_u16 ( q9u16 ) ;
 q10s16 = vreinterpretq_s16_u16 ( q10u16 ) ;
 q11s16 = vreinterpretq_s16_u16 ( q11u16 ) ;
 q12s16 = vreinterpretq_s16_u16 ( q12u16 ) ;
 q8s16 = vqaddq_s16 ( q8s16 , q3s16 ) ;
 q9s16 = vqaddq_s16 ( q9s16 , q4s16 ) ;
 q10s16 = vqaddq_s16 ( q10s16 , q5s16 ) ;
 q11s16 = vqaddq_s16 ( q11s16 , q6s16 ) ;
 q12s16 = vqaddq_s16 ( q12s16 , q7s16 ) ;
 d26u8 = vqrshrun_n_s16 ( q8s16 , 7 ) ;
 d27u8 = vqrshrun_n_s16 ( q9s16 , 7 ) ;
 d28u8 = vqrshrun_n_s16 ( q10s16 , 7 ) ;
 d29u8 = vqrshrun_n_s16 ( q11s16 , 7 ) ;
 d30u8 = vqrshrun_n_s16 ( q12s16 , 7 ) ;
 dtmps8 = vld1_s8 ( vp8_sub_pel_filters [ yoffset ] ) ;
 d0s8 = vdup_lane_s8 ( dtmps8 , 0 ) ;
 d1s8 = vdup_lane_s8 ( dtmps8 , 1 ) ;
 d2s8 = vdup_lane_s8 ( dtmps8 , 2 ) ;
 d3s8 = vdup_lane_s8 ( dtmps8 , 3 ) ;
 d4s8 = vdup_lane_s8 ( dtmps8 , 4 ) ;
 d5s8 = vdup_lane_s8 ( dtmps8 , 5 ) ;
 d0u8 = vreinterpret_u8_s8 ( vabs_s8 ( d0s8 ) ) ;
 d1u8 = vreinterpret_u8_s8 ( vabs_s8 ( d1s8 ) ) ;
 d2u8 = vreinterpret_u8_s8 ( vabs_s8 ( d2s8 ) ) ;
 d3u8 = vreinterpret_u8_s8 ( vabs_s8 ( d3s8 ) ) ;
 d4u8 = vreinterpret_u8_s8 ( vabs_s8 ( d4s8 ) ) ;
 d5u8 = vreinterpret_u8_s8 ( vabs_s8 ( d5s8 ) ) ;
 tmpp = tmp ;
 q9u8 = vld1q_u8 ( tmpp ) ;
 tmpp += 16 ;
 q10u8 = vld1q_u8 ( tmpp ) ;
 tmpp += 16 ;
 q11u8 = vld1q_u8 ( tmpp ) ;
 tmpp += 16 ;
 q12u8 = vld1q_u8 ( tmpp ) ;
 d18u8 = vget_low_u8 ( q9u8 ) ;
 d19u8 = vget_high_u8 ( q9u8 ) ;
 d20u8 = vget_low_u8 ( q10u8 ) ;
 d21u8 = vget_high_u8 ( q10u8 ) ;
 d22u8 = vget_low_u8 ( q11u8 ) ;
 d23u8 = vget_high_u8 ( q11u8 ) ;
 d24u8 = vget_low_u8 ( q12u8 ) ;
 d25u8 = vget_high_u8 ( q12u8 ) ;
 for ( i = 2 ;
 i > 0 ;
 i -- ) {
 q3u16 = vmull_u8 ( d18u8 , d0u8 ) ;
 q4u16 = vmull_u8 ( d19u8 , d0u8 ) ;
 q5u16 = vmull_u8 ( d20u8 , d0u8 ) ;
 q6u16 = vmull_u8 ( d21u8 , d0u8 ) ;
 q3u16 = vmlsl_u8 ( q3u16 , d19u8 , d1u8 ) ;
 q4u16 = vmlsl_u8 ( q4u16 , d20u8 , d1u8 ) ;
 q5u16 = vmlsl_u8 ( q5u16 , d21u8 , d1u8 ) ;
 q6u16 = vmlsl_u8 ( q6u16 , d22u8 , d1u8 ) ;
 q3u16 = vmlsl_u8 ( q3u16 , d22u8 , d4u8 ) ;
 q4u16 = vmlsl_u8 ( q4u16 , d23u8 , d4u8 ) ;
 q5u16 = vmlsl_u8 ( q5u16 , d24u8 , d4u8 ) ;
 q6u16 = vmlsl_u8 ( q6u16 , d25u8 , d4u8 ) ;
 q3u16 = vmlal_u8 ( q3u16 , d20u8 , d2u8 ) ;
 q4u16 = vmlal_u8 ( q4u16 , d21u8 , d2u8 ) ;
 q5u16 = vmlal_u8 ( q5u16 , d22u8 , d2u8 ) ;
 q6u16 = vmlal_u8 ( q6u16 , d23u8 , d2u8 ) ;
 q3u16 = vmlal_u8 ( q3u16 , d23u8 , d5u8 ) ;
 q4u16 = vmlal_u8 ( q4u16 , d24u8 , d5u8 ) ;
 q5u16 = vmlal_u8 ( q5u16 , d25u8 , d5u8 ) ;
 q6u16 = vmlal_u8 ( q6u16 , d26u8 , d5u8 ) ;
 q7u16 = vmull_u8 ( d21u8 , d3u8 ) ;
 q8u16 = vmull_u8 ( d22u8 , d3u8 ) ;
 q9u16 = vmull_u8 ( d23u8 , d3u8 ) ;
 q10u16 = vmull_u8 ( d24u8 , d3u8 ) ;
 q3s16 = vreinterpretq_s16_u16 ( q3u16 ) ;
 q4s16 = vreinterpretq_s16_u16 ( q4u16 ) ;
 q5s16 = vreinterpretq_s16_u16 ( q5u16 ) ;
 q6s16 = vreinterpretq_s16_u16 ( q6u16 ) ;
 q7s16 = vreinterpretq_s16_u16 ( q7u16 ) ;
 q8s16 = vreinterpretq_s16_u16 ( q8u16 ) ;
 q9s16 = vreinterpretq_s16_u16 ( q9u16 ) ;
 q10s16 = vreinterpretq_s16_u16 ( q10u16 ) ;
 q7s16 = vqaddq_s16 ( q7s16 , q3s16 ) ;
 q8s16 = vqaddq_s16 ( q8s16 , q4s16 ) ;
 q9s16 = vqaddq_s16 ( q9s16 , q5s16 ) ;
 q10s16 = vqaddq_s16 ( q10s16 , q6s16 ) ;
 d6u8 = vqrshrun_n_s16 ( q7s16 , 7 ) ;
 d7u8 = vqrshrun_n_s16 ( q8s16 , 7 ) ;
 d8u8 = vqrshrun_n_s16 ( q9s16 , 7 ) ;
 d9u8 = vqrshrun_n_s16 ( q10s16 , 7 ) ;
 d18u8 = d22u8 ;
 d19u8 = d23u8 ;
 d20u8 = d24u8 ;
 d21u8 = d25u8 ;
 d22u8 = d26u8 ;
 d23u8 = d27u8 ;
 d24u8 = d28u8 ;
 d25u8 = d29u8 ;
 d26u8 = d30u8 ;
 vst1_u8 ( dst_ptr , d6u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d7u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d8u8 ) ;
 dst_ptr += dst_pitch ;
 vst1_u8 ( dst_ptr , d9u8 ) ;
 dst_ptr += dst_pitch ;
 }
 return ;
 }
void vp8_sixtap_predict4x4_neon ( unsigned char * src_ptr , int src_pixels_per_line , int xoffset , int yoffset , unsigned char * dst_ptr , int dst_pitch ) {
 unsigned char * src ;
 uint8x8_t d0u8 , d1u8 , d2u8 , d3u8 , d4u8 , d5u8 , d18u8 , d19u8 , d20u8 , d21u8 ;
 uint8x8_t d23u8 , d24u8 , d25u8 , d26u8 , d27u8 , d28u8 , d29u8 , d30u8 , d31u8 ;
 int8x8_t dtmps8 , d0s8 , d1s8 , d2s8 , d3s8 , d4s8 , d5s8 ;
 uint16x8_t q3u16 , q4u16 , q5u16 , q6u16 , q7u16 ;
 uint16x8_t q8u16 , q9u16 , q10u16 , q11u16 , q12u16 ;
 int16x8_t q3s16 , q4s16 , q5s16 , q6s16 , q7s16 ;
 int16x8_t q8s16 , q9s16 , q10s16 , q11s16 , q12s16 ;
 uint8x16_t q3u8 , q4u8 , q5u8 , q6u8 , q11u8 ;
 uint64x2_t q3u64 , q4u64 , q5u64 , q6u64 , q9u64 , q10u64 ;
 uint32x2x2_t d0u32x2 , d1u32x2 ;
 if ( xoffset == 0 ) {
 uint32x2_t d27u32 = vdup_n_u32 ( 0 ) ;
 uint32x2_t d28u32 = vdup_n_u32 ( 0 ) ;
 uint32x2_t d29u32 = vdup_n_u32 ( 0 ) ;
 uint32x2_t d30u32 = vdup_n_u32 ( 0 ) ;
 uint32x2_t d31u32 = vdup_n_u32 ( 0 ) ;
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
 d27u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d27u32 , 0 ) ;
 src += src_pixels_per_line ;
 d27u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d27u32 , 1 ) ;
 src += src_pixels_per_line ;
 d28u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d28u32 , 0 ) ;
 src += src_pixels_per_line ;
 d28u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d28u32 , 1 ) ;
 src += src_pixels_per_line ;
 d29u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d29u32 , 0 ) ;
 src += src_pixels_per_line ;
 d29u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d29u32 , 1 ) ;
 src += src_pixels_per_line ;
 d30u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d30u32 , 0 ) ;
 src += src_pixels_per_line ;
 d30u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d30u32 , 1 ) ;
 src += src_pixels_per_line ;
 d31u32 = vld1_lane_u32 ( ( const uint32_t * ) src , d31u32 , 0 ) ;
 d27u8 = vreinterpret_u8_u32 ( d27u32 ) ;
 d28u8 = vreinterpret_u8_u32 ( d28u32 ) ;
 d29u8 = vreinterpret_u8_u32 ( d29u32 ) ;
 d30u8 = vreinterpret_u8_u32 ( d30u32 ) ;
 d31u8 = vreinterpret_u8_u32 ( d31u32 ) ;
 d23u8 = vext_u8 ( d27u8 , d28u8 , 4 ) ;
 d24u8 = vext_u8 ( d28u8 , d29u8 , 4 ) ;
 d25u8 = vext_u8 ( d29u8 , d30u8 , 4 ) ;
 d26u8 = vext_u8 ( d30u8 , d31u8 , 4 ) ;
 q3u16 = vmull_u8 ( d27u8 , d0u8 ) ;
 q4u16 = vmull_u8 ( d28u8 , d0u8 ) ;
 q5u16 = vmull_u8 ( d25u8 , d5u8 ) ;
 q6u16 = vmull_u8 ( d26u8 , d5u8 ) ;
 q3u16 = vmlsl_u8 ( q3u16 , d29u8 , d4u8 ) ;
 q4u16 = vmlsl_u8 ( q4u16 , d30u8 , d4u8 ) ;
 q5u16 = vmlsl_u8 ( q5u16 , d23u8 , d1u8 ) ;
 q6u16 = vmlsl_u8 ( q6u16 , d24u8 , d1u8 ) ;
 q3u16 = vmlal_u8 ( q3u16 , d28u8 , d2u8 ) ;
 q4u16 = vmlal_u8 ( q4u16 , d29u8 , d2u8 ) ;
 q5u16 = vmlal_u8 ( q5u16 , d24u8 , d3u8 ) ;
 q6u16 = vmlal_u8 ( q6u16 , d25u8 , d3u8 ) ;
 q3s16 = vreinterpretq_s16_u16 ( q3u16 ) ;
 q4s16 = vreinterpretq_s16_u16 ( q4u16 ) ;
 q5s16 = vreinterpretq_s16_u16 ( q5u16 ) ;
 q6s16 = vreinterpretq_s16_u16 ( q6u16 ) ;
 q5s16 = vqaddq_s16 ( q5s16 , q3s16 ) ;
 q6s16 = vqaddq_s16 ( q6s16 , q4s16 ) ;
 d3u8 = vqrshrun_n_s16 ( q5s16 , 7 ) ;
 d4u8 = vqrshrun_n_s16 ( q6s16 , 7 ) ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d3u8 ) , 0 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d3u8 ) , 1 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d4u8 ) , 0 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d4u8 ) , 1 ) ;
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
 q3u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q4u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q5u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q6u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 d18u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 5 ) ;
 d19u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 5 ) ;
 d20u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 5 ) ;
 d21u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 5 ) ;
 q3u8 = vcombine_u8 ( vget_low_u8 ( q3u8 ) , vget_low_u8 ( q4u8 ) ) ;
 q5u8 = vcombine_u8 ( vget_low_u8 ( q5u8 ) , vget_low_u8 ( q6u8 ) ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( d18u8 ) , vreinterpret_u32_u8 ( d19u8 ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( d20u8 ) , vreinterpret_u32_u8 ( d21u8 ) ) ;
 q7u16 = vmull_u8 ( vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d5u8 ) ;
 q8u16 = vmull_u8 ( vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d5u8 ) ;
 q4u64 = vreinterpretq_u64_u8 ( q3u8 ) ;
 q6u64 = vreinterpretq_u64_u8 ( q5u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( vget_low_u8 ( q3u8 ) ) , vreinterpret_u32_u8 ( vget_high_u8 ( q3u8 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( vget_low_u8 ( q5u8 ) ) , vreinterpret_u32_u8 ( vget_high_u8 ( q5u8 ) ) ) ;
 q9u64 = vshrq_n_u64 ( q4u64 , 8 ) ;
 q10u64 = vshrq_n_u64 ( q6u64 , 8 ) ;
 q7u16 = vmlal_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d0u8 ) ;
 q8u16 = vmlal_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d0u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q9u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q9u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q10u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q10u64 ) ) ) ;
 q3u64 = vshrq_n_u64 ( q4u64 , 32 ) ;
 q5u64 = vshrq_n_u64 ( q6u64 , 32 ) ;
 q7u16 = vmlsl_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d1u8 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d1u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q3u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q3u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q5u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q5u64 ) ) ) ;
 q9u64 = vshrq_n_u64 ( q4u64 , 16 ) ;
 q10u64 = vshrq_n_u64 ( q6u64 , 16 ) ;
 q7u16 = vmlsl_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d4u8 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d4u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q9u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q9u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q10u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q10u64 ) ) ) ;
 q3u64 = vshrq_n_u64 ( q4u64 , 24 ) ;
 q5u64 = vshrq_n_u64 ( q6u64 , 24 ) ;
 q7u16 = vmlal_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d2u8 ) ;
 q8u16 = vmlal_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d2u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q3u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q3u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q5u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q5u64 ) ) ) ;
 q9u16 = vmull_u8 ( vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d3u8 ) ;
 q10u16 = vmull_u8 ( vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d3u8 ) ;
 q7s16 = vreinterpretq_s16_u16 ( q7u16 ) ;
 q8s16 = vreinterpretq_s16_u16 ( q8u16 ) ;
 q9s16 = vreinterpretq_s16_u16 ( q9u16 ) ;
 q10s16 = vreinterpretq_s16_u16 ( q10u16 ) ;
 q7s16 = vqaddq_s16 ( q7s16 , q9s16 ) ;
 q8s16 = vqaddq_s16 ( q8s16 , q10s16 ) ;
 d27u8 = vqrshrun_n_s16 ( q7s16 , 7 ) ;
 d28u8 = vqrshrun_n_s16 ( q8s16 , 7 ) ;
 if ( yoffset == 0 ) {
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d27u8 ) , 0 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d27u8 ) , 1 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d28u8 ) , 0 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d28u8 ) , 1 ) ;
 return ;
 }
 q3u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q4u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q5u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q6u8 = vld1q_u8 ( src ) ;
 src += src_pixels_per_line ;
 q11u8 = vld1q_u8 ( src ) ;
 d18u8 = vext_u8 ( vget_low_u8 ( q3u8 ) , vget_high_u8 ( q3u8 ) , 5 ) ;
 d19u8 = vext_u8 ( vget_low_u8 ( q4u8 ) , vget_high_u8 ( q4u8 ) , 5 ) ;
 d20u8 = vext_u8 ( vget_low_u8 ( q5u8 ) , vget_high_u8 ( q5u8 ) , 5 ) ;
 d21u8 = vext_u8 ( vget_low_u8 ( q6u8 ) , vget_high_u8 ( q6u8 ) , 5 ) ;
 q3u8 = vcombine_u8 ( vget_low_u8 ( q3u8 ) , vget_low_u8 ( q4u8 ) ) ;
 q5u8 = vcombine_u8 ( vget_low_u8 ( q5u8 ) , vget_low_u8 ( q6u8 ) ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( d18u8 ) , vreinterpret_u32_u8 ( d19u8 ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( d20u8 ) , vreinterpret_u32_u8 ( d21u8 ) ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q11u8 ) , vget_high_u8 ( q11u8 ) , 5 ) ;
 q7u16 = vmull_u8 ( vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d5u8 ) ;
 q8u16 = vmull_u8 ( vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d5u8 ) ;
 q12u16 = vmull_u8 ( d31u8 , d5u8 ) ;
 q4u64 = vreinterpretq_u64_u8 ( q3u8 ) ;
 q6u64 = vreinterpretq_u64_u8 ( q5u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( vget_low_u8 ( q3u8 ) ) , vreinterpret_u32_u8 ( vget_high_u8 ( q3u8 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u8 ( vget_low_u8 ( q5u8 ) ) , vreinterpret_u32_u8 ( vget_high_u8 ( q5u8 ) ) ) ;
 q9u64 = vshrq_n_u64 ( q4u64 , 8 ) ;
 q10u64 = vshrq_n_u64 ( q6u64 , 8 ) ;
 q7u16 = vmlal_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d0u8 ) ;
 q8u16 = vmlal_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d0u8 ) ;
 q12u16 = vmlal_u8 ( q12u16 , vget_low_u8 ( q11u8 ) , d0u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q9u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q9u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q10u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q10u64 ) ) ) ;
 q3u64 = vshrq_n_u64 ( q4u64 , 32 ) ;
 q5u64 = vshrq_n_u64 ( q6u64 , 32 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q11u8 ) , vget_high_u8 ( q11u8 ) , 1 ) ;
 q7u16 = vmlsl_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d1u8 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d1u8 ) ;
 q12u16 = vmlsl_u8 ( q12u16 , d31u8 , d1u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q3u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q3u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q5u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q5u64 ) ) ) ;
 q9u64 = vshrq_n_u64 ( q4u64 , 16 ) ;
 q10u64 = vshrq_n_u64 ( q6u64 , 16 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q11u8 ) , vget_high_u8 ( q11u8 ) , 4 ) ;
 q7u16 = vmlsl_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d4u8 ) ;
 q8u16 = vmlsl_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d4u8 ) ;
 q12u16 = vmlsl_u8 ( q12u16 , d31u8 , d4u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q9u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q9u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q10u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q10u64 ) ) ) ;
 q3u64 = vshrq_n_u64 ( q4u64 , 24 ) ;
 q5u64 = vshrq_n_u64 ( q6u64 , 24 ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q11u8 ) , vget_high_u8 ( q11u8 ) , 2 ) ;
 q7u16 = vmlal_u8 ( q7u16 , vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d2u8 ) ;
 q8u16 = vmlal_u8 ( q8u16 , vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d2u8 ) ;
 q12u16 = vmlal_u8 ( q12u16 , d31u8 , d2u8 ) ;
 d0u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q3u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q3u64 ) ) ) ;
 d1u32x2 = vzip_u32 ( vreinterpret_u32_u64 ( vget_low_u64 ( q5u64 ) ) , vreinterpret_u32_u64 ( vget_high_u64 ( q5u64 ) ) ) ;
 d31u8 = vext_u8 ( vget_low_u8 ( q11u8 ) , vget_high_u8 ( q11u8 ) , 3 ) ;
 q9u16 = vmull_u8 ( vreinterpret_u8_u32 ( d0u32x2 . val [ 0 ] ) , d3u8 ) ;
 q10u16 = vmull_u8 ( vreinterpret_u8_u32 ( d1u32x2 . val [ 0 ] ) , d3u8 ) ;
 q11u16 = vmull_u8 ( d31u8 , d3u8 ) ;
 q7s16 = vreinterpretq_s16_u16 ( q7u16 ) ;
 q8s16 = vreinterpretq_s16_u16 ( q8u16 ) ;
 q9s16 = vreinterpretq_s16_u16 ( q9u16 ) ;
 q10s16 = vreinterpretq_s16_u16 ( q10u16 ) ;
 q11s16 = vreinterpretq_s16_u16 ( q11u16 ) ;
 q12s16 = vreinterpretq_s16_u16 ( q12u16 ) ;
 q7s16 = vqaddq_s16 ( q7s16 , q9s16 ) ;
 q8s16 = vqaddq_s16 ( q8s16 , q10s16 ) ;
 q12s16 = vqaddq_s16 ( q12s16 , q11s16 ) ;
 d29u8 = vqrshrun_n_s16 ( q7s16 , 7 ) ;
 d30u8 = vqrshrun_n_s16 ( q8s16 , 7 ) ;
 d31u8 = vqrshrun_n_s16 ( q12s16 , 7 ) ;
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
 d23u8 = vext_u8 ( d27u8 , d28u8 , 4 ) ;
 d24u8 = vext_u8 ( d28u8 , d29u8 , 4 ) ;
 d25u8 = vext_u8 ( d29u8 , d30u8 , 4 ) ;
 d26u8 = vext_u8 ( d30u8 , d31u8 , 4 ) ;
 q3u16 = vmull_u8 ( d27u8 , d0u8 ) ;
 q4u16 = vmull_u8 ( d28u8 , d0u8 ) ;
 q5u16 = vmull_u8 ( d25u8 , d5u8 ) ;
 q6u16 = vmull_u8 ( d26u8 , d5u8 ) ;
 q3u16 = vmlsl_u8 ( q3u16 , d29u8 , d4u8 ) ;
 q4u16 = vmlsl_u8 ( q4u16 , d30u8 , d4u8 ) ;
 q5u16 = vmlsl_u8 ( q5u16 , d23u8 , d1u8 ) ;
 q6u16 = vmlsl_u8 ( q6u16 , d24u8 , d1u8 ) ;
 q3u16 = vmlal_u8 ( q3u16 , d28u8 , d2u8 ) ;
 q4u16 = vmlal_u8 ( q4u16 , d29u8 , d2u8 ) ;
 q5u16 = vmlal_u8 ( q5u16 , d24u8 , d3u8 ) ;
 q6u16 = vmlal_u8 ( q6u16 , d25u8 , d3u8 ) ;
 q3s16 = vreinterpretq_s16_u16 ( q3u16 ) ;
 q4s16 = vreinterpretq_s16_u16 ( q4u16 ) ;
 q5s16 = vreinterpretq_s16_u16 ( q5u16 ) ;
 q6s16 = vreinterpretq_s16_u16 ( q6u16 ) ;
 q5s16 = vqaddq_s16 ( q5s16 , q3s16 ) ;
 q6s16 = vqaddq_s16 ( q6s16 , q4s16 ) ;
 d3u8 = vqrshrun_n_s16 ( q5s16 , 7 ) ;
 d4u8 = vqrshrun_n_s16 ( q6s16 , 7 ) ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d3u8 ) , 0 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d3u8 ) , 1 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d4u8 ) , 0 ) ;
 dst_ptr += dst_pitch ;
 vst1_lane_u32 ( ( uint32_t * ) dst_ptr , vreinterpret_u32_u8 ( d4u8 ) , 1 ) ;
 return ;
 }
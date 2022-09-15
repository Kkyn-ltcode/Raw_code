unsigned int vp8_variance8x16_neon ( const unsigned char * src_ptr , int source_stride , const unsigned char * ref_ptr , int recon_stride , unsigned int * sse ) {
 int i ;
 uint8x8_t d0u8 , d2u8 , d4u8 , d6u8 ;
 int16x4_t d22s16 , d23s16 , d24s16 , d25s16 ;
 uint32x2_t d0u32 , d10u32 ;
 int64x1_t d0s64 , d1s64 ;
 uint16x8_t q11u16 , q12u16 ;
 int32x4_t q8s32 , q9s32 , q10s32 ;
 int64x2_t q0s64 , q1s64 , q5s64 ;
 q8s32 = vdupq_n_s32 ( 0 ) ;
 q9s32 = vdupq_n_s32 ( 0 ) ;
 q10s32 = vdupq_n_s32 ( 0 ) ;
 for ( i = 0 ;
 i < 8 ;
 i ++ ) {
 d0u8 = vld1_u8 ( src_ptr ) ;
 src_ptr += source_stride ;
 d2u8 = vld1_u8 ( src_ptr ) ;
 src_ptr += source_stride ;
 __builtin_prefetch ( src_ptr ) ;
 d4u8 = vld1_u8 ( ref_ptr ) ;
 ref_ptr += recon_stride ;
 d6u8 = vld1_u8 ( ref_ptr ) ;
 ref_ptr += recon_stride ;
 __builtin_prefetch ( ref_ptr ) ;
 q11u16 = vsubl_u8 ( d0u8 , d4u8 ) ;
 q12u16 = vsubl_u8 ( d2u8 , d6u8 ) ;
 d22s16 = vreinterpret_s16_u16 ( vget_low_u16 ( q11u16 ) ) ;
 d23s16 = vreinterpret_s16_u16 ( vget_high_u16 ( q11u16 ) ) ;
 q8s32 = vpadalq_s16 ( q8s32 , vreinterpretq_s16_u16 ( q11u16 ) ) ;
 q9s32 = vmlal_s16 ( q9s32 , d22s16 , d22s16 ) ;
 q10s32 = vmlal_s16 ( q10s32 , d23s16 , d23s16 ) ;
 d24s16 = vreinterpret_s16_u16 ( vget_low_u16 ( q12u16 ) ) ;
 d25s16 = vreinterpret_s16_u16 ( vget_high_u16 ( q12u16 ) ) ;
 q8s32 = vpadalq_s16 ( q8s32 , vreinterpretq_s16_u16 ( q12u16 ) ) ;
 q9s32 = vmlal_s16 ( q9s32 , d24s16 , d24s16 ) ;
 q10s32 = vmlal_s16 ( q10s32 , d25s16 , d25s16 ) ;
 }
 q10s32 = vaddq_s32 ( q10s32 , q9s32 ) ;
 q0s64 = vpaddlq_s32 ( q8s32 ) ;
 q1s64 = vpaddlq_s32 ( q10s32 ) ;
 d0s64 = vadd_s64 ( vget_low_s64 ( q0s64 ) , vget_high_s64 ( q0s64 ) ) ;
 d1s64 = vadd_s64 ( vget_low_s64 ( q1s64 ) , vget_high_s64 ( q1s64 ) ) ;
 q5s64 = vmull_s32 ( vreinterpret_s32_s64 ( d0s64 ) , vreinterpret_s32_s64 ( d0s64 ) ) ;
 vst1_lane_u32 ( ( uint32_t * ) sse , vreinterpret_u32_s64 ( d1s64 ) , 0 ) ;
 d10u32 = vshr_n_u32 ( vreinterpret_u32_s64 ( vget_low_s64 ( q5s64 ) ) , 7 ) ;
 d0u32 = vsub_u32 ( vreinterpret_u32_s64 ( d1s64 ) , d10u32 ) ;
 return vget_lane_u32 ( d0u32 , 0 ) ;
 }
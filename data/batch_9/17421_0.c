static void iadst8_sse2 ( __m128i * in ) {
 const __m128i k__cospi_p02_p30 = pair_set_epi16 ( cospi_2_64 , cospi_30_64 ) ;
 const __m128i k__cospi_p30_m02 = pair_set_epi16 ( cospi_30_64 , - cospi_2_64 ) ;
 const __m128i k__cospi_p10_p22 = pair_set_epi16 ( cospi_10_64 , cospi_22_64 ) ;
 const __m128i k__cospi_p22_m10 = pair_set_epi16 ( cospi_22_64 , - cospi_10_64 ) ;
 const __m128i k__cospi_p18_p14 = pair_set_epi16 ( cospi_18_64 , cospi_14_64 ) ;
 const __m128i k__cospi_p14_m18 = pair_set_epi16 ( cospi_14_64 , - cospi_18_64 ) ;
 const __m128i k__cospi_p26_p06 = pair_set_epi16 ( cospi_26_64 , cospi_6_64 ) ;
 const __m128i k__cospi_p06_m26 = pair_set_epi16 ( cospi_6_64 , - cospi_26_64 ) ;
 const __m128i k__cospi_p08_p24 = pair_set_epi16 ( cospi_8_64 , cospi_24_64 ) ;
 const __m128i k__cospi_p24_m08 = pair_set_epi16 ( cospi_24_64 , - cospi_8_64 ) ;
 const __m128i k__cospi_m24_p08 = pair_set_epi16 ( - cospi_24_64 , cospi_8_64 ) ;
 const __m128i k__cospi_p16_m16 = pair_set_epi16 ( cospi_16_64 , - cospi_16_64 ) ;
 const __m128i k__cospi_p16_p16 = _mm_set1_epi16 ( cospi_16_64 ) ;
 const __m128i k__const_0 = _mm_set1_epi16 ( 0 ) ;
 const __m128i k__DCT_CONST_ROUNDING = _mm_set1_epi32 ( DCT_CONST_ROUNDING ) ;
 __m128i u0 , u1 , u2 , u3 , u4 , u5 , u6 , u7 , u8 , u9 , u10 , u11 , u12 , u13 , u14 , u15 ;
 __m128i v0 , v1 , v2 , v3 , v4 , v5 , v6 , v7 , v8 , v9 , v10 , v11 , v12 , v13 , v14 , v15 ;
 __m128i w0 , w1 , w2 , w3 , w4 , w5 , w6 , w7 , w8 , w9 , w10 , w11 , w12 , w13 , w14 , w15 ;
 __m128i s0 , s1 , s2 , s3 , s4 , s5 , s6 , s7 ;
 __m128i in0 , in1 , in2 , in3 , in4 , in5 , in6 , in7 ;
 array_transpose_8x8 ( in , in ) ;
 in0 = in [ 7 ] ;
 in1 = in [ 0 ] ;
 in2 = in [ 5 ] ;
 in3 = in [ 2 ] ;
 in4 = in [ 3 ] ;
 in5 = in [ 4 ] ;
 in6 = in [ 1 ] ;
 in7 = in [ 6 ] ;
 s0 = _mm_unpacklo_epi16 ( in0 , in1 ) ;
 s1 = _mm_unpackhi_epi16 ( in0 , in1 ) ;
 s2 = _mm_unpacklo_epi16 ( in2 , in3 ) ;
 s3 = _mm_unpackhi_epi16 ( in2 , in3 ) ;
 s4 = _mm_unpacklo_epi16 ( in4 , in5 ) ;
 s5 = _mm_unpackhi_epi16 ( in4 , in5 ) ;
 s6 = _mm_unpacklo_epi16 ( in6 , in7 ) ;
 s7 = _mm_unpackhi_epi16 ( in6 , in7 ) ;
 u0 = _mm_madd_epi16 ( s0 , k__cospi_p02_p30 ) ;
 u1 = _mm_madd_epi16 ( s1 , k__cospi_p02_p30 ) ;
 u2 = _mm_madd_epi16 ( s0 , k__cospi_p30_m02 ) ;
 u3 = _mm_madd_epi16 ( s1 , k__cospi_p30_m02 ) ;
 u4 = _mm_madd_epi16 ( s2 , k__cospi_p10_p22 ) ;
 u5 = _mm_madd_epi16 ( s3 , k__cospi_p10_p22 ) ;
 u6 = _mm_madd_epi16 ( s2 , k__cospi_p22_m10 ) ;
 u7 = _mm_madd_epi16 ( s3 , k__cospi_p22_m10 ) ;
 u8 = _mm_madd_epi16 ( s4 , k__cospi_p18_p14 ) ;
 u9 = _mm_madd_epi16 ( s5 , k__cospi_p18_p14 ) ;
 u10 = _mm_madd_epi16 ( s4 , k__cospi_p14_m18 ) ;
 u11 = _mm_madd_epi16 ( s5 , k__cospi_p14_m18 ) ;
 u12 = _mm_madd_epi16 ( s6 , k__cospi_p26_p06 ) ;
 u13 = _mm_madd_epi16 ( s7 , k__cospi_p26_p06 ) ;
 u14 = _mm_madd_epi16 ( s6 , k__cospi_p06_m26 ) ;
 u15 = _mm_madd_epi16 ( s7 , k__cospi_p06_m26 ) ;
 w0 = _mm_add_epi32 ( u0 , u8 ) ;
 w1 = _mm_add_epi32 ( u1 , u9 ) ;
 w2 = _mm_add_epi32 ( u2 , u10 ) ;
 w3 = _mm_add_epi32 ( u3 , u11 ) ;
 w4 = _mm_add_epi32 ( u4 , u12 ) ;
 w5 = _mm_add_epi32 ( u5 , u13 ) ;
 w6 = _mm_add_epi32 ( u6 , u14 ) ;
 w7 = _mm_add_epi32 ( u7 , u15 ) ;
 w8 = _mm_sub_epi32 ( u0 , u8 ) ;
 w9 = _mm_sub_epi32 ( u1 , u9 ) ;
 w10 = _mm_sub_epi32 ( u2 , u10 ) ;
 w11 = _mm_sub_epi32 ( u3 , u11 ) ;
 w12 = _mm_sub_epi32 ( u4 , u12 ) ;
 w13 = _mm_sub_epi32 ( u5 , u13 ) ;
 w14 = _mm_sub_epi32 ( u6 , u14 ) ;
 w15 = _mm_sub_epi32 ( u7 , u15 ) ;
 v0 = _mm_add_epi32 ( w0 , k__DCT_CONST_ROUNDING ) ;
 v1 = _mm_add_epi32 ( w1 , k__DCT_CONST_ROUNDING ) ;
 v2 = _mm_add_epi32 ( w2 , k__DCT_CONST_ROUNDING ) ;
 v3 = _mm_add_epi32 ( w3 , k__DCT_CONST_ROUNDING ) ;
 v4 = _mm_add_epi32 ( w4 , k__DCT_CONST_ROUNDING ) ;
 v5 = _mm_add_epi32 ( w5 , k__DCT_CONST_ROUNDING ) ;
 v6 = _mm_add_epi32 ( w6 , k__DCT_CONST_ROUNDING ) ;
 v7 = _mm_add_epi32 ( w7 , k__DCT_CONST_ROUNDING ) ;
 v8 = _mm_add_epi32 ( w8 , k__DCT_CONST_ROUNDING ) ;
 v9 = _mm_add_epi32 ( w9 , k__DCT_CONST_ROUNDING ) ;
 v10 = _mm_add_epi32 ( w10 , k__DCT_CONST_ROUNDING ) ;
 v11 = _mm_add_epi32 ( w11 , k__DCT_CONST_ROUNDING ) ;
 v12 = _mm_add_epi32 ( w12 , k__DCT_CONST_ROUNDING ) ;
 v13 = _mm_add_epi32 ( w13 , k__DCT_CONST_ROUNDING ) ;
 v14 = _mm_add_epi32 ( w14 , k__DCT_CONST_ROUNDING ) ;
 v15 = _mm_add_epi32 ( w15 , k__DCT_CONST_ROUNDING ) ;
 u0 = _mm_srai_epi32 ( v0 , DCT_CONST_BITS ) ;
 u1 = _mm_srai_epi32 ( v1 , DCT_CONST_BITS ) ;
 u2 = _mm_srai_epi32 ( v2 , DCT_CONST_BITS ) ;
 u3 = _mm_srai_epi32 ( v3 , DCT_CONST_BITS ) ;
 u4 = _mm_srai_epi32 ( v4 , DCT_CONST_BITS ) ;
 u5 = _mm_srai_epi32 ( v5 , DCT_CONST_BITS ) ;
 u6 = _mm_srai_epi32 ( v6 , DCT_CONST_BITS ) ;
 u7 = _mm_srai_epi32 ( v7 , DCT_CONST_BITS ) ;
 u8 = _mm_srai_epi32 ( v8 , DCT_CONST_BITS ) ;
 u9 = _mm_srai_epi32 ( v9 , DCT_CONST_BITS ) ;
 u10 = _mm_srai_epi32 ( v10 , DCT_CONST_BITS ) ;
 u11 = _mm_srai_epi32 ( v11 , DCT_CONST_BITS ) ;
 u12 = _mm_srai_epi32 ( v12 , DCT_CONST_BITS ) ;
 u13 = _mm_srai_epi32 ( v13 , DCT_CONST_BITS ) ;
 u14 = _mm_srai_epi32 ( v14 , DCT_CONST_BITS ) ;
 u15 = _mm_srai_epi32 ( v15 , DCT_CONST_BITS ) ;
 in [ 0 ] = _mm_packs_epi32 ( u0 , u1 ) ;
 in [ 1 ] = _mm_packs_epi32 ( u2 , u3 ) ;
 in [ 2 ] = _mm_packs_epi32 ( u4 , u5 ) ;
 in [ 3 ] = _mm_packs_epi32 ( u6 , u7 ) ;
 in [ 4 ] = _mm_packs_epi32 ( u8 , u9 ) ;
 in [ 5 ] = _mm_packs_epi32 ( u10 , u11 ) ;
 in [ 6 ] = _mm_packs_epi32 ( u12 , u13 ) ;
 in [ 7 ] = _mm_packs_epi32 ( u14 , u15 ) ;
 s0 = _mm_add_epi16 ( in [ 0 ] , in [ 2 ] ) ;
 s1 = _mm_add_epi16 ( in [ 1 ] , in [ 3 ] ) ;
 s2 = _mm_sub_epi16 ( in [ 0 ] , in [ 2 ] ) ;
 s3 = _mm_sub_epi16 ( in [ 1 ] , in [ 3 ] ) ;
 u0 = _mm_unpacklo_epi16 ( in [ 4 ] , in [ 5 ] ) ;
 u1 = _mm_unpackhi_epi16 ( in [ 4 ] , in [ 5 ] ) ;
 u2 = _mm_unpacklo_epi16 ( in [ 6 ] , in [ 7 ] ) ;
 u3 = _mm_unpackhi_epi16 ( in [ 6 ] , in [ 7 ] ) ;
 v0 = _mm_madd_epi16 ( u0 , k__cospi_p08_p24 ) ;
 v1 = _mm_madd_epi16 ( u1 , k__cospi_p08_p24 ) ;
 v2 = _mm_madd_epi16 ( u0 , k__cospi_p24_m08 ) ;
 v3 = _mm_madd_epi16 ( u1 , k__cospi_p24_m08 ) ;
 v4 = _mm_madd_epi16 ( u2 , k__cospi_m24_p08 ) ;
 v5 = _mm_madd_epi16 ( u3 , k__cospi_m24_p08 ) ;
 v6 = _mm_madd_epi16 ( u2 , k__cospi_p08_p24 ) ;
 v7 = _mm_madd_epi16 ( u3 , k__cospi_p08_p24 ) ;
 w0 = _mm_add_epi32 ( v0 , v4 ) ;
 w1 = _mm_add_epi32 ( v1 , v5 ) ;
 w2 = _mm_add_epi32 ( v2 , v6 ) ;
 w3 = _mm_add_epi32 ( v3 , v7 ) ;
 w4 = _mm_sub_epi32 ( v0 , v4 ) ;
 w5 = _mm_sub_epi32 ( v1 , v5 ) ;
 w6 = _mm_sub_epi32 ( v2 , v6 ) ;
 w7 = _mm_sub_epi32 ( v3 , v7 ) ;
 v0 = _mm_add_epi32 ( w0 , k__DCT_CONST_ROUNDING ) ;
 v1 = _mm_add_epi32 ( w1 , k__DCT_CONST_ROUNDING ) ;
 v2 = _mm_add_epi32 ( w2 , k__DCT_CONST_ROUNDING ) ;
 v3 = _mm_add_epi32 ( w3 , k__DCT_CONST_ROUNDING ) ;
 v4 = _mm_add_epi32 ( w4 , k__DCT_CONST_ROUNDING ) ;
 v5 = _mm_add_epi32 ( w5 , k__DCT_CONST_ROUNDING ) ;
 v6 = _mm_add_epi32 ( w6 , k__DCT_CONST_ROUNDING ) ;
 v7 = _mm_add_epi32 ( w7 , k__DCT_CONST_ROUNDING ) ;
 u0 = _mm_srai_epi32 ( v0 , DCT_CONST_BITS ) ;
 u1 = _mm_srai_epi32 ( v1 , DCT_CONST_BITS ) ;
 u2 = _mm_srai_epi32 ( v2 , DCT_CONST_BITS ) ;
 u3 = _mm_srai_epi32 ( v3 , DCT_CONST_BITS ) ;
 u4 = _mm_srai_epi32 ( v4 , DCT_CONST_BITS ) ;
 u5 = _mm_srai_epi32 ( v5 , DCT_CONST_BITS ) ;
 u6 = _mm_srai_epi32 ( v6 , DCT_CONST_BITS ) ;
 u7 = _mm_srai_epi32 ( v7 , DCT_CONST_BITS ) ;
 s4 = _mm_packs_epi32 ( u0 , u1 ) ;
 s5 = _mm_packs_epi32 ( u2 , u3 ) ;
 s6 = _mm_packs_epi32 ( u4 , u5 ) ;
 s7 = _mm_packs_epi32 ( u6 , u7 ) ;
 u0 = _mm_unpacklo_epi16 ( s2 , s3 ) ;
 u1 = _mm_unpackhi_epi16 ( s2 , s3 ) ;
 u2 = _mm_unpacklo_epi16 ( s6 , s7 ) ;
 u3 = _mm_unpackhi_epi16 ( s6 , s7 ) ;
 v0 = _mm_madd_epi16 ( u0 , k__cospi_p16_p16 ) ;
 v1 = _mm_madd_epi16 ( u1 , k__cospi_p16_p16 ) ;
 v2 = _mm_madd_epi16 ( u0 , k__cospi_p16_m16 ) ;
 v3 = _mm_madd_epi16 ( u1 , k__cospi_p16_m16 ) ;
 v4 = _mm_madd_epi16 ( u2 , k__cospi_p16_p16 ) ;
 v5 = _mm_madd_epi16 ( u3 , k__cospi_p16_p16 ) ;
 v6 = _mm_madd_epi16 ( u2 , k__cospi_p16_m16 ) ;
 v7 = _mm_madd_epi16 ( u3 , k__cospi_p16_m16 ) ;
 u0 = _mm_add_epi32 ( v0 , k__DCT_CONST_ROUNDING ) ;
 u1 = _mm_add_epi32 ( v1 , k__DCT_CONST_ROUNDING ) ;
 u2 = _mm_add_epi32 ( v2 , k__DCT_CONST_ROUNDING ) ;
 u3 = _mm_add_epi32 ( v3 , k__DCT_CONST_ROUNDING ) ;
 u4 = _mm_add_epi32 ( v4 , k__DCT_CONST_ROUNDING ) ;
 u5 = _mm_add_epi32 ( v5 , k__DCT_CONST_ROUNDING ) ;
 u6 = _mm_add_epi32 ( v6 , k__DCT_CONST_ROUNDING ) ;
 u7 = _mm_add_epi32 ( v7 , k__DCT_CONST_ROUNDING ) ;
 v0 = _mm_srai_epi32 ( u0 , DCT_CONST_BITS ) ;
 v1 = _mm_srai_epi32 ( u1 , DCT_CONST_BITS ) ;
 v2 = _mm_srai_epi32 ( u2 , DCT_CONST_BITS ) ;
 v3 = _mm_srai_epi32 ( u3 , DCT_CONST_BITS ) ;
 v4 = _mm_srai_epi32 ( u4 , DCT_CONST_BITS ) ;
 v5 = _mm_srai_epi32 ( u5 , DCT_CONST_BITS ) ;
 v6 = _mm_srai_epi32 ( u6 , DCT_CONST_BITS ) ;
 v7 = _mm_srai_epi32 ( u7 , DCT_CONST_BITS ) ;
 s2 = _mm_packs_epi32 ( v0 , v1 ) ;
 s3 = _mm_packs_epi32 ( v2 , v3 ) ;
 s6 = _mm_packs_epi32 ( v4 , v5 ) ;
 s7 = _mm_packs_epi32 ( v6 , v7 ) ;
 in [ 0 ] = s0 ;
 in [ 1 ] = _mm_sub_epi16 ( k__const_0 , s4 ) ;
 in [ 2 ] = s6 ;
 in [ 3 ] = _mm_sub_epi16 ( k__const_0 , s2 ) ;
 in [ 4 ] = s3 ;
 in [ 5 ] = _mm_sub_epi16 ( k__const_0 , s7 ) ;
 in [ 6 ] = s5 ;
 in [ 7 ] = _mm_sub_epi16 ( k__const_0 , s1 ) ;
 }
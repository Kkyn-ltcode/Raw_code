void vp9_idct16x16_256_add_sse2 ( const int16_t * input , uint8_t * dest , int stride ) {
 const __m128i rounding = _mm_set1_epi32 ( DCT_CONST_ROUNDING ) ;
 const __m128i final_rounding = _mm_set1_epi16 ( 1 << 5 ) ;
 const __m128i zero = _mm_setzero_si128 ( ) ;
 const __m128i stg2_0 = pair_set_epi16 ( cospi_30_64 , - cospi_2_64 ) ;
 const __m128i stg2_1 = pair_set_epi16 ( cospi_2_64 , cospi_30_64 ) ;
 const __m128i stg2_2 = pair_set_epi16 ( cospi_14_64 , - cospi_18_64 ) ;
 const __m128i stg2_3 = pair_set_epi16 ( cospi_18_64 , cospi_14_64 ) ;
 const __m128i stg2_4 = pair_set_epi16 ( cospi_22_64 , - cospi_10_64 ) ;
 const __m128i stg2_5 = pair_set_epi16 ( cospi_10_64 , cospi_22_64 ) ;
 const __m128i stg2_6 = pair_set_epi16 ( cospi_6_64 , - cospi_26_64 ) ;
 const __m128i stg2_7 = pair_set_epi16 ( cospi_26_64 , cospi_6_64 ) ;
 const __m128i stg3_0 = pair_set_epi16 ( cospi_28_64 , - cospi_4_64 ) ;
 const __m128i stg3_1 = pair_set_epi16 ( cospi_4_64 , cospi_28_64 ) ;
 const __m128i stg3_2 = pair_set_epi16 ( cospi_12_64 , - cospi_20_64 ) ;
 const __m128i stg3_3 = pair_set_epi16 ( cospi_20_64 , cospi_12_64 ) ;
 const __m128i stg4_0 = pair_set_epi16 ( cospi_16_64 , cospi_16_64 ) ;
 const __m128i stg4_1 = pair_set_epi16 ( cospi_16_64 , - cospi_16_64 ) ;
 const __m128i stg4_2 = pair_set_epi16 ( cospi_24_64 , - cospi_8_64 ) ;
 const __m128i stg4_3 = pair_set_epi16 ( cospi_8_64 , cospi_24_64 ) ;
 const __m128i stg4_4 = pair_set_epi16 ( - cospi_8_64 , cospi_24_64 ) ;
 const __m128i stg4_5 = pair_set_epi16 ( cospi_24_64 , cospi_8_64 ) ;
 const __m128i stg4_6 = pair_set_epi16 ( - cospi_24_64 , - cospi_8_64 ) ;
 const __m128i stg4_7 = pair_set_epi16 ( - cospi_8_64 , cospi_24_64 ) ;
 const __m128i stg6_0 = pair_set_epi16 ( - cospi_16_64 , cospi_16_64 ) ;
 __m128i in [ 16 ] , l [ 16 ] , r [ 16 ] , * curr1 ;
 __m128i stp1_0 , stp1_1 , stp1_2 , stp1_3 , stp1_4 , stp1_5 , stp1_6 , stp1_7 , stp1_8 , stp1_9 , stp1_10 , stp1_11 , stp1_12 , stp1_13 , stp1_14 , stp1_15 , stp1_8_0 , stp1_12_0 ;
 __m128i stp2_0 , stp2_1 , stp2_2 , stp2_3 , stp2_4 , stp2_5 , stp2_6 , stp2_7 , stp2_8 , stp2_9 , stp2_10 , stp2_11 , stp2_12 , stp2_13 , stp2_14 , stp2_15 ;
 __m128i tmp0 , tmp1 , tmp2 , tmp3 , tmp4 , tmp5 , tmp6 , tmp7 ;
 int i ;
 curr1 = l ;
 for ( i = 0 ;
 i < 2 ;
 i ++ ) {
 in [ 0 ] = _mm_load_si128 ( ( const __m128i * ) input ) ;
 in [ 8 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 1 ) ) ;
 in [ 1 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 2 ) ) ;
 in [ 9 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 3 ) ) ;
 in [ 2 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 4 ) ) ;
 in [ 10 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 5 ) ) ;
 in [ 3 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 6 ) ) ;
 in [ 11 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 7 ) ) ;
 in [ 4 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 8 ) ) ;
 in [ 12 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 9 ) ) ;
 in [ 5 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 10 ) ) ;
 in [ 13 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 11 ) ) ;
 in [ 6 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 12 ) ) ;
 in [ 14 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 13 ) ) ;
 in [ 7 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 14 ) ) ;
 in [ 15 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 15 ) ) ;
 array_transpose_8x8 ( in , in ) ;
 array_transpose_8x8 ( in + 8 , in + 8 ) ;
 IDCT16 curr1 [ 0 ] = _mm_add_epi16 ( stp2_0 , stp1_15 ) ;
 curr1 [ 1 ] = _mm_add_epi16 ( stp2_1 , stp1_14 ) ;
 curr1 [ 2 ] = _mm_add_epi16 ( stp2_2 , stp2_13 ) ;
 curr1 [ 3 ] = _mm_add_epi16 ( stp2_3 , stp2_12 ) ;
 curr1 [ 4 ] = _mm_add_epi16 ( stp2_4 , stp2_11 ) ;
 curr1 [ 5 ] = _mm_add_epi16 ( stp2_5 , stp2_10 ) ;
 curr1 [ 6 ] = _mm_add_epi16 ( stp2_6 , stp1_9 ) ;
 curr1 [ 7 ] = _mm_add_epi16 ( stp2_7 , stp1_8 ) ;
 curr1 [ 8 ] = _mm_sub_epi16 ( stp2_7 , stp1_8 ) ;
 curr1 [ 9 ] = _mm_sub_epi16 ( stp2_6 , stp1_9 ) ;
 curr1 [ 10 ] = _mm_sub_epi16 ( stp2_5 , stp2_10 ) ;
 curr1 [ 11 ] = _mm_sub_epi16 ( stp2_4 , stp2_11 ) ;
 curr1 [ 12 ] = _mm_sub_epi16 ( stp2_3 , stp2_12 ) ;
 curr1 [ 13 ] = _mm_sub_epi16 ( stp2_2 , stp2_13 ) ;
 curr1 [ 14 ] = _mm_sub_epi16 ( stp2_1 , stp1_14 ) ;
 curr1 [ 15 ] = _mm_sub_epi16 ( stp2_0 , stp1_15 ) ;
 curr1 = r ;
 input += 128 ;
 }
 for ( i = 0 ;
 i < 2 ;
 i ++ ) {
 array_transpose_8x8 ( l + i * 8 , in ) ;
 array_transpose_8x8 ( r + i * 8 , in + 8 ) ;
 IDCT16 in [ 0 ] = _mm_add_epi16 ( stp2_0 , stp1_15 ) ;
 in [ 1 ] = _mm_add_epi16 ( stp2_1 , stp1_14 ) ;
 in [ 2 ] = _mm_add_epi16 ( stp2_2 , stp2_13 ) ;
 in [ 3 ] = _mm_add_epi16 ( stp2_3 , stp2_12 ) ;
 in [ 4 ] = _mm_add_epi16 ( stp2_4 , stp2_11 ) ;
 in [ 5 ] = _mm_add_epi16 ( stp2_5 , stp2_10 ) ;
 in [ 6 ] = _mm_add_epi16 ( stp2_6 , stp1_9 ) ;
 in [ 7 ] = _mm_add_epi16 ( stp2_7 , stp1_8 ) ;
 in [ 8 ] = _mm_sub_epi16 ( stp2_7 , stp1_8 ) ;
 in [ 9 ] = _mm_sub_epi16 ( stp2_6 , stp1_9 ) ;
 in [ 10 ] = _mm_sub_epi16 ( stp2_5 , stp2_10 ) ;
 in [ 11 ] = _mm_sub_epi16 ( stp2_4 , stp2_11 ) ;
 in [ 12 ] = _mm_sub_epi16 ( stp2_3 , stp2_12 ) ;
 in [ 13 ] = _mm_sub_epi16 ( stp2_2 , stp2_13 ) ;
 in [ 14 ] = _mm_sub_epi16 ( stp2_1 , stp1_14 ) ;
 in [ 15 ] = _mm_sub_epi16 ( stp2_0 , stp1_15 ) ;
 in [ 0 ] = _mm_adds_epi16 ( in [ 0 ] , final_rounding ) ;
 in [ 1 ] = _mm_adds_epi16 ( in [ 1 ] , final_rounding ) ;
 in [ 2 ] = _mm_adds_epi16 ( in [ 2 ] , final_rounding ) ;
 in [ 3 ] = _mm_adds_epi16 ( in [ 3 ] , final_rounding ) ;
 in [ 4 ] = _mm_adds_epi16 ( in [ 4 ] , final_rounding ) ;
 in [ 5 ] = _mm_adds_epi16 ( in [ 5 ] , final_rounding ) ;
 in [ 6 ] = _mm_adds_epi16 ( in [ 6 ] , final_rounding ) ;
 in [ 7 ] = _mm_adds_epi16 ( in [ 7 ] , final_rounding ) ;
 in [ 8 ] = _mm_adds_epi16 ( in [ 8 ] , final_rounding ) ;
 in [ 9 ] = _mm_adds_epi16 ( in [ 9 ] , final_rounding ) ;
 in [ 10 ] = _mm_adds_epi16 ( in [ 10 ] , final_rounding ) ;
 in [ 11 ] = _mm_adds_epi16 ( in [ 11 ] , final_rounding ) ;
 in [ 12 ] = _mm_adds_epi16 ( in [ 12 ] , final_rounding ) ;
 in [ 13 ] = _mm_adds_epi16 ( in [ 13 ] , final_rounding ) ;
 in [ 14 ] = _mm_adds_epi16 ( in [ 14 ] , final_rounding ) ;
 in [ 15 ] = _mm_adds_epi16 ( in [ 15 ] , final_rounding ) ;
 in [ 0 ] = _mm_srai_epi16 ( in [ 0 ] , 6 ) ;
 in [ 1 ] = _mm_srai_epi16 ( in [ 1 ] , 6 ) ;
 in [ 2 ] = _mm_srai_epi16 ( in [ 2 ] , 6 ) ;
 in [ 3 ] = _mm_srai_epi16 ( in [ 3 ] , 6 ) ;
 in [ 4 ] = _mm_srai_epi16 ( in [ 4 ] , 6 ) ;
 in [ 5 ] = _mm_srai_epi16 ( in [ 5 ] , 6 ) ;
 in [ 6 ] = _mm_srai_epi16 ( in [ 6 ] , 6 ) ;
 in [ 7 ] = _mm_srai_epi16 ( in [ 7 ] , 6 ) ;
 in [ 8 ] = _mm_srai_epi16 ( in [ 8 ] , 6 ) ;
 in [ 9 ] = _mm_srai_epi16 ( in [ 9 ] , 6 ) ;
 in [ 10 ] = _mm_srai_epi16 ( in [ 10 ] , 6 ) ;
 in [ 11 ] = _mm_srai_epi16 ( in [ 11 ] , 6 ) ;
 in [ 12 ] = _mm_srai_epi16 ( in [ 12 ] , 6 ) ;
 in [ 13 ] = _mm_srai_epi16 ( in [ 13 ] , 6 ) ;
 in [ 14 ] = _mm_srai_epi16 ( in [ 14 ] , 6 ) ;
 in [ 15 ] = _mm_srai_epi16 ( in [ 15 ] , 6 ) ;
 RECON_AND_STORE ( dest , in [ 0 ] ) ;
 RECON_AND_STORE ( dest , in [ 1 ] ) ;
 RECON_AND_STORE ( dest , in [ 2 ] ) ;
 RECON_AND_STORE ( dest , in [ 3 ] ) ;
 RECON_AND_STORE ( dest , in [ 4 ] ) ;
 RECON_AND_STORE ( dest , in [ 5 ] ) ;
 RECON_AND_STORE ( dest , in [ 6 ] ) ;
 RECON_AND_STORE ( dest , in [ 7 ] ) ;
 RECON_AND_STORE ( dest , in [ 8 ] ) ;
 RECON_AND_STORE ( dest , in [ 9 ] ) ;
 RECON_AND_STORE ( dest , in [ 10 ] ) ;
 RECON_AND_STORE ( dest , in [ 11 ] ) ;
 RECON_AND_STORE ( dest , in [ 12 ] ) ;
 RECON_AND_STORE ( dest , in [ 13 ] ) ;
 RECON_AND_STORE ( dest , in [ 14 ] ) ;
 RECON_AND_STORE ( dest , in [ 15 ] ) ;
 dest += 8 - ( stride * 16 ) ;
 }
 }
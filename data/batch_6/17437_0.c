static void iadst16_8col ( __m128i * in ) {
 __m128i s [ 16 ] , x [ 16 ] , u [ 32 ] , v [ 32 ] ;
 const __m128i k__cospi_p01_p31 = pair_set_epi16 ( cospi_1_64 , cospi_31_64 ) ;
 const __m128i k__cospi_p31_m01 = pair_set_epi16 ( cospi_31_64 , - cospi_1_64 ) ;
 const __m128i k__cospi_p05_p27 = pair_set_epi16 ( cospi_5_64 , cospi_27_64 ) ;
 const __m128i k__cospi_p27_m05 = pair_set_epi16 ( cospi_27_64 , - cospi_5_64 ) ;
 const __m128i k__cospi_p09_p23 = pair_set_epi16 ( cospi_9_64 , cospi_23_64 ) ;
 const __m128i k__cospi_p23_m09 = pair_set_epi16 ( cospi_23_64 , - cospi_9_64 ) ;
 const __m128i k__cospi_p13_p19 = pair_set_epi16 ( cospi_13_64 , cospi_19_64 ) ;
 const __m128i k__cospi_p19_m13 = pair_set_epi16 ( cospi_19_64 , - cospi_13_64 ) ;
 const __m128i k__cospi_p17_p15 = pair_set_epi16 ( cospi_17_64 , cospi_15_64 ) ;
 const __m128i k__cospi_p15_m17 = pair_set_epi16 ( cospi_15_64 , - cospi_17_64 ) ;
 const __m128i k__cospi_p21_p11 = pair_set_epi16 ( cospi_21_64 , cospi_11_64 ) ;
 const __m128i k__cospi_p11_m21 = pair_set_epi16 ( cospi_11_64 , - cospi_21_64 ) ;
 const __m128i k__cospi_p25_p07 = pair_set_epi16 ( cospi_25_64 , cospi_7_64 ) ;
 const __m128i k__cospi_p07_m25 = pair_set_epi16 ( cospi_7_64 , - cospi_25_64 ) ;
 const __m128i k__cospi_p29_p03 = pair_set_epi16 ( cospi_29_64 , cospi_3_64 ) ;
 const __m128i k__cospi_p03_m29 = pair_set_epi16 ( cospi_3_64 , - cospi_29_64 ) ;
 const __m128i k__cospi_p04_p28 = pair_set_epi16 ( cospi_4_64 , cospi_28_64 ) ;
 const __m128i k__cospi_p28_m04 = pair_set_epi16 ( cospi_28_64 , - cospi_4_64 ) ;
 const __m128i k__cospi_p20_p12 = pair_set_epi16 ( cospi_20_64 , cospi_12_64 ) ;
 const __m128i k__cospi_p12_m20 = pair_set_epi16 ( cospi_12_64 , - cospi_20_64 ) ;
 const __m128i k__cospi_m28_p04 = pair_set_epi16 ( - cospi_28_64 , cospi_4_64 ) ;
 const __m128i k__cospi_m12_p20 = pair_set_epi16 ( - cospi_12_64 , cospi_20_64 ) ;
 const __m128i k__cospi_p08_p24 = pair_set_epi16 ( cospi_8_64 , cospi_24_64 ) ;
 const __m128i k__cospi_p24_m08 = pair_set_epi16 ( cospi_24_64 , - cospi_8_64 ) ;
 const __m128i k__cospi_m24_p08 = pair_set_epi16 ( - cospi_24_64 , cospi_8_64 ) ;
 const __m128i k__cospi_m16_m16 = _mm_set1_epi16 ( - cospi_16_64 ) ;
 const __m128i k__cospi_p16_p16 = _mm_set1_epi16 ( cospi_16_64 ) ;
 const __m128i k__cospi_p16_m16 = pair_set_epi16 ( cospi_16_64 , - cospi_16_64 ) ;
 const __m128i k__cospi_m16_p16 = pair_set_epi16 ( - cospi_16_64 , cospi_16_64 ) ;
 const __m128i k__DCT_CONST_ROUNDING = _mm_set1_epi32 ( DCT_CONST_ROUNDING ) ;
 const __m128i kZero = _mm_set1_epi16 ( 0 ) ;
 u [ 0 ] = _mm_unpacklo_epi16 ( in [ 15 ] , in [ 0 ] ) ;
 u [ 1 ] = _mm_unpackhi_epi16 ( in [ 15 ] , in [ 0 ] ) ;
 u [ 2 ] = _mm_unpacklo_epi16 ( in [ 13 ] , in [ 2 ] ) ;
 u [ 3 ] = _mm_unpackhi_epi16 ( in [ 13 ] , in [ 2 ] ) ;
 u [ 4 ] = _mm_unpacklo_epi16 ( in [ 11 ] , in [ 4 ] ) ;
 u [ 5 ] = _mm_unpackhi_epi16 ( in [ 11 ] , in [ 4 ] ) ;
 u [ 6 ] = _mm_unpacklo_epi16 ( in [ 9 ] , in [ 6 ] ) ;
 u [ 7 ] = _mm_unpackhi_epi16 ( in [ 9 ] , in [ 6 ] ) ;
 u [ 8 ] = _mm_unpacklo_epi16 ( in [ 7 ] , in [ 8 ] ) ;
 u [ 9 ] = _mm_unpackhi_epi16 ( in [ 7 ] , in [ 8 ] ) ;
 u [ 10 ] = _mm_unpacklo_epi16 ( in [ 5 ] , in [ 10 ] ) ;
 u [ 11 ] = _mm_unpackhi_epi16 ( in [ 5 ] , in [ 10 ] ) ;
 u [ 12 ] = _mm_unpacklo_epi16 ( in [ 3 ] , in [ 12 ] ) ;
 u [ 13 ] = _mm_unpackhi_epi16 ( in [ 3 ] , in [ 12 ] ) ;
 u [ 14 ] = _mm_unpacklo_epi16 ( in [ 1 ] , in [ 14 ] ) ;
 u [ 15 ] = _mm_unpackhi_epi16 ( in [ 1 ] , in [ 14 ] ) ;
 v [ 0 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p01_p31 ) ;
 v [ 1 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p01_p31 ) ;
 v [ 2 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p31_m01 ) ;
 v [ 3 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p31_m01 ) ;
 v [ 4 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_p05_p27 ) ;
 v [ 5 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_p05_p27 ) ;
 v [ 6 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_p27_m05 ) ;
 v [ 7 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_p27_m05 ) ;
 v [ 8 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_p09_p23 ) ;
 v [ 9 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_p09_p23 ) ;
 v [ 10 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_p23_m09 ) ;
 v [ 11 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_p23_m09 ) ;
 v [ 12 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_p13_p19 ) ;
 v [ 13 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_p13_p19 ) ;
 v [ 14 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_p19_m13 ) ;
 v [ 15 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_p19_m13 ) ;
 v [ 16 ] = _mm_madd_epi16 ( u [ 8 ] , k__cospi_p17_p15 ) ;
 v [ 17 ] = _mm_madd_epi16 ( u [ 9 ] , k__cospi_p17_p15 ) ;
 v [ 18 ] = _mm_madd_epi16 ( u [ 8 ] , k__cospi_p15_m17 ) ;
 v [ 19 ] = _mm_madd_epi16 ( u [ 9 ] , k__cospi_p15_m17 ) ;
 v [ 20 ] = _mm_madd_epi16 ( u [ 10 ] , k__cospi_p21_p11 ) ;
 v [ 21 ] = _mm_madd_epi16 ( u [ 11 ] , k__cospi_p21_p11 ) ;
 v [ 22 ] = _mm_madd_epi16 ( u [ 10 ] , k__cospi_p11_m21 ) ;
 v [ 23 ] = _mm_madd_epi16 ( u [ 11 ] , k__cospi_p11_m21 ) ;
 v [ 24 ] = _mm_madd_epi16 ( u [ 12 ] , k__cospi_p25_p07 ) ;
 v [ 25 ] = _mm_madd_epi16 ( u [ 13 ] , k__cospi_p25_p07 ) ;
 v [ 26 ] = _mm_madd_epi16 ( u [ 12 ] , k__cospi_p07_m25 ) ;
 v [ 27 ] = _mm_madd_epi16 ( u [ 13 ] , k__cospi_p07_m25 ) ;
 v [ 28 ] = _mm_madd_epi16 ( u [ 14 ] , k__cospi_p29_p03 ) ;
 v [ 29 ] = _mm_madd_epi16 ( u [ 15 ] , k__cospi_p29_p03 ) ;
 v [ 30 ] = _mm_madd_epi16 ( u [ 14 ] , k__cospi_p03_m29 ) ;
 v [ 31 ] = _mm_madd_epi16 ( u [ 15 ] , k__cospi_p03_m29 ) ;
 u [ 0 ] = _mm_add_epi32 ( v [ 0 ] , v [ 16 ] ) ;
 u [ 1 ] = _mm_add_epi32 ( v [ 1 ] , v [ 17 ] ) ;
 u [ 2 ] = _mm_add_epi32 ( v [ 2 ] , v [ 18 ] ) ;
 u [ 3 ] = _mm_add_epi32 ( v [ 3 ] , v [ 19 ] ) ;
 u [ 4 ] = _mm_add_epi32 ( v [ 4 ] , v [ 20 ] ) ;
 u [ 5 ] = _mm_add_epi32 ( v [ 5 ] , v [ 21 ] ) ;
 u [ 6 ] = _mm_add_epi32 ( v [ 6 ] , v [ 22 ] ) ;
 u [ 7 ] = _mm_add_epi32 ( v [ 7 ] , v [ 23 ] ) ;
 u [ 8 ] = _mm_add_epi32 ( v [ 8 ] , v [ 24 ] ) ;
 u [ 9 ] = _mm_add_epi32 ( v [ 9 ] , v [ 25 ] ) ;
 u [ 10 ] = _mm_add_epi32 ( v [ 10 ] , v [ 26 ] ) ;
 u [ 11 ] = _mm_add_epi32 ( v [ 11 ] , v [ 27 ] ) ;
 u [ 12 ] = _mm_add_epi32 ( v [ 12 ] , v [ 28 ] ) ;
 u [ 13 ] = _mm_add_epi32 ( v [ 13 ] , v [ 29 ] ) ;
 u [ 14 ] = _mm_add_epi32 ( v [ 14 ] , v [ 30 ] ) ;
 u [ 15 ] = _mm_add_epi32 ( v [ 15 ] , v [ 31 ] ) ;
 u [ 16 ] = _mm_sub_epi32 ( v [ 0 ] , v [ 16 ] ) ;
 u [ 17 ] = _mm_sub_epi32 ( v [ 1 ] , v [ 17 ] ) ;
 u [ 18 ] = _mm_sub_epi32 ( v [ 2 ] , v [ 18 ] ) ;
 u [ 19 ] = _mm_sub_epi32 ( v [ 3 ] , v [ 19 ] ) ;
 u [ 20 ] = _mm_sub_epi32 ( v [ 4 ] , v [ 20 ] ) ;
 u [ 21 ] = _mm_sub_epi32 ( v [ 5 ] , v [ 21 ] ) ;
 u [ 22 ] = _mm_sub_epi32 ( v [ 6 ] , v [ 22 ] ) ;
 u [ 23 ] = _mm_sub_epi32 ( v [ 7 ] , v [ 23 ] ) ;
 u [ 24 ] = _mm_sub_epi32 ( v [ 8 ] , v [ 24 ] ) ;
 u [ 25 ] = _mm_sub_epi32 ( v [ 9 ] , v [ 25 ] ) ;
 u [ 26 ] = _mm_sub_epi32 ( v [ 10 ] , v [ 26 ] ) ;
 u [ 27 ] = _mm_sub_epi32 ( v [ 11 ] , v [ 27 ] ) ;
 u [ 28 ] = _mm_sub_epi32 ( v [ 12 ] , v [ 28 ] ) ;
 u [ 29 ] = _mm_sub_epi32 ( v [ 13 ] , v [ 29 ] ) ;
 u [ 30 ] = _mm_sub_epi32 ( v [ 14 ] , v [ 30 ] ) ;
 u [ 31 ] = _mm_sub_epi32 ( v [ 15 ] , v [ 31 ] ) ;
 v [ 0 ] = _mm_add_epi32 ( u [ 0 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 1 ] = _mm_add_epi32 ( u [ 1 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 2 ] = _mm_add_epi32 ( u [ 2 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 3 ] = _mm_add_epi32 ( u [ 3 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 4 ] = _mm_add_epi32 ( u [ 4 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 5 ] = _mm_add_epi32 ( u [ 5 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 6 ] = _mm_add_epi32 ( u [ 6 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 7 ] = _mm_add_epi32 ( u [ 7 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 8 ] = _mm_add_epi32 ( u [ 8 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 9 ] = _mm_add_epi32 ( u [ 9 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 10 ] = _mm_add_epi32 ( u [ 10 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 11 ] = _mm_add_epi32 ( u [ 11 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 12 ] = _mm_add_epi32 ( u [ 12 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 13 ] = _mm_add_epi32 ( u [ 13 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 14 ] = _mm_add_epi32 ( u [ 14 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 15 ] = _mm_add_epi32 ( u [ 15 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 16 ] = _mm_add_epi32 ( u [ 16 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 17 ] = _mm_add_epi32 ( u [ 17 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 18 ] = _mm_add_epi32 ( u [ 18 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 19 ] = _mm_add_epi32 ( u [ 19 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 20 ] = _mm_add_epi32 ( u [ 20 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 21 ] = _mm_add_epi32 ( u [ 21 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 22 ] = _mm_add_epi32 ( u [ 22 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 23 ] = _mm_add_epi32 ( u [ 23 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 24 ] = _mm_add_epi32 ( u [ 24 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 25 ] = _mm_add_epi32 ( u [ 25 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 26 ] = _mm_add_epi32 ( u [ 26 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 27 ] = _mm_add_epi32 ( u [ 27 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 28 ] = _mm_add_epi32 ( u [ 28 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 29 ] = _mm_add_epi32 ( u [ 29 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 30 ] = _mm_add_epi32 ( u [ 30 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 31 ] = _mm_add_epi32 ( u [ 31 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 0 ] = _mm_srai_epi32 ( v [ 0 ] , DCT_CONST_BITS ) ;
 u [ 1 ] = _mm_srai_epi32 ( v [ 1 ] , DCT_CONST_BITS ) ;
 u [ 2 ] = _mm_srai_epi32 ( v [ 2 ] , DCT_CONST_BITS ) ;
 u [ 3 ] = _mm_srai_epi32 ( v [ 3 ] , DCT_CONST_BITS ) ;
 u [ 4 ] = _mm_srai_epi32 ( v [ 4 ] , DCT_CONST_BITS ) ;
 u [ 5 ] = _mm_srai_epi32 ( v [ 5 ] , DCT_CONST_BITS ) ;
 u [ 6 ] = _mm_srai_epi32 ( v [ 6 ] , DCT_CONST_BITS ) ;
 u [ 7 ] = _mm_srai_epi32 ( v [ 7 ] , DCT_CONST_BITS ) ;
 u [ 8 ] = _mm_srai_epi32 ( v [ 8 ] , DCT_CONST_BITS ) ;
 u [ 9 ] = _mm_srai_epi32 ( v [ 9 ] , DCT_CONST_BITS ) ;
 u [ 10 ] = _mm_srai_epi32 ( v [ 10 ] , DCT_CONST_BITS ) ;
 u [ 11 ] = _mm_srai_epi32 ( v [ 11 ] , DCT_CONST_BITS ) ;
 u [ 12 ] = _mm_srai_epi32 ( v [ 12 ] , DCT_CONST_BITS ) ;
 u [ 13 ] = _mm_srai_epi32 ( v [ 13 ] , DCT_CONST_BITS ) ;
 u [ 14 ] = _mm_srai_epi32 ( v [ 14 ] , DCT_CONST_BITS ) ;
 u [ 15 ] = _mm_srai_epi32 ( v [ 15 ] , DCT_CONST_BITS ) ;
 u [ 16 ] = _mm_srai_epi32 ( v [ 16 ] , DCT_CONST_BITS ) ;
 u [ 17 ] = _mm_srai_epi32 ( v [ 17 ] , DCT_CONST_BITS ) ;
 u [ 18 ] = _mm_srai_epi32 ( v [ 18 ] , DCT_CONST_BITS ) ;
 u [ 19 ] = _mm_srai_epi32 ( v [ 19 ] , DCT_CONST_BITS ) ;
 u [ 20 ] = _mm_srai_epi32 ( v [ 20 ] , DCT_CONST_BITS ) ;
 u [ 21 ] = _mm_srai_epi32 ( v [ 21 ] , DCT_CONST_BITS ) ;
 u [ 22 ] = _mm_srai_epi32 ( v [ 22 ] , DCT_CONST_BITS ) ;
 u [ 23 ] = _mm_srai_epi32 ( v [ 23 ] , DCT_CONST_BITS ) ;
 u [ 24 ] = _mm_srai_epi32 ( v [ 24 ] , DCT_CONST_BITS ) ;
 u [ 25 ] = _mm_srai_epi32 ( v [ 25 ] , DCT_CONST_BITS ) ;
 u [ 26 ] = _mm_srai_epi32 ( v [ 26 ] , DCT_CONST_BITS ) ;
 u [ 27 ] = _mm_srai_epi32 ( v [ 27 ] , DCT_CONST_BITS ) ;
 u [ 28 ] = _mm_srai_epi32 ( v [ 28 ] , DCT_CONST_BITS ) ;
 u [ 29 ] = _mm_srai_epi32 ( v [ 29 ] , DCT_CONST_BITS ) ;
 u [ 30 ] = _mm_srai_epi32 ( v [ 30 ] , DCT_CONST_BITS ) ;
 u [ 31 ] = _mm_srai_epi32 ( v [ 31 ] , DCT_CONST_BITS ) ;
 s [ 0 ] = _mm_packs_epi32 ( u [ 0 ] , u [ 1 ] ) ;
 s [ 1 ] = _mm_packs_epi32 ( u [ 2 ] , u [ 3 ] ) ;
 s [ 2 ] = _mm_packs_epi32 ( u [ 4 ] , u [ 5 ] ) ;
 s [ 3 ] = _mm_packs_epi32 ( u [ 6 ] , u [ 7 ] ) ;
 s [ 4 ] = _mm_packs_epi32 ( u [ 8 ] , u [ 9 ] ) ;
 s [ 5 ] = _mm_packs_epi32 ( u [ 10 ] , u [ 11 ] ) ;
 s [ 6 ] = _mm_packs_epi32 ( u [ 12 ] , u [ 13 ] ) ;
 s [ 7 ] = _mm_packs_epi32 ( u [ 14 ] , u [ 15 ] ) ;
 s [ 8 ] = _mm_packs_epi32 ( u [ 16 ] , u [ 17 ] ) ;
 s [ 9 ] = _mm_packs_epi32 ( u [ 18 ] , u [ 19 ] ) ;
 s [ 10 ] = _mm_packs_epi32 ( u [ 20 ] , u [ 21 ] ) ;
 s [ 11 ] = _mm_packs_epi32 ( u [ 22 ] , u [ 23 ] ) ;
 s [ 12 ] = _mm_packs_epi32 ( u [ 24 ] , u [ 25 ] ) ;
 s [ 13 ] = _mm_packs_epi32 ( u [ 26 ] , u [ 27 ] ) ;
 s [ 14 ] = _mm_packs_epi32 ( u [ 28 ] , u [ 29 ] ) ;
 s [ 15 ] = _mm_packs_epi32 ( u [ 30 ] , u [ 31 ] ) ;
 u [ 0 ] = _mm_unpacklo_epi16 ( s [ 8 ] , s [ 9 ] ) ;
 u [ 1 ] = _mm_unpackhi_epi16 ( s [ 8 ] , s [ 9 ] ) ;
 u [ 2 ] = _mm_unpacklo_epi16 ( s [ 10 ] , s [ 11 ] ) ;
 u [ 3 ] = _mm_unpackhi_epi16 ( s [ 10 ] , s [ 11 ] ) ;
 u [ 4 ] = _mm_unpacklo_epi16 ( s [ 12 ] , s [ 13 ] ) ;
 u [ 5 ] = _mm_unpackhi_epi16 ( s [ 12 ] , s [ 13 ] ) ;
 u [ 6 ] = _mm_unpacklo_epi16 ( s [ 14 ] , s [ 15 ] ) ;
 u [ 7 ] = _mm_unpackhi_epi16 ( s [ 14 ] , s [ 15 ] ) ;
 v [ 0 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p04_p28 ) ;
 v [ 1 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p04_p28 ) ;
 v [ 2 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p28_m04 ) ;
 v [ 3 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p28_m04 ) ;
 v [ 4 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_p20_p12 ) ;
 v [ 5 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_p20_p12 ) ;
 v [ 6 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_p12_m20 ) ;
 v [ 7 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_p12_m20 ) ;
 v [ 8 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_m28_p04 ) ;
 v [ 9 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_m28_p04 ) ;
 v [ 10 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_p04_p28 ) ;
 v [ 11 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_p04_p28 ) ;
 v [ 12 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_m12_p20 ) ;
 v [ 13 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_m12_p20 ) ;
 v [ 14 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_p20_p12 ) ;
 v [ 15 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_p20_p12 ) ;
 u [ 0 ] = _mm_add_epi32 ( v [ 0 ] , v [ 8 ] ) ;
 u [ 1 ] = _mm_add_epi32 ( v [ 1 ] , v [ 9 ] ) ;
 u [ 2 ] = _mm_add_epi32 ( v [ 2 ] , v [ 10 ] ) ;
 u [ 3 ] = _mm_add_epi32 ( v [ 3 ] , v [ 11 ] ) ;
 u [ 4 ] = _mm_add_epi32 ( v [ 4 ] , v [ 12 ] ) ;
 u [ 5 ] = _mm_add_epi32 ( v [ 5 ] , v [ 13 ] ) ;
 u [ 6 ] = _mm_add_epi32 ( v [ 6 ] , v [ 14 ] ) ;
 u [ 7 ] = _mm_add_epi32 ( v [ 7 ] , v [ 15 ] ) ;
 u [ 8 ] = _mm_sub_epi32 ( v [ 0 ] , v [ 8 ] ) ;
 u [ 9 ] = _mm_sub_epi32 ( v [ 1 ] , v [ 9 ] ) ;
 u [ 10 ] = _mm_sub_epi32 ( v [ 2 ] , v [ 10 ] ) ;
 u [ 11 ] = _mm_sub_epi32 ( v [ 3 ] , v [ 11 ] ) ;
 u [ 12 ] = _mm_sub_epi32 ( v [ 4 ] , v [ 12 ] ) ;
 u [ 13 ] = _mm_sub_epi32 ( v [ 5 ] , v [ 13 ] ) ;
 u [ 14 ] = _mm_sub_epi32 ( v [ 6 ] , v [ 14 ] ) ;
 u [ 15 ] = _mm_sub_epi32 ( v [ 7 ] , v [ 15 ] ) ;
 v [ 0 ] = _mm_add_epi32 ( u [ 0 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 1 ] = _mm_add_epi32 ( u [ 1 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 2 ] = _mm_add_epi32 ( u [ 2 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 3 ] = _mm_add_epi32 ( u [ 3 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 4 ] = _mm_add_epi32 ( u [ 4 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 5 ] = _mm_add_epi32 ( u [ 5 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 6 ] = _mm_add_epi32 ( u [ 6 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 7 ] = _mm_add_epi32 ( u [ 7 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 8 ] = _mm_add_epi32 ( u [ 8 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 9 ] = _mm_add_epi32 ( u [ 9 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 10 ] = _mm_add_epi32 ( u [ 10 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 11 ] = _mm_add_epi32 ( u [ 11 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 12 ] = _mm_add_epi32 ( u [ 12 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 13 ] = _mm_add_epi32 ( u [ 13 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 14 ] = _mm_add_epi32 ( u [ 14 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 15 ] = _mm_add_epi32 ( u [ 15 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 0 ] = _mm_srai_epi32 ( v [ 0 ] , DCT_CONST_BITS ) ;
 u [ 1 ] = _mm_srai_epi32 ( v [ 1 ] , DCT_CONST_BITS ) ;
 u [ 2 ] = _mm_srai_epi32 ( v [ 2 ] , DCT_CONST_BITS ) ;
 u [ 3 ] = _mm_srai_epi32 ( v [ 3 ] , DCT_CONST_BITS ) ;
 u [ 4 ] = _mm_srai_epi32 ( v [ 4 ] , DCT_CONST_BITS ) ;
 u [ 5 ] = _mm_srai_epi32 ( v [ 5 ] , DCT_CONST_BITS ) ;
 u [ 6 ] = _mm_srai_epi32 ( v [ 6 ] , DCT_CONST_BITS ) ;
 u [ 7 ] = _mm_srai_epi32 ( v [ 7 ] , DCT_CONST_BITS ) ;
 u [ 8 ] = _mm_srai_epi32 ( v [ 8 ] , DCT_CONST_BITS ) ;
 u [ 9 ] = _mm_srai_epi32 ( v [ 9 ] , DCT_CONST_BITS ) ;
 u [ 10 ] = _mm_srai_epi32 ( v [ 10 ] , DCT_CONST_BITS ) ;
 u [ 11 ] = _mm_srai_epi32 ( v [ 11 ] , DCT_CONST_BITS ) ;
 u [ 12 ] = _mm_srai_epi32 ( v [ 12 ] , DCT_CONST_BITS ) ;
 u [ 13 ] = _mm_srai_epi32 ( v [ 13 ] , DCT_CONST_BITS ) ;
 u [ 14 ] = _mm_srai_epi32 ( v [ 14 ] , DCT_CONST_BITS ) ;
 u [ 15 ] = _mm_srai_epi32 ( v [ 15 ] , DCT_CONST_BITS ) ;
 x [ 0 ] = _mm_add_epi16 ( s [ 0 ] , s [ 4 ] ) ;
 x [ 1 ] = _mm_add_epi16 ( s [ 1 ] , s [ 5 ] ) ;
 x [ 2 ] = _mm_add_epi16 ( s [ 2 ] , s [ 6 ] ) ;
 x [ 3 ] = _mm_add_epi16 ( s [ 3 ] , s [ 7 ] ) ;
 x [ 4 ] = _mm_sub_epi16 ( s [ 0 ] , s [ 4 ] ) ;
 x [ 5 ] = _mm_sub_epi16 ( s [ 1 ] , s [ 5 ] ) ;
 x [ 6 ] = _mm_sub_epi16 ( s [ 2 ] , s [ 6 ] ) ;
 x [ 7 ] = _mm_sub_epi16 ( s [ 3 ] , s [ 7 ] ) ;
 x [ 8 ] = _mm_packs_epi32 ( u [ 0 ] , u [ 1 ] ) ;
 x [ 9 ] = _mm_packs_epi32 ( u [ 2 ] , u [ 3 ] ) ;
 x [ 10 ] = _mm_packs_epi32 ( u [ 4 ] , u [ 5 ] ) ;
 x [ 11 ] = _mm_packs_epi32 ( u [ 6 ] , u [ 7 ] ) ;
 x [ 12 ] = _mm_packs_epi32 ( u [ 8 ] , u [ 9 ] ) ;
 x [ 13 ] = _mm_packs_epi32 ( u [ 10 ] , u [ 11 ] ) ;
 x [ 14 ] = _mm_packs_epi32 ( u [ 12 ] , u [ 13 ] ) ;
 x [ 15 ] = _mm_packs_epi32 ( u [ 14 ] , u [ 15 ] ) ;
 u [ 0 ] = _mm_unpacklo_epi16 ( x [ 4 ] , x [ 5 ] ) ;
 u [ 1 ] = _mm_unpackhi_epi16 ( x [ 4 ] , x [ 5 ] ) ;
 u [ 2 ] = _mm_unpacklo_epi16 ( x [ 6 ] , x [ 7 ] ) ;
 u [ 3 ] = _mm_unpackhi_epi16 ( x [ 6 ] , x [ 7 ] ) ;
 u [ 4 ] = _mm_unpacklo_epi16 ( x [ 12 ] , x [ 13 ] ) ;
 u [ 5 ] = _mm_unpackhi_epi16 ( x [ 12 ] , x [ 13 ] ) ;
 u [ 6 ] = _mm_unpacklo_epi16 ( x [ 14 ] , x [ 15 ] ) ;
 u [ 7 ] = _mm_unpackhi_epi16 ( x [ 14 ] , x [ 15 ] ) ;
 v [ 0 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p08_p24 ) ;
 v [ 1 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p08_p24 ) ;
 v [ 2 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p24_m08 ) ;
 v [ 3 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p24_m08 ) ;
 v [ 4 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_m24_p08 ) ;
 v [ 5 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_m24_p08 ) ;
 v [ 6 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_p08_p24 ) ;
 v [ 7 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_p08_p24 ) ;
 v [ 8 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_p08_p24 ) ;
 v [ 9 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_p08_p24 ) ;
 v [ 10 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_p24_m08 ) ;
 v [ 11 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_p24_m08 ) ;
 v [ 12 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_m24_p08 ) ;
 v [ 13 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_m24_p08 ) ;
 v [ 14 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_p08_p24 ) ;
 v [ 15 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_p08_p24 ) ;
 u [ 0 ] = _mm_add_epi32 ( v [ 0 ] , v [ 4 ] ) ;
 u [ 1 ] = _mm_add_epi32 ( v [ 1 ] , v [ 5 ] ) ;
 u [ 2 ] = _mm_add_epi32 ( v [ 2 ] , v [ 6 ] ) ;
 u [ 3 ] = _mm_add_epi32 ( v [ 3 ] , v [ 7 ] ) ;
 u [ 4 ] = _mm_sub_epi32 ( v [ 0 ] , v [ 4 ] ) ;
 u [ 5 ] = _mm_sub_epi32 ( v [ 1 ] , v [ 5 ] ) ;
 u [ 6 ] = _mm_sub_epi32 ( v [ 2 ] , v [ 6 ] ) ;
 u [ 7 ] = _mm_sub_epi32 ( v [ 3 ] , v [ 7 ] ) ;
 u [ 8 ] = _mm_add_epi32 ( v [ 8 ] , v [ 12 ] ) ;
 u [ 9 ] = _mm_add_epi32 ( v [ 9 ] , v [ 13 ] ) ;
 u [ 10 ] = _mm_add_epi32 ( v [ 10 ] , v [ 14 ] ) ;
 u [ 11 ] = _mm_add_epi32 ( v [ 11 ] , v [ 15 ] ) ;
 u [ 12 ] = _mm_sub_epi32 ( v [ 8 ] , v [ 12 ] ) ;
 u [ 13 ] = _mm_sub_epi32 ( v [ 9 ] , v [ 13 ] ) ;
 u [ 14 ] = _mm_sub_epi32 ( v [ 10 ] , v [ 14 ] ) ;
 u [ 15 ] = _mm_sub_epi32 ( v [ 11 ] , v [ 15 ] ) ;
 u [ 0 ] = _mm_add_epi32 ( u [ 0 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 1 ] = _mm_add_epi32 ( u [ 1 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 2 ] = _mm_add_epi32 ( u [ 2 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 3 ] = _mm_add_epi32 ( u [ 3 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 4 ] = _mm_add_epi32 ( u [ 4 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 5 ] = _mm_add_epi32 ( u [ 5 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 6 ] = _mm_add_epi32 ( u [ 6 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 7 ] = _mm_add_epi32 ( u [ 7 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 8 ] = _mm_add_epi32 ( u [ 8 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 9 ] = _mm_add_epi32 ( u [ 9 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 10 ] = _mm_add_epi32 ( u [ 10 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 11 ] = _mm_add_epi32 ( u [ 11 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 12 ] = _mm_add_epi32 ( u [ 12 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 13 ] = _mm_add_epi32 ( u [ 13 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 14 ] = _mm_add_epi32 ( u [ 14 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 15 ] = _mm_add_epi32 ( u [ 15 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 0 ] = _mm_srai_epi32 ( u [ 0 ] , DCT_CONST_BITS ) ;
 v [ 1 ] = _mm_srai_epi32 ( u [ 1 ] , DCT_CONST_BITS ) ;
 v [ 2 ] = _mm_srai_epi32 ( u [ 2 ] , DCT_CONST_BITS ) ;
 v [ 3 ] = _mm_srai_epi32 ( u [ 3 ] , DCT_CONST_BITS ) ;
 v [ 4 ] = _mm_srai_epi32 ( u [ 4 ] , DCT_CONST_BITS ) ;
 v [ 5 ] = _mm_srai_epi32 ( u [ 5 ] , DCT_CONST_BITS ) ;
 v [ 6 ] = _mm_srai_epi32 ( u [ 6 ] , DCT_CONST_BITS ) ;
 v [ 7 ] = _mm_srai_epi32 ( u [ 7 ] , DCT_CONST_BITS ) ;
 v [ 8 ] = _mm_srai_epi32 ( u [ 8 ] , DCT_CONST_BITS ) ;
 v [ 9 ] = _mm_srai_epi32 ( u [ 9 ] , DCT_CONST_BITS ) ;
 v [ 10 ] = _mm_srai_epi32 ( u [ 10 ] , DCT_CONST_BITS ) ;
 v [ 11 ] = _mm_srai_epi32 ( u [ 11 ] , DCT_CONST_BITS ) ;
 v [ 12 ] = _mm_srai_epi32 ( u [ 12 ] , DCT_CONST_BITS ) ;
 v [ 13 ] = _mm_srai_epi32 ( u [ 13 ] , DCT_CONST_BITS ) ;
 v [ 14 ] = _mm_srai_epi32 ( u [ 14 ] , DCT_CONST_BITS ) ;
 v [ 15 ] = _mm_srai_epi32 ( u [ 15 ] , DCT_CONST_BITS ) ;
 s [ 0 ] = _mm_add_epi16 ( x [ 0 ] , x [ 2 ] ) ;
 s [ 1 ] = _mm_add_epi16 ( x [ 1 ] , x [ 3 ] ) ;
 s [ 2 ] = _mm_sub_epi16 ( x [ 0 ] , x [ 2 ] ) ;
 s [ 3 ] = _mm_sub_epi16 ( x [ 1 ] , x [ 3 ] ) ;
 s [ 4 ] = _mm_packs_epi32 ( v [ 0 ] , v [ 1 ] ) ;
 s [ 5 ] = _mm_packs_epi32 ( v [ 2 ] , v [ 3 ] ) ;
 s [ 6 ] = _mm_packs_epi32 ( v [ 4 ] , v [ 5 ] ) ;
 s [ 7 ] = _mm_packs_epi32 ( v [ 6 ] , v [ 7 ] ) ;
 s [ 8 ] = _mm_add_epi16 ( x [ 8 ] , x [ 10 ] ) ;
 s [ 9 ] = _mm_add_epi16 ( x [ 9 ] , x [ 11 ] ) ;
 s [ 10 ] = _mm_sub_epi16 ( x [ 8 ] , x [ 10 ] ) ;
 s [ 11 ] = _mm_sub_epi16 ( x [ 9 ] , x [ 11 ] ) ;
 s [ 12 ] = _mm_packs_epi32 ( v [ 8 ] , v [ 9 ] ) ;
 s [ 13 ] = _mm_packs_epi32 ( v [ 10 ] , v [ 11 ] ) ;
 s [ 14 ] = _mm_packs_epi32 ( v [ 12 ] , v [ 13 ] ) ;
 s [ 15 ] = _mm_packs_epi32 ( v [ 14 ] , v [ 15 ] ) ;
 u [ 0 ] = _mm_unpacklo_epi16 ( s [ 2 ] , s [ 3 ] ) ;
 u [ 1 ] = _mm_unpackhi_epi16 ( s [ 2 ] , s [ 3 ] ) ;
 u [ 2 ] = _mm_unpacklo_epi16 ( s [ 6 ] , s [ 7 ] ) ;
 u [ 3 ] = _mm_unpackhi_epi16 ( s [ 6 ] , s [ 7 ] ) ;
 u [ 4 ] = _mm_unpacklo_epi16 ( s [ 10 ] , s [ 11 ] ) ;
 u [ 5 ] = _mm_unpackhi_epi16 ( s [ 10 ] , s [ 11 ] ) ;
 u [ 6 ] = _mm_unpacklo_epi16 ( s [ 14 ] , s [ 15 ] ) ;
 u [ 7 ] = _mm_unpackhi_epi16 ( s [ 14 ] , s [ 15 ] ) ;
 v [ 0 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_m16_m16 ) ;
 v [ 1 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_m16_m16 ) ;
 v [ 2 ] = _mm_madd_epi16 ( u [ 0 ] , k__cospi_p16_m16 ) ;
 v [ 3 ] = _mm_madd_epi16 ( u [ 1 ] , k__cospi_p16_m16 ) ;
 v [ 4 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_p16_p16 ) ;
 v [ 5 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_p16_p16 ) ;
 v [ 6 ] = _mm_madd_epi16 ( u [ 2 ] , k__cospi_m16_p16 ) ;
 v [ 7 ] = _mm_madd_epi16 ( u [ 3 ] , k__cospi_m16_p16 ) ;
 v [ 8 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_p16_p16 ) ;
 v [ 9 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_p16_p16 ) ;
 v [ 10 ] = _mm_madd_epi16 ( u [ 4 ] , k__cospi_m16_p16 ) ;
 v [ 11 ] = _mm_madd_epi16 ( u [ 5 ] , k__cospi_m16_p16 ) ;
 v [ 12 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_m16_m16 ) ;
 v [ 13 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_m16_m16 ) ;
 v [ 14 ] = _mm_madd_epi16 ( u [ 6 ] , k__cospi_p16_m16 ) ;
 v [ 15 ] = _mm_madd_epi16 ( u [ 7 ] , k__cospi_p16_m16 ) ;
 u [ 0 ] = _mm_add_epi32 ( v [ 0 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 1 ] = _mm_add_epi32 ( v [ 1 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 2 ] = _mm_add_epi32 ( v [ 2 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 3 ] = _mm_add_epi32 ( v [ 3 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 4 ] = _mm_add_epi32 ( v [ 4 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 5 ] = _mm_add_epi32 ( v [ 5 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 6 ] = _mm_add_epi32 ( v [ 6 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 7 ] = _mm_add_epi32 ( v [ 7 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 8 ] = _mm_add_epi32 ( v [ 8 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 9 ] = _mm_add_epi32 ( v [ 9 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 10 ] = _mm_add_epi32 ( v [ 10 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 11 ] = _mm_add_epi32 ( v [ 11 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 12 ] = _mm_add_epi32 ( v [ 12 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 13 ] = _mm_add_epi32 ( v [ 13 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 14 ] = _mm_add_epi32 ( v [ 14 ] , k__DCT_CONST_ROUNDING ) ;
 u [ 15 ] = _mm_add_epi32 ( v [ 15 ] , k__DCT_CONST_ROUNDING ) ;
 v [ 0 ] = _mm_srai_epi32 ( u [ 0 ] , DCT_CONST_BITS ) ;
 v [ 1 ] = _mm_srai_epi32 ( u [ 1 ] , DCT_CONST_BITS ) ;
 v [ 2 ] = _mm_srai_epi32 ( u [ 2 ] , DCT_CONST_BITS ) ;
 v [ 3 ] = _mm_srai_epi32 ( u [ 3 ] , DCT_CONST_BITS ) ;
 v [ 4 ] = _mm_srai_epi32 ( u [ 4 ] , DCT_CONST_BITS ) ;
 v [ 5 ] = _mm_srai_epi32 ( u [ 5 ] , DCT_CONST_BITS ) ;
 v [ 6 ] = _mm_srai_epi32 ( u [ 6 ] , DCT_CONST_BITS ) ;
 v [ 7 ] = _mm_srai_epi32 ( u [ 7 ] , DCT_CONST_BITS ) ;
 v [ 8 ] = _mm_srai_epi32 ( u [ 8 ] , DCT_CONST_BITS ) ;
 v [ 9 ] = _mm_srai_epi32 ( u [ 9 ] , DCT_CONST_BITS ) ;
 v [ 10 ] = _mm_srai_epi32 ( u [ 10 ] , DCT_CONST_BITS ) ;
 v [ 11 ] = _mm_srai_epi32 ( u [ 11 ] , DCT_CONST_BITS ) ;
 v [ 12 ] = _mm_srai_epi32 ( u [ 12 ] , DCT_CONST_BITS ) ;
 v [ 13 ] = _mm_srai_epi32 ( u [ 13 ] , DCT_CONST_BITS ) ;
 v [ 14 ] = _mm_srai_epi32 ( u [ 14 ] , DCT_CONST_BITS ) ;
 v [ 15 ] = _mm_srai_epi32 ( u [ 15 ] , DCT_CONST_BITS ) ;
 in [ 0 ] = s [ 0 ] ;
 in [ 1 ] = _mm_sub_epi16 ( kZero , s [ 8 ] ) ;
 in [ 2 ] = s [ 12 ] ;
 in [ 3 ] = _mm_sub_epi16 ( kZero , s [ 4 ] ) ;
 in [ 4 ] = _mm_packs_epi32 ( v [ 4 ] , v [ 5 ] ) ;
 in [ 5 ] = _mm_packs_epi32 ( v [ 12 ] , v [ 13 ] ) ;
 in [ 6 ] = _mm_packs_epi32 ( v [ 8 ] , v [ 9 ] ) ;
 in [ 7 ] = _mm_packs_epi32 ( v [ 0 ] , v [ 1 ] ) ;
 in [ 8 ] = _mm_packs_epi32 ( v [ 2 ] , v [ 3 ] ) ;
 in [ 9 ] = _mm_packs_epi32 ( v [ 10 ] , v [ 11 ] ) ;
 in [ 10 ] = _mm_packs_epi32 ( v [ 14 ] , v [ 15 ] ) ;
 in [ 11 ] = _mm_packs_epi32 ( v [ 6 ] , v [ 7 ] ) ;
 in [ 12 ] = s [ 5 ] ;
 in [ 13 ] = _mm_sub_epi16 ( kZero , s [ 13 ] ) ;
 in [ 14 ] = s [ 9 ] ;
 in [ 15 ] = _mm_sub_epi16 ( kZero , s [ 1 ] ) ;
 }
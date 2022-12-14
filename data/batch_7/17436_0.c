void vp9_iht8x8_64_add_sse2 ( const int16_t * input , uint8_t * dest , int stride , int tx_type ) {
 __m128i in [ 8 ] ;
 const __m128i zero = _mm_setzero_si128 ( ) ;
 const __m128i final_rounding = _mm_set1_epi16 ( 1 << 4 ) ;
 in [ 0 ] = _mm_load_si128 ( ( const __m128i * ) input ) ;
 in [ 1 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 1 ) ) ;
 in [ 2 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 2 ) ) ;
 in [ 3 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 3 ) ) ;
 in [ 4 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 4 ) ) ;
 in [ 5 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 5 ) ) ;
 in [ 6 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 6 ) ) ;
 in [ 7 ] = _mm_load_si128 ( ( const __m128i * ) ( input + 8 * 7 ) ) ;
 switch ( tx_type ) {
 case 0 : idct8_sse2 ( in ) ;
 idct8_sse2 ( in ) ;
 break ;
 case 1 : idct8_sse2 ( in ) ;
 iadst8_sse2 ( in ) ;
 break ;
 case 2 : iadst8_sse2 ( in ) ;
 idct8_sse2 ( in ) ;
 break ;
 case 3 : iadst8_sse2 ( in ) ;
 iadst8_sse2 ( in ) ;
 break ;
 default : assert ( 0 ) ;
 break ;
 }
 in [ 0 ] = _mm_adds_epi16 ( in [ 0 ] , final_rounding ) ;
 in [ 1 ] = _mm_adds_epi16 ( in [ 1 ] , final_rounding ) ;
 in [ 2 ] = _mm_adds_epi16 ( in [ 2 ] , final_rounding ) ;
 in [ 3 ] = _mm_adds_epi16 ( in [ 3 ] , final_rounding ) ;
 in [ 4 ] = _mm_adds_epi16 ( in [ 4 ] , final_rounding ) ;
 in [ 5 ] = _mm_adds_epi16 ( in [ 5 ] , final_rounding ) ;
 in [ 6 ] = _mm_adds_epi16 ( in [ 6 ] , final_rounding ) ;
 in [ 7 ] = _mm_adds_epi16 ( in [ 7 ] , final_rounding ) ;
 in [ 0 ] = _mm_srai_epi16 ( in [ 0 ] , 5 ) ;
 in [ 1 ] = _mm_srai_epi16 ( in [ 1 ] , 5 ) ;
 in [ 2 ] = _mm_srai_epi16 ( in [ 2 ] , 5 ) ;
 in [ 3 ] = _mm_srai_epi16 ( in [ 3 ] , 5 ) ;
 in [ 4 ] = _mm_srai_epi16 ( in [ 4 ] , 5 ) ;
 in [ 5 ] = _mm_srai_epi16 ( in [ 5 ] , 5 ) ;
 in [ 6 ] = _mm_srai_epi16 ( in [ 6 ] , 5 ) ;
 in [ 7 ] = _mm_srai_epi16 ( in [ 7 ] , 5 ) ;
 RECON_AND_STORE ( dest , in [ 0 ] ) ;
 RECON_AND_STORE ( dest , in [ 1 ] ) ;
 RECON_AND_STORE ( dest , in [ 2 ] ) ;
 RECON_AND_STORE ( dest , in [ 3 ] ) ;
 RECON_AND_STORE ( dest , in [ 4 ] ) ;
 RECON_AND_STORE ( dest , in [ 5 ] ) ;
 RECON_AND_STORE ( dest , in [ 6 ] ) ;
 RECON_AND_STORE ( dest , in [ 7 ] ) ;
 }
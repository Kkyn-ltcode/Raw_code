static void read_sbr_envelope ( SpectralBandReplication * sbr , GetBitContext * gb , SBRData * ch_data , int ch ) {
 int bits ;
 int i , j , k ;
 VLC_TYPE ( * t_huff ) [ 2 ] , ( * f_huff ) [ 2 ] ;
 int t_lav , f_lav ;
 const int delta = ( ch == 1 && sbr -> bs_coupling == 1 ) + 1 ;
 const int odd = sbr -> n [ 1 ] & 1 ;
 if ( sbr -> bs_coupling && ch ) {
 if ( ch_data -> bs_amp_res ) {
 bits = 5 ;
 t_huff = vlc_sbr [ T_HUFFMAN_ENV_BAL_3_0DB ] . table ;
 t_lav = vlc_sbr_lav [ T_HUFFMAN_ENV_BAL_3_0DB ] ;
 f_huff = vlc_sbr [ F_HUFFMAN_ENV_BAL_3_0DB ] . table ;
 f_lav = vlc_sbr_lav [ F_HUFFMAN_ENV_BAL_3_0DB ] ;
 }
 else {
 bits = 6 ;
 t_huff = vlc_sbr [ T_HUFFMAN_ENV_BAL_1_5DB ] . table ;
 t_lav = vlc_sbr_lav [ T_HUFFMAN_ENV_BAL_1_5DB ] ;
 f_huff = vlc_sbr [ F_HUFFMAN_ENV_BAL_1_5DB ] . table ;
 f_lav = vlc_sbr_lav [ F_HUFFMAN_ENV_BAL_1_5DB ] ;
 }
 }
 else {
 if ( ch_data -> bs_amp_res ) {
 bits = 6 ;
 t_huff = vlc_sbr [ T_HUFFMAN_ENV_3_0DB ] . table ;
 t_lav = vlc_sbr_lav [ T_HUFFMAN_ENV_3_0DB ] ;
 f_huff = vlc_sbr [ F_HUFFMAN_ENV_3_0DB ] . table ;
 f_lav = vlc_sbr_lav [ F_HUFFMAN_ENV_3_0DB ] ;
 }
 else {
 bits = 7 ;
 t_huff = vlc_sbr [ T_HUFFMAN_ENV_1_5DB ] . table ;
 t_lav = vlc_sbr_lav [ T_HUFFMAN_ENV_1_5DB ] ;
 f_huff = vlc_sbr [ F_HUFFMAN_ENV_1_5DB ] . table ;
 f_lav = vlc_sbr_lav [ F_HUFFMAN_ENV_1_5DB ] ;
 }
 }
 for ( i = 0 ;
 i < ch_data -> bs_num_env ;
 i ++ ) {
 if ( ch_data -> bs_df_env [ i ] ) {
 if ( ch_data -> bs_freq_res [ i + 1 ] == ch_data -> bs_freq_res [ i ] ) {
 for ( j = 0 ;
 j < sbr -> n [ ch_data -> bs_freq_res [ i + 1 ] ] ;
 j ++ ) ch_data -> env_facs [ i + 1 ] [ j ] = ch_data -> env_facs [ i ] [ j ] + delta * ( get_vlc2 ( gb , t_huff , 9 , 3 ) - t_lav ) ;
 }
 else if ( ch_data -> bs_freq_res [ i + 1 ] ) {
 for ( j = 0 ;
 j < sbr -> n [ ch_data -> bs_freq_res [ i + 1 ] ] ;
 j ++ ) {
 k = ( j + odd ) >> 1 ;
 ch_data -> env_facs [ i + 1 ] [ j ] = ch_data -> env_facs [ i ] [ k ] + delta * ( get_vlc2 ( gb , t_huff , 9 , 3 ) - t_lav ) ;
 }
 }
 else {
 for ( j = 0 ;
 j < sbr -> n [ ch_data -> bs_freq_res [ i + 1 ] ] ;
 j ++ ) {
 k = j ? 2 * j - odd : 0 ;
 ch_data -> env_facs [ i + 1 ] [ j ] = ch_data -> env_facs [ i ] [ k ] + delta * ( get_vlc2 ( gb , t_huff , 9 , 3 ) - t_lav ) ;
 }
 }
 }
 else {
 ch_data -> env_facs [ i + 1 ] [ 0 ] = delta * get_bits ( gb , bits ) ;
 for ( j = 1 ;
 j < sbr -> n [ ch_data -> bs_freq_res [ i + 1 ] ] ;
 j ++ ) ch_data -> env_facs [ i + 1 ] [ j ] = ch_data -> env_facs [ i + 1 ] [ j - 1 ] + delta * ( get_vlc2 ( gb , f_huff , 9 , 3 ) - f_lav ) ;
 }
 }
 memcpy ( ch_data -> env_facs [ 0 ] , ch_data -> env_facs [ ch_data -> bs_num_env ] , sizeof ( ch_data -> env_facs [ 0 ] ) ) ;
 }
static unsigned int read_sbr_data ( AACContext * ac , SpectralBandReplication * sbr , GetBitContext * gb , int id_aac ) {
 unsigned int cnt = get_bits_count ( gb ) ;
 sbr -> id_aac = id_aac ;
 if ( id_aac == TYPE_SCE || id_aac == TYPE_CCE ) {
 if ( read_sbr_single_channel_element ( ac , sbr , gb ) ) {
 sbr_turnoff ( sbr ) ;
 return get_bits_count ( gb ) - cnt ;
 }
 }
 else if ( id_aac == TYPE_CPE ) {
 if ( read_sbr_channel_pair_element ( ac , sbr , gb ) ) {
 sbr_turnoff ( sbr ) ;
 return get_bits_count ( gb ) - cnt ;
 }
 }
 else {
 av_log ( ac -> avctx , AV_LOG_ERROR , "Invalid bitstream - cannot apply SBR to element type %d\n" , id_aac ) ;
 sbr_turnoff ( sbr ) ;
 return get_bits_count ( gb ) - cnt ;
 }
 if ( get_bits1 ( gb ) ) {
 int num_bits_left = get_bits ( gb , 4 ) ;
 if ( num_bits_left == 15 ) num_bits_left += get_bits ( gb , 8 ) ;
 num_bits_left <<= 3 ;
 while ( num_bits_left > 7 ) {
 num_bits_left -= 2 ;
 read_sbr_extension ( ac , sbr , gb , get_bits ( gb , 2 ) , & num_bits_left ) ;
 }
 if ( num_bits_left < 0 ) {
 av_log ( ac -> avctx , AV_LOG_ERROR , "SBR Extension over read.\n" ) ;
 }
 if ( num_bits_left > 0 ) skip_bits ( gb , num_bits_left ) ;
 }
 return get_bits_count ( gb ) - cnt ;
 }
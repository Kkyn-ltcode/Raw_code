static int read_restart_header ( MLPDecodeContext * m , GetBitContext * gbp , const uint8_t * buf , unsigned int substr ) {
 SubStream * s = & m -> substream [ substr ] ;
 unsigned int ch ;
 int sync_word , tmp ;
 uint8_t checksum ;
 uint8_t lossless_check ;
 int start_count = get_bits_count ( gbp ) ;
 const int max_matrix_channel = m -> avctx -> codec_id == AV_CODEC_ID_MLP ? MAX_MATRIX_CHANNEL_MLP : MAX_MATRIX_CHANNEL_TRUEHD ;
 sync_word = get_bits ( gbp , 13 ) ;
 if ( sync_word != 0x31ea >> 1 ) {
 av_log ( m -> avctx , AV_LOG_ERROR , "restart header sync incorrect (got 0x%04x)\n" , sync_word ) ;
 return AVERROR_INVALIDDATA ;
 }
 s -> noise_type = get_bits1 ( gbp ) ;
 if ( m -> avctx -> codec_id == AV_CODEC_ID_MLP && s -> noise_type ) {
 av_log ( m -> avctx , AV_LOG_ERROR , "MLP must have 0x31ea sync word.\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 skip_bits ( gbp , 16 ) ;
 s -> min_channel = get_bits ( gbp , 4 ) ;
 s -> max_channel = get_bits ( gbp , 4 ) ;
 s -> max_matrix_channel = get_bits ( gbp , 4 ) ;
 if ( s -> max_matrix_channel > max_matrix_channel ) {
 av_log ( m -> avctx , AV_LOG_ERROR , "Max matrix channel cannot be greater than %d.\n" , max_matrix_channel ) ;
 return AVERROR_INVALIDDATA ;
 }
 if ( s -> max_channel != s -> max_matrix_channel ) {
 av_log ( m -> avctx , AV_LOG_ERROR , "Max channel must be equal max matrix channel.\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 if ( s -> max_channel > MAX_MATRIX_CHANNEL_MLP && ! s -> noise_type ) {
 av_log_ask_for_sample ( m -> avctx , "Number of channels %d is larger than the maximum supported " "by the decoder.\n" , s -> max_channel + 2 ) ;
 return AVERROR_PATCHWELCOME ;
 }
 if ( s -> min_channel > s -> max_channel ) {
 av_log ( m -> avctx , AV_LOG_ERROR , "Substream min channel cannot be greater than max channel.\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 # if FF_API_REQUEST_CHANNELS if ( m -> avctx -> request_channels > 0 && m -> avctx -> request_channels <= s -> max_channel + 1 && m -> max_decoded_substream > substr ) {
 av_log ( m -> avctx , AV_LOG_DEBUG , "Extracting %d-channel downmix from substream %d. " "Further substreams will be skipped.\n" , s -> max_channel + 1 , substr ) ;
 m -> max_decoded_substream = substr ;
 }
 else # endif if ( m -> avctx -> request_channel_layout == s -> ch_layout && m -> max_decoded_substream > substr ) {
 av_log ( m -> avctx , AV_LOG_DEBUG , "Extracting %d-channel downmix (0x%" PRIx64 ") from substream %d. " "Further substreams will be skipped.\n" , s -> max_channel + 1 , s -> ch_layout , substr ) ;
 m -> max_decoded_substream = substr ;
 }
 s -> noise_shift = get_bits ( gbp , 4 ) ;
 s -> noisegen_seed = get_bits ( gbp , 23 ) ;
 skip_bits ( gbp , 19 ) ;
 s -> data_check_present = get_bits1 ( gbp ) ;
 lossless_check = get_bits ( gbp , 8 ) ;
 if ( substr == m -> max_decoded_substream && s -> lossless_check_data != 0xffffffff ) {
 tmp = xor_32_to_8 ( s -> lossless_check_data ) ;
 if ( tmp != lossless_check ) av_log ( m -> avctx , AV_LOG_WARNING , "Lossless check failed - expected %02x, calculated %02x.\n" , lossless_check , tmp ) ;
 }
 skip_bits ( gbp , 16 ) ;
 memset ( s -> ch_assign , 0 , sizeof ( s -> ch_assign ) ) ;
 for ( ch = 0 ;
 ch <= s -> max_matrix_channel ;
 ch ++ ) {
 int ch_assign = get_bits ( gbp , 6 ) ;
 if ( m -> avctx -> codec_id == AV_CODEC_ID_TRUEHD ) {
 uint64_t channel = thd_channel_layout_extract_channel ( s -> ch_layout , ch_assign ) ;
 ch_assign = av_get_channel_layout_channel_index ( s -> ch_layout , channel ) ;
 }
 if ( ch_assign > s -> max_matrix_channel ) {
 av_log_ask_for_sample ( m -> avctx , "Assignment of matrix channel %d to invalid output channel %d.\n" , ch , ch_assign ) ;
 return AVERROR_PATCHWELCOME ;
 }
 s -> ch_assign [ ch_assign ] = ch ;
 }
 checksum = ff_mlp_restart_checksum ( buf , get_bits_count ( gbp ) - start_count ) ;
 if ( checksum != get_bits ( gbp , 8 ) ) av_log ( m -> avctx , AV_LOG_ERROR , "restart header checksum error\n" ) ;
 s -> param_presence_flags = 0xff ;
 s -> num_primitive_matrices = 0 ;
 s -> blocksize = 8 ;
 s -> lossless_check_data = 0 ;
 memset ( s -> output_shift , 0 , sizeof ( s -> output_shift ) ) ;
 memset ( s -> quant_step_size , 0 , sizeof ( s -> quant_step_size ) ) ;
 for ( ch = s -> min_channel ;
 ch <= s -> max_channel ;
 ch ++ ) {
 ChannelParams * cp = & s -> channel_params [ ch ] ;
 cp -> filter_params [ FIR ] . order = 0 ;
 cp -> filter_params [ IIR ] . order = 0 ;
 cp -> filter_params [ FIR ] . shift = 0 ;
 cp -> filter_params [ IIR ] . shift = 0 ;
 cp -> huff_offset = 0 ;
 cp -> sign_huff_offset = ( - 1 ) << 23 ;
 cp -> codebook = 0 ;
 cp -> huff_lsbs = 24 ;
 }
 if ( substr == m -> max_decoded_substream ) {
 m -> avctx -> channels = s -> max_matrix_channel + 1 ;
 m -> avctx -> channel_layout = s -> ch_layout ;
 }
 return 0 ;
 }
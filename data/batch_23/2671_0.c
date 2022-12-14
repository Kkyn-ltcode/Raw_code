static int decode_subframe_length ( WMAProDecodeCtx * s , int offset ) {
 int frame_len_shift = 0 ;
 int subframe_len ;
 if ( offset == s -> samples_per_frame - s -> min_samples_per_subframe ) return s -> min_samples_per_subframe ;
 if ( s -> max_subframe_len_bit ) {
 if ( get_bits1 ( & s -> gb ) ) frame_len_shift = 1 + get_bits ( & s -> gb , s -> subframe_len_bits - 1 ) ;
 }
 else frame_len_shift = get_bits ( & s -> gb , s -> subframe_len_bits ) ;
 subframe_len = s -> samples_per_frame >> frame_len_shift ;
 if ( subframe_len < s -> min_samples_per_subframe || subframe_len > s -> samples_per_frame ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "broken frame: subframe_len %i\n" , subframe_len ) ;
 return AVERROR_INVALIDDATA ;
 }
 return subframe_len ;
 }
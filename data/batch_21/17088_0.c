static void set_segment_data ( VP8_COMP * cpi , signed char * feature_data , unsigned char abs_delta ) {
 cpi -> mb . e_mbd . mb_segement_abs_delta = abs_delta ;
 vpx_memcpy ( cpi -> segment_feature_data , feature_data , sizeof ( cpi -> segment_feature_data ) ) ;
 }
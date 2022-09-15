static void srtp_calc_aead_iv ( srtp_stream_ctx_t * stream , v128_t * iv , xtd_seq_num_t * seq , srtp_hdr_t * hdr ) {
 v128_t in ;
 v128_t salt ;
 # ifdef NO_64BIT_MATH uint32_t local_roc = ( ( high32 ( * seq ) << 16 ) | ( low32 ( * seq ) >> 16 ) ) ;
 uint16_t local_seq = ( uint16_t ) ( low32 ( * seq ) ) ;
 # else uint32_t local_roc = ( uint32_t ) ( * seq >> 16 ) ;
 uint16_t local_seq = ( uint16_t ) * seq ;
 # endif memset ( & in , 0 , sizeof ( v128_t ) ) ;
 memset ( & salt , 0 , sizeof ( v128_t ) ) ;
 in . v16 [ 5 ] = htons ( local_seq ) ;
 local_roc = htonl ( local_roc ) ;
 memcpy ( & in . v16 [ 3 ] , & local_roc , sizeof ( local_roc ) ) ;
 memcpy ( & in . v8 [ 2 ] , & hdr -> ssrc , 4 ) ;
 debug_print ( mod_srtp , "Pre-salted RTP IV = %s\n" , v128_hex_string ( & in ) ) ;
 memcpy ( salt . v8 , stream -> salt , SRTP_AEAD_SALT_LEN ) ;
 debug_print ( mod_srtp , "RTP SALT = %s\n" , v128_hex_string ( & salt ) ) ;
 v128_xor ( iv , & in , & salt ) ;
 }
static void encode_seq_header ( VC2EncContext * s ) {
 avpriv_align_put_bits ( & s -> pb ) ;
 encode_parse_params ( s ) ;
 put_vc2_ue_uint ( & s -> pb , s -> base_vf ) ;
 encode_source_params ( s ) ;
 put_vc2_ue_uint ( & s -> pb , s -> interlaced ) ;
 }
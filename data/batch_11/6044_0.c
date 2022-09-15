static void encode_parse_info ( VC2EncContext * s , enum DiracParseCodes pcode ) {
 uint32_t cur_pos , dist ;
 avpriv_align_put_bits ( & s -> pb ) ;
 cur_pos = put_bits_count ( & s -> pb ) >> 3 ;
 avpriv_put_string ( & s -> pb , "BBCD" , 0 ) ;
 put_bits ( & s -> pb , 8 , pcode ) ;
 dist = cur_pos - s -> next_parse_offset ;
 AV_WB32 ( s -> pb . buf + s -> next_parse_offset + 5 , dist ) ;
 s -> next_parse_offset = cur_pos ;
 put_bits32 ( & s -> pb , pcode == DIRAC_PCODE_END_SEQ ? 13 : 0 ) ;
 put_bits32 ( & s -> pb , s -> last_parse_code == DIRAC_PCODE_END_SEQ ? 13 : dist ) ;
 s -> last_parse_code = pcode ;
 }
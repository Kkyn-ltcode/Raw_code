static void encode_scan_format ( VC2EncContext * s ) {
 put_bits ( & s -> pb , 1 , ! s -> strict_compliance ) ;
 if ( ! s -> strict_compliance ) put_vc2_ue_uint ( & s -> pb , s -> interlaced ) ;
 }
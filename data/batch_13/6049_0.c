static void encode_slice_params ( VC2EncContext * s ) {
 put_vc2_ue_uint ( & s -> pb , s -> num_x ) ;
 put_vc2_ue_uint ( & s -> pb , s -> num_y ) ;
 put_vc2_ue_uint ( & s -> pb , s -> prefix_bytes ) ;
 put_vc2_ue_uint ( & s -> pb , s -> size_scaler ) ;
 }
static int encode_slices ( VC2EncContext * s ) {
 uint8_t * buf ;
 int slice_x , slice_y , skip = 0 ;
 SliceArgs * enc_args = s -> slice_args ;
 avpriv_align_put_bits ( & s -> pb ) ;
 flush_put_bits ( & s -> pb ) ;
 buf = put_bits_ptr ( & s -> pb ) ;
 for ( slice_y = 0 ;
 slice_y < s -> num_y ;
 slice_y ++ ) {
 for ( slice_x = 0 ;
 slice_x < s -> num_x ;
 slice_x ++ ) {
 SliceArgs * args = & enc_args [ s -> num_x * slice_y + slice_x ] ;
 init_put_bits ( & args -> pb , buf + skip , args -> bytes + s -> prefix_bytes ) ;
 skip += args -> bytes ;
 }
 }
 s -> avctx -> execute ( s -> avctx , encode_hq_slice , enc_args , NULL , s -> num_x * s -> num_y , sizeof ( SliceArgs ) ) ;
 skip_put_bytes ( & s -> pb , skip ) ;
 return 0 ;
 }
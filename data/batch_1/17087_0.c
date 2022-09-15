static void generate_psnr_packet ( VP8_COMP * cpi ) {
 YV12_BUFFER_CONFIG * orig = cpi -> Source ;
 YV12_BUFFER_CONFIG * recon = cpi -> common . frame_to_show ;
 struct vpx_codec_cx_pkt pkt ;
 uint64_t sse ;
 int i ;
 unsigned int width = cpi -> common . Width ;
 unsigned int height = cpi -> common . Height ;
 pkt . kind = VPX_CODEC_PSNR_PKT ;
 sse = calc_plane_error ( orig -> y_buffer , orig -> y_stride , recon -> y_buffer , recon -> y_stride , width , height ) ;
 pkt . data . psnr . sse [ 0 ] = sse ;
 pkt . data . psnr . sse [ 1 ] = sse ;
 pkt . data . psnr . samples [ 0 ] = width * height ;
 pkt . data . psnr . samples [ 1 ] = width * height ;
 width = ( width + 1 ) / 2 ;
 height = ( height + 1 ) / 2 ;
 sse = calc_plane_error ( orig -> u_buffer , orig -> uv_stride , recon -> u_buffer , recon -> uv_stride , width , height ) ;
 pkt . data . psnr . sse [ 0 ] += sse ;
 pkt . data . psnr . sse [ 2 ] = sse ;
 pkt . data . psnr . samples [ 0 ] += width * height ;
 pkt . data . psnr . samples [ 2 ] = width * height ;
 sse = calc_plane_error ( orig -> v_buffer , orig -> uv_stride , recon -> v_buffer , recon -> uv_stride , width , height ) ;
 pkt . data . psnr . sse [ 0 ] += sse ;
 pkt . data . psnr . sse [ 3 ] = sse ;
 pkt . data . psnr . samples [ 0 ] += width * height ;
 pkt . data . psnr . samples [ 3 ] = width * height ;
 for ( i = 0 ;
 i < 4 ;
 i ++ ) pkt . data . psnr . psnr [ i ] = vpx_sse_to_psnr ( pkt . data . psnr . samples [ i ] , 255.0 , ( double ) ( pkt . data . psnr . sse [ i ] ) ) ;
 vpx_codec_pkt_list_add ( cpi -> output_pkt_list , & pkt ) ;
 }
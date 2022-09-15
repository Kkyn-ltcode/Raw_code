static int rtp_packetize_amr ( sout_stream_id_sys_t * id , block_t * in ) {
 int i_max = rtp_mtu ( id ) - 2 ;
 int i_count = ( in -> i_buffer + i_max - 1 ) / i_max ;
 uint8_t * p_data = in -> p_buffer ;
 int i_data = in -> i_buffer ;
 int i ;
 for ( i = 0 ;
 i < i_count ;
 i ++ ) {
 int i_payload = __MIN ( i_max , i_data ) ;
 block_t * out = block_Alloc ( 14 + i_payload ) ;
 rtp_packetize_common ( id , out , ( ( i == i_count - 1 ) ? 1 : 0 ) , ( in -> i_pts > VLC_TS_INVALID ? in -> i_pts : in -> i_dts ) ) ;
 out -> p_buffer [ 12 ] = 0xF0 ;
 out -> p_buffer [ 13 ] = p_data [ 0 ] & 0x7C ;
 memcpy ( & out -> p_buffer [ 14 ] , p_data + 1 , i_payload - 1 ) ;
 out -> i_buffer -- ;
 out -> i_dts = in -> i_dts + i * in -> i_length / i_count ;
 out -> i_length = in -> i_length / i_count ;
 rtp_packetize_send ( id , out ) ;
 p_data += i_payload ;
 i_data -= i_payload ;
 }
 block_Release ( in ) ;
 return VLC_SUCCESS ;
 }
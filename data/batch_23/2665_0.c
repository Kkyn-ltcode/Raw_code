static int fraps2_decode_plane ( FrapsContext * s , uint8_t * dst , int stride , int w , int h , const uint8_t * src , int size , int Uoff , const int step ) {
 int i , j , ret ;
 GetBitContext gb ;
 VLC vlc ;
 Node nodes [ 512 ] ;
 for ( i = 0 ;
 i < 256 ;
 i ++ ) nodes [ i ] . count = bytestream_get_le32 ( & src ) ;
 size -= 1024 ;
 if ( ( ret = ff_huff_build_tree ( s -> avctx , & vlc , 256 , nodes , huff_cmp , FF_HUFFMAN_FLAG_ZERO_COUNT ) ) < 0 ) return ret ;
 s -> dsp . bswap_buf ( ( uint32_t * ) s -> tmpbuf , ( const uint32_t * ) src , size >> 2 ) ;
 init_get_bits ( & gb , s -> tmpbuf , size * 8 ) ;
 for ( j = 0 ;
 j < h ;
 j ++ ) {
 for ( i = 0 ;
 i < w * step ;
 i += step ) {
 dst [ i ] = get_vlc2 ( & gb , vlc . table , 9 , 3 ) ;
 if ( j ) dst [ i ] += dst [ i - stride ] ;
 else if ( Uoff ) dst [ i ] += 0x80 ;
 if ( get_bits_left ( & gb ) < 0 ) {
 ff_free_vlc ( & vlc ) ;
 return AVERROR_INVALIDDATA ;
 }
 }
 dst += stride ;
 }
 ff_free_vlc ( & vlc ) ;
 return 0 ;
 }
static int kmvc_decode_intra_8x8 ( KmvcContext * ctx , int w , int h ) {
 BitBuf bb ;
 int res , val ;
 int i , j ;
 int bx , by ;
 int l0x , l1x , l0y , l1y ;
 int mx , my ;
 kmvc_init_getbits ( bb , & ctx -> g ) ;
 for ( by = 0 ;
 by < h ;
 by += 8 ) for ( bx = 0 ;
 bx < w ;
 bx += 8 ) {
 if ( ! bytestream2_get_bytes_left ( & ctx -> g ) ) {
 av_log ( ctx -> avctx , AV_LOG_ERROR , "Data overrun\n" ) ;
 return AVERROR_INVALIDDATA ;
 }
 kmvc_getbit ( bb , & ctx -> g , res ) ;
 if ( ! res ) {
 val = bytestream2_get_byte ( & ctx -> g ) ;
 for ( i = 0 ;
 i < 64 ;
 i ++ ) BLK ( ctx -> cur , bx + ( i & 0x7 ) , by + ( i >> 3 ) ) = val ;
 }
 else {
 for ( i = 0 ;
 i < 4 ;
 i ++ ) {
 l0x = bx + ( i & 1 ) * 4 ;
 l0y = by + ( i & 2 ) * 2 ;
 kmvc_getbit ( bb , & ctx -> g , res ) ;
 if ( ! res ) {
 kmvc_getbit ( bb , & ctx -> g , res ) ;
 if ( ! res ) {
 val = bytestream2_get_byte ( & ctx -> g ) ;
 for ( j = 0 ;
 j < 16 ;
 j ++ ) BLK ( ctx -> cur , l0x + ( j & 3 ) , l0y + ( j >> 2 ) ) = val ;
 }
 else {
 val = bytestream2_get_byte ( & ctx -> g ) ;
 mx = val & 0xF ;
 my = val >> 4 ;
 for ( j = 0 ;
 j < 16 ;
 j ++ ) BLK ( ctx -> cur , l0x + ( j & 3 ) , l0y + ( j >> 2 ) ) = BLK ( ctx -> cur , l0x + ( j & 3 ) - mx , l0y + ( j >> 2 ) - my ) ;
 }
 }
 else {
 for ( j = 0 ;
 j < 4 ;
 j ++ ) {
 l1x = l0x + ( j & 1 ) * 2 ;
 l1y = l0y + ( j & 2 ) ;
 kmvc_getbit ( bb , & ctx -> g , res ) ;
 if ( ! res ) {
 kmvc_getbit ( bb , & ctx -> g , res ) ;
 if ( ! res ) {
 val = bytestream2_get_byte ( & ctx -> g ) ;
 BLK ( ctx -> cur , l1x , l1y ) = val ;
 BLK ( ctx -> cur , l1x + 1 , l1y ) = val ;
 BLK ( ctx -> cur , l1x , l1y + 1 ) = val ;
 BLK ( ctx -> cur , l1x + 1 , l1y + 1 ) = val ;
 }
 else {
 val = bytestream2_get_byte ( & ctx -> g ) ;
 mx = val & 0xF ;
 my = val >> 4 ;
 BLK ( ctx -> cur , l1x , l1y ) = BLK ( ctx -> cur , l1x - mx , l1y - my ) ;
 BLK ( ctx -> cur , l1x + 1 , l1y ) = BLK ( ctx -> cur , l1x + 1 - mx , l1y - my ) ;
 BLK ( ctx -> cur , l1x , l1y + 1 ) = BLK ( ctx -> cur , l1x - mx , l1y + 1 - my ) ;
 BLK ( ctx -> cur , l1x + 1 , l1y + 1 ) = BLK ( ctx -> cur , l1x + 1 - mx , l1y + 1 - my ) ;
 }
 }
 else {
 BLK ( ctx -> cur , l1x , l1y ) = bytestream2_get_byte ( & ctx -> g ) ;
 BLK ( ctx -> cur , l1x + 1 , l1y ) = bytestream2_get_byte ( & ctx -> g ) ;
 BLK ( ctx -> cur , l1x , l1y + 1 ) = bytestream2_get_byte ( & ctx -> g ) ;
 BLK ( ctx -> cur , l1x + 1 , l1y + 1 ) = bytestream2_get_byte ( & ctx -> g ) ;
 }
 }
 }
 }
 }
 }
 return 0 ;
 }
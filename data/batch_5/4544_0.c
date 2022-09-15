int upx_inflate2e ( const char * src , uint32_t ssize , char * dst , uint32_t * dsize , uint32_t upx0 , uint32_t upx1 , uint32_t ep ) {
 int32_t backbytes , unp_offset = - 1 ;
 uint32_t backsize , myebx = 0 , scur = 0 , dcur = 0 , i , magic [ ] = {
 0x128 , 0x130 , 0 }
 ;
 int oob ;
 for ( ;
 ;
 ) {
 while ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) ) {
 if ( oob == - 1 ) return - 1 ;
 if ( scur >= ssize || dcur >= * dsize ) return - 1 ;
 dst [ dcur ++ ] = src [ scur ++ ] ;
 }
 backbytes = 1 ;
 for ( ;
 ;
 ) {
 if ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == - 1 ) return - 1 ;
 backbytes = backbytes * 2 + oob ;
 if ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == - 1 ) return - 1 ;
 if ( oob ) break ;
 backbytes -- ;
 if ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == - 1 ) return - 1 ;
 backbytes = backbytes * 2 + oob ;
 }
 backbytes -= 3 ;
 if ( backbytes >= 0 ) {
 if ( scur >= ssize ) return - 1 ;
 backbytes <<= 8 ;
 backbytes += ( unsigned char ) ( src [ scur ++ ] ) ;
 backbytes ^= 0xffffffff ;
 if ( ! backbytes ) break ;
 backsize = backbytes & 1 ;
 CLI_SAR ( backbytes , 1 ) ;
 unp_offset = backbytes ;
 }
 else {
 if ( ( backsize = ( uint32_t ) doubleebx ( src , & myebx , & scur , ssize ) ) == 0xffffffff ) return - 1 ;
 }
 if ( backsize ) {
 if ( ( backsize = ( uint32_t ) doubleebx ( src , & myebx , & scur , ssize ) ) == 0xffffffff ) return - 1 ;
 }
 else {
 backsize = 1 ;
 if ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == - 1 ) return - 1 ;
 if ( oob ) {
 if ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == - 1 ) return - 1 ;
 backsize = 2 + oob ;
 }
 else {
 do {
 if ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == - 1 ) return - 1 ;
 backsize = backsize * 2 + oob ;
 }
 while ( ( oob = doubleebx ( src , & myebx , & scur , ssize ) ) == 0 ) ;
 if ( oob == - 1 ) return - 1 ;
 backsize += 2 ;
 }
 }
 if ( ( uint32_t ) unp_offset < 0xfffffb00 ) backsize ++ ;
 backsize += 2 ;
 if ( ! CLI_ISCONTAINED ( dst , * dsize , dst + dcur + unp_offset , backsize ) || ! CLI_ISCONTAINED ( dst , * dsize , dst + dcur , backsize ) || unp_offset >= 0 ) return - 1 ;
 for ( i = 0 ;
 i < backsize ;
 i ++ ) dst [ dcur + i ] = dst [ dcur + unp_offset + i ] ;
 dcur += backsize ;
 }
 return pefromupx ( src , ssize , dst , dsize , ep , upx0 , upx1 , magic , dcur ) ;
 }
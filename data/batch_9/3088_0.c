static inline int op ( uint8_t * * dst , const uint8_t * dst_end , GetByteContext * gb , int pixel , int count , int * x , int width , int linesize ) {
 int remaining = width - * x ;
 while ( count > 0 ) {
 int striplen = FFMIN ( count , remaining ) ;
 if ( gb ) {
 if ( bytestream2_get_bytes_left ( gb ) < striplen ) goto exhausted ;
 bytestream2_get_bufferu ( gb , * dst , striplen ) ;
 }
 else if ( pixel >= 0 ) memset ( * dst , pixel , striplen ) ;
 * dst += striplen ;
 remaining -= striplen ;
 count -= striplen ;
 if ( remaining <= 0 ) {
 * dst += linesize - width ;
 remaining = width ;
 }
 if ( linesize > 0 ) {
 if ( * dst >= dst_end ) goto exhausted ;
 }
 else {
 if ( * dst <= dst_end ) goto exhausted ;
 }
 }
 * x = width - remaining ;
 return 0 ;
 exhausted : * x = width - remaining ;
 return 1 ;
 }
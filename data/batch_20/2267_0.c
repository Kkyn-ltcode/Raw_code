static int arith_get_bits ( ArithCoder * c , int bits ) {
 int range = c -> high - c -> low + 1 ;
 int val = ( ( ( c -> value - c -> low + 1 ) << bits ) - 1 ) / range ;
 int prob = range * val ;
 c -> high = ( ( prob + range ) >> bits ) + c -> low - 1 ;
 c -> low += prob >> bits ;
 arith_normalise ( c ) ;
 return val ;
 }
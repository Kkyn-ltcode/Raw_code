void or_bits ( REP_SET * to , REP_SET * from ) {
 reg1 uint i ;
 for ( i = 0 ;
 i < to -> size_of_bits ;
 i ++ ) to -> bits [ i ] |= from -> bits [ i ] ;
 return ;
 }
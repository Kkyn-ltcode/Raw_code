static int rescale ( int val , int num , int denom ) {
 int64_t llnum = num ;
 int64_t llden = denom ;
 int64_t llval = val ;
 return ( int ) ( llval * llnum / llden ) ;
 }
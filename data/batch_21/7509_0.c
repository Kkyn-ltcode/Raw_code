void make_sets_invisible ( REP_SETS * sets ) {
 sets -> invisible = sets -> count ;
 sets -> set += sets -> count ;
 sets -> count = 0 ;
 }
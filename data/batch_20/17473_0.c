static int total_adj_weak_thresh ( BLOCK_SIZE bs , int increase_denoising ) {
 return widths [ bs ] * heights [ bs ] * ( increase_denoising ? 3 : 2 ) ;
 }
static PREDICTION_MODE read_intra_mode ( vp9_reader * r , const vp9_prob * p ) {
 return ( PREDICTION_MODE ) vp9_read_tree ( r , vp9_intra_mode_tree , p ) ;
 }
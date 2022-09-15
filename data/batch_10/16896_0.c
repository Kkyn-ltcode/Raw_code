static int read_inter_segment_id ( VP9_COMMON * const cm , MACROBLOCKD * const xd , int mi_row , int mi_col , vp9_reader * r ) {
 struct segmentation * const seg = & cm -> seg ;
 MB_MODE_INFO * const mbmi = & xd -> mi [ 0 ] . src_mi -> mbmi ;
 const BLOCK_SIZE bsize = mbmi -> sb_type ;
 int predicted_segment_id , segment_id ;
 if ( ! seg -> enabled ) return 0 ;
 predicted_segment_id = vp9_get_segment_id ( cm , cm -> last_frame_seg_map , bsize , mi_row , mi_col ) ;
 if ( ! seg -> update_map ) return predicted_segment_id ;
 if ( seg -> temporal_update ) {
 const vp9_prob pred_prob = vp9_get_pred_prob_seg_id ( seg , xd ) ;
 mbmi -> seg_id_predicted = vp9_read ( r , pred_prob ) ;
 segment_id = mbmi -> seg_id_predicted ? predicted_segment_id : read_segment_id ( r , seg ) ;
 }
 else {
 segment_id = read_segment_id ( r , seg ) ;
 }
 set_segment_id ( cm , bsize , mi_row , mi_col , segment_id ) ;
 return segment_id ;
 }
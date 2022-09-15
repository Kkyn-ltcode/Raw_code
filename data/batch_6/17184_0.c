void vp9_print_modes_and_motion_vectors ( VP9_COMMON * cm , const char * file ) {
 int mi_row ;
 int mi_col ;
 int mi_index = 0 ;
 FILE * mvs = fopen ( file , "a" ) ;
 MODE_INFO * * mi = NULL ;
 int rows = cm -> mi_rows ;
 int cols = cm -> mi_cols ;
 print_mi_data ( cm , mvs , "Partitions:" , offsetof ( MB_MODE_INFO , sb_type ) ) ;
 print_mi_data ( cm , mvs , "Modes:" , offsetof ( MB_MODE_INFO , mode ) ) ;
 print_mi_data ( cm , mvs , "Skips:" , offsetof ( MB_MODE_INFO , skip ) ) ;
 print_mi_data ( cm , mvs , "Ref frame:" , offsetof ( MB_MODE_INFO , ref_frame [ 0 ] ) ) ;
 print_mi_data ( cm , mvs , "Transform:" , offsetof ( MB_MODE_INFO , tx_size ) ) ;
 print_mi_data ( cm , mvs , "UV Modes:" , offsetof ( MB_MODE_INFO , uv_mode ) ) ;
 log_frame_info ( cm , "Vectors " , mvs ) ;
 for ( mi_row = 0 ;
 mi_row < rows ;
 mi_row ++ ) {
 fprintf ( mvs , "V " ) ;
 for ( mi_col = 0 ;
 mi_col < cols ;
 mi_col ++ ) {
 fprintf ( mvs , "%4d:%4d " , mi [ mi_index ] -> mbmi . mv [ 0 ] . as_mv . row , mi [ mi_index ] -> mbmi . mv [ 0 ] . as_mv . col ) ;
 mi_index ++ ;
 }
 fprintf ( mvs , "\n" ) ;
 mi_index += 8 ;
 }
 fprintf ( mvs , "\n" ) ;
 fclose ( mvs ) ;
 }
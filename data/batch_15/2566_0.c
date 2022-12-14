void ff_h264_direct_ref_list_init ( H264Context * const h ) {
 Picture * const ref1 = & h -> ref_list [ 1 ] [ 0 ] ;
 Picture * const cur = h -> cur_pic_ptr ;
 int list , j , field ;
 int sidx = ( h -> picture_structure & 1 ) ^ 1 ;
 int ref1sidx = ( ref1 -> reference & 1 ) ^ 1 ;
 for ( list = 0 ;
 list < 2 ;
 list ++ ) {
 cur -> ref_count [ sidx ] [ list ] = h -> ref_count [ list ] ;
 for ( j = 0 ;
 j < h -> ref_count [ list ] ;
 j ++ ) cur -> ref_poc [ sidx ] [ list ] [ j ] = 4 * h -> ref_list [ list ] [ j ] . frame_num + ( h -> ref_list [ list ] [ j ] . reference & 3 ) ;
 }
 if ( h -> picture_structure == PICT_FRAME ) {
 memcpy ( cur -> ref_count [ 1 ] , cur -> ref_count [ 0 ] , sizeof ( cur -> ref_count [ 0 ] ) ) ;
 memcpy ( cur -> ref_poc [ 1 ] , cur -> ref_poc [ 0 ] , sizeof ( cur -> ref_poc [ 0 ] ) ) ;
 }
 cur -> mbaff = FRAME_MBAFF ;
 h -> col_fieldoff = 0 ;
 if ( h -> picture_structure == PICT_FRAME ) {
 int cur_poc = h -> cur_pic_ptr -> poc ;
 int * col_poc = h -> ref_list [ 1 ] -> field_poc ;
 h -> col_parity = ( FFABS ( col_poc [ 0 ] - cur_poc ) >= FFABS ( col_poc [ 1 ] - cur_poc ) ) ;
 ref1sidx = sidx = h -> col_parity ;
 }
 else if ( ! ( h -> picture_structure & h -> ref_list [ 1 ] [ 0 ] . reference ) && ! h -> ref_list [ 1 ] [ 0 ] . mbaff ) {
 h -> col_fieldoff = 2 * h -> ref_list [ 1 ] [ 0 ] . reference - 3 ;
 }
 if ( h -> slice_type_nos != AV_PICTURE_TYPE_B || h -> direct_spatial_mv_pred ) return ;
 for ( list = 0 ;
 list < 2 ;
 list ++ ) {
 fill_colmap ( h , h -> map_col_to_list0 , list , sidx , ref1sidx , 0 ) ;
 if ( FRAME_MBAFF ) for ( field = 0 ;
 field < 2 ;
 field ++ ) fill_colmap ( h , h -> map_col_to_list0_field [ field ] , list , field , field , 1 ) ;
 }
 }
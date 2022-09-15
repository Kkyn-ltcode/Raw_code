static void pred_temp_direct_motion ( H264Context * const h , int * mb_type ) {
 int b8_stride = 2 ;
 int b4_stride = h -> b_stride ;
 int mb_xy = h -> mb_xy , mb_y = h -> mb_y ;
 int mb_type_col [ 2 ] ;
 const int16_t ( * l1mv0 ) [ 2 ] , ( * l1mv1 ) [ 2 ] ;
 const int8_t * l1ref0 , * l1ref1 ;
 const int is_b8x8 = IS_8X8 ( * mb_type ) ;
 unsigned int sub_mb_type ;
 int i8 , i4 ;
 assert ( h -> ref_list [ 1 ] [ 0 ] . reference & 3 ) ;
 await_reference_mb_row ( h , & h -> ref_list [ 1 ] [ 0 ] , h -> mb_y + ! ! IS_INTERLACED ( * mb_type ) ) ;
 if ( IS_INTERLACED ( h -> ref_list [ 1 ] [ 0 ] . mb_type [ mb_xy ] ) ) {
 if ( ! IS_INTERLACED ( * mb_type ) ) {
 mb_y = ( h -> mb_y & ~ 1 ) + h -> col_parity ;
 mb_xy = h -> mb_x + ( ( h -> mb_y & ~ 1 ) + h -> col_parity ) * h -> mb_stride ;
 b8_stride = 0 ;
 }
 else {
 mb_y += h -> col_fieldoff ;
 mb_xy += h -> mb_stride * h -> col_fieldoff ;
 }
 goto single_col ;
 }
 else {
 if ( IS_INTERLACED ( * mb_type ) ) {
 mb_y = h -> mb_y & ~ 1 ;
 mb_xy = h -> mb_x + ( h -> mb_y & ~ 1 ) * h -> mb_stride ;
 mb_type_col [ 0 ] = h -> ref_list [ 1 ] [ 0 ] . mb_type [ mb_xy ] ;
 mb_type_col [ 1 ] = h -> ref_list [ 1 ] [ 0 ] . mb_type [ mb_xy + h -> mb_stride ] ;
 b8_stride = 2 + 4 * h -> mb_stride ;
 b4_stride *= 6 ;
 if ( IS_INTERLACED ( mb_type_col [ 0 ] ) != IS_INTERLACED ( mb_type_col [ 1 ] ) ) {
 mb_type_col [ 0 ] &= ~ MB_TYPE_INTERLACED ;
 mb_type_col [ 1 ] &= ~ MB_TYPE_INTERLACED ;
 }
 sub_mb_type = MB_TYPE_16x16 | MB_TYPE_P0L0 | MB_TYPE_P0L1 | MB_TYPE_DIRECT2 ;
 if ( ( mb_type_col [ 0 ] & MB_TYPE_16x16_OR_INTRA ) && ( mb_type_col [ 1 ] & MB_TYPE_16x16_OR_INTRA ) && ! is_b8x8 ) {
 * mb_type |= MB_TYPE_16x8 | MB_TYPE_L0L1 | MB_TYPE_DIRECT2 ;
 }
 else {
 * mb_type |= MB_TYPE_8x8 | MB_TYPE_L0L1 ;
 }
 }
 else {
 single_col : mb_type_col [ 0 ] = mb_type_col [ 1 ] = h -> ref_list [ 1 ] [ 0 ] . mb_type [ mb_xy ] ;
 sub_mb_type = MB_TYPE_16x16 | MB_TYPE_P0L0 | MB_TYPE_P0L1 | MB_TYPE_DIRECT2 ;
 if ( ! is_b8x8 && ( mb_type_col [ 0 ] & MB_TYPE_16x16_OR_INTRA ) ) {
 * mb_type |= MB_TYPE_16x16 | MB_TYPE_P0L0 | MB_TYPE_P0L1 | MB_TYPE_DIRECT2 ;
 }
 else if ( ! is_b8x8 && ( mb_type_col [ 0 ] & ( MB_TYPE_16x8 | MB_TYPE_8x16 ) ) ) {
 * mb_type |= MB_TYPE_L0L1 | MB_TYPE_DIRECT2 | ( mb_type_col [ 0 ] & ( MB_TYPE_16x8 | MB_TYPE_8x16 ) ) ;
 }
 else {
 if ( ! h -> sps . direct_8x8_inference_flag ) {
 sub_mb_type = MB_TYPE_8x8 | MB_TYPE_P0L0 | MB_TYPE_P0L1 | MB_TYPE_DIRECT2 ;
 }
 * mb_type |= MB_TYPE_8x8 | MB_TYPE_L0L1 ;
 }
 }
 }
 await_reference_mb_row ( h , & h -> ref_list [ 1 ] [ 0 ] , mb_y ) ;
 l1mv0 = & h -> ref_list [ 1 ] [ 0 ] . motion_val [ 0 ] [ h -> mb2b_xy [ mb_xy ] ] ;
 l1mv1 = & h -> ref_list [ 1 ] [ 0 ] . motion_val [ 1 ] [ h -> mb2b_xy [ mb_xy ] ] ;
 l1ref0 = & h -> ref_list [ 1 ] [ 0 ] . ref_index [ 0 ] [ 4 * mb_xy ] ;
 l1ref1 = & h -> ref_list [ 1 ] [ 0 ] . ref_index [ 1 ] [ 4 * mb_xy ] ;
 if ( ! b8_stride ) {
 if ( h -> mb_y & 1 ) {
 l1ref0 += 2 ;
 l1ref1 += 2 ;
 l1mv0 += 2 * b4_stride ;
 l1mv1 += 2 * b4_stride ;
 }
 }
 {
 const int * map_col_to_list0 [ 2 ] = {
 h -> map_col_to_list0 [ 0 ] , h -> map_col_to_list0 [ 1 ] }
 ;
 const int * dist_scale_factor = h -> dist_scale_factor ;
 int ref_offset ;
 if ( FRAME_MBAFF && IS_INTERLACED ( * mb_type ) ) {
 map_col_to_list0 [ 0 ] = h -> map_col_to_list0_field [ h -> mb_y & 1 ] [ 0 ] ;
 map_col_to_list0 [ 1 ] = h -> map_col_to_list0_field [ h -> mb_y & 1 ] [ 1 ] ;
 dist_scale_factor = h -> dist_scale_factor_field [ h -> mb_y & 1 ] ;
 }
 ref_offset = ( h -> ref_list [ 1 ] [ 0 ] . mbaff << 4 ) & ( mb_type_col [ 0 ] >> 3 ) ;
 if ( IS_INTERLACED ( * mb_type ) != IS_INTERLACED ( mb_type_col [ 0 ] ) ) {
 int y_shift = 2 * ! IS_INTERLACED ( * mb_type ) ;
 assert ( h -> sps . direct_8x8_inference_flag ) ;
 for ( i8 = 0 ;
 i8 < 4 ;
 i8 ++ ) {
 const int x8 = i8 & 1 ;
 const int y8 = i8 >> 1 ;
 int ref0 , scale ;
 const int16_t ( * l1mv ) [ 2 ] = l1mv0 ;
 if ( is_b8x8 && ! IS_DIRECT ( h -> sub_mb_type [ i8 ] ) ) continue ;
 h -> sub_mb_type [ i8 ] = sub_mb_type ;
 fill_rectangle ( & h -> ref_cache [ 1 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 1 ) ;
 if ( IS_INTRA ( mb_type_col [ y8 ] ) ) {
 fill_rectangle ( & h -> ref_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 1 ) ;
 fill_rectangle ( & h -> mv_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 4 ) ;
 fill_rectangle ( & h -> mv_cache [ 1 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 4 ) ;
 continue ;
 }
 ref0 = l1ref0 [ x8 + y8 * b8_stride ] ;
 if ( ref0 >= 0 ) ref0 = map_col_to_list0 [ 0 ] [ ref0 + ref_offset ] ;
 else {
 ref0 = map_col_to_list0 [ 1 ] [ l1ref1 [ x8 + y8 * b8_stride ] + ref_offset ] ;
 l1mv = l1mv1 ;
 }
 scale = dist_scale_factor [ ref0 ] ;
 fill_rectangle ( & h -> ref_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , ref0 , 1 ) ;
 {
 const int16_t * mv_col = l1mv [ x8 * 3 + y8 * b4_stride ] ;
 int my_col = ( mv_col [ 1 ] << y_shift ) / 2 ;
 int mx = ( scale * mv_col [ 0 ] + 128 ) >> 8 ;
 int my = ( scale * my_col + 128 ) >> 8 ;
 fill_rectangle ( & h -> mv_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , pack16to32 ( mx , my ) , 4 ) ;
 fill_rectangle ( & h -> mv_cache [ 1 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , pack16to32 ( mx - mv_col [ 0 ] , my - my_col ) , 4 ) ;
 }
 }
 return ;
 }
 if ( IS_16X16 ( * mb_type ) ) {
 int ref , mv0 , mv1 ;
 fill_rectangle ( & h -> ref_cache [ 1 ] [ scan8 [ 0 ] ] , 4 , 4 , 8 , 0 , 1 ) ;
 if ( IS_INTRA ( mb_type_col [ 0 ] ) ) {
 ref = mv0 = mv1 = 0 ;
 }
 else {
 const int ref0 = l1ref0 [ 0 ] >= 0 ? map_col_to_list0 [ 0 ] [ l1ref0 [ 0 ] + ref_offset ] : map_col_to_list0 [ 1 ] [ l1ref1 [ 0 ] + ref_offset ] ;
 const int scale = dist_scale_factor [ ref0 ] ;
 const int16_t * mv_col = l1ref0 [ 0 ] >= 0 ? l1mv0 [ 0 ] : l1mv1 [ 0 ] ;
 int mv_l0 [ 2 ] ;
 mv_l0 [ 0 ] = ( scale * mv_col [ 0 ] + 128 ) >> 8 ;
 mv_l0 [ 1 ] = ( scale * mv_col [ 1 ] + 128 ) >> 8 ;
 ref = ref0 ;
 mv0 = pack16to32 ( mv_l0 [ 0 ] , mv_l0 [ 1 ] ) ;
 mv1 = pack16to32 ( mv_l0 [ 0 ] - mv_col [ 0 ] , mv_l0 [ 1 ] - mv_col [ 1 ] ) ;
 }
 fill_rectangle ( & h -> ref_cache [ 0 ] [ scan8 [ 0 ] ] , 4 , 4 , 8 , ref , 1 ) ;
 fill_rectangle ( & h -> mv_cache [ 0 ] [ scan8 [ 0 ] ] , 4 , 4 , 8 , mv0 , 4 ) ;
 fill_rectangle ( & h -> mv_cache [ 1 ] [ scan8 [ 0 ] ] , 4 , 4 , 8 , mv1 , 4 ) ;
 }
 else {
 for ( i8 = 0 ;
 i8 < 4 ;
 i8 ++ ) {
 const int x8 = i8 & 1 ;
 const int y8 = i8 >> 1 ;
 int ref0 , scale ;
 const int16_t ( * l1mv ) [ 2 ] = l1mv0 ;
 if ( is_b8x8 && ! IS_DIRECT ( h -> sub_mb_type [ i8 ] ) ) continue ;
 h -> sub_mb_type [ i8 ] = sub_mb_type ;
 fill_rectangle ( & h -> ref_cache [ 1 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 1 ) ;
 if ( IS_INTRA ( mb_type_col [ 0 ] ) ) {
 fill_rectangle ( & h -> ref_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 1 ) ;
 fill_rectangle ( & h -> mv_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 4 ) ;
 fill_rectangle ( & h -> mv_cache [ 1 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , 0 , 4 ) ;
 continue ;
 }
 assert ( b8_stride == 2 ) ;
 ref0 = l1ref0 [ i8 ] ;
 if ( ref0 >= 0 ) ref0 = map_col_to_list0 [ 0 ] [ ref0 + ref_offset ] ;
 else {
 ref0 = map_col_to_list0 [ 1 ] [ l1ref1 [ i8 ] + ref_offset ] ;
 l1mv = l1mv1 ;
 }
 scale = dist_scale_factor [ ref0 ] ;
 fill_rectangle ( & h -> ref_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , ref0 , 1 ) ;
 if ( IS_SUB_8X8 ( sub_mb_type ) ) {
 const int16_t * mv_col = l1mv [ x8 * 3 + y8 * 3 * b4_stride ] ;
 int mx = ( scale * mv_col [ 0 ] + 128 ) >> 8 ;
 int my = ( scale * mv_col [ 1 ] + 128 ) >> 8 ;
 fill_rectangle ( & h -> mv_cache [ 0 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , pack16to32 ( mx , my ) , 4 ) ;
 fill_rectangle ( & h -> mv_cache [ 1 ] [ scan8 [ i8 * 4 ] ] , 2 , 2 , 8 , pack16to32 ( mx - mv_col [ 0 ] , my - mv_col [ 1 ] ) , 4 ) ;
 }
 else for ( i4 = 0 ;
 i4 < 4 ;
 i4 ++ ) {
 const int16_t * mv_col = l1mv [ x8 * 2 + ( i4 & 1 ) + ( y8 * 2 + ( i4 >> 1 ) ) * b4_stride ] ;
 int16_t * mv_l0 = h -> mv_cache [ 0 ] [ scan8 [ i8 * 4 + i4 ] ] ;
 mv_l0 [ 0 ] = ( scale * mv_col [ 0 ] + 128 ) >> 8 ;
 mv_l0 [ 1 ] = ( scale * mv_col [ 1 ] + 128 ) >> 8 ;
 AV_WN32A ( h -> mv_cache [ 1 ] [ scan8 [ i8 * 4 + i4 ] ] , pack16to32 ( mv_l0 [ 0 ] - mv_col [ 0 ] , mv_l0 [ 1 ] - mv_col [ 1 ] ) ) ;
 }
 }
 }
 }
 }
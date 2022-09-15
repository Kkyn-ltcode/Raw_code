static int select_input_picture ( MpegEncContext * s ) {
 int i ;
 for ( i = 1 ;
 i < MAX_PICTURE_COUNT ;
 i ++ ) s -> reordered_input_picture [ i - 1 ] = s -> reordered_input_picture [ i ] ;
 s -> reordered_input_picture [ MAX_PICTURE_COUNT - 1 ] = NULL ;
 if ( s -> reordered_input_picture [ 0 ] == NULL && s -> input_picture [ 0 ] ) {
 if ( s -> next_picture_ptr == NULL || s -> intra_only ) {
 s -> reordered_input_picture [ 0 ] = s -> input_picture [ 0 ] ;
 s -> reordered_input_picture [ 0 ] -> f . pict_type = AV_PICTURE_TYPE_I ;
 s -> reordered_input_picture [ 0 ] -> f . coded_picture_number = s -> coded_picture_number ++ ;
 }
 else {
 int b_frames ;
 if ( s -> avctx -> frame_skip_threshold || s -> avctx -> frame_skip_factor ) {
 if ( s -> picture_in_gop_number < s -> gop_size && skip_check ( s , s -> input_picture [ 0 ] , s -> next_picture_ptr ) ) {
 if ( s -> input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_SHARED ) {
 for ( i = 0 ;
 i < 4 ;
 i ++ ) s -> input_picture [ 0 ] -> f . data [ i ] = NULL ;
 s -> input_picture [ 0 ] -> f . type = 0 ;
 }
 else {
 assert ( s -> input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_USER || s -> input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_INTERNAL ) ;
 s -> avctx -> release_buffer ( s -> avctx , & s -> input_picture [ 0 ] -> f ) ;
 }
 emms_c ( ) ;
 ff_vbv_update ( s , 0 ) ;
 goto no_output_pic ;
 }
 }
 if ( s -> flags & CODEC_FLAG_PASS2 ) {
 for ( i = 0 ;
 i < s -> max_b_frames + 1 ;
 i ++ ) {
 int pict_num = s -> input_picture [ 0 ] -> f . display_picture_number + i ;
 if ( pict_num >= s -> rc_context . num_entries ) break ;
 if ( ! s -> input_picture [ i ] ) {
 s -> rc_context . entry [ pict_num - 1 ] . new_pict_type = AV_PICTURE_TYPE_P ;
 break ;
 }
 s -> input_picture [ i ] -> f . pict_type = s -> rc_context . entry [ pict_num ] . new_pict_type ;
 }
 }
 if ( s -> avctx -> b_frame_strategy == 0 ) {
 b_frames = s -> max_b_frames ;
 while ( b_frames && ! s -> input_picture [ b_frames ] ) b_frames -- ;
 }
 else if ( s -> avctx -> b_frame_strategy == 1 ) {
 for ( i = 1 ;
 i < s -> max_b_frames + 1 ;
 i ++ ) {
 if ( s -> input_picture [ i ] && s -> input_picture [ i ] -> b_frame_score == 0 ) {
 s -> input_picture [ i ] -> b_frame_score = get_intra_count ( s , s -> input_picture [ i ] -> f . data [ 0 ] , s -> input_picture [ i - 1 ] -> f . data [ 0 ] , s -> linesize ) + 1 ;
 }
 }
 for ( i = 0 ;
 i < s -> max_b_frames + 1 ;
 i ++ ) {
 if ( s -> input_picture [ i ] == NULL || s -> input_picture [ i ] -> b_frame_score - 1 > s -> mb_num / s -> avctx -> b_sensitivity ) break ;
 }
 b_frames = FFMAX ( 0 , i - 1 ) ;
 for ( i = 0 ;
 i < b_frames + 1 ;
 i ++ ) {
 s -> input_picture [ i ] -> b_frame_score = 0 ;
 }
 }
 else if ( s -> avctx -> b_frame_strategy == 2 ) {
 b_frames = estimate_best_b_count ( s ) ;
 }
 else {
 av_log ( s -> avctx , AV_LOG_ERROR , "illegal b frame strategy\n" ) ;
 b_frames = 0 ;
 }
 emms_c ( ) ;
 for ( i = b_frames - 1 ;
 i >= 0 ;
 i -- ) {
 int type = s -> input_picture [ i ] -> f . pict_type ;
 if ( type && type != AV_PICTURE_TYPE_B ) b_frames = i ;
 }
 if ( s -> input_picture [ b_frames ] -> f . pict_type == AV_PICTURE_TYPE_B && b_frames == s -> max_b_frames ) {
 av_log ( s -> avctx , AV_LOG_ERROR , "warning, too many b frames in a row\n" ) ;
 }
 if ( s -> picture_in_gop_number + b_frames >= s -> gop_size ) {
 if ( ( s -> mpv_flags & FF_MPV_FLAG_STRICT_GOP ) && s -> gop_size > s -> picture_in_gop_number ) {
 b_frames = s -> gop_size - s -> picture_in_gop_number - 1 ;
 }
 else {
 if ( s -> flags & CODEC_FLAG_CLOSED_GOP ) b_frames = 0 ;
 s -> input_picture [ b_frames ] -> f . pict_type = AV_PICTURE_TYPE_I ;
 }
 }
 if ( ( s -> flags & CODEC_FLAG_CLOSED_GOP ) && b_frames && s -> input_picture [ b_frames ] -> f . pict_type == AV_PICTURE_TYPE_I ) b_frames -- ;
 s -> reordered_input_picture [ 0 ] = s -> input_picture [ b_frames ] ;
 if ( s -> reordered_input_picture [ 0 ] -> f . pict_type != AV_PICTURE_TYPE_I ) s -> reordered_input_picture [ 0 ] -> f . pict_type = AV_PICTURE_TYPE_P ;
 s -> reordered_input_picture [ 0 ] -> f . coded_picture_number = s -> coded_picture_number ++ ;
 for ( i = 0 ;
 i < b_frames ;
 i ++ ) {
 s -> reordered_input_picture [ i + 1 ] = s -> input_picture [ i ] ;
 s -> reordered_input_picture [ i + 1 ] -> f . pict_type = AV_PICTURE_TYPE_B ;
 s -> reordered_input_picture [ i + 1 ] -> f . coded_picture_number = s -> coded_picture_number ++ ;
 }
 }
 }
 no_output_pic : if ( s -> reordered_input_picture [ 0 ] ) {
 s -> reordered_input_picture [ 0 ] -> f . reference = s -> reordered_input_picture [ 0 ] -> f . pict_type != AV_PICTURE_TYPE_B ? 3 : 0 ;
 ff_copy_picture ( & s -> new_picture , s -> reordered_input_picture [ 0 ] ) ;
 if ( s -> reordered_input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_SHARED || s -> avctx -> rc_buffer_size ) {
 Picture * pic ;
 int i = ff_find_unused_picture ( s , 0 ) ;
 if ( i < 0 ) return i ;
 pic = & s -> picture [ i ] ;
 pic -> f . reference = s -> reordered_input_picture [ 0 ] -> f . reference ;
 if ( ff_alloc_picture ( s , pic , 0 ) < 0 ) {
 return - 1 ;
 }
 if ( s -> reordered_input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_INTERNAL ) s -> avctx -> release_buffer ( s -> avctx , & s -> reordered_input_picture [ 0 ] -> f ) ;
 for ( i = 0 ;
 i < 4 ;
 i ++ ) s -> reordered_input_picture [ 0 ] -> f . data [ i ] = NULL ;
 s -> reordered_input_picture [ 0 ] -> f . type = 0 ;
 copy_picture_attributes ( s , & pic -> f , & s -> reordered_input_picture [ 0 ] -> f ) ;
 s -> current_picture_ptr = pic ;
 }
 else {
 assert ( s -> reordered_input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_USER || s -> reordered_input_picture [ 0 ] -> f . type == FF_BUFFER_TYPE_INTERNAL ) ;
 s -> current_picture_ptr = s -> reordered_input_picture [ 0 ] ;
 for ( i = 0 ;
 i < 4 ;
 i ++ ) {
 s -> new_picture . f . data [ i ] += INPLACE_OFFSET ;
 }
 }
 ff_copy_picture ( & s -> current_picture , s -> current_picture_ptr ) ;
 s -> picture_number = s -> new_picture . f . display_picture_number ;
 }
 else {
 memset ( & s -> new_picture , 0 , sizeof ( Picture ) ) ;
 }
 return 0 ;
 }
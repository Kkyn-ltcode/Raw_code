static int vp8_alloc_partition_data ( VP8_COMP * cpi ) {
 vpx_free ( cpi -> mb . pip ) ;
 cpi -> mb . pip = vpx_calloc ( ( cpi -> common . mb_cols + 1 ) * ( cpi -> common . mb_rows + 1 ) , sizeof ( PARTITION_INFO ) ) ;
 if ( ! cpi -> mb . pip ) return 1 ;
 cpi -> mb . pi = cpi -> mb . pip + cpi -> common . mode_info_stride + 1 ;
 return 0 ;
 }
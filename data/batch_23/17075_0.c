static void enable_segmentation ( VP8_COMP * cpi ) {
 cpi -> mb . e_mbd . segmentation_enabled = 1 ;
 cpi -> mb . e_mbd . update_mb_segmentation_map = 1 ;
 cpi -> mb . e_mbd . update_mb_segmentation_data = 1 ;
 }
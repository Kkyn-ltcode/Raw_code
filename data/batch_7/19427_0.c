void hb_shape_plan_destroy ( hb_shape_plan_t * shape_plan ) {
 if ( ! hb_object_destroy ( shape_plan ) ) return ;
 # define HB_SHAPER_IMPLEMENT ( shaper ) HB_SHAPER_DATA_DESTROY ( shaper , shape_plan ) ;
 # include "hb-shaper-list.hh" # undef HB_SHAPER_IMPLEMENT free ( shape_plan -> user_features ) ;
 free ( shape_plan ) ;
 }
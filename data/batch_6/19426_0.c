hb_shape_plan_t * hb_shape_plan_get_empty ( void ) {
 static const hb_shape_plan_t _hb_shape_plan_nil = {
 HB_OBJECT_HEADER_STATIC , true , NULL , HB_SEGMENT_PROPERTIES_DEFAULT , NULL , NULL , NULL , 0 , {
 # define HB_SHAPER_IMPLEMENT ( shaper ) HB_SHAPER_DATA_INVALID , # include "hb-shaper-list.hh" # undef HB_SHAPER_IMPLEMENT }
 }
 ;
 return const_cast < hb_shape_plan_t * > ( & _hb_shape_plan_nil ) ;
 }
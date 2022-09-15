static hb_bool_t hb_shape_plan_matches ( const hb_shape_plan_t * shape_plan , const hb_shape_plan_proposal_t * proposal ) {
 return hb_segment_properties_equal ( & shape_plan -> props , & proposal -> props ) && hb_shape_plan_user_features_match ( shape_plan , proposal ) && ( ( shape_plan -> default_shaper_list && proposal -> shaper_list == NULL ) || ( shape_plan -> shaper_func == proposal -> shaper_func ) ) ;
 }
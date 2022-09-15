int vp9_get_switchable_rate ( const VP9_COMP * cpi ) {
 const MACROBLOCKD * const xd = & cpi -> mb . e_mbd ;
 const MB_MODE_INFO * const mbmi = & xd -> mi [ 0 ] -> mbmi ;
 const int ctx = vp9_get_pred_context_switchable_interp ( xd ) ;
 return SWITCHABLE_INTERP_RATE_FACTOR * cpi -> switchable_interp_costs [ ctx ] [ mbmi -> interp_filter ] ;
 }
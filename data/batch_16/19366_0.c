GType hb_gobject_ ## name ## _get_type ( void ) \ {
 static gsize type_id = 0 ;
 if ( g_once_init_enter ( & type_id ) ) {
 GType id = g_boxed_type_register_static ( g_intern_static_string ( "hb_" # name "_t" ) , ( GBoxedCopyFunc ) copy_func , ( GBoxedFreeFunc ) free_func ) ;
 g_once_init_leave ( & type_id , id ) ;
 }
 return type_id ;
 \ }
 # define HB_DEFINE_OBJECT_TYPE ( name ) HB_DEFINE_BOXED_TYPE ( name , hb_ ## name ## _reference , hb_ ## name ## _destroy ) ;
 # define HB_DEFINE_VALUE_TYPE ( name ) static hb_ ## name ## _t * _hb_ ## name ## _reference ( const hb_ ## name ## _t * l ) {
 hb_ ## name ## _t * c = ( hb_ ## name ## _t * ) calloc ( 1 , sizeof ( hb_ ## name ## _t ) ) ;
 if ( unlikely ( ! c ) ) return NULL ;
 * c = * l ;
 return c ;
 }
 static void _hb_ ## name ## _destroy ( hb_ ## name ## _t * l ) {
 free ( l ) ;
 }
 HB_DEFINE_BOXED_TYPE ( name , _hb_ ## name ## _reference , _hb_ ## name ## _destroy ) ;
 HB_DEFINE_OBJECT_TYPE ( buffer ) HB_DEFINE_OBJECT_TYPE ( blob ) HB_DEFINE_OBJECT_TYPE ( face ) HB_DEFINE_OBJECT_TYPE ( font ) HB_DEFINE_OBJECT_TYPE ( font_funcs ) HB_DEFINE_OBJECT_TYPE ( set ) HB_DEFINE_OBJECT_TYPE ( shape_plan ) HB_DEFINE_OBJECT_TYPE ( unicode_funcs ) HB_DEFINE_VALUE_TYPE ( feature ) HB_DEFINE_VALUE_TYPE ( glyph_info ) HB_DEFINE_VALUE_TYPE ( glyph_position ) HB_DEFINE_VALUE_TYPE ( segment_properties ) HB_DEFINE_VALUE_TYPE ( user_data_key )
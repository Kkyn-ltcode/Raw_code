hb_unicode_funcs_t * hb_icu_get_unicode_funcs ( void ) {
 static const hb_unicode_funcs_t _hb_icu_unicode_funcs = {
 HB_OBJECT_HEADER_STATIC , NULL , true , {
 # define HB_UNICODE_FUNC_IMPLEMENT ( name ) hb_icu_unicode_ ## name , HB_UNICODE_FUNCS_IMPLEMENT_CALLBACKS # undef HB_UNICODE_FUNC_IMPLEMENT }
 }
 ;
 # if U_ICU_VERSION_MAJOR_NUM >= 49 if ( ! hb_atomic_ptr_get ( & normalizer ) ) {
 UErrorCode icu_err = U_ZERO_ERROR ;
 ( void ) hb_atomic_ptr_cmpexch ( & normalizer , NULL , unorm2_getNFCInstance ( & icu_err ) ) ;
 }
 # endif return const_cast < hb_unicode_funcs_t * > ( & _hb_icu_unicode_funcs ) ;
 }
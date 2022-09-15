static void fill_label_number64 ( field_info * fi , gchar * label_str , gboolean is_signed ) {
 header_field_info * hfinfo = fi -> hfinfo ;
 guint64 value ;
 char buf [ 48 ] ;
 const char * out ;
 if ( is_signed ) value = fvalue_get_sinteger64 ( & fi -> value ) ;
 else value = fvalue_get_uinteger64 ( & fi -> value ) ;
 if ( hfinfo -> display == BASE_CUSTOM ) {
 gchar tmp [ ITEM_LABEL_LENGTH ] ;
 const custom_fmt_func_64_t fmtfunc64 = ( const custom_fmt_func_64_t ) hfinfo -> strings ;
 DISSECTOR_ASSERT ( fmtfunc64 ) ;
 fmtfunc64 ( tmp , value ) ;
 label_fill ( label_str , 0 , hfinfo , tmp ) ;
 }
 else if ( hfinfo -> strings ) {
 const char * val_str = hf_try_val64_to_str_const ( value , hfinfo , "Unknown" ) ;
 out = hfinfo_number_vals_format64 ( hfinfo , buf , value ) ;
 if ( out == NULL ) label_fill ( label_str , 0 , hfinfo , val_str ) ;
 else label_fill_descr ( label_str , 0 , hfinfo , val_str , out ) ;
 }
 else {
 out = hfinfo_number_value_format64 ( hfinfo , buf , value ) ;
 label_fill ( label_str , 0 , hfinfo , out ) ;
 }
 }
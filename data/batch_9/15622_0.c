static const char * hf_try_val_to_str ( guint32 value , const header_field_info * hfinfo ) {
 if ( hfinfo -> display & BASE_RANGE_STRING ) return try_rval_to_str ( value , ( const range_string * ) hfinfo -> strings ) ;
 if ( hfinfo -> display & BASE_EXT_STRING ) return try_val_to_str_ext ( value , ( value_string_ext * ) hfinfo -> strings ) ;
 if ( hfinfo -> display & BASE_VAL64_STRING ) return try_val64_to_str ( value , ( const val64_string * ) hfinfo -> strings ) ;
 return try_val_to_str ( value , ( const value_string * ) hfinfo -> strings ) ;
 }
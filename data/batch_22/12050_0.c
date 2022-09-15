static void pdf_process_extgstate ( fz_context * ctx , pdf_processor * proc , pdf_csi * csi , pdf_obj * dict ) {
 pdf_obj * obj ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_LW ) ;
 if ( pdf_is_number ( ctx , obj ) && proc -> op_w ) proc -> op_w ( ctx , proc , pdf_to_real ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_LC ) ;
 if ( pdf_is_int ( ctx , obj ) && proc -> op_J ) proc -> op_J ( ctx , proc , fz_clampi ( pdf_to_int ( ctx , obj ) , 0 , 2 ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_LJ ) ;
 if ( pdf_is_int ( ctx , obj ) && proc -> op_j ) proc -> op_j ( ctx , proc , fz_clampi ( pdf_to_int ( ctx , obj ) , 0 , 2 ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_ML ) ;
 if ( pdf_is_number ( ctx , obj ) && proc -> op_M ) proc -> op_M ( ctx , proc , pdf_to_real ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_D ) ;
 if ( pdf_is_array ( ctx , obj ) && proc -> op_d ) {
 pdf_obj * dash_array = pdf_array_get ( ctx , obj , 0 ) ;
 pdf_obj * dash_phase = pdf_array_get ( ctx , obj , 1 ) ;
 proc -> op_d ( ctx , proc , dash_array , pdf_to_real ( ctx , dash_phase ) ) ;
 }
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_RI ) ;
 if ( pdf_is_name ( ctx , obj ) && proc -> op_ri ) proc -> op_ri ( ctx , proc , pdf_to_name ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_FL ) ;
 if ( pdf_is_number ( ctx , obj ) && proc -> op_i ) proc -> op_i ( ctx , proc , pdf_to_real ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_Font ) ;
 if ( pdf_is_array ( ctx , obj ) && proc -> op_Tf ) {
 pdf_obj * font_ref = pdf_array_get ( ctx , obj , 0 ) ;
 pdf_obj * font_size = pdf_array_get ( ctx , obj , 1 ) ;
 pdf_font_desc * font = load_font_or_hail_mary ( ctx , csi -> doc , csi -> rdb , font_ref , 0 , csi -> cookie ) ;
 fz_try ( ctx ) proc -> op_Tf ( ctx , proc , "ExtGState" , font , pdf_to_real ( ctx , font_size ) ) ;
 fz_always ( ctx ) pdf_drop_font ( ctx , font ) ;
 fz_catch ( ctx ) fz_rethrow ( ctx ) ;
 }
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_OP ) ;
 if ( pdf_is_bool ( ctx , obj ) && proc -> op_gs_OP ) proc -> op_gs_OP ( ctx , proc , pdf_to_bool ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_op ) ;
 if ( pdf_is_bool ( ctx , obj ) && proc -> op_gs_op ) proc -> op_gs_op ( ctx , proc , pdf_to_bool ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_OPM ) ;
 if ( pdf_is_int ( ctx , obj ) && proc -> op_gs_OPM ) proc -> op_gs_OPM ( ctx , proc , pdf_to_int ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_UseBlackPtComp ) ;
 if ( pdf_is_name ( ctx , obj ) && proc -> op_gs_UseBlackPtComp ) proc -> op_gs_UseBlackPtComp ( ctx , proc , obj ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_TR2 ) ;
 if ( pdf_is_name ( ctx , obj ) ) if ( ! pdf_name_eq ( ctx , obj , PDF_NAME_Identity ) && ! pdf_name_eq ( ctx , obj , PDF_NAME_Default ) ) fz_warn ( ctx , "ignoring transfer function" ) ;
 if ( ! obj ) {
 pdf_obj * tr = pdf_dict_get ( ctx , dict , PDF_NAME_TR ) ;
 if ( pdf_is_name ( ctx , tr ) ) if ( ! pdf_name_eq ( ctx , tr , PDF_NAME_Identity ) ) fz_warn ( ctx , "ignoring transfer function" ) ;
 }
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_CA ) ;
 if ( pdf_is_number ( ctx , obj ) && proc -> op_gs_CA ) proc -> op_gs_CA ( ctx , proc , pdf_to_real ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_ca ) ;
 if ( pdf_is_number ( ctx , obj ) && proc -> op_gs_ca ) proc -> op_gs_ca ( ctx , proc , pdf_to_real ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_BM ) ;
 if ( pdf_is_array ( ctx , obj ) ) obj = pdf_array_get ( ctx , obj , 0 ) ;
 if ( pdf_is_name ( ctx , obj ) && proc -> op_gs_BM ) proc -> op_gs_BM ( ctx , proc , pdf_to_name ( ctx , obj ) ) ;
 obj = pdf_dict_get ( ctx , dict , PDF_NAME_SMask ) ;
 if ( proc -> op_gs_SMask ) {
 if ( pdf_is_dict ( ctx , obj ) ) {
 pdf_xobject * xobj ;
 pdf_obj * group , * s , * bc , * tr ;
 float softmask_bc [ FZ_MAX_COLORS ] ;
 fz_colorspace * colorspace ;
 int colorspace_n = 1 ;
 int k , luminosity ;
 fz_var ( xobj ) ;
 group = pdf_dict_get ( ctx , obj , PDF_NAME_G ) ;
 xobj = pdf_load_xobject ( ctx , csi -> doc , group ) ;
 fz_try ( ctx ) {
 colorspace = pdf_xobject_colorspace ( ctx , xobj ) ;
 if ( colorspace ) colorspace_n = fz_colorspace_n ( ctx , colorspace ) ;
 for ( k = 0 ;
 k < colorspace_n ;
 k ++ ) softmask_bc [ k ] = 0 ;
 if ( fz_colorspace_is_cmyk ( ctx , colorspace ) ) softmask_bc [ 3 ] = 1.0f ;
 fz_drop_colorspace ( ctx , colorspace ) ;
 bc = pdf_dict_get ( ctx , obj , PDF_NAME_BC ) ;
 if ( pdf_is_array ( ctx , bc ) ) {
 for ( k = 0 ;
 k < colorspace_n ;
 k ++ ) softmask_bc [ k ] = pdf_to_real ( ctx , pdf_array_get ( ctx , bc , k ) ) ;
 }
 s = pdf_dict_get ( ctx , obj , PDF_NAME_S ) ;
 if ( pdf_name_eq ( ctx , s , PDF_NAME_Luminosity ) ) luminosity = 1 ;
 else luminosity = 0 ;
 tr = pdf_dict_get ( ctx , obj , PDF_NAME_TR ) ;
 if ( tr && ! pdf_name_eq ( ctx , tr , PDF_NAME_Identity ) ) fz_warn ( ctx , "ignoring transfer function" ) ;
 proc -> op_gs_SMask ( ctx , proc , xobj , csi -> rdb , softmask_bc , luminosity ) ;
 }
 fz_always ( ctx ) {
 pdf_drop_xobject ( ctx , xobj ) ;
 }
 fz_catch ( ctx ) {
 fz_rethrow ( ctx ) ;
 }
 }
 else if ( pdf_is_name ( ctx , obj ) && pdf_name_eq ( ctx , obj , PDF_NAME_None ) ) {
 proc -> op_gs_SMask ( ctx , proc , NULL , NULL , NULL , 0 ) ;
 }
 }
 }
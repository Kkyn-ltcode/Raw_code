static struct qcms_modular_transform * qcms_modular_transform_create_lut ( struct lutType * lut ) {
 struct qcms_modular_transform * first_transform = NULL ;
 struct qcms_modular_transform * * next_transform = & first_transform ;
 struct qcms_modular_transform * transform = NULL ;
 size_t in_curve_len , clut_length , out_curve_len ;
 float * in_curves , * clut , * out_curves ;
 transform = qcms_modular_transform_alloc ( ) ;
 if ( ! transform ) goto fail ;
 append_transform ( transform , & next_transform ) ;
 transform -> matrix = build_lut_matrix ( lut ) ;
 if ( transform -> matrix . invalid ) goto fail ;
 transform -> transform_module_fn = qcms_transform_module_matrix ;
 transform = qcms_modular_transform_alloc ( ) ;
 if ( ! transform ) goto fail ;
 append_transform ( transform , & next_transform ) ;
 in_curve_len = sizeof ( float ) * lut -> num_input_table_entries * 3 ;
 in_curves = malloc ( in_curve_len ) ;
 if ( ! in_curves ) goto fail ;
 memcpy ( in_curves , lut -> input_table , in_curve_len ) ;
 transform -> input_clut_table_r = in_curves + lut -> num_input_table_entries * 0 ;
 transform -> input_clut_table_g = in_curves + lut -> num_input_table_entries * 1 ;
 transform -> input_clut_table_b = in_curves + lut -> num_input_table_entries * 2 ;
 transform -> input_clut_table_length = lut -> num_input_table_entries ;
 clut_length = sizeof ( float ) * pow ( lut -> num_clut_grid_points , 3 ) * 3 ;
 clut = malloc ( clut_length ) ;
 if ( ! clut ) goto fail ;
 memcpy ( clut , lut -> clut_table , clut_length ) ;
 transform -> r_clut = clut + 0 ;
 transform -> g_clut = clut + 1 ;
 transform -> b_clut = clut + 2 ;
 transform -> grid_size = lut -> num_clut_grid_points ;
 out_curve_len = sizeof ( float ) * lut -> num_output_table_entries * 3 ;
 out_curves = malloc ( out_curve_len ) ;
 if ( ! out_curves ) goto fail ;
 memcpy ( out_curves , lut -> output_table , out_curve_len ) ;
 transform -> output_clut_table_r = out_curves + lut -> num_output_table_entries * 0 ;
 transform -> output_clut_table_g = out_curves + lut -> num_output_table_entries * 1 ;
 transform -> output_clut_table_b = out_curves + lut -> num_output_table_entries * 2 ;
 transform -> output_clut_table_length = lut -> num_output_table_entries ;
 transform -> transform_module_fn = qcms_transform_module_clut ;
 return first_transform ;
 fail : qcms_modular_transform_release ( first_transform ) ;
 return NULL ;
 }
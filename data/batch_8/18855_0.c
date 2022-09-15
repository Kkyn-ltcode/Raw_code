static float * qcms_modular_transform_data ( struct qcms_modular_transform * transform , float * src , float * dest , size_t len ) {
 while ( transform != NULL ) {
 float * new_src = dest ;
 const transform_module_fn_t transform_fn = transform -> transform_module_fn ;
 if ( transform_fn != qcms_transform_module_gamma_table && transform_fn != qcms_transform_module_gamma_lut && transform_fn != qcms_transform_module_clut && transform_fn != qcms_transform_module_clut_only && transform_fn != qcms_transform_module_matrix && transform_fn != qcms_transform_module_matrix_translate && transform_fn != qcms_transform_module_LAB_to_XYZ && transform_fn != qcms_transform_module_XYZ_to_LAB ) {
 assert ( 0 && "Unsupported transform module" ) ;
 return NULL ;
 }
 transform -> transform_module_fn ( transform , src , dest , len ) ;
 dest = src ;
 src = new_src ;
 transform = transform -> next_transform ;
 }
 return src ;
 }
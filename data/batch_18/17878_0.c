static vpx_codec_err_t ctrl_set_previewpp ( vpx_codec_alg_priv_t * ctx , va_list args ) {
 # if CONFIG_VP9_POSTPROC vp8_postproc_cfg_t * config = va_arg ( args , vp8_postproc_cfg_t * ) ;
 if ( config != NULL ) {
 ctx -> preview_ppcfg = * config ;
 return VPX_CODEC_OK ;
 }
 else {
 return VPX_CODEC_INVALID_PARAM ;
 }
 # else ( void ) ctx ;
 ( void ) args ;
 return VPX_CODEC_INCAPABLE ;
 # endif }
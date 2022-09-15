vpx_codec_err_t vpx_codec_enc_init_multi_ver ( vpx_codec_ctx_t * ctx , vpx_codec_iface_t * iface , vpx_codec_enc_cfg_t * cfg , int num_enc , vpx_codec_flags_t flags , vpx_rational_t * dsf , int ver ) {
 vpx_codec_err_t res = VPX_CODEC_OK ;
 if ( ver != VPX_ENCODER_ABI_VERSION ) res = VPX_CODEC_ABI_MISMATCH ;
 else if ( ! ctx || ! iface || ! cfg || ( num_enc > 16 || num_enc < 1 ) ) res = VPX_CODEC_INVALID_PARAM ;
 else if ( iface -> abi_version != VPX_CODEC_INTERNAL_ABI_VERSION ) res = VPX_CODEC_ABI_MISMATCH ;
 else if ( ! ( iface -> caps & VPX_CODEC_CAP_ENCODER ) ) res = VPX_CODEC_INCAPABLE ;
 else if ( ( flags & VPX_CODEC_USE_PSNR ) && ! ( iface -> caps & VPX_CODEC_CAP_PSNR ) ) res = VPX_CODEC_INCAPABLE ;
 else if ( ( flags & VPX_CODEC_USE_OUTPUT_PARTITION ) && ! ( iface -> caps & VPX_CODEC_CAP_OUTPUT_PARTITION ) ) res = VPX_CODEC_INCAPABLE ;
 else {
 int i ;
 void * mem_loc = NULL ;
 if ( ! ( res = iface -> enc . mr_get_mem_loc ( cfg , & mem_loc ) ) ) {
 for ( i = 0 ;
 i < num_enc ;
 i ++ ) {
 vpx_codec_priv_enc_mr_cfg_t mr_cfg ;
 if ( dsf -> num < 1 || dsf -> num > 4096 || dsf -> den < 1 || dsf -> den > dsf -> num ) {
 res = VPX_CODEC_INVALID_PARAM ;
 break ;
 }
 mr_cfg . mr_low_res_mode_info = mem_loc ;
 mr_cfg . mr_total_resolutions = num_enc ;
 mr_cfg . mr_encoder_id = num_enc - 1 - i ;
 mr_cfg . mr_down_sampling_factor . num = dsf -> num ;
 mr_cfg . mr_down_sampling_factor . den = dsf -> den ;
 if ( mr_cfg . mr_encoder_id ) cfg -> kf_mode = VPX_KF_DISABLED ;
 ctx -> iface = iface ;
 ctx -> name = iface -> name ;
 ctx -> priv = NULL ;
 ctx -> init_flags = flags ;
 ctx -> config . enc = cfg ;
 res = ctx -> iface -> init ( ctx , & mr_cfg ) ;
 if ( res ) {
 const char * error_detail = ctx -> priv ? ctx -> priv -> err_detail : NULL ;
 ctx -> err_detail = error_detail ;
 vpx_codec_destroy ( ctx ) ;
 while ( i ) {
 ctx -- ;
 ctx -> err_detail = error_detail ;
 vpx_codec_destroy ( ctx ) ;
 i -- ;
 }
 }
 if ( res ) break ;
 ctx ++ ;
 cfg ++ ;
 dsf ++ ;
 }
 ctx -- ;
 }
 }
 return SAVE_STATUS ( ctx , res ) ;
 }
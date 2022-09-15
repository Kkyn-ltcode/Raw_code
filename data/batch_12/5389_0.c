static enum fetch_step vbf_stp_retry ( struct worker * wrk , struct busyobj * bo ) {
 struct vfp_ctx * vfc ;
 CHECK_OBJ_NOTNULL ( wrk , WORKER_MAGIC ) ;
 CHECK_OBJ_NOTNULL ( bo , BUSYOBJ_MAGIC ) ;
 vfc = bo -> vfc ;
 CHECK_OBJ_NOTNULL ( vfc , VFP_CTX_MAGIC ) ;
 assert ( bo -> fetch_objcore -> boc -> state <= BOS_REQ_DONE ) ;
 VSLb_ts_busyobj ( bo , "Retry" , W_TIM_real ( wrk ) ) ;
 assert ( bo -> director_state == DIR_S_NULL ) ;
 bo -> storage = NULL ;
 bo -> storage_hint = NULL ;
 bo -> do_esi = 0 ;
 bo -> do_stream = 1 ;
 VFP_Setup ( vfc ) ;
 VSL_ChgId ( bo -> vsl , "bereq" , "retry" , VXID_Get ( wrk , VSL_BACKENDMARKER ) ) ;
 VSLb_ts_busyobj ( bo , "Start" , bo -> t_prev ) ;
 http_VSL_log ( bo -> bereq ) ;
 return ( F_STP_STARTFETCH ) ;
 }
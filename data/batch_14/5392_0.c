static enum fetch_step vbf_stp_startfetch ( struct worker * wrk , struct busyobj * bo ) {
 int i ;
 double now ;
 CHECK_OBJ_NOTNULL ( wrk , WORKER_MAGIC ) ;
 CHECK_OBJ_NOTNULL ( bo , BUSYOBJ_MAGIC ) ;
 AZ ( bo -> storage ) ;
 AZ ( bo -> storage_hint ) ;
 bo -> storage = STV_next ( ) ;
 if ( bo -> retries > 0 ) http_Unset ( bo -> bereq , "\012X-Varnish:" ) ;
 http_PrintfHeader ( bo -> bereq , "X-Varnish: %u" , VXID ( bo -> vsl -> wid ) ) ;
 VCL_backend_fetch_method ( bo -> vcl , wrk , NULL , bo , NULL ) ;
 bo -> uncacheable = bo -> do_pass ;
 if ( wrk -> handling == VCL_RET_ABANDON || wrk -> handling == VCL_RET_FAIL ) return ( F_STP_FAIL ) ;
 assert ( wrk -> handling == VCL_RET_FETCH ) ;
 HTTP_Setup ( bo -> beresp , bo -> ws , bo -> vsl , SLT_BerespMethod ) ;
 assert ( bo -> fetch_objcore -> boc -> state <= BOS_REQ_DONE ) ;
 AZ ( bo -> htc ) ;
 i = VDI_GetHdr ( wrk , bo ) ;
 now = W_TIM_real ( wrk ) ;
 VSLb_ts_busyobj ( bo , "Beresp" , now ) ;
 if ( i ) {
 assert ( bo -> director_state == DIR_S_NULL ) ;
 return ( F_STP_ERROR ) ;
 }
 http_VSL_log ( bo -> beresp ) ;
 if ( ! http_GetHdr ( bo -> beresp , H_Date , NULL ) ) {
 http_TimeHeader ( bo -> beresp , "Date: " , now ) ;
 }
 http_CollectHdr ( bo -> beresp , H_Cache_Control ) ;
 http_CollectHdr ( bo -> beresp , H_Vary ) ;
 if ( ! strcasecmp ( http_GetMethod ( bo -> bereq ) , "head" ) ) {
 wrk -> stats -> fetch_head ++ ;
 bo -> htc -> body_status = BS_NONE ;
 }
 else if ( http_GetStatus ( bo -> beresp ) <= 199 ) {
 wrk -> stats -> fetch_1xx ++ ;
 bo -> htc -> body_status = BS_ERROR ;
 }
 else if ( http_IsStatus ( bo -> beresp , 204 ) ) {
 wrk -> stats -> fetch_204 ++ ;
 if ( ( http_GetHdr ( bo -> beresp , H_Content_Length , NULL ) && bo -> htc -> content_length != 0 ) || http_GetHdr ( bo -> beresp , H_Transfer_Encoding , NULL ) ) bo -> htc -> body_status = BS_ERROR ;
 else bo -> htc -> body_status = BS_NONE ;
 }
 else if ( http_IsStatus ( bo -> beresp , 304 ) ) {
 wrk -> stats -> fetch_304 ++ ;
 bo -> htc -> body_status = BS_NONE ;
 }
 else if ( bo -> htc -> body_status == BS_CHUNKED ) {
 wrk -> stats -> fetch_chunked ++ ;
 }
 else if ( bo -> htc -> body_status == BS_LENGTH ) {
 assert ( bo -> htc -> content_length > 0 ) ;
 wrk -> stats -> fetch_length ++ ;
 }
 else if ( bo -> htc -> body_status == BS_EOF ) {
 wrk -> stats -> fetch_eof ++ ;
 }
 else if ( bo -> htc -> body_status == BS_ERROR ) {
 wrk -> stats -> fetch_bad ++ ;
 }
 else if ( bo -> htc -> body_status == BS_NONE ) {
 wrk -> stats -> fetch_none ++ ;
 }
 else {
 WRONG ( "wrong bodystatus" ) ;
 }
 if ( bo -> htc -> body_status == BS_ERROR ) {
 bo -> htc -> doclose = SC_RX_BODY ;
 VDI_Finish ( bo -> wrk , bo ) ;
 VSLb ( bo -> vsl , SLT_Error , "Body cannot be fetched" ) ;
 assert ( bo -> director_state == DIR_S_NULL ) ;
 return ( F_STP_ERROR ) ;
 }
 if ( bo -> fetch_objcore -> flags & OC_F_PRIVATE ) {
 bo -> fetch_objcore -> t_origin = now ;
 bo -> fetch_objcore -> ttl = - 1. ;
 bo -> fetch_objcore -> grace = 0 ;
 bo -> fetch_objcore -> keep = 0 ;
 }
 else {
 RFC2616_Ttl ( bo , now , & bo -> fetch_objcore -> t_origin , & bo -> fetch_objcore -> ttl , & bo -> fetch_objcore -> grace , & bo -> fetch_objcore -> keep ) ;
 }
 AZ ( bo -> do_esi ) ;
 AZ ( bo -> was_304 ) ;
 if ( http_IsStatus ( bo -> beresp , 304 ) ) {
 if ( bo -> stale_oc != NULL && ObjCheckFlag ( bo -> wrk , bo -> stale_oc , OF_IMSCAND ) ) {
 if ( ObjCheckFlag ( bo -> wrk , bo -> stale_oc , OF_CHGGZIP ) ) {
 http_Unset ( bo -> beresp , H_Content_Encoding ) ;
 RFC2616_Weaken_Etag ( bo -> beresp ) ;
 }
 http_Unset ( bo -> beresp , H_Content_Length ) ;
 HTTP_Merge ( bo -> wrk , bo -> stale_oc , bo -> beresp ) ;
 assert ( http_IsStatus ( bo -> beresp , 200 ) ) ;
 bo -> was_304 = 1 ;
 }
 else if ( ! bo -> do_pass ) {
 VSLb ( bo -> vsl , SLT_Error , "304 response but not conditional fetch" ) ;
 bo -> htc -> doclose = SC_RX_BAD ;
 VDI_Finish ( bo -> wrk , bo ) ;
 return ( F_STP_ERROR ) ;
 }
 }
 bo -> vfc -> bo = bo ;
 bo -> vfc -> oc = bo -> fetch_objcore ;
 bo -> vfc -> wrk = bo -> wrk ;
 bo -> vfc -> http = bo -> beresp ;
 bo -> vfc -> esi_req = bo -> bereq ;
 VCL_backend_response_method ( bo -> vcl , wrk , NULL , bo , NULL ) ;
 if ( wrk -> handling == VCL_RET_ABANDON || wrk -> handling == VCL_RET_FAIL ) {
 bo -> htc -> doclose = SC_RESP_CLOSE ;
 VDI_Finish ( bo -> wrk , bo ) ;
 return ( F_STP_FAIL ) ;
 }
 if ( wrk -> handling == VCL_RET_RETRY ) {
 if ( bo -> htc -> body_status != BS_NONE ) bo -> htc -> doclose = SC_RESP_CLOSE ;
 if ( bo -> director_state != DIR_S_NULL ) VDI_Finish ( bo -> wrk , bo ) ;
 if ( bo -> retries ++ < cache_param -> max_retries ) return ( F_STP_RETRY ) ;
 VSLb ( bo -> vsl , SLT_VCL_Error , "Too many retries, delivering 503" ) ;
 assert ( bo -> director_state == DIR_S_NULL ) ;
 return ( F_STP_ERROR ) ;
 }
 assert ( bo -> fetch_objcore -> boc -> state <= BOS_REQ_DONE ) ;
 if ( bo -> fetch_objcore -> boc -> state != BOS_REQ_DONE ) {
 bo -> req = NULL ;
 ObjSetState ( wrk , bo -> fetch_objcore , BOS_REQ_DONE ) ;
 }
 if ( bo -> do_esi ) bo -> do_stream = 0 ;
 if ( wrk -> handling == VCL_RET_PASS ) {
 bo -> fetch_objcore -> flags |= OC_F_HFP ;
 bo -> uncacheable = 1 ;
 wrk -> handling = VCL_RET_DELIVER ;
 }
 if ( bo -> do_pass || bo -> uncacheable ) bo -> fetch_objcore -> flags |= OC_F_PASS ;
 assert ( wrk -> handling == VCL_RET_DELIVER ) ;
 return ( bo -> was_304 ? F_STP_CONDFETCH : F_STP_FETCH ) ;
 }
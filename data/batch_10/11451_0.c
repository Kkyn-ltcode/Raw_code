static int ts_lua_http_enable_redirect ( lua_State * L ) {
 int value ;
 ts_lua_http_ctx * http_ctx ;
 GET_HTTP_CONTEXT ( http_ctx , L ) ;
 value = luaL_checkinteger ( L , 1 ) ;
 TSDebug ( TS_LUA_DEBUG_TAG , "enable redirect" ) ;
 TSHttpTxnFollowRedirect ( http_ctx -> txnp , value ) ;
 return 0 ;
 }
static int ts_lua_http_client_packet_tos_set ( lua_State * L ) {
 int value ;
 ts_lua_http_ctx * http_ctx ;
 GET_HTTP_CONTEXT ( http_ctx , L ) ;
 value = luaL_checkinteger ( L , 1 ) ;
 TSDebug ( TS_LUA_DEBUG_TAG , "client packet tos set" ) ;
 TSHttpTxnClientPacketTosSet ( http_ctx -> txnp , value ) ;
 return 0 ;
 }
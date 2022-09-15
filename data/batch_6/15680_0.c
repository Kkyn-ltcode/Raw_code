void luaD_reallocstack ( lua_State * L , int newsize ) {
 TValue * oldstack = L -> stack ;
 int realsize = newsize + 1 + EXTRA_STACK ;
 lua_assert ( L -> stack_last - L -> stack == L -> stacksize - EXTRA_STACK - 1 ) ;
 luaM_reallocvector ( L , L -> stack , L -> stacksize , realsize , TValue ) ;
 L -> stacksize = realsize ;
 L -> stack_last = L -> stack + newsize ;
 correctstack ( L , oldstack ) ;
 }
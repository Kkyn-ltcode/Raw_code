int evutil_vsnprintf ( char * buf , size_t buflen , const char * format , va_list ap ) {
 # ifdef _MSC_VER int r = _vsnprintf ( buf , buflen , format , ap ) ;
 buf [ buflen - 1 ] = '\0' ;
 if ( r >= 0 ) return r ;
 else return _vscprintf ( format , ap ) ;
 # else int r = vsnprintf ( buf , buflen , format , ap ) ;
 buf [ buflen - 1 ] = '\0' ;
 return r ;
 # endif }
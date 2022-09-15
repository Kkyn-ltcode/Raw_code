int evbuffer_read ( struct evbuffer * buf , int fd , int howmuch ) {
 u_char * p ;
 size_t oldoff = buf -> off ;
 int n = EVBUFFER_MAX_READ ;
 # if defined ( FIONREAD ) # ifdef WIN32 long lng = n ;
 if ( ioctlsocket ( fd , FIONREAD , & lng ) == - 1 || ( n = lng ) <= 0 ) {
 # else if ( ioctl ( fd , FIONREAD , & n ) == - 1 || n <= 0 ) {
 # endif n = EVBUFFER_MAX_READ ;
 }
 else if ( n > EVBUFFER_MAX_READ && n > howmuch ) {
 if ( ( size_t ) n > buf -> totallen << 2 ) n = buf -> totallen << 2 ;
 if ( n < EVBUFFER_MAX_READ ) n = EVBUFFER_MAX_READ ;
 }
 # endif if ( howmuch < 0 || howmuch > n ) howmuch = n ;
 if ( evbuffer_expand ( buf , howmuch ) == - 1 ) return ( - 1 ) ;
 p = buf -> buffer + buf -> off ;
 # ifndef WIN32 n = read ( fd , p , howmuch ) ;
 # else n = recv ( fd , p , howmuch , 0 ) ;
 # endif if ( n == - 1 ) return ( - 1 ) ;
 if ( n == 0 ) return ( 0 ) ;
 buf -> off += n ;
 if ( buf -> off != oldoff && buf -> cb != NULL ) ( * buf -> cb ) ( buf , oldoff , buf -> off , buf -> cbarg ) ;
 return ( n ) ;
 }
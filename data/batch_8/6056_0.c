void dlhandle_free ( struct dl_handle * dlhandle ) {
 if ( dlhandle -> ptr && dlhandle -> open && dlhandle -> enable_close ) {
 dlclose ( dlhandle -> ptr ) ;
 }
 }
static uint64 _tiffSizeProc ( thandle_t fd ) {
 ULARGE_INTEGER m ;
 m . LowPart = GetFileSize ( fd , & m . HighPart ) ;
 return ( m . QuadPart ) ;
 }
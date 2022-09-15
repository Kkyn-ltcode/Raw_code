bool checkSeek ( FILE * fp ) {
 pgoff_t tpos ;
 # ifndef HAVE_FSEEKO if ( sizeof ( pgoff_t ) > sizeof ( long ) ) return false ;
 # endif tpos = ftello ( fp ) ;
 if ( tpos < 0 ) return false ;
 if ( fseeko ( fp , tpos , SEEK_SET ) != 0 ) return false ;
 return true ;
 }
MPI # ifdef M_DEBUG mpi_debug_alloc_like ( MPI a , const char * info ) # else mpi_alloc_like ( MPI a ) # endif {
 MPI b ;
 if ( a && ( a -> flags & 4 ) ) {
 void * p = m_is_secure ( a -> d ) ? xmalloc_secure ( a -> nbits ) : xmalloc ( a -> nbits ) ;
 memcpy ( p , a -> d , a -> nbits ) ;
 b = mpi_set_opaque ( NULL , p , a -> nbits ) ;
 }
 else if ( a ) {
 # ifdef M_DEBUG b = mpi_is_secure ( a ) ? mpi_debug_alloc_secure ( a -> nlimbs , info ) : mpi_debug_alloc ( a -> nlimbs , info ) ;
 # else b = mpi_is_secure ( a ) ? mpi_alloc_secure ( a -> nlimbs ) : mpi_alloc ( a -> nlimbs ) ;
 # endif b -> nlimbs = 0 ;
 b -> sign = 0 ;
 b -> flags = a -> flags ;
 b -> nbits = 0 ;
 }
 else b = NULL ;
 return b ;
 }